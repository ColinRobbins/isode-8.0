/* bind.c - */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/quipu/dish/RCS/bind.c,v 9.0 1992/06/16 12:35:39 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/quipu/dish/RCS/bind.c,v 9.0 1992/06/16 12:35:39 isode Rel $
 *
 *
 * $Log: bind.c,v $
 * Revision 9.0  1992/06/16  12:35:39  isode
 * Release 8.0
 *
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */


#include <signal.h>
#include "manifest.h"
#include "quipu/util.h"
#include <fcntl.h>
#include <sys/stat.h>
#include "quipu/dua.h"
#include "quipu/name.h"
#include "quipu/bind.h"
#include "quipu/dsp.h"
#include "quipu/ds_error.h"
#include "quipu/entry.h"
#include "quipu/read.h"
#include "tailor.h"
#include "pepsy.h"
#include "quipu/DAS-types.h"

#include "osisec-stub.h"

extern DN       fixed_pos;
DN	        user_name;

#define	OPT	(!frompipe || rps -> ps_byteno == 0 ? opt : rps)
#define	RPS	(!frompipe || opt -> ps_byteno == 0 ? rps : opt)
extern	char	frompipe;
extern	PS	opt, rps;

extern char	retpipe[],
	   inbuf [],
	   bound;

extern char	dad_flag;

extern int	dsap_ad;
extern unsigned	connect_time,
	   cache_time;

extern Entry database_root;

static char	username [LINESIZE];
static char	password [LINESIZE];
static int	auth_type = DBA_AUTH_SIMPLE;
static char	first_bind = TRUE;

char		neverefer = FALSE;

static struct ds_bind_arg bindarg;
static struct ds_bind_arg bindresult;
static struct ds_bind_error binderr;

static int 	main_dsa_id;
static int	referral_dsa;

#ifndef NO_STATS
extern LLog * log_stat;
#endif
extern LLog * log_dsap;

extern int parent_pid;
static unsigned waiting = 0;

extern char *new_version();
extern unsigned long hash_passwd();
extern char *hash2str();
extern struct certificate *cert_cpy();
extern struct SecurityServices *dsap_security;
static int protect_password();
static int sign_bindarg();

/* ARGSUSED */
SFD alarm_sig (sd)
int sd;
{
	SFD dish_quit ();

	if (frompipe && (parent_pid != 0))
		if (kill (parent_pid,0) == -1) {
			/* invoking shell gone - exit */
			dish_quit (SIGHUP);
		}


	if (bound) {
		dap_unbind (main_dsa_id);
#ifndef NO_STATS
		LLOG (log_stat,LLOG_NOTICE,("Connection closed"));
#endif
		bound = FALSE;
		if (referral_dsa != 0) {
			dap_unbind (referral_dsa);
			referral_dsa = 0;
		}
	}

	waiting += connect_time;
	if (frompipe && (waiting >= cache_time))
		dish_quit (SIGHUP);

	signal (SIGALRM, alarm_sig);
	alarm (connect_time);
}

int
set_alarm (void) {
	waiting = 0;
	signal (SIGALRM, alarm_sig);
	alarm (connect_time);
}

/* ARGSUSED */
SFD bind_sig (sd)
int sd;
{
	extern jmp_buf  dish_env;

	ps_print (OPT,"Bind timeout\n");
	if (referral_dsa != 0) {
		referral_dsa = 0;
		dsap_ad = main_dsa_id;
	}
	longjmp (dish_env,1);
}

int
bind_alarm (void) {
	signal (SIGALRM, bind_sig);
	alarm (connect_time);
}

int
isnumeric (char *ptr) {
	if ((ptr == NULLCP) || (*ptr == 0))
		return FALSE;

	while (*ptr)
		if (! isdigit (*ptr++) )
			return FALSE;

	return TRUE;
}

int
call_bind (int argc, char **argv) {
	int 	x;
	char    noconnect = FALSE;
	static  char    bdsa  [LINESIZE], save_bdsa[LINESIZE];
	char   *save_address;
	char   *save_name;
	extern  char * dsa_address,
			* myname;
	FILE    *fp;
	char    buf[BUFSIZ];
	DN	newdn, dsadn;
	extern  char * tailfile;
	extern DN sequence_dn ();
	char got_name = FALSE;
	char got_pass = FALSE;

	bdsa[0] = 0;
	save_address = dsa_address;
	save_name = myname;

	for (x=1; x<argc; x++) {
		if (test_arg (argv[x], "-noconnect",3))
			noconnect = TRUE;
#ifdef PDU_DUMP
		else if (test_arg (argv[x], "-pdus",2)) {
			if (++x == argc) {
				ps_print (OPT,"PDU file name missing\n");
				Usage (argv[0]);
				return (NOTOK);
			}
			ps_printf (RPS,"Dumping PDUs in directory %s\n",argv[x]);
			pdu_dump_init (argv[x]);
		}
#endif
		else if (test_arg (argv[x], "-user",1)) {
			got_name = TRUE;
			if ((++x == argc) || (*argv[x] == '-')) {
				x--;
				*username = 0;
			} else
				strcpy (username,argv[x]);
		} else if (test_arg (argv[x], "-pipe",2)) {
			if (strcmp (argv[0],"dish") == 0)
				ps_print (OPT,"Sorry... '-pipe' must be the first argument to dish.\n");
			else
				Usage (argv[0]);
			return (NOTOK);
		} else if (test_arg (argv[x], "-norefer",3))
			neverefer = TRUE;
		else if (test_arg (argv[x], "-refer",1))
			neverefer = FALSE;
		/* these flags select the mode of authentication only */
		else if (test_arg (argv[x],"-noauthentication",3))
			auth_type = DBA_AUTH_NONE;
		else if (test_arg (argv[x], "-protected", 3))
			auth_type = DBA_AUTH_PROTECTED;
		else if (test_arg (argv[x], "-simple", 3))
			auth_type = DBA_AUTH_SIMPLE;
		else if (test_arg (argv[x], "-strong", 3))
			auth_type = DBA_AUTH_STRONG;
		/* -password sets the `key', whatever the mode  */
		else if (test_arg (argv[x], "-password",2)) {
			got_pass = TRUE;
			if ((++x == argc)  || (*argv[x] == '-')) {
				x--;
				*password = 0;
			} else {
				int i;
				strcpy (password,argv[x]);
				for (i=0; i< (int)strlen(password) ; i++)
					if ( i < 4 )
						argv[x][i] = 'X';
					else
						argv[x][i] = 0;

			}
		} else if (test_arg (argv[x], "-call",1)) {
			if (++x == argc) {
				ps_print (OPT,"dsa name missing\n");
				Usage (argv[0]);
				return (NOTOK);
			}
			strcpy (bdsa,argv[x]);
		} else {
			/* assume its the user name */
			if (got_name) {
				ps_print (OPT,"One user name only please!\n");
				Usage (argv[0]);
				return (NOTOK);
			}
			got_name = TRUE;
			strcpy (username,argv[x]);
			if (*username == '-') {
				ps_printf (OPT,"Unknown option %s\n",username);
				username[0] = 0;
				Usage (argv[0]);
				return (NOTOK);
			}
		}
	}


	if (noconnect)
		return (OK);

	if (isnumeric (username)) {
		PS	    ps;

		if ((newdn = sequence_dn (atoi (username))) == NULLDN) {
			ps_printf (OPT,"Invalid sequence in username %s\n",username);
			Usage (argv[0]);
			return (NOTOK);
		}
		if ((ps = ps_alloc (str_open)) == NULLPS) {
			ps_printf (OPT, "Unable to expand sequence: out of memory\n");
			return NOTOK;
		}
		if (str_setup (ps, username, sizeof username - 2, 1) == NOTOK) {
			ps_printf (OPT, "Unable to expand sequence: %s\n",
					   ps_error (ps -> ps_errno));
			ps_free (ps);
			return NOTOK;
		}
		dn_print (ps, newdn, EDBOUT);
		ps_print (ps, " ");
		*--ps -> ps_ptr = NULL, ps -> ps_cnt++;

		ps_free (ps);
	} else
		newdn = NULLDN;

	if ((got_name && ! got_pass) || (*password == 0)) {
		bindarg.dba_passwd_len = 0;
		bindarg.dba_passwd[0]  = 0;
		if ((*username != 0) && (auth_type != DBA_AUTH_NONE)) {
			get_password (username, password);
			strcpy(&bindarg.dba_passwd[0], password);
			bindarg.dba_passwd_len = strlen	(&bindarg.dba_passwd[0]);
		}
	} else {
		bindarg.dba_passwd_len = strlen (password);
		strcpy (bindarg.dba_passwd, password);
	}

	if ((bindarg.dba_passwd_len == 0) && (auth_type != DBA_AUTH_STRONG))
		auth_type = DBA_AUTH_NONE;

	if (*username == 0) {
		bindarg.dba_dn = NULLDN;
		/* Don't need credentials to bind as NULLDN! */
		auth_type = DBA_AUTH_NONE;
	} else if (newdn)
		bindarg.dba_dn = dn_cpy (newdn);
	else {
		if ((bindarg.dba_dn = str2dn (username[0] != '@' ? username
									  : username + 1))
				== NULLDN) {
			ps_printf (OPT,"Invalid DN for username: %s\n",username);
			Usage (argv[0]);
			return (NOTOK);
		}
	}

	/* prepare credentials */
	bindarg.dba_auth_type = auth_type;
	switch (auth_type) {
	case DBA_AUTH_NONE:
	case DBA_AUTH_SIMPLE:
		break;
	case DBA_AUTH_PROTECTED:
		protect_password();
		break;
	case DBA_AUTH_STRONG:
		if (sign_bindarg() != OK)
			bindarg.dba_auth_type = DBA_AUTH_NONE;
		break;
	}

	if (isnumeric (bdsa) && (dsadn = sequence_dn (atoi (bdsa)))) {
		PS	ps;

		dsadn = dn_cpy (dsadn);
		if ((ps = ps_alloc (str_open)) == NULLPS) {
			ps_printf (OPT, "Unable to expand sequence: out of memory\n");
			return NOTOK;
		}
		if (str_setup (ps, bdsa, sizeof bdsa - 2, 1) == NOTOK) {
			ps_printf (OPT, "Unable to expand sequence: %s\n",
					   ps_error (ps -> ps_errno));
			ps_free (ps);
			return NOTOK;
		}
		dn_print (ps, dsadn, EDBOUT);
		ps_print (ps, " ");
		*--ps -> ps_ptr = NULL, ps -> ps_cnt++;

		ps_free (ps);
	} else {
		int	    old_ppe;
		extern int print_parse_errors;

		old_ppe = print_parse_errors, print_parse_errors = FALSE;
		dsadn = *bdsa == '@' && index (bdsa + 1, '=') ? str2dn (bdsa + 1)
				: NULLDN;
		print_parse_errors = old_ppe;
	}

	if (dsadn) {
		int	    gotit = 0;
		Entry   e;
		static AttributeType t_addr = NULL;

		if (!t_addr && !(t_addr = str2AttrT ("presentationAddress")))
			fatal (-100, "presentationAddress: invalid attribute type");

		if ((!(e = local_find_entry (dsadn, FALSE)) || !e -> e_lock)
				&& bound
				&& rebind () == OK) {
			struct ds_read_arg read_arg;
			struct ds_read_result read_result;
			struct DSError read_error;

			bzero ((char *) &read_arg, sizeof read_arg);

			read_arg.rda_object = dsadn;

			service_control (OPT, 0, NULLVP, &read_arg.rda_common);

			read_arg.rda_eis.eis_allattributes = FALSE;
			read_arg.rda_eis.eis_select = as_comp_new (AttrT_cpy (t_addr),
										  NULLAV,
										  NULLACL_INFO);
			read_arg.rda_eis.eis_infotypes = EIS_ATTRIBUTESANDVALUES;

			if (ds_read (&read_arg, &read_error, &read_result) == DS_OK) {
				cache_entry (&read_result.rdr_entry,
							 read_arg.rda_eis.eis_allattributes,
							 read_arg.rda_eis.eis_infotypes);
				entryinfo_comp_free (&read_result.rdr_entry, 0);
				e = local_find_entry (dsadn, FALSE);
			}
		}

		if (e) {
			Attr_Sequence attr;
			AV_Sequence avseq;

			for (attr = e -> e_attributes; attr; attr = attr -> attr_link)
				if (AttrT_cmp (attr -> attr_type, t_addr) == 0)
					break;
			if (attr && (avseq = attr -> attr_value)) {
				static char dsaddr[BUFSIZ];

				strcpy (myname = save_bdsa, bdsa);
				strcpy (dsa_address = dsaddr,
						paddr2str ((struct PSAPaddr *)
								   avseq -> avseq_av.av_struct,
								   NULLNA));
				gotit++;
			}
		}
		if (!gotit) {
			ps_printf (OPT,
					   "Unable to determine presentation address for @");
			dn_print (OPT, dsadn, EDBOUT);
			ps_printf (OPT, "\n");
			return NOTOK;
		}

		dn_free (dsadn), dsadn = NULL;
	} else
		/* now set dsa_address */
		if (bdsa[0] != 0) {
			strcpy (myname = save_bdsa, bdsa);
			dsa_address = NULLCP;

			/* read tailor file to get address */

			if( (fp = fopen(isodefile(tailfile, 0), "r")) == (FILE *)NULL) {
				LLOG (log_dsap,LLOG_FATAL,("can't open %s",tailfile));
				fatal (-72, "Cannot open tailor file");
			}

			while(fgets(buf, sizeof(buf), fp) != NULLCP)
				if ( (*buf != '#') && (*buf != '\n') )
					/* not a comment or blank */
					if (tai_string (buf) == NOTOK)
						DLOG (log_dsap,LLOG_DEBUG,("tai_string failed %s",buf));

			fclose(fp);

			if (dsa_address == NULLCP)
				dsa_address = myname;
		}

	if (bound)
		ds_unbind ();

	bound = FALSE;
	first_bind = FALSE;

	binderr.dbe_value = 0;
	bind_alarm ();

	if (secure_ds_bind (&bindarg, &binderr, &bindresult) != OK) {
		signal (SIGALRM, SIG_IGN);
		if (binderr.dbe_value == 0)
			ps_print (OPT, "*** Service error : Unable to contact DSA ***\n");
		else
			ds_bind_error(OPT, &binderr);

#ifdef DEBUG
		if (binderr.dbe_cc)
			ps_printf (OPT, "%s\n", binderr.dbe_data);
#endif

		dsa_address = save_address;
		myname = save_name;
		return (NOTOK);
	}
	signal (SIGALRM, SIG_IGN);
	main_dsa_id = dsap_ad;

#ifndef NO_STATS
	LLOG (log_stat,LLOG_NOTICE,("Bound '%s' to '%s'",username,myname));
#endif

	bound = TRUE;
	user_name = bindarg.dba_dn;

	return (OK);

}

int
rebind (void) {

	if (referral_dsa != 0) {
		dap_unbind (referral_dsa);
		referral_dsa = 0;
		dsap_ad = main_dsa_id;
	}

	if (first_bind) {
		char * buff = "bind";
		return (call_bind (1,&buff));
	}

	if (bound)
		return (OK);

	/* prepare credentials */
	bindarg.dba_auth_type = auth_type;
	switch (auth_type) {
	case DBA_AUTH_NONE:
	case DBA_AUTH_SIMPLE:
		break;
	case DBA_AUTH_PROTECTED:
		protect_password();
		break;
	case DBA_AUTH_STRONG:
		if (sign_bindarg() != OK)
			bindarg.dba_auth_type = DBA_AUTH_NONE;
		break;
	}

	binderr.dbe_value = 0;
	bind_alarm ();
	if (secure_ds_bind (&bindarg, &binderr, &bindresult) != OK) {
		signal (SIGALRM, SIG_IGN);
		if (binderr.dbe_value == 0)
			ps_print (OPT, "*** Service error: Unable to contact DSA ***\n");
		else
			ds_bind_error(OPT, &binderr);

#ifdef DEBUG
		if (binderr.dbe_cc)
			ps_printf (OPT, "%s\n", binderr.dbe_data);
#endif
		return (NOTOK);
	}
	signal (SIGALRM, SIG_IGN);
	main_dsa_id = dsap_ad;
#ifndef NO_STATS
	LLOG (log_stat,LLOG_NOTICE,("re-connect"));
#endif

	bound = TRUE;
	user_name = bindarg.dba_dn;
	return (OK);
}

int
referral_bind (struct PSAPaddr *addr) {
	if (referral_dsa != 0)
		dap_unbind (referral_dsa++);
	else
		referral_dsa = dsap_ad + 1;

	dsap_ad = referral_dsa;

	/* prepare credentials */
	bindarg.dba_auth_type = auth_type;
	switch (auth_type) {
	case DBA_AUTH_NONE:
	case DBA_AUTH_SIMPLE:
		break;
	case DBA_AUTH_PROTECTED:
		protect_password();
		break;
	case DBA_AUTH_STRONG:
		sign_bindarg();
		break;
	}

	binderr.dbe_value = 0;
	bind_alarm ();
	if (dap_bind (&dsap_ad, &bindarg, &binderr, &bindresult, addr) != OK) {
		signal (SIGALRM, SIG_IGN);
		if (binderr.dbe_value == 0)
			ps_print (OPT, "*** Service error : Unable to contact DSA ***\n");
		else
			ds_bind_error(OPT, &binderr);

#ifdef DEBUG
		if (binderr.dbe_cc)
			ps_printf (OPT, "%s\n", binderr.dbe_data);
#endif

		referral_dsa = 0;
		dsap_ad = main_dsa_id;
		return (0);
	}
	signal (SIGALRM, SIG_IGN);
	referral_dsa = dsap_ad;

#ifndef NO_STATS
	LLOG (log_stat,LLOG_NOTICE,("referral connect"));
#endif

	return (1);
}

int
call_unbind (int argc, char **argv) {
	int		x;
	char		noquit = FALSE;
	extern char	resbuf [];
	static int very_first_time = 1;

	for (x=1; x<argc; x++) {
		if (test_arg (argv[x], "-noquit",3))
			noquit = TRUE;
		else {
			Usage (argv[0]);
			return;
		}
	}
	if (!noquit)
		signal (SIGINT, SIG_DFL);

	if (bound) {
		dap_unbind (main_dsa_id);
		if (referral_dsa != 0) {
			dap_unbind (referral_dsa);
			referral_dsa = 0;
		}
	}

	bound = FALSE;

	if (! noquit) {
		if (frompipe)
			exit_pipe ();
		ps_free (opt);
		ps_free (rps);
		directory_free (database_root);	   /* clean /tmp files */
		exit (0);
	} else if (dad_flag && very_first_time) {
		very_first_time = 0;
		cache_time = 24 * 60 * 60;
	}
}

int
unbind_from_dsa (void) {
	if (bound) {
		dap_unbind (main_dsa_id);
		if (referral_dsa != 0) {
			dap_unbind (referral_dsa);
			referral_dsa = 0;
		}
	}

	bound = FALSE;
}

extern char no_rcfile;
static time_t rc_mod_time;
static char Dish_Home[LINESIZE];

int
user_tailor (void) {
	int		isenv;
	char           *part1;
	char           *part2;
	char           *getenv ();
	char           *home;

	FILE           *file;
	char            Read_in_Stuff[BUFSIZ];
	char           *p,
				   *TidyString();
	extern char    *local_dit;
	extern char	dishinit;
	struct	 stat	sbuf;

	*password = 0;
	*username = 0;

	set_sequence ("default");

	set_cmd_default ("modify","-dontusecopy");
	/* we dont want to make templates with copies */


	bzero ((char *)&bindarg, sizeof bindarg);
	bindarg.dba_version = DBA_VERSION_V1988;

	isenv = 0;
	if (home = getenv ("QUIPURC"))
		strcpy (Dish_Home, home), isenv = 1;
	else if (home = getenv ("HOME"))
		sprintf (Dish_Home, "%s/.quipurc", home);
	else
		strcpy (Dish_Home, "./.quipurc");

	if (no_rcfile)
		goto out;

	if (stat (Dish_Home,&sbuf) != 0) {
		if (isenv)
			goto no_dice;

		if (dishinit && !frompipe) {
			char cmd_buf [LINESIZE];
			int msk;

			ps_print (OPT,"Please wait whilst I initialise everything...\n");
			msk = umask (0111);
			strcpy (cmd_buf, isodefile ("new_quipurc", 1));
			if ((file = fopen (Dish_Home, "w")) == 0)
				return (OK);	/* cant make one */
			umask (msk);
			fclose (file);
			if (system (cmd_buf) == 0) {
				chmod (Dish_Home,0600);
				if ((file = fopen (Dish_Home, "r")) == 0) {
					fprintf (stderr,"Cant open %s - BUT I just created it!!!\n", Dish_Home);
					return (NOTOK);
				}
			} else {
				unlink (Dish_Home);
				return (NOTOK);
			}
			rc_mod_time = time ((time_t *)0);
		} else {
			rc_mod_time = time ((time_t *)0);
			goto out;
		}
	} else
		rc_mod_time = sbuf.st_mtime;

	if ((file = fopen (Dish_Home, "r")) == 0) {
no_dice:
		;
		fprintf (stderr,"Cant open ");
		perror (Dish_Home);
		return NOTOK;
	}

	while (fgets (Read_in_Stuff, BUFSIZ, file) != 0) {
		p = SkipSpace (Read_in_Stuff);
		if (( *p == '#') || (*p == '\0'))
			continue;  /* ignore comments and blanks */

		part1 = p;
		if ((part2 = index (p,':')) == NULLCP) {
			ps_printf (OPT,"Seperator missing '%s'\n",p);
			return (NOTOK);
		}

		*part2++ = '\0';
		part2 = TidyString (part2);

		if (lexequ (part1, "username") == 0) {
			if ((user_name = str2dn (*part2 != '@' ? part2
									 : part2 + 1))
					== NULLDN) {
				ps_printf (OPT,"Invalid DN for username: %s\n",part2);
				return (NOTOK);
			}
			strcpy (username, part2);
			bindarg.dba_dn = user_name;
		} else if (lexequ (part1, "password") == 0) {
			strcpy (bindarg.dba_passwd,part2);
			strcpy (password, part2);
			bindarg.dba_passwd_len = strlen (part2);
		} else if (lexequ (part1, "cache_time") == 0)
			cache_time = MIN (atoi(part2) * 60, 5 * 60 * 60);
		/* enforce 5 hour maximum */
		else if (lexequ (part1, "connect_time") == 0)
			connect_time = MIN (atoi(part2) * 60, 5 * 60);
		/* enforce 5 minute maximum */
		else if (lexequ (part1, "service") == 0)
			new_service (part2);
		else if (lexequ (part1, "type") == 0) {
			if (lexequ (part2,"unknown") == 0)
				show_unknown();
		} else if (lexequ (part1, "notype") == 0)
			new_ignore (part2);
		else if (lexequ (part1, "sequence") == 0) {
			DN sdn;
			if ( (sdn = str2dn (*part2 != '@' ? part2 : part2 + 1))
					== NULLDN) {
				ps_printf (OPT,"Invalid DN for sequence: %s\n",part2);
				return (NOTOK);
			}
			add_sequence (sdn);
		} else if (lexequ (part1, "dsap") == 0)
			tai_string (part2);
		else if (lexequ (part1, "isode") == 0) {
			char * split;
			if ((split = index (part2,' ')) != NULLCP) {
				*split++ = 0;
				isodesetvar (part2,strdup(split),0);
			}
		} else if (set_cmd_default (part1,part2) != OK) {
			if (*part2 == '@')
				part2++;
			if (add_alias (part1,part2) != OK) {
				ps_printf (OPT,"Unknown parameter %s\n",part1);
				return (NOTOK);
			}
		}
	}
	fclose (file);

out:
	;
	if ((local_dit != NULLCP) && (strcmp ("@", TidyString(local_dit)) != 0))
		if ((fixed_pos = str2dn (*local_dit != '@' ? local_dit
								 : local_dit + 1))
				== NULLDN) {
			ps_printf (OPT,"Invalid DN for dsaptailor default position: %s\n",local_dit);
			return (NOTOK);
		}

	strcpy (bindarg.dba_passwd,password);
	bindarg.dba_passwd_len = strlen (password);

	isodexport (NULLCP);

	return (OK);
}

test_rc_file (ps)
PS  ps;
{
	struct	 stat	sbuf;

	if (stat (Dish_Home,&sbuf) != 0)
		return;

	if (rc_mod_time < sbuf.st_mtime) {
		ps_printf (ps,"WARNING: %s has changed - but not re-read!!!\n",
				   Dish_Home);
		rc_mod_time = sbuf.st_mtime;
	}

}

SFD dish_quit (sig)
int sig;
{
	if (bound) {
		dap_unbind (main_dsa_id);
		if (referral_dsa != 0) {
			dap_unbind (referral_dsa);
			referral_dsa = 0;
		}
	}

	if (frompipe)
		exit_pipe ();
	else
		fprintf (stderr,"Dish Problem\n");

	hide_picture();

	switch (sig) {
	case SIGALRM:
		LLOG (log_dsap, LLOG_EXCEPTIONS, ("Timer expired :- Dish quitting"));
		exit (0);
	case SIGHUP:
	case SIGINT:
	case SIGTERM:
		LLOG (log_dsap, LLOG_EXCEPTIONS, ("Dish quitting - signal %d",sig));
		exit (0);
	default:
		LLOG (log_dsap, LLOG_EXCEPTIONS, ("Dish problem - signal %d",sig));
		signal (sig, SIG_DFL); /* to stop recursion */
		abort ();
	}

}

static int
protect_password (void) {
	long hash;
	char *cp;
	int len;

	bindarg.dba_time1 = new_version();
	bindarg.dba_time2 = NULLCP;
	bindarg.dba_r1.n_bits = 0;
	bindarg.dba_r1.value = NULLCP;
	bindarg.dba_r2.n_bits = 0;
	bindarg.dba_r2.value = NULLCP;
	hash = 0;
	hash = hash_passwd(hash, password, strlen(password));
	hash = hash_passwd(hash, bindarg.dba_time1, strlen(bindarg.dba_time1));
	cp = hash2str(hash, &len);
	bcopy(cp, bindarg.dba_passwd, len);
	bindarg.dba_passwd_len = len;
}


static int
sign_bindarg (void) {
	struct Nonce *nonce;

	if (dsap_security == (struct SecurityServices *) 0)
		return (NOTOK);

	if (! dsap_security->serv_mknonce)
		return (NOTOK);

	nonce = (dsap_security->serv_mknonce)((struct Nonce *) 0);
	if (nonce == (struct Nonce *) 0)
		return (NOTOK);

	bindarg.dba_time1 = nonce->non_time1;
	bindarg.dba_time2 = nonce->non_time2;
	bindarg.dba_r1.n_bits = nonce->non_r1.n_bits;
	bindarg.dba_r1.value = nonce->non_r1.value;
	bindarg.dba_r2.n_bits = nonce->non_r2.n_bits;
	bindarg.dba_alg.algorithm = nonce->non_alg.algorithm;
	bindarg.dba_alg.p_type = nonce->non_alg.p_type;
	bindarg.dba_alg.asn = nonce->non_alg.asn;
	free((char *) nonce);
	if (dsap_security->serv_sign)
		bindarg.dba_sig = (dsap_security->serv_sign)((char*)&bindarg,
						  _ZTokenToSignDAS, &_ZDAS_mod);
	else
		return (NOTOK);

	if (bindarg.dba_sig == (struct signature *) 0)
		return (NOTOK);

	if (dsap_security->serv_mkpath)
		bindarg.dba_cpath = (dsap_security->serv_mkpath)();
	else
		bindarg.dba_cpath = (struct certificate_list *)0;

	return (OK);
}
