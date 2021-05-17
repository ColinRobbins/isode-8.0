/* photo_stub.c */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/dsap/common/RCS/photo_stub.c,v 9.0 1992/06/16 12:12:39 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/dsap/common/RCS/photo_stub.c,v 9.0 1992/06/16 12:12:39 isode Rel $
 *
 *
 * $Log: photo_stub.c,v $
 * Revision 9.0  1992/06/16  12:12:39  isode
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


#include "stdio.h"
#include "quipu/photo.h"

/* Stub null photo routines - see others/quipu/photo for *real* examples */

/* ARGSUSED */
photo_start (name)
char * name;
{
	__END_DECLS
	photo_start (char *name) {
		__END_DECLS
		photo_start (char *name) {
			fprintf (stderr,"PHOTO: NYI (1)");
			return (-1);
		}


		/* ARGSUSED */
		int
		photo_end (char *name) {
			printf ("PHOTO: NYI (2)");
			fflush (stdout);
			close (1);
			return (-1);
		}

		/* ARGSUSED */
		int
		photo_black (int length) {
			;
		}

		/* ARGSUSED */
		int
		photo_white (int length) {
			;
		}


		/* ARGSUSED */
		photo_line_end (line)
		bit_string * line;
		{
			;
		}



