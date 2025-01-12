/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_ntp_signd
#define _PIDL_HEADER_ntp_signd

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#ifndef _HEADER_ntp_signd
#define _HEADER_ntp_signd

#define NTP_SIGND_PROTOCOL_VERSION_0	( 0 )
enum ntp_signd_op
#ifndef USE_UINT_ENUMS
 {
	SIGN_TO_CLIENT=(int)(0),
	ASK_SERVER_TO_SIGN=(int)(1),
	CHECK_SERVER_SIGNATURE=(int)(2),
	SIGNING_SUCCESS=(int)(3),
	SIGNING_FAILURE=(int)(4)
}
#else
 { __do_not_use_enum_ntp_signd_op=0x7FFFFFFF}
#define SIGN_TO_CLIENT ( 0 )
#define ASK_SERVER_TO_SIGN ( 1 )
#define CHECK_SERVER_SIGNATURE ( 2 )
#define SIGNING_SUCCESS ( 3 )
#define SIGNING_FAILURE ( 4 )
#endif
;

struct sign_request {
	uint32_t version;/* [value(NTP_SIGND_PROTOCOL_VERSION_0)] */
	enum ntp_signd_op op;
	uint16_t packet_id;
	uint32_t key_id;/* [flag(LIBNDR_FLAG_LITTLE_ENDIAN)] */
	DATA_BLOB packet_to_sign;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [flag(LIBNDR_FLAG_BIGENDIAN),public] */;

struct signed_reply {
	uint32_t version;/* [value(NTP_SIGND_PROTOCOL_VERSION_0)] */
	enum ntp_signd_op op;
	uint32_t packet_id;
	DATA_BLOB signed_packet;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [flag(LIBNDR_FLAG_BIGENDIAN),public] */;

#endif /* _HEADER_ntp_signd */
#endif /* _PIDL_HEADER_ntp_signd */
