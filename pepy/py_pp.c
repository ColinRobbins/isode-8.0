/* py_pp.c - generic pretty-printer */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/pepy/RCS/py_pp.c,v 9.0 1992/06/16 12:25:01 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/pepy/RCS/py_pp.c,v 9.0 1992/06/16 12:25:01 isode Rel $
 *
 *
 * $Log: py_pp.c,v $
 * Revision 9.0  1992/06/16  12:25:01  isode
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


/* LINTLIBRARY */

#include <stdio.h>
#include "psap.h"

#define	ps_advise(ps, f) \
	advise (NULLCP, "%s: %s", (f), ps_error ((ps) -> ps_errno))

/*    DATA */

static char *myname = "pp";

static enum { ps2pp, pl2pp } mode = ps2pp;


static void adios (char*what, ...);

static void advise (char*what, ...);

static int  process ();

/*  */

/* ARGSUSED */

int
PY_pp (int argc, char **argv, char **envp, IFP pfx) {
	int    status = 0;
	char  *cp;
	FILE  *fp;

	if (myname = rindex (argv[0], '/'))
		myname++;
	if (myname == NULL || *myname == NULL)
		myname = argv[0];

	for (argc--, argv++; cp = *argv; argc--, argv++)
		if (*cp == '-') {
			if (strcmp (cp + 1, "ps") == 0) {
				mode = ps2pp;
				continue;
			}
			if (strcmp (cp + 1, "pl") == 0) {
				mode = pl2pp;
				continue;
			}
			adios (NULLCP, "usage: %s [ -ps | -pl ] [ files... ]", myname);
		} else
			break;

	if (argc == 0)
		status = process ("(stdin)", stdin, pfx);
	else
		while (cp = *argv++) {
			if ((fp = fopen (cp, "r")) == NULL) {
				advise (cp, "unable to read");
				status++;
				continue;
			}
			status += process (cp, fp, pfx);
			fclose (fp);
		}

	return status;
}

/*  */

static int  process (file, fp, pfx)
char *file;
FILE *fp;
IFP	pfx;
{
	PE	    pe;
	PS	    ps;

	if ((ps = ps_alloc (std_open)) == NULLPS) {
		ps_advise (ps, "ps_alloc");
		return 1;
	}
	if (std_setup (ps, fp) == NOTOK) {
		advise (NULLCP, "%s: std_setup loses", file);
		return 1;
	}

	for (;;) {
		switch (mode) {
		case ps2pp:
			if ((pe = ps2pe (ps)) == NULLPE)
				if (ps -> ps_errno) {
					ps_advise (ps, "ps2pe");
you_lose:
					;
					ps_free (ps);
					return 1;
				} else {
done:
					;
					ps_free (ps);
					return 0;
				}
			break;

		case pl2pp:
			if ((pe = pl2pe (ps)) == NULLPE)
				if (ps -> ps_errno) {
					ps_advise (ps, "pl2pe");
					goto you_lose;
				} else
					goto done;
			break;
		}

		(*pfx) (pe, 1, NULLIP, NULLVP, NULLCP);

		pe_free (pe);
	}
}

/*    ERRORS */

#include <stdarg.h>


#ifndef	lint
static void	_advise (char*what, ...);


static void  adios (char*what, ...) {
	va_list ap;

	va_start (ap, what);

	_advise (what, ap);

	va_end (ap);

	_exit (1);
}
#else
/* VARARGS */

static void
adios (char *what, char *fmt) {
	adios (what, fmt);
}
#endif


#ifndef	lint
static void  advise (char*what, ...) {
	va_list ap;

	va_start (ap, what);

	_advise (what, ap);

	va_end (ap);
}


static void  _advise (char*what, ...) {
	char    buffer[BUFSIZ];

	va_list ap;

	va_start (ap, what);

	_asprintf (buffer, what, ap);

	fflush (stdout);

	fprintf (stderr, "%s: ", myname);
	fputs (buffer, stderr);
	fputc ('\n', stderr);

	fflush (stderr);

	va_end (ap);
}
#else
/* VARARGS */

static void
advise (char *what, char *fmt) {
	advise (what, fmt);
}
#endif
