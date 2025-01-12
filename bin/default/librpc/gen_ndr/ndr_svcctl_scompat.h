#ifndef __NDR_SVCCTL_SCOMPAT_H__
#define __NDR_SVCCTL_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *svcctl_get_ep_server(void);

NTSTATUS svcctl__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct svcctl_CloseServiceHandle;
WERROR _svcctl_CloseServiceHandle(struct pipes_struct *p, struct svcctl_CloseServiceHandle *r);
struct svcctl_ControlService;
WERROR _svcctl_ControlService(struct pipes_struct *p, struct svcctl_ControlService *r);
struct svcctl_DeleteService;
WERROR _svcctl_DeleteService(struct pipes_struct *p, struct svcctl_DeleteService *r);
struct svcctl_LockServiceDatabase;
WERROR _svcctl_LockServiceDatabase(struct pipes_struct *p, struct svcctl_LockServiceDatabase *r);
struct svcctl_QueryServiceObjectSecurity;
WERROR _svcctl_QueryServiceObjectSecurity(struct pipes_struct *p, struct svcctl_QueryServiceObjectSecurity *r);
struct svcctl_SetServiceObjectSecurity;
WERROR _svcctl_SetServiceObjectSecurity(struct pipes_struct *p, struct svcctl_SetServiceObjectSecurity *r);
struct svcctl_QueryServiceStatus;
WERROR _svcctl_QueryServiceStatus(struct pipes_struct *p, struct svcctl_QueryServiceStatus *r);
struct svcctl_SetServiceStatus;
WERROR _svcctl_SetServiceStatus(struct pipes_struct *p, struct svcctl_SetServiceStatus *r);
struct svcctl_UnlockServiceDatabase;
WERROR _svcctl_UnlockServiceDatabase(struct pipes_struct *p, struct svcctl_UnlockServiceDatabase *r);
struct svcctl_NotifyBootConfigStatus;
WERROR _svcctl_NotifyBootConfigStatus(struct pipes_struct *p, struct svcctl_NotifyBootConfigStatus *r);
struct svcctl_SCSetServiceBitsW;
WERROR _svcctl_SCSetServiceBitsW(struct pipes_struct *p, struct svcctl_SCSetServiceBitsW *r);
struct svcctl_ChangeServiceConfigW;
WERROR _svcctl_ChangeServiceConfigW(struct pipes_struct *p, struct svcctl_ChangeServiceConfigW *r);
struct svcctl_CreateServiceW;
WERROR _svcctl_CreateServiceW(struct pipes_struct *p, struct svcctl_CreateServiceW *r);
struct svcctl_EnumDependentServicesW;
WERROR _svcctl_EnumDependentServicesW(struct pipes_struct *p, struct svcctl_EnumDependentServicesW *r);
struct svcctl_EnumServicesStatusW;
WERROR _svcctl_EnumServicesStatusW(struct pipes_struct *p, struct svcctl_EnumServicesStatusW *r);
struct svcctl_OpenSCManagerW;
WERROR _svcctl_OpenSCManagerW(struct pipes_struct *p, struct svcctl_OpenSCManagerW *r);
struct svcctl_OpenServiceW;
WERROR _svcctl_OpenServiceW(struct pipes_struct *p, struct svcctl_OpenServiceW *r);
struct svcctl_QueryServiceConfigW;
WERROR _svcctl_QueryServiceConfigW(struct pipes_struct *p, struct svcctl_QueryServiceConfigW *r);
struct svcctl_QueryServiceLockStatusW;
WERROR _svcctl_QueryServiceLockStatusW(struct pipes_struct *p, struct svcctl_QueryServiceLockStatusW *r);
struct svcctl_StartServiceW;
WERROR _svcctl_StartServiceW(struct pipes_struct *p, struct svcctl_StartServiceW *r);
struct svcctl_GetServiceDisplayNameW;
WERROR _svcctl_GetServiceDisplayNameW(struct pipes_struct *p, struct svcctl_GetServiceDisplayNameW *r);
struct svcctl_GetServiceKeyNameW;
WERROR _svcctl_GetServiceKeyNameW(struct pipes_struct *p, struct svcctl_GetServiceKeyNameW *r);
struct svcctl_SCSetServiceBitsA;
WERROR _svcctl_SCSetServiceBitsA(struct pipes_struct *p, struct svcctl_SCSetServiceBitsA *r);
struct svcctl_ChangeServiceConfigA;
WERROR _svcctl_ChangeServiceConfigA(struct pipes_struct *p, struct svcctl_ChangeServiceConfigA *r);
struct svcctl_CreateServiceA;
WERROR _svcctl_CreateServiceA(struct pipes_struct *p, struct svcctl_CreateServiceA *r);
struct svcctl_EnumDependentServicesA;
WERROR _svcctl_EnumDependentServicesA(struct pipes_struct *p, struct svcctl_EnumDependentServicesA *r);
struct svcctl_EnumServicesStatusA;
WERROR _svcctl_EnumServicesStatusA(struct pipes_struct *p, struct svcctl_EnumServicesStatusA *r);
struct svcctl_OpenSCManagerA;
WERROR _svcctl_OpenSCManagerA(struct pipes_struct *p, struct svcctl_OpenSCManagerA *r);
struct svcctl_OpenServiceA;
WERROR _svcctl_OpenServiceA(struct pipes_struct *p, struct svcctl_OpenServiceA *r);
struct svcctl_QueryServiceConfigA;
WERROR _svcctl_QueryServiceConfigA(struct pipes_struct *p, struct svcctl_QueryServiceConfigA *r);
struct svcctl_QueryServiceLockStatusA;
WERROR _svcctl_QueryServiceLockStatusA(struct pipes_struct *p, struct svcctl_QueryServiceLockStatusA *r);
struct svcctl_StartServiceA;
WERROR _svcctl_StartServiceA(struct pipes_struct *p, struct svcctl_StartServiceA *r);
struct svcctl_GetServiceDisplayNameA;
WERROR _svcctl_GetServiceDisplayNameA(struct pipes_struct *p, struct svcctl_GetServiceDisplayNameA *r);
struct svcctl_GetServiceKeyNameA;
WERROR _svcctl_GetServiceKeyNameA(struct pipes_struct *p, struct svcctl_GetServiceKeyNameA *r);
struct svcctl_GetCurrentGroupeStateW;
WERROR _svcctl_GetCurrentGroupeStateW(struct pipes_struct *p, struct svcctl_GetCurrentGroupeStateW *r);
struct svcctl_EnumServiceGroupW;
WERROR _svcctl_EnumServiceGroupW(struct pipes_struct *p, struct svcctl_EnumServiceGroupW *r);
struct svcctl_ChangeServiceConfig2A;
WERROR _svcctl_ChangeServiceConfig2A(struct pipes_struct *p, struct svcctl_ChangeServiceConfig2A *r);
struct svcctl_ChangeServiceConfig2W;
WERROR _svcctl_ChangeServiceConfig2W(struct pipes_struct *p, struct svcctl_ChangeServiceConfig2W *r);
struct svcctl_QueryServiceConfig2A;
WERROR _svcctl_QueryServiceConfig2A(struct pipes_struct *p, struct svcctl_QueryServiceConfig2A *r);
struct svcctl_QueryServiceConfig2W;
WERROR _svcctl_QueryServiceConfig2W(struct pipes_struct *p, struct svcctl_QueryServiceConfig2W *r);
struct svcctl_QueryServiceStatusEx;
WERROR _svcctl_QueryServiceStatusEx(struct pipes_struct *p, struct svcctl_QueryServiceStatusEx *r);
struct EnumServicesStatusExA;
WERROR _EnumServicesStatusExA(struct pipes_struct *p, struct EnumServicesStatusExA *r);
struct EnumServicesStatusExW;
WERROR _EnumServicesStatusExW(struct pipes_struct *p, struct EnumServicesStatusExW *r);
struct svcctl_SCSendTSMessage;
WERROR _svcctl_SCSendTSMessage(struct pipes_struct *p, struct svcctl_SCSendTSMessage *r);
NTSTATUS svcctl__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS svcctl__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS svcctl__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS svcctl__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_SVCCTL_SCOMPAT_H__ */
