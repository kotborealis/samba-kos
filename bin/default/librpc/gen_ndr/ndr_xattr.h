/* header auto-generated by pidl */

#include "librpc/ndr/libndr.h"
#include "bin/default/librpc/gen_ndr/xattr.h"

#ifndef _HEADER_NDR_xattr
#define _HEADER_NDR_xattr

#include "../librpc/ndr/ndr_xattr.h"
extern const struct ndr_interface_table ndr_table_xattr;
#define NDR_XATTR_CALL_COUNT (0)
void ndr_print_xattr_DosInfoFFFFCompat(struct ndr_print *ndr, const char *name, const struct xattr_DosInfoFFFFCompat *r);
void ndr_print_xattr_DosInfo1(struct ndr_print *ndr, const char *name, const struct xattr_DosInfo1 *r);
void ndr_print_xattr_DosInfo2Old(struct ndr_print *ndr, const char *name, const struct xattr_DosInfo2Old *r);
void ndr_print_xattr_DosInfoValidFlags(struct ndr_print *ndr, const char *name, uint32_t r);
void ndr_print_xattr_DosInfo3(struct ndr_print *ndr, const char *name, const struct xattr_DosInfo3 *r);
void ndr_print_xattr_DosInfo4(struct ndr_print *ndr, const char *name, const struct xattr_DosInfo4 *r);
enum ndr_err_code ndr_push_xattr_DosInfo(struct ndr_push *ndr, int ndr_flags, const union xattr_DosInfo *r);
enum ndr_err_code ndr_pull_xattr_DosInfo(struct ndr_pull *ndr, int ndr_flags, union xattr_DosInfo *r);
void ndr_print_xattr_DosInfo(struct ndr_print *ndr, const char *name, const union xattr_DosInfo *r);
enum ndr_err_code ndr_push_xattr_DosAttrib(struct ndr_push *ndr, int ndr_flags, const struct xattr_DosAttrib *r);
enum ndr_err_code ndr_pull_xattr_DosAttrib(struct ndr_pull *ndr, int ndr_flags, struct xattr_DosAttrib *r);
void ndr_print_xattr_DosAttrib(struct ndr_print *ndr, const char *name, const struct xattr_DosAttrib *r);
enum ndr_err_code ndr_push_xattr_DOSATTRIB(struct ndr_push *ndr, int ndr_flags, const struct xattr_DOSATTRIB *r);
enum ndr_err_code ndr_pull_xattr_DOSATTRIB(struct ndr_pull *ndr, int ndr_flags, struct xattr_DOSATTRIB *r);
void ndr_print_xattr_DOSATTRIB(struct ndr_print *ndr, const char *name, const struct xattr_DOSATTRIB *r);
void ndr_print_xattr_EA(struct ndr_print *ndr, const char *name, const struct xattr_EA *r);
enum ndr_err_code ndr_push_xattr_DosEAs(struct ndr_push *ndr, int ndr_flags, const struct xattr_DosEAs *r);
enum ndr_err_code ndr_pull_xattr_DosEAs(struct ndr_pull *ndr, int ndr_flags, struct xattr_DosEAs *r);
void ndr_print_xattr_DosEAs(struct ndr_print *ndr, const char *name, const struct xattr_DosEAs *r);
enum ndr_err_code ndr_push_tdb_xattrs(struct ndr_push *ndr, int ndr_flags, const struct tdb_xattrs *r);
enum ndr_err_code ndr_pull_tdb_xattrs(struct ndr_pull *ndr, int ndr_flags, struct tdb_xattrs *r);
void ndr_print_tdb_xattrs(struct ndr_print *ndr, const char *name, const struct tdb_xattrs *r);
void ndr_print_xattr_DosStream(struct ndr_print *ndr, const char *name, const struct xattr_DosStream *r);
enum ndr_err_code ndr_push_xattr_DosStreams(struct ndr_push *ndr, int ndr_flags, const struct xattr_DosStreams *r);
enum ndr_err_code ndr_pull_xattr_DosStreams(struct ndr_pull *ndr, int ndr_flags, struct xattr_DosStreams *r);
void ndr_print_xattr_DosStreams(struct ndr_print *ndr, const char *name, const struct xattr_DosStreams *r);
enum ndr_err_code ndr_push_security_descriptor_hash_v2(struct ndr_push *ndr, int ndr_flags, const struct security_descriptor_hash_v2 *r);
enum ndr_err_code ndr_pull_security_descriptor_hash_v2(struct ndr_pull *ndr, int ndr_flags, struct security_descriptor_hash_v2 *r);
void ndr_print_security_descriptor_hash_v2(struct ndr_print *ndr, const char *name, const struct security_descriptor_hash_v2 *r);
enum ndr_err_code ndr_push_security_descriptor_hash_v3(struct ndr_push *ndr, int ndr_flags, const struct security_descriptor_hash_v3 *r);
enum ndr_err_code ndr_pull_security_descriptor_hash_v3(struct ndr_pull *ndr, int ndr_flags, struct security_descriptor_hash_v3 *r);
void ndr_print_security_descriptor_hash_v3(struct ndr_print *ndr, const char *name, const struct security_descriptor_hash_v3 *r);
enum ndr_err_code ndr_push_security_descriptor_hash_v4(struct ndr_push *ndr, int ndr_flags, const struct security_descriptor_hash_v4 *r);
enum ndr_err_code ndr_pull_security_descriptor_hash_v4(struct ndr_pull *ndr, int ndr_flags, struct security_descriptor_hash_v4 *r);
void ndr_print_security_descriptor_hash_v4(struct ndr_print *ndr, const char *name, const struct security_descriptor_hash_v4 *r);
void ndr_print_xattr_NTACL_Info(struct ndr_print *ndr, const char *name, const union xattr_NTACL_Info *r);
enum ndr_err_code ndr_push_xattr_NTACL(struct ndr_push *ndr, int ndr_flags, const struct xattr_NTACL *r);
enum ndr_err_code ndr_pull_xattr_NTACL(struct ndr_pull *ndr, int ndr_flags, struct xattr_NTACL *r);
void ndr_print_xattr_NTACL(struct ndr_print *ndr, const char *name, const struct xattr_NTACL *r);
enum ndr_err_code ndr_push_xattr_sys_acl_hash_wrapper(struct ndr_push *ndr, int ndr_flags, const struct xattr_sys_acl_hash_wrapper *r);
enum ndr_err_code ndr_pull_xattr_sys_acl_hash_wrapper(struct ndr_pull *ndr, int ndr_flags, struct xattr_sys_acl_hash_wrapper *r);
void ndr_print_xattr_sys_acl_hash_wrapper(struct ndr_print *ndr, const char *name, const struct xattr_sys_acl_hash_wrapper *r);
#endif /* _HEADER_NDR_xattr */
