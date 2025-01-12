/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_bkupblobs
#define _PIDL_HEADER_bkupblobs

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#include "librpc/gen_ndr/security.h"
#include "librpc/gen_ndr/fscc.h"
#ifndef _HEADER_bkupblobs
#define _HEADER_bkupblobs

enum bkup_StreamId
#ifndef USE_UINT_ENUMS
 {
	STREAM_ID_DATA=(int)(1),
	STREAM_ID_EX_DATA=(int)(2),
	STREAM_ID_SECURITY_DATA=(int)(3),
	STREAM_ID_ALTERNATE_DATA=(int)(4),
	STREAM_ID_LINK=(int)(5),
	STREAM_ID_OBJECTID=(int)(7),
	STREAM_ID_REPARSE_DATA=(int)(8),
	STREAM_ID_SPARSE_BLOCK=(int)(9),
	STREAM_ID_TXFS_DATA=(int)(10)
}
#else
 { __do_not_use_enum_bkup_StreamId=0x7FFFFFFF}
#define STREAM_ID_DATA ( 1 )
#define STREAM_ID_EX_DATA ( 2 )
#define STREAM_ID_SECURITY_DATA ( 3 )
#define STREAM_ID_ALTERNATE_DATA ( 4 )
#define STREAM_ID_LINK ( 5 )
#define STREAM_ID_OBJECTID ( 7 )
#define STREAM_ID_REPARSE_DATA ( 8 )
#define STREAM_ID_SPARSE_BLOCK ( 9 )
#define STREAM_ID_TXFS_DATA ( 10 )
#endif
;

enum bkup_StreamAttribute
#ifndef USE_UINT_ENUMS
 {
	STREAM_ATTRIBUTE_NORMAL=(int)(0),
	STREAM_ATTRIBUTE_SECURITY=(int)(2),
	STREAM_ATTRIBUTE_SPARSE=(int)(8)
}
#else
 { __do_not_use_enum_bkup_StreamAttribute=0x7FFFFFFF}
#define STREAM_ATTRIBUTE_NORMAL ( 0 )
#define STREAM_ATTRIBUTE_SECURITY ( 2 )
#define STREAM_ATTRIBUTE_SPARSE ( 8 )
#endif
;

union bkup_StreamData {
	DATA_BLOB blob;/* [default] */
	struct security_descriptor sd;/* [case(STREAM_ID_SECURITY_DATA),flag(LIBNDR_FLAG_ALIGN2)] */
	struct fscc_FileObjectIdBuffer_2 object;/* [case(STREAM_ID_OBJECTID)] */
}/* [nodiscriminant] */;

struct bkup_Win32StreamId {
	enum bkup_StreamId id;
	enum bkup_StreamAttribute attribute;
	uint64_t size;
	uint32_t stream_name_size;
	const char *stream_name;/* [charset(UTF16),flag(LIBNDR_FLAG_STR_NOTERM)] */
	union bkup_StreamData data;/* [flag(LIBNDR_FLAG_REMAINING),subcontext(0),subcontext_size(size),switch_is(id)] */
}/* [public] */;

struct bkup_NTBackupFile {
	uint32_t num_stream;
	struct bkup_Win32StreamId *streams;
}/* [flag(LIBNDR_FLAG_NOALIGN),nopull,nopush,public] */;

#endif /* _HEADER_bkupblobs */
#endif /* _PIDL_HEADER_bkupblobs */
