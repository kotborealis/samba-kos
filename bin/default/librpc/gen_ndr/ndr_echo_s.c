/* server functions auto-generated by pidl */
#include "bin/default/librpc/gen_ndr/ndr_echo.h"
#include <util/debug.h>

NTSTATUS dcerpc_server_rpcecho_init(TALLOC_CTX *);

/* rpcecho - dcerpc server boilerplate generated by pidl */


static NTSTATUS rpcecho__op_bind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
#ifdef DCESRV_INTERFACE_RPCECHO_BIND
	return DCESRV_INTERFACE_RPCECHO_BIND(context,iface);
#else
	return NT_STATUS_OK;
#endif
}

static void rpcecho__op_unbind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
#ifdef DCESRV_INTERFACE_RPCECHO_UNBIND
	DCESRV_INTERFACE_RPCECHO_UNBIND(context, iface);
#else
	return;
#endif
}

static NTSTATUS rpcecho__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	dce_call->fault_code = 0;

	if (opnum >= ndr_table_rpcecho.num_calls) {
		dce_call->fault_code = DCERPC_FAULT_OP_RNG_ERROR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	*r = talloc_named(mem_ctx,
			  ndr_table_rpcecho.calls[opnum].struct_size,
			  "struct %s",
			  ndr_table_rpcecho.calls[opnum].name);
	NT_STATUS_HAVE_NO_MEMORY(*r);

        /* unravel the NDR for the packet */
	ndr_err = ndr_table_rpcecho.calls[opnum].ndr_pull(pull, NDR_IN, *r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpcecho__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	switch (opnum) {
	case 0: {
		struct echo_AddOne *r2 = (struct echo_AddOne *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_AddOne, NDR_IN, r2);
		}
		dcesrv_echo_AddOne(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_AddOne will reply async\n"));
		}
		break;
	}
	case 1: {
		struct echo_EchoData *r2 = (struct echo_EchoData *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_EchoData, NDR_IN, r2);
		}
		dcesrv_echo_EchoData(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_EchoData will reply async\n"));
		}
		break;
	}
	case 2: {
		struct echo_SinkData *r2 = (struct echo_SinkData *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_SinkData, NDR_IN, r2);
		}
		dcesrv_echo_SinkData(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_SinkData will reply async\n"));
		}
		break;
	}
	case 3: {
		struct echo_SourceData *r2 = (struct echo_SourceData *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_SourceData, NDR_IN, r2);
		}
		dcesrv_echo_SourceData(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_SourceData will reply async\n"));
		}
		break;
	}
	case 4: {
		struct echo_TestCall *r2 = (struct echo_TestCall *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestCall, NDR_IN, r2);
		}
		dcesrv_echo_TestCall(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestCall will reply async\n"));
		}
		break;
	}
	case 5: {
		struct echo_TestCall2 *r2 = (struct echo_TestCall2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestCall2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_echo_TestCall2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestCall2 will reply async\n"));
		}
		break;
	}
	case 6: {
		struct echo_TestSleep *r2 = (struct echo_TestSleep *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestSleep, NDR_IN, r2);
		}
		r2->out.result = dcesrv_echo_TestSleep(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestSleep will reply async\n"));
		}
		break;
	}
	case 7: {
		struct echo_TestEnum *r2 = (struct echo_TestEnum *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestEnum, NDR_IN, r2);
		}
		dcesrv_echo_TestEnum(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestEnum will reply async\n"));
		}
		break;
	}
	case 8: {
		struct echo_TestSurrounding *r2 = (struct echo_TestSurrounding *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestSurrounding, NDR_IN, r2);
		}
		dcesrv_echo_TestSurrounding(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestSurrounding will reply async\n"));
		}
		break;
	}
	case 9: {
		struct echo_TestDoublePointer *r2 = (struct echo_TestDoublePointer *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestDoublePointer, NDR_IN, r2);
		}
		r2->out.result = dcesrv_echo_TestDoublePointer(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestDoublePointer will reply async\n"));
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

static NTSTATUS rpcecho__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	switch (opnum) {
	case 0: {
		struct echo_AddOne *r2 = (struct echo_AddOne *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_AddOne replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_AddOne, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_AddOne\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 1: {
		struct echo_EchoData *r2 = (struct echo_EchoData *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_EchoData replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_EchoData, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_EchoData\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 2: {
		struct echo_SinkData *r2 = (struct echo_SinkData *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_SinkData replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_SinkData, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_SinkData\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 3: {
		struct echo_SourceData *r2 = (struct echo_SourceData *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_SourceData replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_SourceData, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_SourceData\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 4: {
		struct echo_TestCall *r2 = (struct echo_TestCall *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestCall replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestCall, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestCall\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 5: {
		struct echo_TestCall2 *r2 = (struct echo_TestCall2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestCall2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestCall2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestCall2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 6: {
		struct echo_TestSleep *r2 = (struct echo_TestSleep *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestSleep replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestSleep, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestSleep\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 7: {
		struct echo_TestEnum *r2 = (struct echo_TestEnum *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestEnum replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestEnum, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestEnum\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 8: {
		struct echo_TestSurrounding *r2 = (struct echo_TestSurrounding *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestSurrounding replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestSurrounding, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestSurrounding\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 9: {
		struct echo_TestDoublePointer *r2 = (struct echo_TestDoublePointer *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function echo_TestDoublePointer replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(echo_TestDoublePointer, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in echo_TestDoublePointer\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
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

static NTSTATUS rpcecho__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	ndr_err = ndr_table_rpcecho.calls[opnum].ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

static const struct dcesrv_interface dcesrv_rpcecho_interface = {
	.name		    = "rpcecho",
	.syntax_id          = {{0x60a15ec5,0x4de8,0x11d7,{0xa6,0x37},{0x00,0x50,0x56,0xa2,0x01,0x82}},1.0},
	.bind		    = rpcecho__op_bind,
	.unbind		    = rpcecho__op_unbind,
	.ndr_pull	    = rpcecho__op_ndr_pull,
	.dispatch	    = rpcecho__op_dispatch,
	.reply		    = rpcecho__op_reply,
	.ndr_push	    = rpcecho__op_ndr_push,
	.local		    = NULL,
#ifdef DCESRV_INTERFACE_RPCECHO_FLAGS
	.flags              = DCESRV_INTERFACE_RPCECHO_FLAGS
#else
	.flags              = 0
#endif
};


static NTSTATUS rpcecho__op_init_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	int i;
#ifdef DCESRV_INTERFACE_RPCECHO_NCACN_NP_SECONDARY_ENDPOINT
	const char *ncacn_np_secondary_endpoint =
		DCESRV_INTERFACE_RPCECHO_NCACN_NP_SECONDARY_ENDPOINT;
#else
	const char *ncacn_np_secondary_endpoint = NULL;
#endif

	for (i=0;i<ndr_table_rpcecho.endpoints->count;i++) {
		NTSTATUS ret;
		const char *name = ndr_table_rpcecho.endpoints->names[i];

		ret = dcesrv_interface_register(dce_ctx,
						name,
						ncacn_np_secondary_endpoint,
						&dcesrv_rpcecho_interface,
						NULL);
		if (!NT_STATUS_IS_OK(ret)) {
			DEBUG(1,("rpcecho_op_init_server: failed to register endpoint '%s'\n",name));
			return ret;
		}
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpcecho__op_shutdown_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	return NT_STATUS_OK;
}

static bool rpcecho__op_interface_by_uuid(struct dcesrv_interface *iface, const struct GUID *uuid, uint32_t if_version)
{
	if (dcesrv_rpcecho_interface.syntax_id.if_version == if_version &&
		GUID_equal(&dcesrv_rpcecho_interface.syntax_id.uuid, uuid)) {
		memcpy(iface,&dcesrv_rpcecho_interface, sizeof(*iface));
		return true;
	}

	return false;
}

static bool rpcecho__op_interface_by_name(struct dcesrv_interface *iface, const char *name)
{
	if (strcmp(dcesrv_rpcecho_interface.name, name)==0) {
		memcpy(iface, &dcesrv_rpcecho_interface, sizeof(*iface));
		return true;
	}

	return false;
}

NTSTATUS dcerpc_server_rpcecho_init(TALLOC_CTX *ctx)
{
	NTSTATUS ret;
	static const struct dcesrv_endpoint_server ep_server = {
	    /* fill in our name */
	    .name = "rpcecho",

	    /* Initialization flag */
	    .initialized = false,

	    /* fill in all the operations */
#ifdef DCESRV_INTERFACE_RPCECHO_INIT_SERVER
	    .init_server = DCESRV_INTERFACE_RPCECHO_INIT_SERVER,
#else
	    .init_server = rpcecho__op_init_server,
#endif
#ifdef DCESRV_INTERFACE_RPCECHO_SHUTDOWN_SERVER
	    .shutdown_server = DCESRV_INTERFACE_RPCECHO_SHUTDOWN_SERVER,
#else
	    .shutdown_server = rpcecho__op_shutdown_server,
#endif
	    .interface_by_uuid = rpcecho__op_interface_by_uuid,
	    .interface_by_name = rpcecho__op_interface_by_name
	};
	/* register ourselves with the DCERPC subsystem. */
	ret = dcerpc_register_ep_server(&ep_server);

	if (!NT_STATUS_IS_OK(ret)) {
		DEBUG(0,("Failed to register 'rpcecho' endpoint server!\n"));
		return ret;
	}

	return ret;
}

