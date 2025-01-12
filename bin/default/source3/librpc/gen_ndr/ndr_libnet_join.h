/* header auto-generated by pidl */

#include "librpc/ndr/libndr.h"
#include "bin/default/source3/librpc/gen_ndr/libnet_join.h"

#ifndef _HEADER_NDR_libnetjoin
#define _HEADER_NDR_libnetjoin

#include "ads.h"
extern const struct ndr_interface_table ndr_table_libnetjoin;
#define NDR_LIBNETJOIN_CALL_COUNT (0)
enum ndr_err_code ndr_push_libnetjoin_JoinDomNameType(struct ndr_push *ndr, int ndr_flags, enum libnetjoin_JoinDomNameType r);
enum ndr_err_code ndr_pull_libnetjoin_JoinDomNameType(struct ndr_pull *ndr, int ndr_flags, enum libnetjoin_JoinDomNameType *r);
void ndr_print_libnetjoin_JoinDomNameType(struct ndr_print *ndr, const char *name, enum libnetjoin_JoinDomNameType r);
enum ndr_err_code ndr_push_libnet_JoinCtx(struct ndr_push *ndr, int flags, const struct libnet_JoinCtx *r);
enum ndr_err_code ndr_pull_libnet_JoinCtx(struct ndr_pull *ndr, int flags, struct libnet_JoinCtx *r);
void ndr_print_libnet_JoinCtx(struct ndr_print *ndr, const char *name, int flags, const struct libnet_JoinCtx *r);
enum ndr_err_code ndr_push_libnet_UnjoinCtx(struct ndr_push *ndr, int flags, const struct libnet_UnjoinCtx *r);
enum ndr_err_code ndr_pull_libnet_UnjoinCtx(struct ndr_pull *ndr, int flags, struct libnet_UnjoinCtx *r);
void ndr_print_libnet_UnjoinCtx(struct ndr_print *ndr, const char *name, int flags, const struct libnet_UnjoinCtx *r);
#endif /* _HEADER_NDR_libnetjoin */
