/* parser auto-generated by pidl */

#include "includes.h"
#include "bin/default/librpc/gen_ndr/ndr_file_id.h"

_PUBLIC_ enum ndr_err_code ndr_push_file_id(struct ndr_push *ndr, int ndr_flags, const struct file_id *r)
{
	NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_udlong(ndr, NDR_SCALARS, r->devid));
		NDR_CHECK(ndr_push_udlong(ndr, NDR_SCALARS, r->inode));
		NDR_CHECK(ndr_push_udlong(ndr, NDR_SCALARS, r->extid));
		NDR_CHECK(ndr_push_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_file_id(struct ndr_pull *ndr, int ndr_flags, struct file_id *r)
{
	NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_udlong(ndr, NDR_SCALARS, &r->devid));
		NDR_CHECK(ndr_pull_udlong(ndr, NDR_SCALARS, &r->inode));
		NDR_CHECK(ndr_pull_udlong(ndr, NDR_SCALARS, &r->extid));
		NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static void ndr_print_flags_file_id(struct ndr_print *ndr, const char *name, int unused, const struct file_id *r)
{
	ndr_print_file_id(ndr, name, r);
}

_PUBLIC_ void ndr_print_file_id(struct ndr_print *ndr, const char *name, const struct file_id *r)
{
	ndr_print_struct(ndr, name, "file_id");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	ndr_print_udlong(ndr, "devid", r->devid);
	ndr_print_udlong(ndr, "inode", r->inode);
	ndr_print_udlong(ndr, "extid", r->extid);
	ndr->depth--;
}

#ifndef SKIP_NDR_TABLE_file_id
static const struct ndr_interface_public_struct file_id_public_structs[] = {
	{
		.name = "file_id",
		.struct_size = sizeof(struct file_id ),
		.ndr_push = (ndr_push_flags_fn_t) ndr_push_file_id,
		.ndr_pull = (ndr_pull_flags_fn_t) ndr_pull_file_id,
		.ndr_print = (ndr_print_function_t) ndr_print_flags_file_id,
	},
	{ .name = NULL }
};

static const struct ndr_interface_call file_id_calls[] = {
	{ .name = NULL }
};

static const char * const file_id_endpoint_strings[] = {
	"ncacn_np:[\\pipe\\file_id]", 
};

static const struct ndr_interface_string_array file_id_endpoints = {
	.count	= 1,
	.names	= file_id_endpoint_strings
};

static const char * const file_id_authservice_strings[] = {
	"host", 
};

static const struct ndr_interface_string_array file_id_authservices = {
	.count	= 1,
	.names	= file_id_authservice_strings
};


const struct ndr_interface_table ndr_table_file_id = {
	.name		= "file_id",
	.num_calls	= 0,
	.calls		= file_id_calls,
	.num_public_structs	= 1,
	.public_structs		= file_id_public_structs,
	.endpoints	= &file_id_endpoints,
	.authservices	= &file_id_authservices
};

#endif /* SKIP_NDR_TABLE_file_id */
