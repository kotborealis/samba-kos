/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "bin/default/librpc/gen_ndr/ndr_unixinfo.h"
#include "bin/default/librpc/gen_ndr/ndr_unixinfo_c.h"

/* unixinfo - client functions generated by pidl */

struct dcerpc_unixinfo_SidToUid_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_SidToUid_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_SidToUid_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct unixinfo_SidToUid *r)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_SidToUid_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_SidToUid_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_SIDTOUID, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_SidToUid_r_done, req);

	return req;
}

static void dcerpc_unixinfo_SidToUid_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_SidToUid_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_unixinfo_SidToUid_r_state *state =
		tevent_req_data(req,
		struct dcerpc_unixinfo_SidToUid_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_SidToUid_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct unixinfo_SidToUid *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_SIDTOUID, mem_ctx, r);

	return status;
}

struct dcerpc_unixinfo_SidToUid_state {
	struct unixinfo_SidToUid orig;
	struct unixinfo_SidToUid tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_SidToUid_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_SidToUid_send(TALLOC_CTX *mem_ctx,
						 struct tevent_context *ev,
						 struct dcerpc_binding_handle *h,
						 struct dom_sid _sid /* [in]  */,
						 uint64_t *_uid /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_SidToUid_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_SidToUid_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.sid = _sid;

	/* Out parameters */
	state->orig.out.uid = _uid;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_unixinfo_SidToUid_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_unixinfo_SidToUid_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_SidToUid_done, req);
	return req;
}

static void dcerpc_unixinfo_SidToUid_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_unixinfo_SidToUid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_SidToUid_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_unixinfo_SidToUid_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.uid = *state->tmp.out.uid;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_SidToUid_recv(struct tevent_req *req,
				       TALLOC_CTX *mem_ctx,
				       NTSTATUS *result)
{
	struct dcerpc_unixinfo_SidToUid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_SidToUid_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_SidToUid(struct dcerpc_binding_handle *h,
				  TALLOC_CTX *mem_ctx,
				  struct dom_sid _sid /* [in]  */,
				  uint64_t *_uid /* [out] [ref] */,
				  NTSTATUS *result)
{
	struct unixinfo_SidToUid r;
	NTSTATUS status;

	/* In parameters */
	r.in.sid = _sid;

	/* Out parameters */
	r.out.uid = _uid;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_unixinfo_SidToUid_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_uid = *r.out.uid;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_unixinfo_UidToSid_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_UidToSid_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_UidToSid_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct unixinfo_UidToSid *r)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_UidToSid_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_UidToSid_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_UIDTOSID, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_UidToSid_r_done, req);

	return req;
}

static void dcerpc_unixinfo_UidToSid_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_UidToSid_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_unixinfo_UidToSid_r_state *state =
		tevent_req_data(req,
		struct dcerpc_unixinfo_UidToSid_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_UidToSid_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct unixinfo_UidToSid *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_UIDTOSID, mem_ctx, r);

	return status;
}

struct dcerpc_unixinfo_UidToSid_state {
	struct unixinfo_UidToSid orig;
	struct unixinfo_UidToSid tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_UidToSid_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_UidToSid_send(TALLOC_CTX *mem_ctx,
						 struct tevent_context *ev,
						 struct dcerpc_binding_handle *h,
						 uint64_t _uid /* [in]  */,
						 struct dom_sid *_sid /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_UidToSid_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_UidToSid_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.uid = _uid;

	/* Out parameters */
	state->orig.out.sid = _sid;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_unixinfo_UidToSid_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_unixinfo_UidToSid_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_UidToSid_done, req);
	return req;
}

static void dcerpc_unixinfo_UidToSid_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_unixinfo_UidToSid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_UidToSid_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_unixinfo_UidToSid_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.sid = *state->tmp.out.sid;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_UidToSid_recv(struct tevent_req *req,
				       TALLOC_CTX *mem_ctx,
				       NTSTATUS *result)
{
	struct dcerpc_unixinfo_UidToSid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_UidToSid_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_UidToSid(struct dcerpc_binding_handle *h,
				  TALLOC_CTX *mem_ctx,
				  uint64_t _uid /* [in]  */,
				  struct dom_sid *_sid /* [out] [ref] */,
				  NTSTATUS *result)
{
	struct unixinfo_UidToSid r;
	NTSTATUS status;

	/* In parameters */
	r.in.uid = _uid;

	/* Out parameters */
	r.out.sid = _sid;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_unixinfo_UidToSid_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_sid = *r.out.sid;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_unixinfo_SidToGid_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_SidToGid_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_SidToGid_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct unixinfo_SidToGid *r)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_SidToGid_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_SidToGid_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_SIDTOGID, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_SidToGid_r_done, req);

	return req;
}

static void dcerpc_unixinfo_SidToGid_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_SidToGid_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_unixinfo_SidToGid_r_state *state =
		tevent_req_data(req,
		struct dcerpc_unixinfo_SidToGid_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_SidToGid_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct unixinfo_SidToGid *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_SIDTOGID, mem_ctx, r);

	return status;
}

struct dcerpc_unixinfo_SidToGid_state {
	struct unixinfo_SidToGid orig;
	struct unixinfo_SidToGid tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_SidToGid_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_SidToGid_send(TALLOC_CTX *mem_ctx,
						 struct tevent_context *ev,
						 struct dcerpc_binding_handle *h,
						 struct dom_sid _sid /* [in]  */,
						 uint64_t *_gid /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_SidToGid_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_SidToGid_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.sid = _sid;

	/* Out parameters */
	state->orig.out.gid = _gid;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_unixinfo_SidToGid_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_unixinfo_SidToGid_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_SidToGid_done, req);
	return req;
}

static void dcerpc_unixinfo_SidToGid_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_unixinfo_SidToGid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_SidToGid_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_unixinfo_SidToGid_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.gid = *state->tmp.out.gid;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_SidToGid_recv(struct tevent_req *req,
				       TALLOC_CTX *mem_ctx,
				       NTSTATUS *result)
{
	struct dcerpc_unixinfo_SidToGid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_SidToGid_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_SidToGid(struct dcerpc_binding_handle *h,
				  TALLOC_CTX *mem_ctx,
				  struct dom_sid _sid /* [in]  */,
				  uint64_t *_gid /* [out] [ref] */,
				  NTSTATUS *result)
{
	struct unixinfo_SidToGid r;
	NTSTATUS status;

	/* In parameters */
	r.in.sid = _sid;

	/* Out parameters */
	r.out.gid = _gid;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_unixinfo_SidToGid_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_gid = *r.out.gid;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_unixinfo_GidToSid_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_GidToSid_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_GidToSid_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct unixinfo_GidToSid *r)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_GidToSid_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_GidToSid_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_GIDTOSID, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_GidToSid_r_done, req);

	return req;
}

static void dcerpc_unixinfo_GidToSid_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_GidToSid_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_unixinfo_GidToSid_r_state *state =
		tevent_req_data(req,
		struct dcerpc_unixinfo_GidToSid_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_GidToSid_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct unixinfo_GidToSid *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_GIDTOSID, mem_ctx, r);

	return status;
}

struct dcerpc_unixinfo_GidToSid_state {
	struct unixinfo_GidToSid orig;
	struct unixinfo_GidToSid tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_GidToSid_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_GidToSid_send(TALLOC_CTX *mem_ctx,
						 struct tevent_context *ev,
						 struct dcerpc_binding_handle *h,
						 uint64_t _gid /* [in]  */,
						 struct dom_sid *_sid /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_GidToSid_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_GidToSid_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.gid = _gid;

	/* Out parameters */
	state->orig.out.sid = _sid;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_unixinfo_GidToSid_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_unixinfo_GidToSid_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_GidToSid_done, req);
	return req;
}

static void dcerpc_unixinfo_GidToSid_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_unixinfo_GidToSid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_GidToSid_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_unixinfo_GidToSid_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.sid = *state->tmp.out.sid;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_GidToSid_recv(struct tevent_req *req,
				       TALLOC_CTX *mem_ctx,
				       NTSTATUS *result)
{
	struct dcerpc_unixinfo_GidToSid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_GidToSid_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_GidToSid(struct dcerpc_binding_handle *h,
				  TALLOC_CTX *mem_ctx,
				  uint64_t _gid /* [in]  */,
				  struct dom_sid *_sid /* [out] [ref] */,
				  NTSTATUS *result)
{
	struct unixinfo_GidToSid r;
	NTSTATUS status;

	/* In parameters */
	r.in.gid = _gid;

	/* Out parameters */
	r.out.sid = _sid;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_unixinfo_GidToSid_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_sid = *r.out.sid;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_unixinfo_GetPWUid_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_GetPWUid_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_GetPWUid_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct unixinfo_GetPWUid *r)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_GetPWUid_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_GetPWUid_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_GETPWUID, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_GetPWUid_r_done, req);

	return req;
}

static void dcerpc_unixinfo_GetPWUid_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_GetPWUid_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_unixinfo_GetPWUid_r_state *state =
		tevent_req_data(req,
		struct dcerpc_unixinfo_GetPWUid_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_GetPWUid_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct unixinfo_GetPWUid *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_unixinfo,
			NDR_UNIXINFO_GETPWUID, mem_ctx, r);

	return status;
}

struct dcerpc_unixinfo_GetPWUid_state {
	struct unixinfo_GetPWUid orig;
	struct unixinfo_GetPWUid tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_unixinfo_GetPWUid_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_unixinfo_GetPWUid_send(TALLOC_CTX *mem_ctx,
						 struct tevent_context *ev,
						 struct dcerpc_binding_handle *h,
						 uint32_t *_count /* [in,out] [range(0,1023),ref] */,
						 uint64_t *_uids /* [in] [size_is(*count)] */,
						 struct unixinfo_GetPWUidInfo *_infos /* [out] [size_is(*count)] */)
{
	struct tevent_req *req;
	struct dcerpc_unixinfo_GetPWUid_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_unixinfo_GetPWUid_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.count = _count;
	state->orig.in.uids = _uids;

	/* Out parameters */
	state->orig.out.count = _count;
	state->orig.out.infos = _infos;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_unixinfo_GetPWUid_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_unixinfo_GetPWUid_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_unixinfo_GetPWUid_done, req);
	return req;
}

static void dcerpc_unixinfo_GetPWUid_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_unixinfo_GetPWUid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_GetPWUid_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_unixinfo_GetPWUid_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.count = *state->tmp.out.count;
	{
		size_t _copy_len_infos;
		if ((*state->tmp.out.count) > (*state->tmp.in.count)) {
			tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
			return;
		}
		_copy_len_infos = *state->tmp.out.count;
		if (state->orig.out.infos != state->tmp.out.infos) {
			memcpy(state->orig.out.infos, state->tmp.out.infos, _copy_len_infos * sizeof(*state->orig.out.infos));
		}
	}

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_unixinfo_GetPWUid_recv(struct tevent_req *req,
				       TALLOC_CTX *mem_ctx,
				       NTSTATUS *result)
{
	struct dcerpc_unixinfo_GetPWUid_state *state = tevent_req_data(
		req, struct dcerpc_unixinfo_GetPWUid_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_unixinfo_GetPWUid(struct dcerpc_binding_handle *h,
				  TALLOC_CTX *mem_ctx,
				  uint32_t *_count /* [in,out] [range(0,1023),ref] */,
				  uint64_t *_uids /* [in] [size_is(*count)] */,
				  struct unixinfo_GetPWUidInfo *_infos /* [out] [size_is(*count)] */,
				  NTSTATUS *result)
{
	struct unixinfo_GetPWUid r;
	NTSTATUS status;

	/* In parameters */
	r.in.count = _count;
	r.in.uids = _uids;

	/* Out parameters */
	r.out.count = _count;
	r.out.infos = _infos;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_unixinfo_GetPWUid_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_count = *r.out.count;
	{
		size_t _copy_len_infos;
		if ((*r.out.count) > (*r.in.count)) {
			return NT_STATUS_INVALID_NETWORK_RESPONSE;
		}
		_copy_len_infos = *r.out.count;
		if (_infos != r.out.infos) {
			memcpy(_infos, r.out.infos, _copy_len_infos * sizeof(*_infos));
		}
	}

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

