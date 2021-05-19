/* automatically generated by pepsy 8.0 #11 (Mercury), do not edit! */

#ifndef	_module_Thorn_defined_
#define	_module_Thorn_defined_

#ifndef	PEPSY_VERSION
#define	PEPSY_VERSION		2
#endif

#ifndef	PEPYPATH
#include <isode/psap.h>
#include <isode/pepsy.h>
#include <isode/pepsy/UNIV-types.h>
#else
#include "psap.h"
#include "pepsy.h"
#include "UNIV-types.h"
#endif



extern modtyp	_ZThorn_mod;
#define _ZDocumentStoreSyntaxThorn	1
#define _ZDSAQualitySyntaxThorn	2
#define _ZAttributeQualityThorn	4
#define _ZMailBoxThorn	0
#define _ZDataQualitySyntaxThorn	3

#ifndef	lint
#define encode_Thorn_MailBox(pe, top, len, buffer, parm) \
    enc_f(_ZMailBoxThorn, &_ZThorn_mod, pe, top, len, buffer, (char *) parm)

#define decode_Thorn_MailBox(pe, top, len, buffer, parm) \
    dec_f(_ZMailBoxThorn, &_ZThorn_mod, pe, top, len, buffer, (char **) parm)

#define print_Thorn_MailBox(pe, top, len, buffer, parm) \
    prnt_f(_ZMailBoxThorn, &_ZThorn_mod, pe, top, len, buffer)
#define print_Thorn_MailBox_P    _ZMailBoxThorn, &_ZThorn_mod

#define encode_Thorn_DocumentStoreSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZDocumentStoreSyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char *) parm)

#define decode_Thorn_DocumentStoreSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZDocumentStoreSyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char **) parm)

#define print_Thorn_DocumentStoreSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZDocumentStoreSyntaxThorn, &_ZThorn_mod, pe, top, len, buffer)
#define print_Thorn_DocumentStoreSyntax_P    _ZDocumentStoreSyntaxThorn, &_ZThorn_mod

#define encode_Thorn_DSAQualitySyntax(pe, top, len, buffer, parm) \
    enc_f(_ZDSAQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char *) parm)

#define decode_Thorn_DSAQualitySyntax(pe, top, len, buffer, parm) \
    dec_f(_ZDSAQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char **) parm)

#define print_Thorn_DSAQualitySyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZDSAQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer)
#define print_Thorn_DSAQualitySyntax_P    _ZDSAQualitySyntaxThorn, &_ZThorn_mod

#define encode_Thorn_DataQualitySyntax(pe, top, len, buffer, parm) \
    enc_f(_ZDataQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char *) parm)

#define decode_Thorn_DataQualitySyntax(pe, top, len, buffer, parm) \
    dec_f(_ZDataQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer, (char **) parm)

#define print_Thorn_DataQualitySyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZDataQualitySyntaxThorn, &_ZThorn_mod, pe, top, len, buffer)
#define print_Thorn_DataQualitySyntax_P    _ZDataQualitySyntaxThorn, &_ZThorn_mod

#define encode_Thorn_AttributeQuality(pe, top, len, buffer, parm) \
    enc_f(_ZAttributeQualityThorn, &_ZThorn_mod, pe, top, len, buffer, (char *) parm)

#define decode_Thorn_AttributeQuality(pe, top, len, buffer, parm) \
    dec_f(_ZAttributeQualityThorn, &_ZThorn_mod, pe, top, len, buffer, (char **) parm)

#define print_Thorn_AttributeQuality(pe, top, len, buffer, parm) \
    prnt_f(_ZAttributeQualityThorn, &_ZThorn_mod, pe, top, len, buffer)
#define print_Thorn_AttributeQuality_P    _ZAttributeQualityThorn, &_ZThorn_mod


#endif   /* lint */
#include "if-cdefs.h"
#ifndef	PEPYPATH
#include "IF-types.h"
#else
#include "IF-types.h"
#endif



struct type_Thorn_MailBox {
    struct	qbuf	*mailboxType;

    struct	qbuf	*mailbox;
};
#define	free_Thorn_MailBox(parm)\
	 fre_obj((char *) parm, _ZThorn_mod.md_dtab[_ZMailBoxThorn], &_ZThorn_mod, 1)

struct type_Thorn_DocumentStoreSyntax {
    integer     method;
#define	int_Thorn_method_ftp	0
#define	int_Thorn_method_ftam	1

    struct	qbuf	*textEncodedHostName;

    struct	qbuf	*directoryName;

    struct	qbuf	*fileFsName;
};
#define	free_Thorn_DocumentStoreSyntax(parm)\
	 fre_obj((char *) parm, _ZThorn_mod.md_dtab[_ZDocumentStoreSyntaxThorn], &_ZThorn_mod, 1)

struct type_Thorn_DSAQualitySyntax {
    integer     serviceQuality;
#define	int_Thorn_serviceQuality_defunct	0
#define	int_Thorn_serviceQuality_experimental	1
#define	int_Thorn_serviceQuality_best__effort	2
#define	int_Thorn_serviceQuality_pilot__service	3
#define	int_Thorn_serviceQuality_full__service	4

    struct	qbuf	*description;
};
#define	free_Thorn_DSAQualitySyntax(parm)\
	 fre_obj((char *) parm, _ZThorn_mod.md_dtab[_ZDSAQualitySyntaxThorn], &_ZThorn_mod, 1)

struct type_Thorn_DataQualitySyntax {
    integer     namespace__completeness;
#define	int_Thorn_namespace__completeness_none	1
#define	int_Thorn_namespace__completeness_sample	2
#define	int_Thorn_namespace__completeness_selected	3
#define	int_Thorn_namespace__completeness_substantial	4
#define	int_Thorn_namespace__completeness_full	5

    struct type_Thorn_AttributeQuality *defaultAttributeQuality;

    struct member_Thorn_0 {
        struct element_Thorn_0 {
            struct type_IF_AttributeType *element_Thorn_1;

            struct type_Thorn_AttributeQuality *element_Thorn_2;
        } *member_Thorn_1;

        struct member_Thorn_0 *next;
    } *attributeQuality;

    struct	qbuf	*description;
};
#define	free_Thorn_DataQualitySyntax(parm)\
	 fre_obj((char *) parm, _ZThorn_mod.md_dtab[_ZDataQualitySyntaxThorn], &_ZThorn_mod, 1)

struct type_Thorn_AttributeQuality {
    integer     optionals;
#define	opt_Thorn_AttributeQuality_attribute__completeness (000000001)

    integer     maintenance__level;
#define	int_Thorn_maintenance__level_unknown	1
#define	int_Thorn_maintenance__level_external	2
#define	int_Thorn_maintenance__level_system__maintained	3
#define	int_Thorn_maintenance__level_user__supplied	4

    integer     attribute__completeness;
#define	int_Thorn_attribute__completeness_none	1
#define	int_Thorn_attribute__completeness_sample	2
#define	int_Thorn_attribute__completeness_selected	3
#define	int_Thorn_attribute__completeness_substantial	4
#define	int_Thorn_attribute__completeness_full	5
};
#define	free_Thorn_AttributeQuality(parm)\
	 fre_obj((char *) parm, _ZThorn_mod.md_dtab[_ZAttributeQualityThorn], &_ZThorn_mod, 1)
#endif
