#ifndef __SOURCE4_TORTURE_LDAP_PROTO_H__
#define __SOURCE4_TORTURE_LDAP_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

/* this file contains prototypes for functions that are private 
 * to this subsystem or library. These functions should not be 
 * used outside this particular subsystem! */


/* The following definitions come from ../../source4/torture/ldap/common.c  */

NTSTATUS torture_ldap_bind(struct ldap_connection *conn, const char *userdn, const char *password);
NTSTATUS torture_ldap_bind_sasl(struct ldap_connection *conn, 
				struct cli_credentials *creds, 
				struct loadparm_context *lp_ctx);
NTSTATUS torture_ldap_connection(struct torture_context *tctx, 
					  struct ldap_connection **conn, 
					  const char *url);
NTSTATUS torture_ldap_close(struct ldap_connection *conn);
NTSTATUS torture_ldap_init(TALLOC_CTX *ctx);

/* The following definitions come from ../../source4/torture/ldap/basic.c  */

bool torture_ldap_basic(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/schema.c  */

bool torture_ldap_schema(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/uptodatevector.c  */

bool torture_ldap_uptodatevector(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/cldap.c  */

bool torture_cldap(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/netlogon.c  */

bool torture_netlogon_tcp(struct torture_context *tctx);
bool torture_netlogon_udp(struct torture_context *tctx);

/* The following definitions come from ../../source4/torture/ldap/cldapbench.c  */

bool torture_bench_cldap(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/ldap_sort.c  */

bool torture_ldap_sort(struct torture_context *torture);

/* The following definitions come from ../../source4/torture/ldap/nested_search.c  */


/**
 * Test nested search execution against RootDSE
 * on remote LDAP server.
 */
bool test_ldap_nested_search(struct torture_context *tctx);

/* The following definitions come from ../../source4/torture/ldap/session_expiry.c  */

bool torture_ldap_session_expiry(struct torture_context *torture);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __SOURCE4_TORTURE_LDAP_PROTO_H__ */

