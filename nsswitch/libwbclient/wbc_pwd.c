/*
   Unix SMB/CIFS implementation.

   Winbind client API

   Copyright (C) Gerald (Jerry) Carter 2007
   Copyright (C) Matthew Newton 2015


   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Required Headers */

#include "replace.h"
#include "libwbclient.h"
#include "../winbind_client.h"

/** @brief The maximum number of pwent structs to get from winbindd
 *
 */
#define MAX_GETPWENT_USERS 500

/** @brief The maximum number of grent structs to get from winbindd
 *
 */
#define MAX_GETGRENT_GROUPS 500

/**
 *
 **/

static void wbcPasswdDestructor(void *ptr)
{
	struct passwd *pw = (struct passwd *)ptr;
	free(pw->pw_name);
#ifndef __KOS__
	free(pw->pw_passwd);
	free(pw->pw_gecos);
#endif
	free(pw->pw_shell);
	free(pw->pw_dir);
}

static struct passwd *copy_passwd_entry(struct winbindd_pw *p)
{
	struct passwd *pw = NULL;

	pw = (struct passwd *)wbcAllocateMemory(1, sizeof(struct passwd),
						wbcPasswdDestructor);
	if (pw == NULL) {
		return NULL;
	}
	pw->pw_name = strdup(p->pw_name);
	if (pw->pw_name == NULL) {
		goto fail;
	}
#ifndef __KOS__
	pw->pw_passwd = strdup(p->pw_passwd);
	if (pw->pw_passwd == NULL) {
		goto fail;
	}
	pw->pw_gecos = strdup(p->pw_gecos);
	if (pw->pw_gecos == NULL) {
		goto fail;
	}
#endif
	pw->pw_shell = strdup(p->pw_shell);
	if (pw->pw_shell == NULL) {
		goto fail;
	}
	pw->pw_dir = strdup(p->pw_dir);
	if (pw->pw_dir == NULL) {
		goto fail;
	}
	pw->pw_uid = p->pw_uid;
	pw->pw_gid = p->pw_gid;
	return pw;

fail:
	wbcFreeMemory(pw);
	return NULL;
}

/**
 *
 **/

static void wbcGroupDestructor(void *ptr)
{
	struct group *gr = (struct group *)ptr;
	int i;

	free(gr->gr_name);
#ifndef __KOS__
	free(gr->gr_passwd);
#endif

	/* if the array was partly created this can be NULL */
	if (gr->gr_mem == NULL) {
		return;
	}

	for (i=0; gr->gr_mem[i] != NULL; i++) {
		free(gr->gr_mem[i]);
	}
	free(gr->gr_mem);
}

static struct group *copy_group_entry(struct winbindd_gr *g,
				      char *mem_buf)
{
	struct group *gr = NULL;
	int i;
	char *mem_p, *mem_q;

	gr = (struct group *)wbcAllocateMemory(
		1, sizeof(struct group), wbcGroupDestructor);
	if (gr == NULL) {
		return NULL;
	}

	gr->gr_name = strdup(g->gr_name);
	if (gr->gr_name == NULL) {
		goto fail;
	}
#ifndef __KOS__
	gr->gr_passwd = strdup(g->gr_passwd);
	if (gr->gr_passwd == NULL) {
		goto fail;
	}
#endif
	gr->gr_gid = g->gr_gid;

	gr->gr_mem = (char **)calloc(g->num_gr_mem+1, sizeof(char *));
	if (gr->gr_mem == NULL) {
		goto fail;
	}

	mem_p = mem_q = mem_buf;
	for (i=0; i<g->num_gr_mem && mem_p; i++) {
		mem_q = strchr(mem_p, ',');
		if (mem_q != NULL) {
			*mem_q = '\0';
		}

		gr->gr_mem[i] = strdup(mem_p);
		if (gr->gr_mem[i] == NULL) {
			goto fail;
		}

		if (mem_q == NULL) {
			i += 1;
			break;
		}
		mem_p = mem_q + 1;
	}
	gr->gr_mem[i] = NULL;

	return gr;

fail:
	wbcFreeMemory(gr);
	return NULL;
}

/* Fill in a struct passwd* for a domain user based on username */
wbcErr wbcCtxGetpwnam(struct wbcContext *ctx,
		      const char *name, struct passwd **pwd)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;

	if (!name || !pwd) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	/* dst is already null terminated from the memset above */

	strncpy(request.data.username, name, sizeof(request.data.username)-1);

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETPWNAM,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	*pwd = copy_passwd_entry(&response.data.pw);
	BAIL_ON_PTR_ERROR(*pwd, wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcGetpwnam(const char *name, struct passwd **pwd)
{
	return wbcCtxGetpwnam(NULL, name, pwd);
}

/* Fill in a struct passwd* for a domain user based on uid */
wbcErr wbcCtxGetpwuid(struct wbcContext *ctx, uid_t uid, struct passwd **pwd)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;

	if (!pwd) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	request.data.uid = uid;

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETPWUID,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	*pwd = copy_passwd_entry(&response.data.pw);
	BAIL_ON_PTR_ERROR(*pwd, wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcGetpwuid(uid_t uid, struct passwd **pwd)
{
	return wbcCtxGetpwuid(NULL, uid, pwd);
}

/* Fill in a struct passwd* for a domain user based on sid */
wbcErr wbcCtxGetpwsid(struct wbcContext *ctx,
		      struct wbcDomainSid *sid, struct passwd **pwd)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;

	if (!pwd) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

        wbcSidToStringBuf(sid, request.data.sid, sizeof(request.data.sid));

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETPWSID,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	*pwd = copy_passwd_entry(&response.data.pw);
	BAIL_ON_PTR_ERROR(*pwd, wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcGetpwsid(struct wbcDomainSid *sid, struct passwd **pwd)
{
	return wbcCtxGetpwsid(NULL, sid, pwd);
}

/* Fill in a struct passwd* for a domain user based on username */
wbcErr wbcCtxGetgrnam(struct wbcContext *ctx,
		      const char *name, struct group **grp)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	if (!name || !grp) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	/* dst is already null terminated from the memset above */

	strncpy(request.data.groupname, name, sizeof(request.data.groupname)-1);

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETGRNAM,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	*grp = copy_group_entry(&response.data.gr,
				(char*)response.extra_data.data);
	BAIL_ON_PTR_ERROR(*grp, wbc_status);

 done:
	winbindd_free_response(&response);

	return wbc_status;
}

wbcErr wbcGetgrnam(const char *name, struct group **grp)
{
	return wbcCtxGetgrnam(NULL, name, grp);
}

/* Fill in a struct passwd* for a domain user based on uid */
wbcErr wbcCtxGetgrgid(struct wbcContext *ctx, gid_t gid, struct group **grp)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	if (!grp) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	request.data.gid = gid;

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETGRGID,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	*grp = copy_group_entry(&response.data.gr,
				(char*)response.extra_data.data);
	BAIL_ON_PTR_ERROR(*grp, wbc_status);

 done:
	winbindd_free_response(&response);

	return wbc_status;
}

wbcErr wbcGetgrgid(gid_t gid, struct group **grp)
{
	return wbcCtxGetgrgid(NULL, gid, grp);
}

/** @brief Winbindd response containing the passwd structs
 *
 */
static struct winbindd_response pw_response;

/* Reset the passwd iterator */
wbcErr wbcCtxSetpwent(struct wbcContext *ctx)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	if (ctx->pw_cache_size > 0) {
		ctx->pw_cache_idx = ctx->pw_cache_size = 0;
		winbindd_free_response(&pw_response);
	}

	ZERO_STRUCT(pw_response);

	wbc_status = wbcRequestResponse(ctx, WINBINDD_SETPWENT,
					NULL, NULL);
	BAIL_ON_WBC_ERROR(wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcSetpwent(void)
{
	return wbcCtxSetpwent(NULL);
}

/* Close the passwd iterator */
wbcErr wbcCtxEndpwent(struct wbcContext *ctx)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	if (ctx->pw_cache_size > 0) {
		ctx->pw_cache_idx = ctx->pw_cache_size = 0;
		winbindd_free_response(&pw_response);
	}

	wbc_status = wbcRequestResponse(ctx, WINBINDD_ENDPWENT,
					NULL, NULL);
	BAIL_ON_WBC_ERROR(wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcEndpwent(void)
{
	return wbcCtxEndpwent(NULL);
}

/* Return the next struct passwd* entry from the pwent iterator */
wbcErr wbcCtxGetpwent(struct wbcContext *ctx, struct passwd **pwd)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_pw *wb_pw;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	/* If there's a cached result, return that. */
	if (ctx->pw_cache_idx < ctx->pw_cache_size) {
		goto return_result;
	}

	/* Otherwise, query winbindd for some entries. */

	ctx->pw_cache_idx = 0;

	winbindd_free_response(&pw_response);

	ZERO_STRUCT(request);
	request.data.num_entries = MAX_GETPWENT_USERS;

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETPWENT, &request,
					&pw_response);

	BAIL_ON_WBC_ERROR(wbc_status);

	ctx->pw_cache_size = pw_response.data.num_entries;

return_result:

	wb_pw = (struct winbindd_pw *) pw_response.extra_data.data;

	*pwd = copy_passwd_entry(&wb_pw[ctx->pw_cache_idx]);

	BAIL_ON_PTR_ERROR(*pwd, wbc_status);

	ctx->pw_cache_idx++;

done:
	return wbc_status;
}

wbcErr wbcGetpwent(struct passwd **pwd)
{
	return wbcCtxGetpwent(NULL, pwd);
}

/** @brief Winbindd response containing the group structs
 *
 */
static struct winbindd_response gr_response;

/* Reset the group iterator */
wbcErr wbcCtxSetgrent(struct wbcContext *ctx)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	if (ctx->gr_cache_size > 0) {
		ctx->gr_cache_idx = ctx->gr_cache_size = 0;
		winbindd_free_response(&gr_response);
	}

	ZERO_STRUCT(gr_response);

	wbc_status = wbcRequestResponse(ctx, WINBINDD_SETGRENT,
					NULL, NULL);
	BAIL_ON_WBC_ERROR(wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcSetgrent(void)
{
	return wbcCtxSetgrent(NULL);
}

/* Close the group iterator */
wbcErr wbcCtxEndgrent(struct wbcContext *ctx)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	if (ctx->gr_cache_size > 0) {
		ctx->gr_cache_idx = ctx->gr_cache_size = 0;
		winbindd_free_response(&gr_response);
	}

	wbc_status = wbcRequestResponse(ctx, WINBINDD_ENDGRENT,
					NULL, NULL);
	BAIL_ON_WBC_ERROR(wbc_status);

 done:
	return wbc_status;
}

wbcErr wbcEndgrent(void)
{
	return wbcCtxEndgrent(NULL);
}

/* Return the next struct group* entry from the pwent iterator */
wbcErr wbcCtxGetgrent(struct wbcContext *ctx, struct group **grp)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_gr *wb_gr;
	uint32_t mem_ofs;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	/* If there's a cached result, return that. */
	if (ctx->gr_cache_idx < ctx->gr_cache_size) {
		goto return_result;
	}

	/* Otherwise, query winbindd for some entries. */

	ctx->gr_cache_idx = 0;

	winbindd_free_response(&gr_response);

	ZERO_STRUCT(request);
	request.data.num_entries = MAX_GETGRENT_GROUPS;

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETGRENT,
					&request, &gr_response);

	BAIL_ON_WBC_ERROR(wbc_status);

	ctx->gr_cache_size = gr_response.data.num_entries;

return_result:

	wb_gr = (struct winbindd_gr *) gr_response.extra_data.data;

	mem_ofs = wb_gr[ctx->gr_cache_idx].gr_mem_ofs +
		  ctx->gr_cache_size * sizeof(struct winbindd_gr);

	*grp = copy_group_entry(&wb_gr[ctx->gr_cache_idx],
				((char *)gr_response.extra_data.data)+mem_ofs);

	BAIL_ON_PTR_ERROR(*grp, wbc_status);

	ctx->gr_cache_idx++;

done:
	return wbc_status;
}

wbcErr wbcGetgrent(struct group **grp)
{
	return wbcCtxGetgrent(NULL, grp);
}

/* Return the next struct group* entry from the pwent iterator */
wbcErr wbcCtxGetgrlist(struct wbcContext *ctx, struct group **grp)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_gr *wb_gr;

	if (!ctx) {
		ctx = wbcGetGlobalCtx();
	}

	/* If there's a cached result, return that. */
	if (ctx->gr_cache_idx < ctx->gr_cache_size) {
		goto return_result;
	}

	/* Otherwise, query winbindd for some entries. */

	ctx->gr_cache_idx = 0;

	winbindd_free_response(&gr_response);
	ZERO_STRUCT(gr_response);

	ZERO_STRUCT(request);
	request.data.num_entries = MAX_GETGRENT_GROUPS;

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETGRLST,
					&request, &gr_response);

	BAIL_ON_WBC_ERROR(wbc_status);

	ctx->gr_cache_size = gr_response.data.num_entries;

return_result:

	wb_gr = (struct winbindd_gr *) gr_response.extra_data.data;

	*grp = copy_group_entry(&wb_gr[ctx->gr_cache_idx], NULL);

	BAIL_ON_PTR_ERROR(*grp, wbc_status);

	ctx->gr_cache_idx++;

done:
	return wbc_status;
}

wbcErr wbcGetgrlist(struct group **grp)
{
	return wbcCtxGetgrlist(NULL, grp);
}

/* Return the unix group array belonging to the given user */
wbcErr wbcCtxGetGroups(struct wbcContext *ctx, const char *account,
		       uint32_t *num_groups, gid_t **_groups)
{
	wbcErr wbc_status = WBC_ERR_UNKNOWN_FAILURE;
	struct winbindd_request request;
	struct winbindd_response response;
	uint32_t i;
	gid_t *groups = NULL;

	/* Initialize request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	if (!account) {
		wbc_status = WBC_ERR_INVALID_PARAM;
		BAIL_ON_WBC_ERROR(wbc_status);
	}

	/* Send request */

	strncpy(request.data.username, account, sizeof(request.data.username)-1);

	wbc_status = wbcRequestResponse(ctx, WINBINDD_GETGROUPS,
					&request,
					&response);
	BAIL_ON_WBC_ERROR(wbc_status);

	groups = (gid_t *)wbcAllocateMemory(
		response.data.num_entries, sizeof(gid_t), NULL);
	BAIL_ON_PTR_ERROR(groups, wbc_status);

	for (i = 0; i < response.data.num_entries; i++) {
		groups[i] = ((gid_t *)response.extra_data.data)[i];
	}

	*num_groups = response.data.num_entries;
	*_groups = groups;
	groups = NULL;

	wbc_status = WBC_ERR_SUCCESS;

 done:
	winbindd_free_response(&response);
	wbcFreeMemory(groups);
	return wbc_status;
}

wbcErr wbcGetGroups(const char *account, uint32_t *num_groups, gid_t **_groups)
{
	return wbcCtxGetGroups(NULL, account, num_groups, _groups);
}
