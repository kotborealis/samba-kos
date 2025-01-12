/* server functions auto-generated by pidl */
#include "bin/default/librpc/gen_ndr/ndr_dnsserver.h"
#include <util/debug.h>

NTSTATUS dcerpc_server_dnsserver_init(TALLOC_CTX *);

/* dnsserver - dcerpc server boilerplate generated by pidl */


static NTSTATUS dnsserver__op_bind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
#ifdef DCESRV_INTERFACE_DNSSERVER_BIND
	return DCESRV_INTERFACE_DNSSERVER_BIND(context,iface);
#else
	return NT_STATUS_OK;
#endif
}

static void dnsserver__op_unbind(struct dcesrv_connection_context *context, const struct dcesrv_interface *iface)
{
#ifdef DCESRV_INTERFACE_DNSSERVER_UNBIND
	DCESRV_INTERFACE_DNSSERVER_UNBIND(context, iface);
#else
	return;
#endif
}

static NTSTATUS dnsserver__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	dce_call->fault_code = 0;

	if (opnum >= ndr_table_dnsserver.num_calls) {
		dce_call->fault_code = DCERPC_FAULT_OP_RNG_ERROR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	*r = talloc_named(mem_ctx,
			  ndr_table_dnsserver.calls[opnum].struct_size,
			  "struct %s",
			  ndr_table_dnsserver.calls[opnum].name);
	NT_STATUS_HAVE_NO_MEMORY(*r);

        /* unravel the NDR for the packet */
	ndr_err = ndr_table_dnsserver.calls[opnum].ndr_pull(pull, NDR_IN, *r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

static NTSTATUS dnsserver__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	switch (opnum) {
	case 0: {
		struct DnssrvOperation *r2 = (struct DnssrvOperation *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvOperation, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvOperation(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvOperation will reply async\n"));
		}
		break;
	}
	case 1: {
		struct DnssrvQuery *r2 = (struct DnssrvQuery *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvQuery, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvQuery(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvQuery will reply async\n"));
		}
		break;
	}
	case 2: {
		struct DnssrvComplexOperation *r2 = (struct DnssrvComplexOperation *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvComplexOperation, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvComplexOperation(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvComplexOperation will reply async\n"));
		}
		break;
	}
	case 3: {
		struct DnssrvEnumRecords *r2 = (struct DnssrvEnumRecords *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvEnumRecords, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvEnumRecords(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvEnumRecords will reply async\n"));
		}
		break;
	}
	case 4: {
		struct DnssrvUpdateRecord *r2 = (struct DnssrvUpdateRecord *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvUpdateRecord, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvUpdateRecord(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvUpdateRecord will reply async\n"));
		}
		break;
	}
	case 5: {
		struct DnssrvOperation2 *r2 = (struct DnssrvOperation2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvOperation2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvOperation2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvOperation2 will reply async\n"));
		}
		break;
	}
	case 6: {
		struct DnssrvQuery2 *r2 = (struct DnssrvQuery2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvQuery2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvQuery2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvQuery2 will reply async\n"));
		}
		break;
	}
	case 7: {
		struct DnssrvComplexOperation2 *r2 = (struct DnssrvComplexOperation2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvComplexOperation2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvComplexOperation2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvComplexOperation2 will reply async\n"));
		}
		break;
	}
	case 8: {
		struct DnssrvEnumRecords2 *r2 = (struct DnssrvEnumRecords2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvEnumRecords2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvEnumRecords2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvEnumRecords2 will reply async\n"));
		}
		break;
	}
	case 9: {
		struct DnssrvUpdateRecord2 *r2 = (struct DnssrvUpdateRecord2 *)r;
		if (DEBUGLEVEL >= 10) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvUpdateRecord2, NDR_IN, r2);
		}
		r2->out.result = dcesrv_DnssrvUpdateRecord2(dce_call, mem_ctx, r2);
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvUpdateRecord2 will reply async\n"));
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

static NTSTATUS dnsserver__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r)
{
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	switch (opnum) {
	case 0: {
		struct DnssrvOperation *r2 = (struct DnssrvOperation *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvOperation replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvOperation, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvOperation\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 1: {
		struct DnssrvQuery *r2 = (struct DnssrvQuery *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvQuery replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvQuery, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvQuery\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 2: {
		struct DnssrvComplexOperation *r2 = (struct DnssrvComplexOperation *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvComplexOperation replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvComplexOperation, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvComplexOperation\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 3: {
		struct DnssrvEnumRecords *r2 = (struct DnssrvEnumRecords *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvEnumRecords replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvEnumRecords, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvEnumRecords\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 4: {
		struct DnssrvUpdateRecord *r2 = (struct DnssrvUpdateRecord *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvUpdateRecord replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvUpdateRecord, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvUpdateRecord\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 5: {
		struct DnssrvOperation2 *r2 = (struct DnssrvOperation2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvOperation2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvOperation2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvOperation2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 6: {
		struct DnssrvQuery2 *r2 = (struct DnssrvQuery2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvQuery2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvQuery2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvQuery2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 7: {
		struct DnssrvComplexOperation2 *r2 = (struct DnssrvComplexOperation2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvComplexOperation2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvComplexOperation2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvComplexOperation2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 8: {
		struct DnssrvEnumRecords2 *r2 = (struct DnssrvEnumRecords2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvEnumRecords2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvEnumRecords2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvEnumRecords2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
		}
		break;
	}
	case 9: {
		struct DnssrvUpdateRecord2 *r2 = (struct DnssrvUpdateRecord2 *)r;
		if (dce_call->state_flags & DCESRV_CALL_STATE_FLAG_ASYNC) {
			DEBUG(5,("function DnssrvUpdateRecord2 replied async\n"));
		}
		if (DEBUGLEVEL >= 10 && dce_call->fault_code == 0) {
			NDR_PRINT_FUNCTION_DEBUG(DnssrvUpdateRecord2, NDR_OUT | NDR_SET_VALUES, r2);
		}
		if (dce_call->fault_code != 0) {
			DEBUG(2,("dcerpc_fault %s in DnssrvUpdateRecord2\n", dcerpc_errstr(mem_ctx, dce_call->fault_code)));
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

static NTSTATUS dnsserver__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r)
{
	enum ndr_err_code ndr_err;
	uint16_t opnum = dce_call->pkt.u.request.opnum;

	ndr_err = ndr_table_dnsserver.calls[opnum].ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		dce_call->fault_code = DCERPC_FAULT_NDR;
		return NT_STATUS_NET_WRITE_FAULT;
	}

	return NT_STATUS_OK;
}

static const struct dcesrv_interface dcesrv_dnsserver_interface = {
	.name		    = "dnsserver",
	.syntax_id          = {{0x50abc2a4,0x574d,0x40b3,{0x9d,0x66},{0xee,0x4f,0xd5,0xfb,0xa0,0x76}},5.0},
	.bind		    = dnsserver__op_bind,
	.unbind		    = dnsserver__op_unbind,
	.ndr_pull	    = dnsserver__op_ndr_pull,
	.dispatch	    = dnsserver__op_dispatch,
	.reply		    = dnsserver__op_reply,
	.ndr_push	    = dnsserver__op_ndr_push,
	.local		    = NULL,
#ifdef DCESRV_INTERFACE_DNSSERVER_FLAGS
	.flags              = DCESRV_INTERFACE_DNSSERVER_FLAGS
#else
	.flags              = 0
#endif
};


static NTSTATUS dnsserver__op_init_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	int i;
#ifdef DCESRV_INTERFACE_DNSSERVER_NCACN_NP_SECONDARY_ENDPOINT
	const char *ncacn_np_secondary_endpoint =
		DCESRV_INTERFACE_DNSSERVER_NCACN_NP_SECONDARY_ENDPOINT;
#else
	const char *ncacn_np_secondary_endpoint = NULL;
#endif

	for (i=0;i<ndr_table_dnsserver.endpoints->count;i++) {
		NTSTATUS ret;
		const char *name = ndr_table_dnsserver.endpoints->names[i];

		ret = dcesrv_interface_register(dce_ctx,
						name,
						ncacn_np_secondary_endpoint,
						&dcesrv_dnsserver_interface,
						NULL);
		if (!NT_STATUS_IS_OK(ret)) {
			DEBUG(1,("dnsserver_op_init_server: failed to register endpoint '%s'\n",name));
			return ret;
		}
	}

	return NT_STATUS_OK;
}

static NTSTATUS dnsserver__op_shutdown_server(struct dcesrv_context *dce_ctx, const struct dcesrv_endpoint_server *ep_server)
{
	return NT_STATUS_OK;
}

static bool dnsserver__op_interface_by_uuid(struct dcesrv_interface *iface, const struct GUID *uuid, uint32_t if_version)
{
	if (dcesrv_dnsserver_interface.syntax_id.if_version == if_version &&
		GUID_equal(&dcesrv_dnsserver_interface.syntax_id.uuid, uuid)) {
		memcpy(iface,&dcesrv_dnsserver_interface, sizeof(*iface));
		return true;
	}

	return false;
}

static bool dnsserver__op_interface_by_name(struct dcesrv_interface *iface, const char *name)
{
	if (strcmp(dcesrv_dnsserver_interface.name, name)==0) {
		memcpy(iface, &dcesrv_dnsserver_interface, sizeof(*iface));
		return true;
	}

	return false;
}

NTSTATUS dcerpc_server_dnsserver_init(TALLOC_CTX *ctx)
{
	NTSTATUS ret;
	static const struct dcesrv_endpoint_server ep_server = {
	    /* fill in our name */
	    .name = "dnsserver",

	    /* Initialization flag */
	    .initialized = false,

	    /* fill in all the operations */
#ifdef DCESRV_INTERFACE_DNSSERVER_INIT_SERVER
	    .init_server = DCESRV_INTERFACE_DNSSERVER_INIT_SERVER,
#else
	    .init_server = dnsserver__op_init_server,
#endif
#ifdef DCESRV_INTERFACE_DNSSERVER_SHUTDOWN_SERVER
	    .shutdown_server = DCESRV_INTERFACE_DNSSERVER_SHUTDOWN_SERVER,
#else
	    .shutdown_server = dnsserver__op_shutdown_server,
#endif
	    .interface_by_uuid = dnsserver__op_interface_by_uuid,
	    .interface_by_name = dnsserver__op_interface_by_name
	};
	/* register ourselves with the DCERPC subsystem. */
	ret = dcerpc_register_ep_server(&ep_server);

	if (!NT_STATUS_IS_OK(ret)) {
		DEBUG(0,("Failed to register 'dnsserver' endpoint server!\n"));
		return ret;
	}

	return ret;
}

