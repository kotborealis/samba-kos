 /*
   Unix SMB/CIFS implementation.

   trivial database library

   Copyright (C) Andrew Tridgell              1999-2005
   Copyright (C) Paul `Rusty' Russell		   2000
   Copyright (C) Jeremy Allison			   2000-2003

     ** NOTE! The following LGPL license applies to the tdb
     ** library. This does NOT imply that all of Samba is released
     ** under the LGPL

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#include "tdb_private.h"
#include <source3/smbd/kos/kos_thread.h>

_PUBLIC_ void tdb_setalarm_sigptr(struct tdb_context *tdb, volatile sig_atomic_t *ptr)
{
	tdb->interrupt_sig_ptr = ptr;
}

static int fcntl_lock(struct tdb_context *tdb,
		      int rw, off_t off, off_t len, bool waitflag)
{
	struct flock fl;
	int cmd;

#ifdef USE_TDB_MUTEX_LOCKING
	{
		int ret;
		if (tdb_mutex_lock(tdb, rw, off, len, waitflag, &ret)) {
			return ret;
		}
	}
#endif

	fl.l_type = rw;
	fl.l_whence = SEEK_SET;
	fl.l_start = off;
	fl.l_len = len;
	fl.l_pid = 0;

	cmd = waitflag ? F_SETLKW : F_SETLK;

	return fcntl(tdb->fd, cmd, &fl);
}

static int fcntl_unlock(struct tdb_context *tdb, int rw, off_t off, off_t len)
{
	struct flock fl;
#if 0 /* Check they matched up locks and unlocks correctly. */
	char line[80];
	FILE *locks;
	bool found = false;

	locks = fopen("/proc/locks", "r");

	while (fgets(line, 80, locks)) {
		char *p;
		int type, start, l;

		/* eg. 1: FLOCK  ADVISORY  WRITE 2440 08:01:2180826 0 EOF */
		p = strchr(line, ':') + 1;
		if (strncmp(p, " POSIX  ADVISORY  ", strlen(" POSIX  ADVISORY  ")))
			continue;
		p += strlen(" FLOCK  ADVISORY  ");
		if (strncmp(p, "READ  ", strlen("READ  ")) == 0)
			type = F_RDLCK;
		else if (strncmp(p, "WRITE ", strlen("WRITE ")) == 0)
			type = F_WRLCK;
		else
			abort();
		p += 6;
		if (atoi(p) != getpid())
			continue;
		p = strchr(strchr(p, ' ') + 1, ' ') + 1;
		start = atoi(p);
		p = strchr(p, ' ') + 1;
		if (strncmp(p, "EOF", 3) == 0)
			l = 0;
		else
			l = atoi(p) - start + 1;

		if (off == start) {
			if (len != l) {
				fprintf(stderr, "Len %u should be %u: %s",
					(int)len, l, line);
				abort();
			}
			if (type != rw) {
				fprintf(stderr, "Type %s wrong: %s",
					rw == F_RDLCK ? "READ" : "WRITE", line);
				abort();
			}
			found = true;
			break;
		}
	}

	if (!found) {
		fprintf(stderr, "Unlock on %u@%u not found!\n",
			(int)off, (int)len);
		abort();
	}

	fclose(locks);
#endif

#ifdef USE_TDB_MUTEX_LOCKING
	{
		int ret;
		if (tdb_mutex_unlock(tdb, rw, off, len, &ret)) {
			return ret;
		}
	}
#endif

	fl.l_type = F_UNLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = off;
	fl.l_len = len;
	fl.l_pid = 0;

	return fcntl(tdb->fd, F_SETLKW, &fl);
}

/*
 * Calculate the lock offset for a list
 *
 * list -1 is the freelist, otherwise a hash chain.
 *
 * Note that we consistently (but without real reason) lock hash chains at an
 * offset that is 4 bytes below the real offset of the corresponding list head
 * in the db.
 *
 * This is the memory layout of the hashchain array:
 *
 * FREELIST_TOP + 0 = freelist
 * FREELIST_TOP + 4 = hashtable list 0
 * FREELIST_TOP + 8 = hashtable list 1
 * ...
 *
 * Otoh lock_offset computes:
 *
 * freelist = FREELIST_TOP - 4
 * list 0   = FREELIST_TOP + 0
 * list 1   = FREELIST_TOP + 4
 * ...
 *
 * Unfortunately we can't change this calculation in order to align the locking
 * offset with the memory layout, as that would make the locking incompatible
 * between different tdb versions.
 */
static tdb_off_t lock_offset(int list)
{
	return FREELIST_TOP + 4*list;
}

/* a byte range locking function - return 0 on success
   this functions locks/unlocks "len" byte at the specified offset.

   On error, errno is also set so that errors are passed back properly
   through tdb_open().

   note that a len of zero means lock to end of file
*/
int tdb_brlock(struct tdb_context *tdb,
	       int rw_type, tdb_off_t offset, size_t len,
	       enum tdb_lock_flags flags)
{
	int ret;

	if (tdb->flags & TDB_NOLOCK) {
		return 0;
	}

	if (flags & TDB_LOCK_MARK_ONLY) {
		return 0;
	}

	if ((rw_type == F_WRLCK) && (tdb->read_only || tdb->traverse_read)) {
		tdb->ecode = TDB_ERR_RDONLY;
		return -1;
	}

	do {
		ret = fcntl_lock(tdb, rw_type, offset, len,
				 flags & TDB_LOCK_WAIT);
		/* Check for a sigalarm break. */
		if (ret == -1 && errno == EINTR &&
				tdb->interrupt_sig_ptr &&
				*tdb->interrupt_sig_ptr) {
			break;
		}
	} while (ret == -1 && errno == EINTR);

	if (ret == -1) {
		tdb->ecode = TDB_ERR_LOCK;
		/* Generic lock error. errno set by fcntl.
		 * EAGAIN is an expected return from non-blocking
		 * locks. */
		if (!(flags & TDB_LOCK_PROBE) && errno != EAGAIN) {
			TDB_LOG((tdb, TDB_DEBUG_TRACE,"tdb_brlock failed (fd=%d) at offset %u rw_type=%d flags=%d len=%zu\n",
				 tdb->fd, offset, rw_type, flags, len));
		}
		return -1;
	}
	return 0;
}

int tdb_brunlock(struct tdb_context *tdb,
		 int rw_type, tdb_off_t offset, size_t len)
{
	int ret;

	if (tdb->flags & TDB_NOLOCK) {
		return 0;
	}

	do {
		ret = fcntl_unlock(tdb, rw_type, offset, len);
	} while (ret == -1 && errno == EINTR);

	if (ret == -1) {
		TDB_LOG((tdb, TDB_DEBUG_TRACE,"tdb_brunlock failed (fd=%d) at offset %u rw_type=%u len=%zu\n",
			 tdb->fd, offset, rw_type, len));
	}
	return ret;
}

/*
 * Do a tdb_brlock in a loop. Some OSes (such as solaris) have too
 * conservative deadlock detection and claim a deadlock when progress can be
 * made. For those OSes we may loop for a while.
 */

static int tdb_brlock_retry(struct tdb_context *tdb,
			    int rw_type, tdb_off_t offset, size_t len,
			    enum tdb_lock_flags flags)
{
	int count = 1000;

	while (count--) {
		struct timeval tv;
		int ret;

		ret = tdb_brlock(tdb, rw_type, offset, len, flags);
		if (ret == 0) {
			return 0;
		}
		if (errno != EDEADLK) {
			break;
		}
		/* sleep for as short a time as we can - more portable than usleep() */
		tv.tv_sec = 0;
		tv.tv_usec = 1;
		select(0, NULL, NULL, NULL, &tv);
	}
	return -1;
}

/*
  upgrade a read lock to a write lock.
*/
int tdb_allrecord_upgrade(struct tdb_context *tdb)
{
	int ret;

	if (tdb->allrecord_lock.count != 1) {
		TDB_LOG((tdb, TDB_DEBUG_ERROR,
			 "tdb_allrecord_upgrade failed: count %u too high\n",
			 tdb->allrecord_lock.count));
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb->allrecord_lock.off != 1) {
		TDB_LOG((tdb, TDB_DEBUG_ERROR,
			 "tdb_allrecord_upgrade failed: already upgraded?\n"));
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb_have_mutexes(tdb)) {
		ret = tdb_mutex_allrecord_upgrade(tdb);
		if (ret == -1) {
			goto fail;
		}
		ret = tdb_brlock_retry(tdb, F_WRLCK, lock_offset(tdb->hash_size),
				       0, TDB_LOCK_WAIT|TDB_LOCK_PROBE);
		if (ret == -1) {
			tdb_mutex_allrecord_downgrade(tdb);
		}
	} else {
		ret = tdb_brlock_retry(tdb, F_WRLCK, FREELIST_TOP, 0,
				       TDB_LOCK_WAIT|TDB_LOCK_PROBE);
	}

	if (ret == 0) {
		tdb->allrecord_lock.ltype = F_WRLCK;
		tdb->allrecord_lock.off = 0;
		return 0;
	}
fail:
	TDB_LOG((tdb, TDB_DEBUG_TRACE,"tdb_allrecord_upgrade failed\n"));
	return -1;
}

static struct tdb_lock_type *find_nestlock(struct tdb_context *tdb,
					   tdb_off_t offset)
{
	int i;

	for (i=0; i<tdb->num_lockrecs; i++) {
		if (tdb->lockrecs[i].off == offset) {
			return &tdb->lockrecs[i];
		}
	}
	return NULL;
}

/* lock an offset in the database. */
int tdb_nest_lock(struct tdb_context *tdb, uint32_t offset, int ltype,
		  enum tdb_lock_flags flags)
{
	struct tdb_lock_type *new_lck;

	if (offset >= lock_offset(tdb->hash_size)) {
		tdb->ecode = TDB_ERR_LOCK;
		TDB_LOG((tdb, TDB_DEBUG_ERROR,"tdb_lock: invalid offset %u for ltype=%d\n",
			 offset, ltype));
		return -1;
	}
	if (tdb->flags & TDB_NOLOCK)
		return 0;

	new_lck = find_nestlock(tdb, offset);
	if (new_lck) {
		if ((new_lck->ltype == F_RDLCK) && (ltype == F_WRLCK)) {
			if (!tdb_have_mutexes(tdb)) {
				int ret;
				/*
				 * Upgrade the underlying fcntl
				 * lock. Mutexes don't do readlocks,
				 * so this only applies to fcntl
				 * locking.
				 */
				ret = tdb_brlock(tdb, ltype, offset, 1, flags);
				if (ret != 0) {
					return ret;
				}
			}
			new_lck->ltype = F_WRLCK;
		}
		/*
		 * Just increment the in-memory struct, posix locks
		 * don't stack.
		 */
		new_lck->count++;
		return 0;
	}

	if (tdb->num_lockrecs == tdb->lockrecs_array_length) {
		new_lck = (struct tdb_lock_type *)realloc(
			tdb->lockrecs,
			sizeof(*tdb->lockrecs) * (tdb->num_lockrecs+256));
		if (new_lck == NULL) {
			errno = ENOMEM;
			return -1;
		}
		tdb->lockrecs_array_length = tdb->num_lockrecs+256;
		tdb->lockrecs = new_lck;
	}

	/* Since fcntl locks don't nest, we do a lock for the first one,
	   and simply bump the count for future ones */
	if (tdb_brlock(tdb, ltype, offset, 1, flags)) {
		return -1;
	}

	new_lck = &tdb->lockrecs[tdb->num_lockrecs];

	new_lck->off = offset;
	new_lck->count = 1;
	new_lck->ltype = ltype;
	tdb->num_lockrecs++;

	return 0;
}

static int tdb_lock_and_recover(struct tdb_context *tdb)
{
	int ret;

	/* We need to match locking order in transaction commit. */
	if (tdb_brlock(tdb, F_WRLCK, FREELIST_TOP, 0, TDB_LOCK_WAIT)) {
		return -1;
	}

	if (tdb_brlock(tdb, F_WRLCK, OPEN_LOCK, 1, TDB_LOCK_WAIT)) {
		tdb_brunlock(tdb, F_WRLCK, FREELIST_TOP, 0);
		return -1;
	}

	ret = tdb_transaction_recover(tdb);

	tdb_brunlock(tdb, F_WRLCK, OPEN_LOCK, 1);
	tdb_brunlock(tdb, F_WRLCK, FREELIST_TOP, 0);

	return ret;
}

static bool have_data_locks(const struct tdb_context *tdb)
{
	int i;

	for (i = 0; i < tdb->num_lockrecs; i++) {
		if (tdb->lockrecs[i].off >= lock_offset(-1))
			return true;
	}
	return false;
}

/*
 * A allrecord lock allows us to avoid per chain locks. Check if the allrecord
 * lock is strong enough.
 */
static int tdb_lock_covered_by_allrecord_lock(struct tdb_context *tdb,
					      int ltype)
{
	if (ltype == F_RDLCK) {
		/*
		 * The allrecord_lock is equal (F_RDLCK) or stronger
		 * (F_WRLCK). Pass.
		 */
		return 0;
	}

	if (tdb->allrecord_lock.ltype == F_RDLCK) {
		/*
		 * We ask for ltype==F_WRLCK, but the allrecord_lock
		 * is too weak. We can't upgrade here, so fail.
		 */
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	/*
	 * Asking for F_WRLCK, allrecord is F_WRLCK as well. Pass.
	 */
	return 0;
}

static int tdb_lock_list(struct tdb_context *tdb, int list, int ltype,
			 enum tdb_lock_flags waitflag)
{
	int ret;
	bool check = false;

	if (tdb->allrecord_lock.count) {
		return tdb_lock_covered_by_allrecord_lock(tdb, ltype);
	}

	/*
	 * Check for recoveries: Someone might have kill -9'ed a process
	 * during a commit.
	 */
	check = !have_data_locks(tdb);
	ret = tdb_nest_lock(tdb, lock_offset(list), ltype, waitflag);

	if (ret == 0 && check && tdb_needs_recovery(tdb)) {
		tdb_nest_unlock(tdb, lock_offset(list), ltype, false);

		if (tdb_lock_and_recover(tdb) == -1) {
			return -1;
		}
		return tdb_lock_list(tdb, list, ltype, waitflag);
	}
	return ret;
}

/* lock a list in the database. list -1 is the alloc list */
int tdb_lock(struct tdb_context *tdb, int list, int ltype)
{
	int ret;

	ret = tdb_lock_list(tdb, list, ltype, TDB_LOCK_WAIT);
	if (ret) {
		TDB_LOG((tdb, TDB_DEBUG_ERROR, "tdb_lock failed on list %d "
			 "ltype=%d (%s)\n",  list, ltype, strerror(errno)));
	}
	return ret;
}

/* lock a list in the database. list -1 is the alloc list. non-blocking lock */
_PUBLIC_ int tdb_lock_nonblock(struct tdb_context *tdb, int list, int ltype);
_PUBLIC_ int tdb_lock_nonblock(struct tdb_context *tdb, int list, int ltype)
{
	return tdb_lock_list(tdb, list, ltype, TDB_LOCK_NOWAIT);
}


int tdb_nest_unlock(struct tdb_context *tdb, uint32_t offset, int ltype,
		    bool mark_lock)
{
	int ret = -1;
	struct tdb_lock_type *lck;

	if (tdb->flags & TDB_NOLOCK)
		return 0;

	/* Sanity checks */
	if (offset >= lock_offset(tdb->hash_size)) {
		TDB_LOG((tdb, TDB_DEBUG_ERROR, "tdb_unlock: offset %u invalid (%d)\n", offset, tdb->hash_size));
		return ret;
	}

	lck = find_nestlock(tdb, offset);
	if ((lck == NULL) || (lck->count == 0)) {
		TDB_LOG((tdb, TDB_DEBUG_ERROR, "tdb_unlock: count is 0\n"));
		return -1;
	}

	if (lck->count > 1) {
		lck->count--;
		return 0;
	}

	/*
	 * This lock has count==1 left, so we need to unlock it in the
	 * kernel. We don't bother with decrementing the in-memory array
	 * element, we're about to overwrite it with the last array element
	 * anyway.
	 */

	if (mark_lock) {
		ret = 0;
	} else {
		ret = tdb_brunlock(tdb, ltype, offset, 1);
	}

	/*
	 * Shrink the array by overwriting the element just unlocked with the
	 * last array element.
	 */
	*lck = tdb->lockrecs[--tdb->num_lockrecs];

	/*
	 * We don't bother with realloc when the array shrinks, but if we have
	 * a completely idle tdb we should get rid of the locked array.
	 */

	if (ret)
		TDB_LOG((tdb, TDB_DEBUG_ERROR, "tdb_unlock: An error occurred unlocking!\n"));
	return ret;
}

_PUBLIC_ int tdb_unlock(struct tdb_context *tdb, int list, int ltype);
_PUBLIC_ int tdb_unlock(struct tdb_context *tdb, int list, int ltype)
{
	/* a global lock allows us to avoid per chain locks */
	if (tdb->allrecord_lock.count) {
		return tdb_lock_covered_by_allrecord_lock(tdb, ltype);
	}

	return tdb_nest_unlock(tdb, lock_offset(list), ltype, false);
}

/*
  get the transaction lock
 */
int tdb_transaction_lock(struct tdb_context *tdb, int ltype,
			 enum tdb_lock_flags lockflags)
{
	return tdb_nest_lock(tdb, TRANSACTION_LOCK, ltype, lockflags);
}

/*
  release the transaction lock
 */
int tdb_transaction_unlock(struct tdb_context *tdb, int ltype)
{
	return tdb_nest_unlock(tdb, TRANSACTION_LOCK, ltype, false);
}

/* Returns 0 if all done, -1 if error, 1 if ok. */
static int tdb_allrecord_check(struct tdb_context *tdb, int ltype,
			       enum tdb_lock_flags flags, bool upgradable)
{
	/* There are no locks on read-only dbs */
	if (tdb->read_only || tdb->traverse_read) {
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb->allrecord_lock.count &&
	    tdb->allrecord_lock.ltype == (uint32_t)ltype) {
		tdb->allrecord_lock.count++;
		return 0;
	}

	if (tdb->allrecord_lock.count) {
		/* a global lock of a different type exists */
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb_have_extra_locks(tdb)) {
		/* can't combine global and chain locks */
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (upgradable && ltype != F_RDLCK) {
		/* tdb error: you can't upgrade a write lock! */
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}
	return 1;
}

/* We only need to lock individual bytes, but Linux merges consecutive locks
 * so we lock in contiguous ranges. */
static int tdb_chainlock_gradual(struct tdb_context *tdb,
				 int ltype, enum tdb_lock_flags flags,
				 size_t off, size_t len)
{
	int ret;
	enum tdb_lock_flags nb_flags = (flags & ~TDB_LOCK_WAIT);

	if (len <= 4) {
		/* Single record.  Just do blocking lock. */
		return tdb_brlock(tdb, ltype, off, len, flags);
	}

	/* First we try non-blocking. */
	ret = tdb_brlock(tdb, ltype, off, len, nb_flags);
	if (ret == 0) {
		return 0;
	}

	/* Try locking first half, then second. */
	ret = tdb_chainlock_gradual(tdb, ltype, flags, off, len / 2);
	if (ret == -1)
		return -1;

	ret = tdb_chainlock_gradual(tdb, ltype, flags,
				    off + len / 2, len - len / 2);
	if (ret == -1) {
		tdb_brunlock(tdb, ltype, off, len / 2);
		return -1;
	}
	return 0;
}

/* lock/unlock entire database.  It can only be upgradable if you have some
 * other way of guaranteeing exclusivity (ie. transaction write lock).
 * We do the locking gradually to avoid being starved by smaller locks. */
int tdb_allrecord_lock(struct tdb_context *tdb, int ltype,
		       enum tdb_lock_flags flags, bool upgradable)
{
	int ret;

	switch (tdb_allrecord_check(tdb, ltype, flags, upgradable)) {
	case -1:
		return -1;
	case 0:
		return 0;
	}

	/* We cover two kinds of locks:
	 * 1) Normal chain locks.  Taken for almost all operations.
	 * 2) Individual records locks.  Taken after normal or free
	 *    chain locks.
	 *
	 * It is (1) which cause the starvation problem, so we're only
	 * gradual for that. */

	if (tdb_have_mutexes(tdb)) {
		ret = tdb_mutex_allrecord_lock(tdb, ltype, flags);
	} else {
		ret = tdb_chainlock_gradual(tdb, ltype, flags, FREELIST_TOP,
					    tdb->hash_size * 4);
	}

	if (ret == -1) {
		return -1;
	}

	/* Grab individual record locks. */
	if (tdb_brlock(tdb, ltype, lock_offset(tdb->hash_size), 0,
		       flags) == -1) {
		if (tdb_have_mutexes(tdb)) {
			tdb_mutex_allrecord_unlock(tdb);
		} else {
			tdb_brunlock(tdb, ltype, FREELIST_TOP,
				     tdb->hash_size * 4);
		}
		return -1;
	}

	tdb->allrecord_lock.count = 1;
	/* If it's upgradable, it's actually exclusive so we can treat
	 * it as a write lock. */
	tdb->allrecord_lock.ltype = upgradable ? F_WRLCK : ltype;
	tdb->allrecord_lock.off = upgradable;

	if (tdb_needs_recovery(tdb)) {
		bool mark = flags & TDB_LOCK_MARK_ONLY;
		tdb_allrecord_unlock(tdb, ltype, mark);
		if (mark) {
			tdb->ecode = TDB_ERR_LOCK;
			TDB_LOG((tdb, TDB_DEBUG_ERROR,
				 "tdb_lockall_mark cannot do recovery\n"));
			return -1;
		}
		if (tdb_lock_and_recover(tdb) == -1) {
			return -1;
		}
		return tdb_allrecord_lock(tdb, ltype, flags, upgradable);
	}

	return 0;
}



/* unlock entire db */
int tdb_allrecord_unlock(struct tdb_context *tdb, int ltype, bool mark_lock)
{
	/* There are no locks on read-only dbs */
	if (tdb->read_only || tdb->traverse_read) {
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb->allrecord_lock.count == 0) {
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	/* Upgradable locks are marked as write locks. */
	if (tdb->allrecord_lock.ltype != (uint32_t)ltype
	    && (!tdb->allrecord_lock.off || ltype != F_RDLCK)) {
		tdb->ecode = TDB_ERR_LOCK;
		return -1;
	}

	if (tdb->allrecord_lock.count > 1) {
		tdb->allrecord_lock.count--;
		return 0;
	}

	if (!mark_lock) {
		int ret;

		if (tdb_have_mutexes(tdb)) {
			ret = tdb_mutex_allrecord_unlock(tdb);
			if (ret == 0) {
				ret = tdb_brunlock(tdb, ltype,
						   lock_offset(tdb->hash_size),
						   0);
			}
		} else {
			ret = tdb_brunlock(tdb, ltype, FREELIST_TOP, 0);
		}

		if (ret != 0) {
			TDB_LOG((tdb, TDB_DEBUG_ERROR, "tdb_unlockall failed "
				 "(%s)\n", strerror(errno)));
			return -1;
		}
	}

	tdb->allrecord_lock.count = 0;
	tdb->allrecord_lock.ltype = 0;

	return 0;
}

/* lock entire database with write lock */
_PUBLIC_ int tdb_lockall(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_lockall");
	return tdb_allrecord_lock(tdb, F_WRLCK, TDB_LOCK_WAIT, false);
}

/* lock entire database with write lock - mark only */
_PUBLIC_ int tdb_lockall_mark(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_lockall_mark");
	return tdb_allrecord_lock(tdb, F_WRLCK, TDB_LOCK_MARK_ONLY, false);
}

/* unlock entire database with write lock - unmark only */
_PUBLIC_ int tdb_lockall_unmark(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_lockall_unmark");
	return tdb_allrecord_unlock(tdb, F_WRLCK, true);
}

/* lock entire database with write lock - nonblocking varient */
_PUBLIC_ int tdb_lockall_nonblock(struct tdb_context *tdb)
{
	int ret = tdb_allrecord_lock(tdb, F_WRLCK, TDB_LOCK_NOWAIT, false);
	tdb_trace_ret(tdb, "tdb_lockall_nonblock", ret);
	return ret;
}

/* unlock entire database with write lock */
_PUBLIC_ int tdb_unlockall(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_unlockall");
	return tdb_allrecord_unlock(tdb, F_WRLCK, false);
}

/* lock entire database with read lock */
_PUBLIC_ int tdb_lockall_read(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_lockall_read");
	return tdb_allrecord_lock(tdb, F_RDLCK, TDB_LOCK_WAIT, false);
}

/* lock entire database with read lock - nonblock varient */
_PUBLIC_ int tdb_lockall_read_nonblock(struct tdb_context *tdb)
{
	int ret = tdb_allrecord_lock(tdb, F_RDLCK, TDB_LOCK_NOWAIT, false);
	tdb_trace_ret(tdb, "tdb_lockall_read_nonblock", ret);
	return ret;
}

/* unlock entire database with read lock */
_PUBLIC_ int tdb_unlockall_read(struct tdb_context *tdb)
{
	tdb_trace(tdb, "tdb_unlockall_read");
	return tdb_allrecord_unlock(tdb, F_RDLCK, false);
}

/* lock/unlock one hash chain. This is meant to be used to reduce
   contention - it cannot guarantee how many records will be locked */
_PUBLIC_ int tdb_chainlock(struct tdb_context *tdb, TDB_DATA key)
{
	int ret = tdb_lock(tdb, BUCKET(tdb->hash_fn(&key)), F_WRLCK);
	tdb_trace_1rec(tdb, "tdb_chainlock", key);
	return ret;
}

/* lock/unlock one hash chain, non-blocking. This is meant to be used
   to reduce contention - it cannot guarantee how many records will be
   locked */
_PUBLIC_ int tdb_chainlock_nonblock(struct tdb_context *tdb, TDB_DATA key)
{
	int ret = tdb_lock_nonblock(tdb, BUCKET(tdb->hash_fn(&key)), F_WRLCK);
	tdb_trace_1rec_ret(tdb, "tdb_chainlock_nonblock", key, ret);
	return ret;
}

/* mark a chain as locked without actually locking it. Warning! use with great caution! */
_PUBLIC_ int tdb_chainlock_mark(struct tdb_context *tdb, TDB_DATA key)
{
	int ret = tdb_nest_lock(tdb, lock_offset(BUCKET(tdb->hash_fn(&key))),
				F_WRLCK, TDB_LOCK_MARK_ONLY);
	tdb_trace_1rec(tdb, "tdb_chainlock_mark", key);
	return ret;
}

/* unmark a chain as locked without actually locking it. Warning! use with great caution! */
_PUBLIC_ int tdb_chainlock_unmark(struct tdb_context *tdb, TDB_DATA key)
{
	tdb_trace_1rec(tdb, "tdb_chainlock_unmark", key);
	return tdb_nest_unlock(tdb, lock_offset(BUCKET(tdb->hash_fn(&key))),
			       F_WRLCK, true);
}

_PUBLIC_ int tdb_chainunlock(struct tdb_context *tdb, TDB_DATA key)
{
	tdb_trace_1rec(tdb, "tdb_chainunlock", key);
	return tdb_unlock(tdb, BUCKET(tdb->hash_fn(&key)), F_WRLCK);
}

_PUBLIC_ int tdb_chainlock_read(struct tdb_context *tdb, TDB_DATA key)
{
	int ret;
	ret = tdb_lock(tdb, BUCKET(tdb->hash_fn(&key)), F_RDLCK);
	tdb_trace_1rec(tdb, "tdb_chainlock_read", key);
	return ret;
}

_PUBLIC_ int tdb_chainunlock_read(struct tdb_context *tdb, TDB_DATA key)
{
	tdb_trace_1rec(tdb, "tdb_chainunlock_read", key);
	return tdb_unlock(tdb, BUCKET(tdb->hash_fn(&key)), F_RDLCK);
}

_PUBLIC_ int tdb_chainlock_read_nonblock(struct tdb_context *tdb, TDB_DATA key)
{
	int ret = tdb_lock_nonblock(tdb, BUCKET(tdb->hash_fn(&key)), F_RDLCK);
	tdb_trace_1rec_ret(tdb, "tdb_chainlock_read_nonblock", key, ret);
	return ret;
}

/* record lock stops delete underneath */
int tdb_lock_record(struct tdb_context *tdb, tdb_off_t off)
{
	if (tdb->allrecord_lock.count) {
		return 0;
	}
	return off ? tdb_brlock(tdb, F_RDLCK, off, 1, TDB_LOCK_WAIT) : 0;
}

/*
  Write locks override our own fcntl readlocks, so check it here.
  Note this is meant to be F_SETLK, *not* F_SETLKW, as it's not
  an error to fail to get the lock here.
*/
int tdb_write_lock_record(struct tdb_context *tdb, tdb_off_t off)
{
	struct tdb_traverse_lock *i;
	if (tdb == NULL) {
		return -1;
	}
	for (i = &tdb->travlocks; i; i = i->next)
		if (i->off == off)
			return -1;
	if (tdb->allrecord_lock.count) {
		if (tdb->allrecord_lock.ltype == F_WRLCK) {
			return 0;
		}
		return -1;
	}
	return tdb_brlock(tdb, F_WRLCK, off, 1, TDB_LOCK_NOWAIT|TDB_LOCK_PROBE);
}

int tdb_write_unlock_record(struct tdb_context *tdb, tdb_off_t off)
{
	if (tdb->allrecord_lock.count) {
		return 0;
	}
	return tdb_brunlock(tdb, F_WRLCK, off, 1);
}

/* fcntl locks don't stack: avoid unlocking someone else's */
int tdb_unlock_record(struct tdb_context *tdb, tdb_off_t off)
{
	struct tdb_traverse_lock *i;
	uint32_t count = 0;

	if (tdb->allrecord_lock.count) {
		return 0;
	}

	if (off == 0)
		return 0;
	for (i = &tdb->travlocks; i; i = i->next)
		if (i->off == off)
			count++;
	return (count == 1 ? tdb_brunlock(tdb, F_RDLCK, off, 1) : 0);
}

bool tdb_have_extra_locks(struct tdb_context *tdb)
{
	unsigned int extra = tdb->num_lockrecs;

	/* A transaction holds the lock for all records. */
	if (!tdb->transaction && tdb->allrecord_lock.count) {
		return true;
	}

	/* We always hold the active lock if CLEAR_IF_FIRST. */
	if (find_nestlock(tdb, ACTIVE_LOCK)) {
		extra--;
	}

	/* In a transaction, we expect to hold the transaction lock */
	if (tdb->transaction && find_nestlock(tdb, TRANSACTION_LOCK)) {
		extra--;
	}

	return extra;
}

/* The transaction code uses this to remove all locks. */
void tdb_release_transaction_locks(struct tdb_context *tdb)
{
	int i;
	unsigned int active = 0;

	if (tdb->allrecord_lock.count != 0) {
		tdb_allrecord_unlock(tdb, tdb->allrecord_lock.ltype, false);
		tdb->allrecord_lock.count = 0;
	}

	for (i=0;i<tdb->num_lockrecs;i++) {
		struct tdb_lock_type *lck = &tdb->lockrecs[i];

		/* Don't release the active lock!  Copy it to first entry. */
		if (lck->off == ACTIVE_LOCK) {
			tdb->lockrecs[active++] = *lck;
		} else {
			tdb_brunlock(tdb, lck->ltype, lck->off, 1);
		}
	}
	tdb->num_lockrecs = active;
}

/* Following functions are added specifically to support CTDB. */

/* Don't do actual fcntl locking, just mark tdb locked */
_PUBLIC_ int tdb_transaction_write_lock_mark(struct tdb_context *tdb);
_PUBLIC_ int tdb_transaction_write_lock_mark(struct tdb_context *tdb)
{
	return tdb_transaction_lock(tdb, F_WRLCK, TDB_LOCK_MARK_ONLY);
}

/* Don't do actual fcntl unlocking, just mark tdb unlocked */
_PUBLIC_ int tdb_transaction_write_lock_unmark(struct tdb_context *tdb);
_PUBLIC_ int tdb_transaction_write_lock_unmark(struct tdb_context *tdb)
{
	return tdb_nest_unlock(tdb, TRANSACTION_LOCK, F_WRLCK, true);
}
