/* s3 compat server functions auto-generated by pidl */
#include "bin/default/librpc/gen_ndr/ndr_frsapi.h"
#include "bin/default/librpc/gen_ndr/ndr_frsapi_scompat.h"
#include <librpc/rpc/dcesrv_core.h>
#include <rpc_server/rpc_config.h>
#include <rpc_server/rpc_server.h>
#include <util/debug.h>

enum s3compat_rpc_dispatch {
	S3COMPAT_RPC_DISPATCH_EXTERNAL = 0x00000001,
	S3COMPAT_RPC_DISPATCH_INTERNAL = 0x00000002,
};

/* frsapi - dcerpc server boilerplate generated by pidl */
static NTSTATUS frsapi__op_bind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
	struct pipes_struct *p = NULL;

	/* Retrieve pipes struct */
	p = dcesrv_get_pipes_struct(context->conn);
	p->pipe_bound = true;
#ifdef DCESRV_INTERFACE_FRSAPI_BIND
	return DCESRV_INTERFACE_FRSAPI_BIND(context,iface);
#else
	return NT_STATUS_OK;
#endif
}

static void frsapi__op_unbind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
#ifdef DCESRV_INTERFACE_FRSAPI_UNBIND
	DCESRV_INTERFACE_FRSAPI_UNBIND(context, iface);
#else
	return;
#endif
}

NTSTATUS frsapi__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	dce_call->fault_code = 0;

	if (opnum >= ndr_table_frsapi.num_calls) {
		dce_call->fault_code = DCERPC_FAULT_OP_RNG_ERROR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	*r = talloc_named(mem_ctx, ndr_table_frsapi.calls[opnum].struct_size, "struct %s", ndr_table_frsapi.calls[opnum].name);
	NT_STATUS_HAVE_NO_MEMORY(*r);

	/* unravel the NDR for the packet */
	ndr_err = ndr_table_frsapi.calls[opnum].ndr_pull(pull, NDR_IN, *r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

static NTSTATUS frsapi__op_dispatch_internal(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r, enum s3compat_rpc_dispatch dispatch)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;
	struct pipes_struct *p = NULL;
	struct auth_session_info *pipe_session_info = NULL;
	NTSTATUS status = NT_STATUS_OK;
	bool impersonated = false;

	/* Retrieve pipes struct */
	p = dcesrv_get_pipes_struct(dce_call->conn);
	/* Update pipes struct opnum */
	p->opnum = opnum;
	p->dce_call = dce_call;
	p->mem_ctx = mem_ctx;
	/* Update pipes struct session info */
	pipe_session_info = p->session_info;
	p->session_info = dce_call->auth_state->session_info;
	p->auth.auth_type = dce_call->auth_state->auth_type;
	p->auth.auth_level = dce_call->auth_state->auth_level;
	p->auth.auth_context_id = dce_call->auth_state->auth_context_id;
	/* Reset pipes struct fault state */
	p->fault_state = 0;

	/* Impersonate */
	if (dispatch == S3COMPAT_RPC_DISPATCH_EXTERNAL) {
		impersonated = become_authenticated_pipe_user(p->session_info);
		if (!impersonated) {
			dce_call->fault_code = DCERPC_FAULT_ACCESS_DENIED;
			status = NT_STATUS_NET_WRITE_FAULT;
			goto fail;
		}
	}

	switch (opnum) {
	case 0: { /* FRSAPI_VERIFY_PROMOTION */
		struct FRSAPI_VERIFY_PROMOTION *r2 = (struct FRSAPI_VERIFY_PROMOTION *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_VERIFY_PROMOTION, NDR_IN, r2);
		}
		_FRSAPI_VERIFY_PROMOTION(p, r2);
		break;
	}
	case 1: { /* FRSAPI_PROMOTION_STATUS */
		struct FRSAPI_PROMOTION_STATUS *r2 = (struct FRSAPI_PROMOTION_STATUS *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_PROMOTION_STATUS, NDR_IN, r2);
		}
		_FRSAPI_PROMOTION_STATUS(p, r2);
		break;
	}
	case 2: { /* FRSAPI_START_DEMOTION */
		struct FRSAPI_START_DEMOTION *r2 = (struct FRSAPI_START_DEMOTION *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_START_DEMOTION, NDR_IN, r2);
		}
		_FRSAPI_START_DEMOTION(p, r2);
		break;
	}
	case 3: { /* FRSAPI_COMMIT_DEMOTION */
		struct FRSAPI_COMMIT_DEMOTION *r2 = (struct FRSAPI_COMMIT_DEMOTION *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_COMMIT_DEMOTION, NDR_IN, r2);
		}
		_FRSAPI_COMMIT_DEMOTION(p, r2);
		break;
	}
	case 4: { /* frsapi_SetDsPollingIntervalW */
		struct frsapi_SetDsPollingIntervalW *r2 = (struct frsapi_SetDsPollingIntervalW *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_SetDsPollingIntervalW, NDR_IN, r2);
		}
		r2->out.result = _frsapi_SetDsPollingIntervalW(p, r2);
		break;
	}
	case 5: { /* frsapi_GetDsPollingIntervalW */
		struct frsapi_GetDsPollingIntervalW *r2 = (struct frsapi_GetDsPollingIntervalW *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_GetDsPollingIntervalW, NDR_IN, r2);
		}
		NDR_ZERO_STRUCT(r2->out);
		r2->out.CurrentInterval = talloc_zero(r2, uint32_t);
		if (r2->out.CurrentInterval == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.DsPollingLongInterval = talloc_zero(r2, uint32_t);
		if (r2->out.DsPollingLongInterval == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.DsPollingShortInterval = talloc_zero(r2, uint32_t);
		if (r2->out.DsPollingShortInterval == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.result = _frsapi_GetDsPollingIntervalW(p, r2);
		break;
	}
	case 6: { /* FRSAPI_VERIFY_PROMOTION_W */
		struct FRSAPI_VERIFY_PROMOTION_W *r2 = (struct FRSAPI_VERIFY_PROMOTION_W *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_VERIFY_PROMOTION_W, NDR_IN, r2);
		}
		_FRSAPI_VERIFY_PROMOTION_W(p, r2);
		break;
	}
	case 7: { /* frsapi_InfoW */
		struct frsapi_InfoW *r2 = (struct frsapi_InfoW *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_InfoW, NDR_IN, r2);
		}
		NDR_ZERO_STRUCT(r2->out);
		r2->out.info = r2->in.info;
		r2->out.result = _frsapi_InfoW(p, r2);
		break;
	}
	case 8: { /* frsapi_IsPathReplicated */
		struct frsapi_IsPathReplicated *r2 = (struct frsapi_IsPathReplicated *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_IsPathReplicated, NDR_IN, r2);
		}
		NDR_ZERO_STRUCT(r2->out);
		r2->out.replicated = talloc_zero(r2, uint32_t);
		if (r2->out.replicated == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.primary = talloc_zero(r2, uint32_t);
		if (r2->out.primary == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.root = talloc_zero(r2, uint32_t);
		if (r2->out.root == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.replica_set_guid = talloc_zero(r2, struct GUID);
		if (r2->out.replica_set_guid == NULL) {
			status = NT_STATUS_NO_MEMORY;
			p->fault_state = DCERPC_FAULT_CANT_PERFORM;
			goto fail;
		}

		r2->out.result = _frsapi_IsPathReplicated(p, r2);
		break;
	}
	case 9: { /* frsapi_WriterCommand */
		struct frsapi_WriterCommand *r2 = (struct frsapi_WriterCommand *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_WriterCommand, NDR_IN, r2);
		}
		r2->out.result = _frsapi_WriterCommand(p, r2);
		break;
	}
	case 10: { /* frsapi_ForceReplication */
		struct frsapi_ForceReplication *r2 = (struct frsapi_ForceReplication *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_ForceReplication, NDR_IN, r2);
		}
		r2->out.result = _frsapi_ForceReplication(p, r2);
		break;
	}
	default:
		dce_call->fault_code = DCERPC_FAULT_OP_RNG_ERROR;
		break;
	}

fail:
	/* Unimpersonate */
	if (impersonated) {
		unbecome_authenticated_pipe_user();
	}

	p->dce_call = NULL;
	p->mem_ctx = NULL;
	/* Restore session info */
	p->session_info = pipe_session_info;
	p->auth.auth_type = 0;
	p->auth.auth_level = 0;
	p->auth.auth_context_id = 0;
	/* Check pipes struct fault state */
	if (p->fault_state != 0) {
		dce_call->fault_code = p->fault_state;
	}
	if (dce_call->fault_code != 0) {
		status = NT_STATUS_NET_WRITE_FAULT;
	}

	return status;
}

NTSTATUS frsapi__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	return frsapi__op_dispatch_internal(dce_call, mem_ctx, r, S3COMPAT_RPC_DISPATCH_EXTERNAL);
}

NTSTATUS frsapi__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	switch (opnum) {
	case 0: { /* FRSAPI_VERIFY_PROMOTION */
		struct FRSAPI_VERIFY_PROMOTION *r2 = (struct FRSAPI_VERIFY_PROMOTION *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function FRSAPI_VERIFY_PROMOTION replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_VERIFY_PROMOTION, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in FRSAPI_VERIFY_PROMOTION\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 1: { /* FRSAPI_PROMOTION_STATUS */
		struct FRSAPI_PROMOTION_STATUS *r2 = (struct FRSAPI_PROMOTION_STATUS *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function FRSAPI_PROMOTION_STATUS replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_PROMOTION_STATUS, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in FRSAPI_PROMOTION_STATUS\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 2: { /* FRSAPI_START_DEMOTION */
		struct FRSAPI_START_DEMOTION *r2 = (struct FRSAPI_START_DEMOTION *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function FRSAPI_START_DEMOTION replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_START_DEMOTION, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in FRSAPI_START_DEMOTION\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 3: { /* FRSAPI_COMMIT_DEMOTION */
		struct FRSAPI_COMMIT_DEMOTION *r2 = (struct FRSAPI_COMMIT_DEMOTION *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function FRSAPI_COMMIT_DEMOTION replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_COMMIT_DEMOTION, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in FRSAPI_COMMIT_DEMOTION\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 4: { /* frsapi_SetDsPollingIntervalW */
		struct frsapi_SetDsPollingIntervalW *r2 = (struct frsapi_SetDsPollingIntervalW *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_SetDsPollingIntervalW replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_SetDsPollingIntervalW, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_SetDsPollingIntervalW\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 5: { /* frsapi_GetDsPollingIntervalW */
		struct frsapi_GetDsPollingIntervalW *r2 = (struct frsapi_GetDsPollingIntervalW *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_GetDsPollingIntervalW replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_GetDsPollingIntervalW, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_GetDsPollingIntervalW\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 6: { /* FRSAPI_VERIFY_PROMOTION_W */
		struct FRSAPI_VERIFY_PROMOTION_W *r2 = (struct FRSAPI_VERIFY_PROMOTION_W *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function FRSAPI_VERIFY_PROMOTION_W replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(FRSAPI_VERIFY_PROMOTION_W, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in FRSAPI_VERIFY_PROMOTION_W\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 7: { /* frsapi_InfoW */
		struct frsapi_InfoW *r2 = (struct frsapi_InfoW *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_InfoW replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_InfoW, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_InfoW\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 8: { /* frsapi_IsPathReplicated */
		struct frsapi_IsPathReplicated *r2 = (struct frsapi_IsPathReplicated *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_IsPathReplicated replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_IsPathReplicated, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_IsPathReplicated\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 9: { /* frsapi_WriterCommand */
		struct frsapi_WriterCommand *r2 = (struct frsapi_WriterCommand *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_WriterCommand replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_WriterCommand, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_WriterCommand\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	case 10: { /* frsapi_ForceReplication */
		struct frsapi_ForceReplication *r2 = (struct frsapi_ForceReplication *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function frsapi_ForceReplication replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(frsapi_ForceReplication, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DBG_WARNING("dcerpc_fault %s in frsapi_ForceReplication\n", dcerpc_errstr(mem_ctx, dce_call->fault_code));
		}
		break;
	}
	default:
		dce_call->fault_code = DCERPC_FAULT_OP_RNG_ERROR;
		break;
	}

	if (dce_call->fault_code != 0) {
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

NTSTATUS frsapi__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	ndr_err = ndr_table_frsapi.calls[opnum].ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

NTSTATUS frsapi__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	return frsapi__op_dispatch_internal(dce_call, mem_ctx, r, S3COMPAT_RPC_DISPATCH_INTERNAL);
}

static const struct dcesrv_interface dcesrv_frsapi_interface = {
	.name      = "frsapi",
	.syntax_id = {{0xd049b186,0x814f,0x11d1,{0x9a,0x3c},{0x00,0xc0,0x4f,0xc9,0xb2,0x32}},65537},
	.bind      = frsapi__op_bind,
	.unbind    = frsapi__op_unbind,
	.ndr_pull  = frsapi__op_ndr_pull,
	.dispatch  = frsapi__op_dispatch,
	.reply     = frsapi__op_reply,
	.ndr_push  = frsapi__op_ndr_push,
	.local     = frsapi__op_local,
#ifdef DCESRV_INTERFACE_FRSAPI_FLAGS
	.flags     = DCESRV_INTERFACE_FRSAPI_FLAGS
#else
	.flags     = 0
#endif
};

static NTSTATUS frsapi__check_register_in_endpoint(const char *name, struct dcerpc_binding *binding) {
	enum dcerpc_transport_t transport = dcerpc_binding_get_transport(binding);

	/* If service is embedded, register only for ncacn_np
	 * see 8466b3c85e4b835e57e41776853093f4a0edc8b8
	 */
	if (rpc_service_mode(name) == RPC_SERVICE_MODE_EMBEDDED && (transport != NCACN_NP && transport != NCALRPC)) {
		DBG_INFO("Interface 'frsapi' not registered in endpoint '%s' as service is embedded\n", name);
		return NT_STATUS_NOT_SUPPORTED;
	}

	return NT_STATUS_OK;
}

static NTSTATUS frsapi__op_init_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	uint32_t i;
	NTSTATUS ret;
	struct dcerpc_binding *binding;

#ifdef DCESRV_INTERFACE_FRSAPI_NCACN_NP_SECONDARY_ENDPOINT
	const char *ncacn_np_secondary_endpoint = DCESRV_INTERFACE_FRSAPI_NCACN_NP_SECONDARY_ENDPOINT;
#else
	const char *ncacn_np_secondary_endpoint = NULL;
#endif

	for (i=0;i<ndr_table_frsapi.endpoints->count;i++) {
		const char *name = ndr_table_frsapi.endpoints->names[i];

		ret = dcerpc_parse_binding(dce_ctx, name, &binding);
		if (NT_STATUS_IS_ERR(ret)) {
			DBG_ERR("Failed to parse binding string '%s'\n", name);
			return ret;
		}

		ret = frsapi__check_register_in_endpoint("frsapi", binding);
		if (NT_STATUS_IS_ERR(ret)) {
			talloc_free(binding);
			continue;
		}
		talloc_free(binding);

		ret = dcesrv_interface_register(dce_ctx, name, ncacn_np_secondary_endpoint, &dcesrv_frsapi_interface, NULL);
		if (!NT_STATUS_IS_OK(ret)) {
			DBG_ERR("Failed to register endpoint '%s'\n",name);
			return ret;
		}
	}

	return NT_STATUS_OK;
}

static NTSTATUS frsapi__op_shutdown_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	return NT_STATUS_OK;
}

static bool frsapi__op_interface_by_uuid(struct dcesrv_interface *iface, const struct GUID *uuid, uint32_t if_version)
{
	if (dcesrv_frsapi_interface.syntax_id.if_version == if_version && GUID_equal(&dcesrv_frsapi_interface.syntax_id.uuid, uuid)) {
		memcpy(iface,&dcesrv_frsapi_interface, sizeof(*iface));
		return true;
	}

	return false;
}

static bool frsapi__op_interface_by_name(struct dcesrv_interface *iface, const char *name)
{
	if (strcmp(dcesrv_frsapi_interface.name, name)==0) {
		memcpy(iface, &dcesrv_frsapi_interface, sizeof(*iface));
		return true;
	}

	return false;
}

static const struct dcesrv_endpoint_server frsapi_ep_server = {
	/* fill in our name */
	.name = "frsapi",

	/* Initialization flag */
	.initialized = false,

	/* fill in all the operations */
#ifdef DCESRV_INTERFACE_FRSAPI_INIT_SERVER
	.init_server = DCESRV_INTERFACE_FRSAPI_INIT_SERVER,
#else
	.init_server = frsapi__op_init_server,
#endif
#ifdef DCESRV_INTERFACE_FRSAPI_SHUTDOWN_SERVER
	.shutdown_server = DCESRV_INTERFACE_FRSAPI_SHUTDOWN_SERVER,
#else
	.shutdown_server = frsapi__op_shutdown_server,
#endif
	.interface_by_uuid = frsapi__op_interface_by_uuid,
	.interface_by_name = frsapi__op_interface_by_name
};

const struct dcesrv_endpoint_server *frsapi_get_ep_server(void)
{
	return &frsapi_ep_server;
}
