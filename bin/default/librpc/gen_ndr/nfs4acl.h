/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_nfs4acl_interface
#define _PIDL_HEADER_nfs4acl_interface

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#include "librpc/gen_ndr/security.h"
#ifndef _HEADER_nfs4acl_interface
#define _HEADER_nfs4acl_interface

#define NFS4ACL_NDR_XATTR_NAME	( "security.nfs4acl_ndr" )
#define NFS4ACL_XATTR_OWNER_WHO	( "OWNER@" )
#define NFS4ACL_XATTR_GROUP_WHO	( "GROUP@" )
#define NFS4ACL_XATTR_EVERYONE_WHO	( "EVERYONE@" )
#define ACL4_XATTR_VERSION_40	( 0x00 )
#define ACL4_XATTR_VERSION_41	( 0x01 )
#define ACL4_XATTR_VERSION_DEFAULT	( ACL4_XATTR_VERSION_41 )
#define ACL4_AUTO_INHERIT	( 0x01 )
#define ACL4_PROTECTED	( 0x02 )
#define ACL4_DEFAULTED	( 0x04 )
#define ACL4_WRITE_THROUGH	( 0x40 )
struct nfs4ace {
	uint16_t e_type;
	uint16_t e_flags;
	uint32_t e_mask;
	uint32_t e_id;
	const char * e_who;/* [flag(LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM)] */
	DATA_BLOB _pad;/* [flag(LIBNDR_FLAG_ALIGN4)] */
}/* [flag(LIBNDR_FLAG_BIGENDIAN)] */;

struct nfs4acl {
	uint8_t a_version;
	uint8_t a_flags;
	uint16_t a_count;
	uint32_t a_owner_mask;
	uint32_t a_group_mask;
	uint32_t a_other_mask;
	struct nfs4ace *ace;
}/* [flag(LIBNDR_FLAG_BIGENDIAN),public] */;

#endif /* _HEADER_nfs4acl_interface */
#endif /* _PIDL_HEADER_nfs4acl_interface */
