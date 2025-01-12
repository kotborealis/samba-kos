
/* Python wrapper functions auto-generated by pidl */
#define PY_SSIZE_T_CLEAN 1 /* We use Py_ssize_t for PyArg_ParseTupleAndKeywords */
#include <Python.h>
#include "python/py3compat.h"
#include "includes.h"
#include "python/modules.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "bin/default/librpc/gen_ndr/ndr_preg.h"


/*
 * Suppress compiler warnings if the generated code does not call these
 * functions
 */
#ifndef _MAYBE_UNUSED_
#ifdef __has_attribute
#if __has_attribute(unused)
#define _MAYBE_UNUSED_ __attribute__ ((unused))
#else
#define _MAYBE_UNUSED_
#endif
#endif
#endif
/*
 * These functions are here to ensure they can be optimized out by
 * the compiler based on the constant input values
 */

static inline unsigned long long ndr_sizeof2uintmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return UINT64_MAX;
	case 4:
		return UINT32_MAX;
	case 2:
		return UINT16_MAX;
	case 1:
		return UINT8_MAX;
	}

	return 0;
}

static inline _MAYBE_UNUSED_ long long ndr_sizeof2intmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return INT64_MAX;
	case 4:
		return INT32_MAX;
	case 2:
		return INT16_MAX;
	case 1:
		return INT8_MAX;
	}

	return 0;
}

#include "librpc/gen_ndr/misc.h"
static PyTypeObject preg_entry_Type;
static PyTypeObject preg_header_Type;
static PyTypeObject preg_file_Type;
static PyTypeObject preg_InterfaceType;

static PyTypeObject *winreg_Data_GPO_Type;
static PyTypeObject *BaseObject_Type;
static PyTypeObject *ClientConnection_Type;
static PyTypeObject *ndr_syntax_id_Type;

static PyObject *py_preg_entry_get__opening_bracket(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__opening_bracket;
	if (object->_opening_bracket == NULL) {
		py__opening_bracket = Py_None;
		Py_INCREF(py__opening_bracket);
	} else {
		py__opening_bracket = PyUnicode_Decode(object->_opening_bracket, strlen(object->_opening_bracket), "utf-8", "ignore");
	}
	return py__opening_bracket;
}

static int py_preg_entry_set__opening_bracket(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_opening_bracket");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_opening_bracket = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get_keyname(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py_keyname;
	py_keyname = PyString_FromStringOrNULL(object->keyname);
	return py_keyname;
}

static int py_preg_entry_set_keyname(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->keyname");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->keyname = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get__sep1(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__sep1;
	if (object->_sep1 == NULL) {
		py__sep1 = Py_None;
		Py_INCREF(py__sep1);
	} else {
		py__sep1 = PyUnicode_Decode(object->_sep1, strlen(object->_sep1), "utf-8", "ignore");
	}
	return py__sep1;
}

static int py_preg_entry_set__sep1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_sep1");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_sep1 = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get_valuename(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py_valuename;
	py_valuename = PyString_FromStringOrNULL(object->valuename);
	return py_valuename;
}

static int py_preg_entry_set_valuename(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->valuename");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->valuename = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get__sep2(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__sep2;
	if (object->_sep2 == NULL) {
		py__sep2 = Py_None;
		Py_INCREF(py__sep2);
	} else {
		py__sep2 = PyUnicode_Decode(object->_sep2, strlen(object->_sep2), "utf-8", "ignore");
	}
	return py__sep2;
}

static int py_preg_entry_set__sep2(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_sep2");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_sep2 = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get_type(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py_type;
	py_type = PyLong_FromUnsignedLongLong((uint32_t)object->type);
	return py_type;
}

static int py_preg_entry_set_type(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->type");
		return -1;
	}
	{
		const unsigned long long uint_max = ndr_sizeof2uintmax(sizeof(object->type));
		if (PyLong_Check(value)) {
			unsigned long long test_var;
			test_var = PyLong_AsUnsignedLongLong(value);
			if (PyErr_Occurred() != NULL) {
				return -1;
			}
			if (test_var > uint_max) {
				PyErr_Format(PyExc_OverflowError, "Expected type %s within range 0 - %llu, got %llu",\
				  PyLong_Type.tp_name, uint_max, test_var);
				return -1;
			}
			object->type = test_var;
		} else {
			PyErr_Format(PyExc_TypeError, "Expected type %s",\
			  PyLong_Type.tp_name);
			return -1;
		}
	}
	return 0;
}

static PyObject *py_preg_entry_get__sep3(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__sep3;
	if (object->_sep3 == NULL) {
		py__sep3 = Py_None;
		Py_INCREF(py__sep3);
	} else {
		py__sep3 = PyUnicode_Decode(object->_sep3, strlen(object->_sep3), "utf-8", "ignore");
	}
	return py__sep3;
}

static int py_preg_entry_set__sep3(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_sep3");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_sep3 = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get_size(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py_size;
	py_size = PyLong_FromUnsignedLongLong((uint32_t)object->size);
	return py_size;
}

static int py_preg_entry_set_size(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->size");
		return -1;
	}
	{
		const unsigned long long uint_max = ndr_sizeof2uintmax(sizeof(object->size));
		if (PyLong_Check(value)) {
			unsigned long long test_var;
			test_var = PyLong_AsUnsignedLongLong(value);
			if (PyErr_Occurred() != NULL) {
				return -1;
			}
			if (test_var > uint_max) {
				PyErr_Format(PyExc_OverflowError, "Expected type %s within range 0 - %llu, got %llu",\
				  PyLong_Type.tp_name, uint_max, test_var);
				return -1;
			}
			object->size = test_var;
		} else {
			PyErr_Format(PyExc_TypeError, "Expected type %s",\
			  PyLong_Type.tp_name);
			return -1;
		}
	}
	return 0;
}

static PyObject *py_preg_entry_get__sep4(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__sep4;
	if (object->_sep4 == NULL) {
		py__sep4 = Py_None;
		Py_INCREF(py__sep4);
	} else {
		py__sep4 = PyUnicode_Decode(object->_sep4, strlen(object->_sep4), "utf-8", "ignore");
	}
	return py__sep4;
}

static int py_preg_entry_set__sep4(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_sep4");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_sep4 = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_entry_get_data(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py_data;
	py_data = pyrpc_import_union(winreg_Data_GPO_Type, pytalloc_get_mem_ctx(obj), object->type, &object->data, "union winreg_Data_GPO");
	if (py_data == NULL) {
		return NULL;
	}
	return py_data;
}

static int py_preg_entry_set_data(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->data");
		return -1;
	}
	{
		union winreg_Data_GPO *data_switch_1;
		data_switch_1 = (union winreg_Data_GPO *)pyrpc_export_union(winreg_Data_GPO_Type, pytalloc_get_mem_ctx(py_obj), object->type, value, "union winreg_Data_GPO");
		if (data_switch_1 == NULL) {
			return -1;
		}
		object->data = *data_switch_1;
	}
	return 0;
}

static PyObject *py_preg_entry_get__closing_bracket(PyObject *obj, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(obj);
	PyObject *py__closing_bracket;
	if (object->_closing_bracket == NULL) {
		py__closing_bracket = Py_None;
		Py_INCREF(py__closing_bracket);
	} else {
		py__closing_bracket = PyUnicode_Decode(object->_closing_bracket, strlen(object->_closing_bracket), "utf-8", "ignore");
	}
	return py__closing_bracket;
}

static int py_preg_entry_set__closing_bracket(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->_closing_bracket");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->_closing_bracket = talloc_str;
	}
	return 0;
}

static PyGetSetDef py_preg_entry_getsetters[] = {
	{
		.name = discard_const_p(char, "_opening_bracket"),
		.get = py_preg_entry_get__opening_bracket,
		.set = py_preg_entry_set__opening_bracket,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "keyname"),
		.get = py_preg_entry_get_keyname,
		.set = py_preg_entry_set_keyname,
		.doc = discard_const_p(char, "PIDL-generated element of base type string")
	},
	{
		.name = discard_const_p(char, "_sep1"),
		.get = py_preg_entry_get__sep1,
		.set = py_preg_entry_set__sep1,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "valuename"),
		.get = py_preg_entry_get_valuename,
		.set = py_preg_entry_set_valuename,
		.doc = discard_const_p(char, "PIDL-generated element of base type string")
	},
	{
		.name = discard_const_p(char, "_sep2"),
		.get = py_preg_entry_get__sep2,
		.set = py_preg_entry_set__sep2,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "type"),
		.get = py_preg_entry_get_type,
		.set = py_preg_entry_set_type,
		.doc = discard_const_p(char, "PIDL-generated element of base type winreg_Type")
	},
	{
		.name = discard_const_p(char, "_sep3"),
		.get = py_preg_entry_get__sep3,
		.set = py_preg_entry_set__sep3,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "size"),
		.get = py_preg_entry_get_size,
		.set = py_preg_entry_set_size,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint32")
	},
	{
		.name = discard_const_p(char, "_sep4"),
		.get = py_preg_entry_get__sep4,
		.set = py_preg_entry_set__sep4,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "data"),
		.get = py_preg_entry_get_data,
		.set = py_preg_entry_set_data,
		.doc = discard_const_p(char, "PIDL-generated element of base type winreg_Data_GPO")
	},
	{
		.name = discard_const_p(char, "_closing_bracket"),
		.get = py_preg_entry_get__closing_bracket,
		.set = py_preg_entry_set__closing_bracket,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{ .name = NULL }
};

static PyObject *py_preg_entry_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct preg_entry, type);
}

static PyObject *py_preg_entry_ndr_pack(PyObject *py_obj,  PyObject *Py_UNUSED(ignored))
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	PyObject *ret = NULL;
	DATA_BLOB blob;
	enum ndr_err_code err;
	TALLOC_CTX *tmp_ctx = talloc_new(pytalloc_get_mem_ctx(py_obj));
	if (tmp_ctx == NULL) {
		PyErr_SetNdrError(NDR_ERR_ALLOC);
		return NULL;
	}
	err = ndr_push_struct_blob(&blob, tmp_ctx, object, (ndr_push_flags_fn_t)ndr_push_preg_entry);
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		TALLOC_FREE(tmp_ctx);
		PyErr_SetNdrError(err);
		return NULL;
	}

	ret = PyBytes_FromStringAndSize((char *)blob.data, blob.length);
	TALLOC_FREE(tmp_ctx);
	return ret;
}

static PyObject *py_preg_entry_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob = {.data = NULL, .length = 0};
	Py_ssize_t blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, PYARG_BYTES_LEN "|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_entry);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_entry);
	}
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_preg_entry_ndr_print(PyObject *py_obj, PyObject *Py_UNUSED(ignored))
{
	struct preg_entry *object = (struct preg_entry *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_preg_entry, "preg_entry", object);
	ret = PyUnicode_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_preg_entry_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_preg_entry_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", PY_DISCARD_FUNC_SIG(PyCFunction,py_preg_entry_ndr_unpack), METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_preg_entry_ndr_print, METH_NOARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject preg_entry_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "preg.entry",
	.tp_getset = py_preg_entry_getsetters,
	.tp_methods = py_preg_entry_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = py_preg_entry_new,
};


static PyObject *py_preg_header_get_signature(PyObject *obj, void *closure)
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(obj);
	PyObject *py_signature;
	if (object->signature == NULL) {
		py_signature = Py_None;
		Py_INCREF(py_signature);
	} else {
		py_signature = PyUnicode_Decode(object->signature, strlen(object->signature), "utf-8", "ignore");
	}
	return py_signature;
}

static int py_preg_header_set_signature(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->signature");
		return -1;
	}
	{
		const char *test_str;
		const char *talloc_str;
		PyObject *unicode = NULL;
		if (PyUnicode_Check(value)) {
			unicode = PyUnicode_AsEncodedString(value, "utf-8", "ignore");
			if (unicode == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			test_str = PyBytes_AS_STRING(unicode);
		} else if (PyBytes_Check(value)) {
			test_str = PyBytes_AS_STRING(value);
		} else {
			PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(value)->tp_name);
			return -1;
		}
		talloc_str = talloc_strdup(pytalloc_get_mem_ctx(py_obj), test_str);
		if (unicode != NULL) {
			Py_DECREF(unicode);
		}
		if (talloc_str == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->signature = talloc_str;
	}
	return 0;
}

static PyObject *py_preg_header_get_version(PyObject *obj, void *closure)
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(obj);
	PyObject *py_version;
	py_version = PyLong_FromUnsignedLongLong((uint32_t)object->version);
	return py_version;
}

static int py_preg_header_set_version(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->version");
		return -1;
	}
	{
		const unsigned long long uint_max = ndr_sizeof2uintmax(sizeof(object->version));
		if (PyLong_Check(value)) {
			unsigned long long test_var;
			test_var = PyLong_AsUnsignedLongLong(value);
			if (PyErr_Occurred() != NULL) {
				return -1;
			}
			if (test_var > uint_max) {
				PyErr_Format(PyExc_OverflowError, "Expected type %s within range 0 - %llu, got %llu",\
				  PyLong_Type.tp_name, uint_max, test_var);
				return -1;
			}
			object->version = test_var;
		} else {
			PyErr_Format(PyExc_TypeError, "Expected type %s",\
			  PyLong_Type.tp_name);
			return -1;
		}
	}
	return 0;
}

static PyGetSetDef py_preg_header_getsetters[] = {
	{
		.name = discard_const_p(char, "signature"),
		.get = py_preg_header_get_signature,
		.set = py_preg_header_set_signature,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint8")
	},
	{
		.name = discard_const_p(char, "version"),
		.get = py_preg_header_get_version,
		.set = py_preg_header_set_version,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint32")
	},
	{ .name = NULL }
};

static PyObject *py_preg_header_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct preg_header, type);
}

static PyObject *py_preg_header_ndr_pack(PyObject *py_obj,  PyObject *Py_UNUSED(ignored))
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(py_obj);
	PyObject *ret = NULL;
	DATA_BLOB blob;
	enum ndr_err_code err;
	TALLOC_CTX *tmp_ctx = talloc_new(pytalloc_get_mem_ctx(py_obj));
	if (tmp_ctx == NULL) {
		PyErr_SetNdrError(NDR_ERR_ALLOC);
		return NULL;
	}
	err = ndr_push_struct_blob(&blob, tmp_ctx, object, (ndr_push_flags_fn_t)ndr_push_preg_header);
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		TALLOC_FREE(tmp_ctx);
		PyErr_SetNdrError(err);
		return NULL;
	}

	ret = PyBytes_FromStringAndSize((char *)blob.data, blob.length);
	TALLOC_FREE(tmp_ctx);
	return ret;
}

static PyObject *py_preg_header_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob = {.data = NULL, .length = 0};
	Py_ssize_t blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, PYARG_BYTES_LEN "|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_header);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_header);
	}
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_preg_header_ndr_print(PyObject *py_obj, PyObject *Py_UNUSED(ignored))
{
	struct preg_header *object = (struct preg_header *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_preg_header, "preg_header", object);
	ret = PyUnicode_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_preg_header_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_preg_header_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", PY_DISCARD_FUNC_SIG(PyCFunction,py_preg_header_ndr_unpack), METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_preg_header_ndr_print, METH_NOARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject preg_header_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "preg.header",
	.tp_getset = py_preg_header_getsetters,
	.tp_methods = py_preg_header_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = py_preg_header_new,
};


static PyObject *py_preg_file_get_header(PyObject *obj, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(obj);
	PyObject *py_header;
	py_header = pytalloc_reference_ex(&preg_header_Type, pytalloc_get_mem_ctx(obj), &object->header);
	return py_header;
}

static int py_preg_file_set_header(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->header");
		return -1;
	}
	PY_CHECK_TYPE(&preg_header_Type, value, return -1;);
	if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
		PyErr_NoMemory();
		return -1;
	}
	object->header = *(struct preg_header *)pytalloc_get_ptr(value);
	return 0;
}

static PyObject *py_preg_file_get_num_entries(PyObject *obj, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(obj);
	PyObject *py_num_entries;
	py_num_entries = PyLong_FromUnsignedLongLong((uint32_t)object->num_entries);
	return py_num_entries;
}

static int py_preg_file_set_num_entries(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->num_entries");
		return -1;
	}
	{
		const unsigned long long uint_max = ndr_sizeof2uintmax(sizeof(object->num_entries));
		if (PyLong_Check(value)) {
			unsigned long long test_var;
			test_var = PyLong_AsUnsignedLongLong(value);
			if (PyErr_Occurred() != NULL) {
				return -1;
			}
			if (test_var > uint_max) {
				PyErr_Format(PyExc_OverflowError, "Expected type %s within range 0 - %llu, got %llu",\
				  PyLong_Type.tp_name, uint_max, test_var);
				return -1;
			}
			object->num_entries = test_var;
		} else {
			PyErr_Format(PyExc_TypeError, "Expected type %s",\
			  PyLong_Type.tp_name);
			return -1;
		}
	}
	return 0;
}

static PyObject *py_preg_file_get_entries(PyObject *obj, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(obj);
	PyObject *py_entries;
	py_entries = PyList_New(object->num_entries);
	if (py_entries == NULL) {
		return NULL;
	}
	{
		int entries_cntr_0;
		for (entries_cntr_0 = 0; entries_cntr_0 < (object->num_entries); entries_cntr_0++) {
			PyObject *py_entries_0;
			py_entries_0 = pytalloc_reference_ex(&preg_entry_Type, object->entries, &object->entries[entries_cntr_0]);
			PyList_SetItem(py_entries, entries_cntr_0, py_entries_0);
		}
	}
	return py_entries;
}

static int py_preg_file_set_entries(PyObject *py_obj, PyObject *value, void *closure)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	if (value == NULL) {
		PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->entries");
		return -1;
	}
	PY_CHECK_TYPE(&PyList_Type, value, return -1;);
	{
		int entries_cntr_0;
		object->entries = talloc_array_ptrtype(pytalloc_get_mem_ctx(py_obj), object->entries, PyList_GET_SIZE(value));
		if (!object->entries) { return -1;; }
		talloc_set_name_const(object->entries, "ARRAY: object->entries");
		for (entries_cntr_0 = 0; entries_cntr_0 < PyList_GET_SIZE(value); entries_cntr_0++) {
			if (PyList_GET_ITEM(value, entries_cntr_0) == NULL) {
				PyErr_Format(PyExc_AttributeError, "Cannot delete NDR object: struct object->entries[entries_cntr_0]");
				return -1;
			}
			PY_CHECK_TYPE(&preg_entry_Type, PyList_GET_ITEM(value, entries_cntr_0), return -1;);
			if (talloc_reference(object->entries, pytalloc_get_mem_ctx(PyList_GET_ITEM(value, entries_cntr_0))) == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			object->entries[entries_cntr_0] = *(struct preg_entry *)pytalloc_get_ptr(PyList_GET_ITEM(value, entries_cntr_0));
		}
	}
	return 0;
}

static PyGetSetDef py_preg_file_getsetters[] = {
	{
		.name = discard_const_p(char, "header"),
		.get = py_preg_file_get_header,
		.set = py_preg_file_set_header,
		.doc = discard_const_p(char, "PIDL-generated element of base type preg_header")
	},
	{
		.name = discard_const_p(char, "num_entries"),
		.get = py_preg_file_get_num_entries,
		.set = py_preg_file_set_num_entries,
		.doc = discard_const_p(char, "PIDL-generated element of base type uint32")
	},
	{
		.name = discard_const_p(char, "entries"),
		.get = py_preg_file_get_entries,
		.set = py_preg_file_set_entries,
		.doc = discard_const_p(char, "PIDL-generated element of base type preg_entry")
	},
	{ .name = NULL }
};

static PyObject *py_preg_file_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct preg_file, type);
}

static PyObject *py_preg_file_ndr_pack(PyObject *py_obj,  PyObject *Py_UNUSED(ignored))
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	PyObject *ret = NULL;
	DATA_BLOB blob;
	enum ndr_err_code err;
	TALLOC_CTX *tmp_ctx = talloc_new(pytalloc_get_mem_ctx(py_obj));
	if (tmp_ctx == NULL) {
		PyErr_SetNdrError(NDR_ERR_ALLOC);
		return NULL;
	}
	err = ndr_push_struct_blob(&blob, tmp_ctx, object, (ndr_push_flags_fn_t)ndr_push_preg_file);
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		TALLOC_FREE(tmp_ctx);
		PyErr_SetNdrError(err);
		return NULL;
	}

	ret = PyBytes_FromStringAndSize((char *)blob.data, blob.length);
	TALLOC_FREE(tmp_ctx);
	return ret;
}

static PyObject *py_preg_file_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob = {.data = NULL, .length = 0};
	Py_ssize_t blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, PYARG_BYTES_LEN "|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_file);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_preg_file);
	}
	if (!NDR_ERR_CODE_IS_SUCCESS(err)) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_preg_file_ndr_print(PyObject *py_obj, PyObject *Py_UNUSED(ignored))
{
	struct preg_file *object = (struct preg_file *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_preg_file, "preg_file", object);
	ret = PyUnicode_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_preg_file_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_preg_file_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", PY_DISCARD_FUNC_SIG(PyCFunction,py_preg_file_ndr_unpack), METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_preg_file_ndr_print, METH_NOARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject preg_file_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "preg.file",
	.tp_getset = py_preg_file_getsetters,
	.tp_methods = py_preg_file_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = py_preg_file_new,
};


const struct PyNdrRpcMethodDef py_ndr_preg_methods[] = {
	{0}
};

static PyObject *interface_preg_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_preg);
}

#define PY_DOC_PREG "PReg structure"
static PyTypeObject preg_InterfaceType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "preg.preg",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "preg(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_PREG,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_preg_new,
};

static PyObject *syntax_preg_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_syntax_init_helper(type, args, kwargs, &ndr_table_preg.syntax_id);
}

#define PY_DOC_PREG_SYNTAX "PReg structure"
static PyTypeObject preg_SyntaxType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "preg.preg_abstract_syntax",
	.tp_doc = "preg_abstract_syntax()\n"PY_DOC_PREG_SYNTAX,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = syntax_preg_new,
};

static PyMethodDef preg_methods[] = {
	{ NULL, NULL, 0, NULL }
};

static struct PyModuleDef moduledef = {
	PyModuleDef_HEAD_INIT,
	.m_name = "preg",
	.m_doc = "preg DCE/RPC",
	.m_size = -1,
	.m_methods = preg_methods,
};
MODULE_INIT_FUNC(preg)
{
	PyObject *m = NULL;
	PyObject *dep_samba_dcerpc_misc = NULL;
	PyObject *dep_talloc = NULL;
	PyObject *dep_samba_dcerpc_base = NULL;

	dep_samba_dcerpc_misc = PyImport_ImportModule("samba.dcerpc.misc");
	if (dep_samba_dcerpc_misc == NULL)
		goto out;

	dep_talloc = PyImport_ImportModule("talloc");
	if (dep_talloc == NULL)
		goto out;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		goto out;

	winreg_Data_GPO_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_misc, "winreg_Data_GPO");
	if (winreg_Data_GPO_Type == NULL)
		goto out;

	BaseObject_Type = (PyTypeObject *)PyObject_GetAttrString(dep_talloc, "BaseObject");
	if (BaseObject_Type == NULL)
		goto out;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		goto out;

	ndr_syntax_id_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_misc, "ndr_syntax_id");
	if (ndr_syntax_id_Type == NULL)
		goto out;

	preg_entry_Type.tp_base = BaseObject_Type;
	preg_entry_Type.tp_basicsize = pytalloc_BaseObject_size();

	preg_header_Type.tp_base = BaseObject_Type;
	preg_header_Type.tp_basicsize = pytalloc_BaseObject_size();

	preg_file_Type.tp_base = BaseObject_Type;
	preg_file_Type.tp_basicsize = pytalloc_BaseObject_size();

	preg_InterfaceType.tp_base = ClientConnection_Type;

	preg_SyntaxType.tp_base = ndr_syntax_id_Type;
	preg_SyntaxType.tp_basicsize = pytalloc_BaseObject_size();

	if (PyType_Ready(&preg_entry_Type) < 0)
		goto out;
	if (PyType_Ready(&preg_header_Type) < 0)
		goto out;
	if (PyType_Ready(&preg_file_Type) < 0)
		goto out;
	if (PyType_Ready(&preg_InterfaceType) < 0)
		goto out;
	if (PyType_Ready(&preg_SyntaxType) < 0)
		goto out;
	if (!PyInterface_AddNdrRpcMethods(&preg_InterfaceType, py_ndr_preg_methods))
		return NULL;

#ifdef PY_ENTRY_PATCH
	PY_ENTRY_PATCH(&preg_entry_Type);
#endif
#ifdef PY_HEADER_PATCH
	PY_HEADER_PATCH(&preg_header_Type);
#endif
#ifdef PY_FILE_PATCH
	PY_FILE_PATCH(&preg_file_Type);
#endif
#ifdef PY_PREG_PATCH
	PY_PREG_PATCH(&preg_InterfaceType);
#endif
#ifdef PY_PREG_ABSTRACT_SYNTAX_PATCH
	PY_PREG_ABSTRACT_SYNTAX_PATCH(&preg_SyntaxType);
#endif
#ifdef PY_ABSTRACT_SYNTAX_PATCH
	PY_ABSTRACT_SYNTAX_PATCH(&preg_SyntaxType);
#endif

	m = PyModule_Create(&moduledef);
	if (m == NULL)
		goto out;

	Py_INCREF((PyObject *)(void *)&preg_entry_Type);
	PyModule_AddObject(m, "entry", (PyObject *)(void *)&preg_entry_Type);
	Py_INCREF((PyObject *)(void *)&preg_header_Type);
	PyModule_AddObject(m, "header", (PyObject *)(void *)&preg_header_Type);
	Py_INCREF((PyObject *)(void *)&preg_file_Type);
	PyModule_AddObject(m, "file", (PyObject *)(void *)&preg_file_Type);
	Py_INCREF((PyObject *)(void *)&preg_InterfaceType);
	PyModule_AddObject(m, "preg", (PyObject *)(void *)&preg_InterfaceType);
	Py_INCREF((PyObject *)(void *)&preg_SyntaxType);
	PyModule_AddObject(m, "preg_abstract_syntax", (PyObject *)(void *)&preg_SyntaxType);
	Py_INCREF((PyObject *)(void *)&preg_SyntaxType);
	PyModule_AddObject(m, "abstract_syntax", (PyObject *)(void *)&preg_SyntaxType);
#ifdef PY_MOD_PREG_PATCH
	PY_MOD_PREG_PATCH(m);
#endif
	out:
	Py_XDECREF(dep_samba_dcerpc_misc);
	Py_XDECREF(dep_talloc);
	Py_XDECREF(dep_samba_dcerpc_base);
	return m;

}
