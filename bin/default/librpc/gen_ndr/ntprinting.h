/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_ntprinting
#define _PIDL_HEADER_ntprinting

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#ifndef _HEADER_ntprinting
#define _HEADER_ntprinting

struct ntprinting_form {
	uint32_t position;
	uint32_t flag;
	uint32_t width;
	uint32_t length;
	uint32_t left;
	uint32_t top;
	uint32_t right;
	uint32_t bottom;
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct ntprinting_driver {
	uint32_t string_flags;/* [skip_noinit] */
	uint32_t version;
	const char * name;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * environment;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * driverpath;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * datafile;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * configfile;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * helpfile;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * monitorname;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * defaultdatatype;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char ** dependent_files;/* [flag((ndr_ntprinting_string_flags(r->string_flags)&~LIBNDR_FLAG_STR_NULLTERM)|LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING)] */
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct ntprinting_devicemode {
	uint32_t string_flags;/* [skip_noinit] */
	const char * devicename;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * formname;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	uint16_t specversion;
	uint16_t driverversion;
	uint16_t size;
	uint16_t driverextra;
	uint16_t orientation;
	uint16_t papersize;
	uint16_t paperlength;
	uint16_t paperwidth;
	uint16_t scale;
	uint16_t copies;
	uint16_t defaultsource;
	uint16_t printquality;
	uint16_t color;
	uint16_t duplex;
	uint16_t yresolution;
	uint16_t ttoption;
	uint16_t collate;
	uint16_t logpixels;
	uint32_t fields;
	uint32_t bitsperpel;
	uint32_t pelswidth;
	uint32_t pelsheight;
	uint32_t displayflags;
	uint32_t displayfrequency;
	uint32_t icmmethod;
	uint32_t icmintent;
	uint32_t mediatype;
	uint32_t dithertype;
	uint32_t reserved1;
	uint32_t reserved2;
	uint32_t panningwidth;
	uint32_t panningheight;
	DATA_BLOB *nt_dev_private;/* [unique] */
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct ntprinting_printer_data {
	uint32_t string_flags;/* [skip_noinit] */
	uint32_t ptr;
	const char * name;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	uint32_t type;
	DATA_BLOB data;
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct ntprinting_printer_info {
	uint32_t string_flags;/* [skip_noinit] */
	uint32_t attributes;
	uint32_t priority;
	uint32_t default_priority;
	uint32_t starttime;
	uint32_t untiltime;
	uint32_t status;
	uint32_t cjobs;
	uint32_t averageppm;
	uint32_t changeid;
	uint32_t c_setprinter;
	uint32_t setuptime;
	const char * servername;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * printername;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * sharename;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * portname;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * drivername;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * comment;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * location;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * sepfile;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * printprocessor;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * datatype;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
	const char * parameters;/* [flag(ndr_ntprinting_string_flags(r->string_flags))] */
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct ntprinting_printer {
	struct ntprinting_printer_info info;
	struct ntprinting_devicemode *devmode;/* [unique] */
	uint32_t count;
	struct ntprinting_printer_data *printer_data;
}/* [flag(LIBNDR_FLAG_NOALIGN),nopull,public] */;

#endif /* _HEADER_ntprinting */
#endif /* _PIDL_HEADER_ntprinting */
