#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libsmbclient.h"
#include "get_auth_data_fn.h"

enum acl_mode
{
	SMB_ACL_LIST,
	SMB_ACL_GET,
	SMB_ACL_SET,
	SMB_ACL_DELETE,
	SMB_ACL_MODIFY,
	SMB_ACL_ADD,
	SMB_ACL_CHOWN,
	SMB_ACL_CHGRP
};


int main(int argc, const char *argv[])
{
	int opt;
	int flags = 0;
	int debug = 0;
	int numeric = 0;
	int stat_and_retry = 0;
	int full_time_names = 0;
	enum acl_mode mode = SMB_ACL_LIST;
	static const char *the_acl = NULL;
	int ret;
	char *p;
	const char *debugstr;
	char path[1024];
	char value[1024];
	poptContext pc;
	struct stat st;
	struct poptOption long_options[] =
	{
		POPT_AUTOHELP
		{
			.longName   = "numeric",
			.shortName  = 'n',
			.argInfo    = POPT_ARG_NONE,
			.arg        = &numeric,
			.val        = 1,
			.descrip    = "Don't resolve sids or masks to names"
		},
		{
			.longName   = "debug",
			.shortName  = 'd',
			.argInfo    = POPT_ARG_INT,
			.arg        = &debug,
			.val        = 0,
			.descrip    = "Set debug level (0-100)"
		},
		{
			.longName   = "full_time_names",
			.shortName  = 'f',
			.argInfo    = POPT_ARG_NONE,
			.arg        = &full_time_names,
			.val        = 1,
			.descrip    = "Use new style xattr names, which include CREATE_TIME"
		},
		{
			.longName   = "delete",
			.shortName  = 'D',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'D',
			.descrip    = "Delete an acl",
			.argDescrip = "ACL"
		},
		{
			.longName   = "modify",
			.shortName  = 'M',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'M',
			.descrip    = "Modify an acl",
			.argDescrip = "ACL"
		},
		{
			.longName   = "add",
			.shortName  = 'a',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'a',
			.descrip    = "Add an acl",
			.argDescrip = "ACL"
		},
		{
			.longName   = "set",
			.shortName  = 'S',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'S',
			.descrip    = "Set acls",
			.argDescrip = "ACLS"
		},
		{
			.longName   = "chown",
			.shortName  = 'C',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'C',
			.descrip    = "Change ownership of a file",
			.argDescrip = "USERNAME"
		},
		{
			.longName   = "chgrp",
			.shortName  = 'G',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'G',
			.descrip    = "Change group ownership of a file",
			.argDescrip = "GROUPNAME"
		},
		{
			.longName   = "get",
			.shortName  = 'g',
			.argInfo    = POPT_ARG_STRING,
			.arg        = NULL,
			.val        = 'g',
			.descrip    = "Get a specific acl attribute",
			.argDescrip = "ACL"
		},
		{
			.longName   = "stat_and_retry",
			.shortName  = 'R',
			.argInfo    = POPT_ARG_NONE,
			.arg        = &stat_and_retry,
			.val        = 1,
			.descrip    = "After 'get' do 'stat' and another 'get'"
		},
		POPT_TABLEEND
	};

	setbuf(stdout, NULL);

	pc = poptGetContext("smbcacls", argc, argv, long_options, 0);

	poptSetOtherOptionHelp(pc, "smb://server1/share1/filename");

	while ((opt = poptGetNextOpt(pc)) != -1) {
		switch (opt) {
		case 'S':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_SET;
			break;

		case 'D':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_DELETE;
			break;

		case 'M':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_MODIFY;
			break;

		case 'a':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_ADD;
			break;

		case 'g':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_GET;
			break;

		case 'C':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_CHOWN;
			break;

		case 'G':
			the_acl = strdup(poptGetOptArg(pc));
			mode = SMB_ACL_CHGRP;
			break;
		}
	}

	/* Make connection to server */
	if(!poptPeekArg(pc)) {
		poptPrintUsage(pc, stderr, 0);
		return 1;
	}

	strncpy(path, poptGetArg(pc), sizeof(path));
	path[sizeof(path)-1] = '\0';

	if (smbc_init(get_auth_data_fn, debug) != 0)
	{
		printf("Could not initialize smbc_ library\n");
		return 1;
	}

	if (full_time_names) {
		SMBCCTX *context = smbc_set_context(NULL);
		smbc_setOptionFullTimeNames(context, 1);
	}

	/* Perform requested action */

	switch(mode)
	{
	case SMB_ACL_LIST:
		ret = smbc_listxattr(path, value, sizeof(value)-2);
		if (ret < 0)
		{
			printf("Could not get attribute list for [%s] %d: %s\n",
					path, errno, strerror(errno));
			return 1;
		}

		/*
		 * The list of attributes has a series of null-terminated strings.
		 * The list of strings terminates with an extra null byte, thus two in
		 * a row.  Ensure that our buffer, which is conceivably shorter than
		 * the list of attributes, actually ends with two null bytes in a row.
		 */
		value[sizeof(value) - 2] = '\0';
		value[sizeof(value) - 1] = '\0';
		printf("Supported attributes:\n");
		for (p = value; *p; p += strlen(p) + 1)
		{
			printf("\t%s\n", p);
		}
		break;

	case SMB_ACL_GET:
		do
		{
			if (the_acl == NULL)
			{
				if (numeric)
				{
					the_acl = "system.*";
				}
				else
				{
					the_acl = "system.*+";
				}
			}
			ret = smbc_getxattr(path, the_acl, value, sizeof(value));
			if (ret < 0)
			{
				printf("Could not get attributes for [%s] %d: %s\n",
						path, errno, strerror(errno));
				return 1;
			}

			printf("Attributes for [%s] are:\n%s\n", path, value);

			if (stat_and_retry)
			{
				if (smbc_stat(path, &st) < 0)
				{
					perror("smbc_stat");
					return 1;
				}
			}

			--stat_and_retry;
		} while (stat_and_retry >= 0);
		break;

	case SMB_ACL_ADD:
		flags = SMBC_XATTR_FLAG_CREATE;
		debugstr = "add attributes";
		goto do_set;

	case SMB_ACL_MODIFY:
		flags = SMBC_XATTR_FLAG_REPLACE;
		debugstr = "modify attributes";
		goto do_set;

	case SMB_ACL_CHOWN:
		snprintf(value, sizeof(value),
				"system.nt_sec_desc.owner%s:%s",
				numeric ? "" : "+", the_acl);
		the_acl = value;
		debugstr = "chown owner";
		goto do_set;

	case SMB_ACL_CHGRP:
		snprintf(value, sizeof(value),
				"system.nt_sec_desc.group%s:%s",
				numeric ? "" : "+", the_acl);
		the_acl = value;
		debugstr = "change group";
		goto do_set;

	case SMB_ACL_SET:
		flags = 0;
		debugstr = "set attributes";

do_set:
		if ((p = strchr(the_acl, ':')) == NULL)
		{
			printf("Missing value.  ACL must be name:value pair\n");
			return 1;
		}

		*p++ = '\0';

		ret = smbc_setxattr(path, the_acl, p, strlen(p), flags);
		if (ret < 0)
		{
			printf("Could not %s for [%s] %d: %s\n",
					debugstr, path, errno, strerror(errno));
			return 1;
		}
		break;

	case SMB_ACL_DELETE:
		ret = smbc_removexattr(path, the_acl);
		if (ret < 0)
		{
			printf("Could not remove attribute %s for [%s] %d:%s\n",
					the_acl, path, errno, strerror(errno));
			return 1;
		}
		break;

	default:
		printf("operation not yet implemented\n");
		break;
	}

	return 0;
}
