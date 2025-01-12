/* header auto-generated by pidl */

#include "librpc/ndr/libndr.h"
#include "bin/default/librpc/gen_ndr/krb5ccache.h"

#ifndef _HEADER_NDR_krb5ccache
#define _HEADER_NDR_krb5ccache

#define NDR_KRB5CCACHE_UUID "1702b695-99ca-4f32-93e4-1e1c4d5ddb53"
#define NDR_KRB5CCACHE_VERSION 0.0
#define NDR_KRB5CCACHE_NAME "krb5ccache"
#define NDR_KRB5CCACHE_HELPSTRING "KRB5 credentials cache"
extern const struct ndr_interface_table ndr_table_krb5ccache;
#define NDR_KRB5CCACHE_CALL_COUNT (0)
void ndr_print_PRINCIPAL(struct ndr_print *ndr, const char *name, const struct PRINCIPAL *r);
void ndr_print_KEYBLOCK(struct ndr_print *ndr, const char *name, const struct KEYBLOCK *r);
void ndr_print_ADDRESS(struct ndr_print *ndr, const char *name, const struct ADDRESS *r);
void ndr_print_ADDRESSES(struct ndr_print *ndr, const char *name, const struct ADDRESSES *r);
void ndr_print_AUTHDATUM(struct ndr_print *ndr, const char *name, const struct AUTHDATUM *r);
void ndr_print_AUTHDATA(struct ndr_print *ndr, const char *name, const struct AUTHDATA *r);
void ndr_print_CREDENTIAL(struct ndr_print *ndr, const char *name, const struct CREDENTIAL *r);
void ndr_print_DELTATIME_TAG(struct ndr_print *ndr, const char *name, const struct DELTATIME_TAG *r);
void ndr_print_FIELD(struct ndr_print *ndr, const char *name, const union FIELD *r);
void ndr_print_V4TAG(struct ndr_print *ndr, const char *name, const struct V4TAG *r);
void ndr_print_V4TAGS(struct ndr_print *ndr, const char *name, const struct V4TAGS *r);
void ndr_print_V4HEADER(struct ndr_print *ndr, const char *name, const struct V4HEADER *r);
void ndr_print_OPTIONAL_HEADER(struct ndr_print *ndr, const char *name, const union OPTIONAL_HEADER *r);
enum ndr_err_code ndr_push_CCACHE(struct ndr_push *ndr, int ndr_flags, const struct CCACHE *r);
enum ndr_err_code ndr_pull_CCACHE(struct ndr_pull *ndr, int ndr_flags, struct CCACHE *r);
void ndr_print_CCACHE(struct ndr_print *ndr, const char *name, const struct CCACHE *r);
enum ndr_err_code ndr_push_MULTIPLE_CREDENTIALS(struct ndr_push *ndr, int ndr_flags, const struct MULTIPLE_CREDENTIALS *r);
enum ndr_err_code ndr_pull_MULTIPLE_CREDENTIALS(struct ndr_pull *ndr, int ndr_flags, struct MULTIPLE_CREDENTIALS *r);
void ndr_print_MULTIPLE_CREDENTIALS(struct ndr_print *ndr, const char *name, const struct MULTIPLE_CREDENTIALS *r);
#endif /* _HEADER_NDR_krb5ccache */
