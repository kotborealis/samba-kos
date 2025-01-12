/* This file was automatically generated by generate_param.py. DO NOT EDIT */

#ifndef __PARAM_GLOBAL_H__
#define __PARAM_GLOBAL_H__

/**
 * This structure describes global (ie., server-wide) parameters.
 */
struct loadparm_global 
{
	TALLOC_CTX *ctx; /* Context for talloced members */
	char *  abort_shutdown_script;
	char *  add_group_script;
	const char **  additional_dns_hostnames;
	char *  add_machine_script;
	char *  addport_command;
	char *  addprinter_command;
	char *  add_share_command;
	char *  add_user_script;
	char *  add_user_to_group_script;
	int   afs_token_lifetime;
	char *  afs_username_map;
	int   aio_max_threads;
	int   algorithmic_rid_base;
	bool   allow_dcerpc_auth_level_connect;
	int   allow_dns_updates;
	bool   allow_insecure_wide_links;
	bool   allow_nt4_crypto;
	bool   allow_trusted_domains;
	bool   allow_unsafe_cluster_upgrade;
	bool   apply_group_policies;
	int   async_dns_timeout;
	bool   async_smb_echo_handler;
	bool   auth_event_notification;
	char *  auto_services;
	char *  binddns_dir;
	bool   bind_interfaces_only;
	bool   browse_list;
	char *  cache_directory;
	bool   change_notify;
	char *  change_share_command;
	char *  check_password_script;
	int   cldap_port;
	int   _client_ipc_max_protocol;
	int   _client_ipc_min_protocol;
	int   _client_ipc_signing;
	bool   client_lanman_auth;
	int   client_ldap_sasl_wrapping;
	int   _client_max_protocol;
	int   client_min_protocol;
	bool   client_ntlmv2_auth;
	bool   client_plaintext_auth;
	int   client_protection;
	int   client_schannel;
	int   client_signing;
	int   client_smb_encrypt;
	const char **  client_smb3_encryption_algorithms;
	const char **  client_smb3_signing_algorithms;
	int   _client_use_kerberos;
	bool   client_use_spnego_principal;
	bool   client_use_spnego;
	const char **  cluster_addresses;
	bool   clustering;
	int   config_backend;
	char *  next_configfile;
	bool   create_krb5_conf;
	char *  _ctdbd_socket;
	int   ctdb_locktime_warn_threshold;
	int   ctdb_timeout;
	int   cups_connection_timeout;
	int   cups_encrypt;
	char *  cups_server;
	const char **  dcerpc_endpoint_servers;
	int   deadtime;
	bool   debug_class;
	bool   debug_encryption;
	bool   debug_hires_timestamp;
	bool   debug_pid;
	bool   debug_prefix_timestamp;
	bool   debug_syslog_format;
	bool   debug_uid;
	char *  dedicated_keytab_file;
	char *  defaultservice;
	bool   defer_sharing_violations;
	char *  delete_group_script;
	char *  deleteprinter_command;
	char *  delete_share_command;
	char *  delete_user_from_group_script;
	char *  delete_user_script;
	int   dgram_port;
	bool   disable_netbios;
	bool   _disable_spoolss;
	const char **  dns_forwarder;
	bool   wins_dns_proxy;
	const char **  dns_update_command;
	bool   dns_zone_scavenging;
	const char **  dns_zone_transfer_clients_allow;
	const char **  dns_zone_transfer_clients_deny;
	bool   _domain_logons;
	int   _domain_master;
	char *  dos_charset;
	bool   dsdb_event_notification;
	bool   dsdb_group_change_notification;
	bool   dsdb_password_event_notification;
	bool   enable_asu_support;
	bool   enable_core_files;
	bool   enable_privileges;
	bool   encrypt_passwords;
	bool   enhanced_browsing;
	char *  enumports_command;
	const char **  eventlog_list;
	char *  get_quota_command;
	bool   getwd_cache;
	const char **  gpo_update_command;
	char *  guest_account;
	bool   host_msdfs;
	bool   hostname_lookups;
	char *  idmap_backend;
	int   idmap_cache_time;
	char *  idmap_gid;
	int   idmap_negative_cache_time;
	char *  idmap_uid;
	bool   include_system_krb5_conf;
	int   init_logon_delay;
	const char **  init_logon_delayed_hosts;
	const char **  interfaces;
	char *  iprint_server;
	int   keepalive;
	int   kerberos_encryption_types;
	int   kerberos_method;
	bool   kernel_change_notify;
	int   kpasswd_port;
	int   krb5_port;
	bool   _lanman_auth;
	bool   large_readwrite;
	char *  ldap_admin_dn;
	int   ldap_connection_timeout;
	int   ldap_debug_level;
	int   ldap_debug_threshold;
	bool   ldap_delete_dn;
	int   ldap_deref;
	int   ldap_follow_referral;
	char *  _ldap_group_suffix;
	char *  _ldap_idmap_suffix;
	char *  _ldap_machine_suffix;
	int   ldap_max_anonymous_request_size;
	int   ldap_max_authenticated_request_size;
	int   ldap_max_search_request_size;
	int   ldap_page_size;
	int   ldap_passwd_sync;
	int   ldap_replication_sleep;
	int   ldap_server_require_strong_auth;
	int   ldap_ssl;
	char *  ldap_suffix;
	int   ldap_timeout;
	char *  _ldap_user_suffix;
	int   lm_announce;
	int   lm_interval;
	bool   load_printers;
	bool   local_master;
	char *  lock_directory;
	int   lock_spin_time;
	char *  logfile;
	char *  logging;
	char *  log_level;
	char *  log_nt_token_command;
	char *  logon_drive;
	char *  logon_home;
	char *  logon_path;
	char *  logon_script;
	bool   log_writeable_files_on_exit;
	int   lpq_cache_time;
	bool   lsa_over_netlogon;
	int   machine_password_timeout;
	int   mangle_prefix;
	char *  mangling_method;
	int   map_to_guest;
	int   max_disk_size;
	int   max_log_size;
	int   max_mux;
	int   max_open_files;
	int   max_smbd_processes;
	int   max_stat_cache_size;
	int   max_ttl;
	int   max_wins_ttl;
	int   max_xmit;
	int   mdns_name;
	char *  message_command;
	int   min_domain_uid;
	int   min_receivefile_size;
	int   min_wins_ttl;
	const char **  mit_kdc_command;
	bool   multicast_dns_register;
	int   name_cache_timeout;
	const char **  name_resolve_order;
	char *  nbt_client_socket_address;
	int   nbt_port;
	char *  ncalrpc_dir;
	const char **  netbios_aliases;
	char *  netbios_name;
	char *  netbios_scope;
	bool   neutralize_nt4_emulation;
	bool   nmbd_bind_explicit_broadcast;
	const char **  nsupdate_command;
	int   ntlm_auth;
	bool   nt_pipe_support;
	char *  ntp_signd_socket_directory;
	bool   nt_status_support;
	bool   null_passwords;
	bool   obey_pam_restrictions;
	int   old_password_allowed_period;
	int   oplock_break_wait_time;
	char *  os2_driver_map;
	int   os_level;
	bool   pam_password_change;
	char *  panic_action;
	char *  passdb_backend;
	bool   passdb_expand_explicit;
	char *  passwd_chat;
	bool   passwd_chat_debug;
	int   passwd_chat_timeout;
	char *  passwd_program;
	const char **  password_hash_gpg_key_ids;
	const char **  password_hash_userpassword_schemes;
	char *  password_server;
	char *  perfcount_module;
	char *  pid_directory;
	int   _preferred_master;
	int   prefork_backoff_increment;
	int   prefork_children;
	int   prefork_maximum_backoff;
	const char **  preload_modules;
	int   printcap_cache_time;
	char *  printcap_name;
	char *  private_dir;
	bool   raw_ntlmv2_auth;
	bool   read_raw;
	char *  realm;
	bool   registry_shares;
	bool   reject_md5_clients;
	bool   reject_md5_servers;
	char *  remote_announce;
	char *  remote_browse_sync;
	char *  rename_user_script;
	bool   require_strong_key;
	bool   reset_on_zero_vc;
	int   restrict_anonymous;
	char *  root_directory;
	bool   rpc_big_endian;
	char *  rpc_server_dynamic_port_range;
	int   rpc_server_port;
	const char **  samba_kcc_command;
	int   _security;
	int   server_max_protocol;
	int   server_min_protocol;
	bool   server_multi_channel_support;
	int   _server_role;
	int   server_schannel;
	const char **  server_services;
	int   server_signing;
	const char **  server_smb3_encryption_algorithms;
	const char **  server_smb3_signing_algorithms;
	char *  server_string;
	char *  set_primary_group_script;
	char *  set_quota_command;
	bool   show_add_printer_wizard;
	char *  shutdown_script;
	bool   smb2_disable_lock_sequence_checking;
	bool   smb2_disable_oplock_break_retry;
	bool   smb2_leases;
	int   smb2_max_credits;
	int   smb2_max_read;
	int   smb2_max_trans;
	int   smb2_max_write;
	int   smbd_profiling_level;
	char *  smb_passwd_file;
	const char **  smb_ports;
	char *  socket_options;
	const char **  spn_update_command;
	bool   stat_cache;
	char *  state_directory;
	const char **  svcctl_list;
	int   syslog;
	bool   syslog_only;
	char *  template_homedir;
	char *  template_shell;
	bool   time_server;
	bool   timestamp_logs;
	char *  _tls_cafile;
	char *  _tls_certfile;
	char *  _tls_crlfile;
	char *  _tls_dhpfile;
	bool   tls_enabled;
	char *  _tls_keyfile;
	char *  tls_priority;
	int   tls_verify_peer;
	bool   unicode;
	char *  unix_charset;
	bool   unix_extensions;
	bool   unix_password_sync;
	bool   use_mmap;
	int   username_level;
	char *  username_map;
	int   username_map_cache_time;
	char *  username_map_script;
	bool   usershare_allow_guests;
	int   usershare_max_shares;
	bool   usershare_owner_only;
	char *  usershare_path;
	const char **  usershare_prefix_allow_list;
	const char **  usershare_prefix_deny_list;
	char *  usershare_template_share;
	bool   utmp;
	char *  utmp_directory;
	int   winbind_cache_time;
	char *  winbindd_socket_directory;
	bool   winbind_enum_groups;
	bool   winbind_enum_users;
	int   winbind_expand_groups;
	int   winbind_max_clients;
	int   _winbind_max_domain_connections;
	bool   winbind_nested_groups;
	bool   winbind_normalize_names;
	const char **  winbind_nss_info;
	bool   winbind_offline_logon;
	int   winbind_reconnect_delay;
	bool   winbind_refresh_tickets;
	int   winbind_request_timeout;
	bool   winbind_rpc_only;
	bool   winbind_scan_trusted_domains;
	bool   winbind_sealed_pipes;
	char *  winbind_separator;
	bool   winbind_use_default_domain;
	bool   winbind_use_krb5_enterprise_principals;
	char *  wins_hook;
	bool   wins_proxy;
	const char **  wins_server_list;
	bool   we_are_a_wins_server;
	char *  workgroup;
	bool   write_raw;
	char *  wtmp_directory;
LOADPARM_EXTRA_GLOBALS
};

#endif /* __PARAM_GLOBAL_H__ */

