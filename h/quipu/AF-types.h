/* automatically generated by pepsy 8.0 #11 (Mercury), do not edit! */

#ifndef	_module_AF_defined_
#define	_module_AF_defined_

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



extern modtyp	_ZAF_mod;
#define _ZRevokedCertificatesToSignAF	12
#define _ZSubjectPublicKeyInfoAF	4
#define _ZVersionAF	0
#define _ZAlgorithmIdentifierAF	3
#define _ZCertificateAF	6
#define _ZCertificateListAF	15
#define _ZCertificateSerialNumberAF	1
#define _ZRevokedCertificatesAF	13
#define _ZCertificateToSignAF	5
#define _ZCertificatePairAF	10
#define _ZValidityAF	2
#define _ZCrossCertificatesAF	7
#define _ZCertificateListToSignAF	14
#define _ZForwardCertificationPathAF	8
#define _ZCertificationPathAF	11
#define _ZCertificatesAF	9

#ifndef	lint
#define encode_AF_Version(pe, top, len, buffer, parm) \
    enc_f(_ZVersionAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_Version(pe, top, len, buffer, parm) \
    dec_f(_ZVersionAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_Version(pe, top, len, buffer, parm) \
    prnt_f(_ZVersionAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_Version_P    _ZVersionAF, &_ZAF_mod

#define encode_AF_CertificateSerialNumber(pe, top, len, buffer, parm) \
    enc_f(_ZCertificateSerialNumberAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificateSerialNumber(pe, top, len, buffer, parm) \
    dec_f(_ZCertificateSerialNumberAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificateSerialNumber(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificateSerialNumberAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificateSerialNumber_P    _ZCertificateSerialNumberAF, &_ZAF_mod

#define encode_AF_Validity(pe, top, len, buffer, parm) \
    enc_f(_ZValidityAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_Validity(pe, top, len, buffer, parm) \
    dec_f(_ZValidityAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_Validity(pe, top, len, buffer, parm) \
    prnt_f(_ZValidityAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_Validity_P    _ZValidityAF, &_ZAF_mod

#define encode_AF_AlgorithmIdentifier(pe, top, len, buffer, parm) \
    enc_f(_ZAlgorithmIdentifierAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_AlgorithmIdentifier(pe, top, len, buffer, parm) \
    dec_f(_ZAlgorithmIdentifierAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_AlgorithmIdentifier(pe, top, len, buffer, parm) \
    prnt_f(_ZAlgorithmIdentifierAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_AlgorithmIdentifier_P    _ZAlgorithmIdentifierAF, &_ZAF_mod

#define encode_AF_SubjectPublicKeyInfo(pe, top, len, buffer, parm) \
    enc_f(_ZSubjectPublicKeyInfoAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_SubjectPublicKeyInfo(pe, top, len, buffer, parm) \
    dec_f(_ZSubjectPublicKeyInfoAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_SubjectPublicKeyInfo(pe, top, len, buffer, parm) \
    prnt_f(_ZSubjectPublicKeyInfoAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_SubjectPublicKeyInfo_P    _ZSubjectPublicKeyInfoAF, &_ZAF_mod

#define encode_AF_CertificateToSign(pe, top, len, buffer, parm) \
    enc_f(_ZCertificateToSignAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificateToSign(pe, top, len, buffer, parm) \
    dec_f(_ZCertificateToSignAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificateToSign(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificateToSignAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificateToSign_P    _ZCertificateToSignAF, &_ZAF_mod

#define encode_AF_Certificate(pe, top, len, buffer, parm) \
    enc_f(_ZCertificateAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_Certificate(pe, top, len, buffer, parm) \
    dec_f(_ZCertificateAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_Certificate(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificateAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_Certificate_P    _ZCertificateAF, &_ZAF_mod

#define encode_AF_CrossCertificates(pe, top, len, buffer, parm) \
    enc_f(_ZCrossCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CrossCertificates(pe, top, len, buffer, parm) \
    dec_f(_ZCrossCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CrossCertificates(pe, top, len, buffer, parm) \
    prnt_f(_ZCrossCertificatesAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CrossCertificates_P    _ZCrossCertificatesAF, &_ZAF_mod

#define encode_AF_ForwardCertificationPath(pe, top, len, buffer, parm) \
    enc_f(_ZForwardCertificationPathAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_ForwardCertificationPath(pe, top, len, buffer, parm) \
    dec_f(_ZForwardCertificationPathAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_ForwardCertificationPath(pe, top, len, buffer, parm) \
    prnt_f(_ZForwardCertificationPathAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_ForwardCertificationPath_P    _ZForwardCertificationPathAF, &_ZAF_mod

#define encode_AF_Certificates(pe, top, len, buffer, parm) \
    enc_f(_ZCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_Certificates(pe, top, len, buffer, parm) \
    dec_f(_ZCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_Certificates(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificatesAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_Certificates_P    _ZCertificatesAF, &_ZAF_mod

#define encode_AF_CertificatePair(pe, top, len, buffer, parm) \
    enc_f(_ZCertificatePairAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificatePair(pe, top, len, buffer, parm) \
    dec_f(_ZCertificatePairAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificatePair(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificatePairAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificatePair_P    _ZCertificatePairAF, &_ZAF_mod

#define encode_AF_CertificationPath(pe, top, len, buffer, parm) \
    enc_f(_ZCertificationPathAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificationPath(pe, top, len, buffer, parm) \
    dec_f(_ZCertificationPathAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificationPath(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificationPathAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificationPath_P    _ZCertificationPathAF, &_ZAF_mod

#define encode_AF_RevokedCertificatesToSign(pe, top, len, buffer, parm) \
    enc_f(_ZRevokedCertificatesToSignAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_RevokedCertificatesToSign(pe, top, len, buffer, parm) \
    dec_f(_ZRevokedCertificatesToSignAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_RevokedCertificatesToSign(pe, top, len, buffer, parm) \
    prnt_f(_ZRevokedCertificatesToSignAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_RevokedCertificatesToSign_P    _ZRevokedCertificatesToSignAF, &_ZAF_mod

#define encode_AF_RevokedCertificates(pe, top, len, buffer, parm) \
    enc_f(_ZRevokedCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_RevokedCertificates(pe, top, len, buffer, parm) \
    dec_f(_ZRevokedCertificatesAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_RevokedCertificates(pe, top, len, buffer, parm) \
    prnt_f(_ZRevokedCertificatesAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_RevokedCertificates_P    _ZRevokedCertificatesAF, &_ZAF_mod

#define encode_AF_CertificateListToSign(pe, top, len, buffer, parm) \
    enc_f(_ZCertificateListToSignAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificateListToSign(pe, top, len, buffer, parm) \
    dec_f(_ZCertificateListToSignAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificateListToSign(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificateListToSignAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificateListToSign_P    _ZCertificateListToSignAF, &_ZAF_mod

#define encode_AF_CertificateList(pe, top, len, buffer, parm) \
    enc_f(_ZCertificateListAF, &_ZAF_mod, pe, top, len, buffer, (char *) parm)

#define decode_AF_CertificateList(pe, top, len, buffer, parm) \
    dec_f(_ZCertificateListAF, &_ZAF_mod, pe, top, len, buffer, (char **) parm)

#define print_AF_CertificateList(pe, top, len, buffer, parm) \
    prnt_f(_ZCertificateListAF, &_ZAF_mod, pe, top, len, buffer)
#define print_AF_CertificateList_P    _ZCertificateListAF, &_ZAF_mod


#endif   /* lint */
#include "af-cdefs.h"
#ifndef	PEPYPATH
#include "IF-types.h"
#else
#include "IF-types.h"
#endif



struct type_AF_Version {
    integer     parm;
#define	int_AF_Version_v1988	0
};
#define	free_AF_Version(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZVersionAF], &_ZAF_mod, 1)

struct type_AF_CertificateSerialNumber {
    integer     parm;
};
#define	free_AF_CertificateSerialNumber(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificateSerialNumberAF], &_ZAF_mod, 1)

struct type_AF_Validity {
    struct	qbuf	*notBefore;

    struct	qbuf	*notAfter;
};
#define	free_AF_Validity(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZValidityAF], &_ZAF_mod, 1)

struct type_AF_AlgorithmIdentifier {
    OID     algorithm;

    PE      parameters;
};
#define	free_AF_AlgorithmIdentifier(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZAlgorithmIdentifierAF], &_ZAF_mod, 1)

struct type_AF_SubjectPublicKeyInfo {
    struct type_AF_AlgorithmIdentifier *algorithm;

    PE      subjectPublicKey;
};
#define	free_AF_SubjectPublicKeyInfo(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZSubjectPublicKeyInfoAF], &_ZAF_mod, 1)

struct type_AF_CertificateToSign {
    struct type_AF_Version *version;

    struct type_AF_CertificateSerialNumber *serialNumber;

    struct type_AF_AlgorithmIdentifier *signature;

    struct type_IF_Name *issuer;

    struct type_AF_Validity *validity;

    struct type_IF_Name *subject;

    struct type_AF_SubjectPublicKeyInfo *subjectPublicKeyInfo;
};
#define	free_AF_CertificateToSign(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificateToSignAF], &_ZAF_mod, 1)

struct type_AF_Certificate {
    struct type_AF_CertificateToSign *element_AF_0;

    struct type_AF_AlgorithmIdentifier *element_AF_1;

    PE      element_AF_2;
};
#define	free_AF_Certificate(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificateAF], &_ZAF_mod, 1)

struct type_AF_CrossCertificates {
        struct type_AF_Certificate *member_AF_0;

        struct type_AF_CrossCertificates *next;
};
#define	free_AF_CrossCertificates(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCrossCertificatesAF], &_ZAF_mod, 1)

struct type_AF_ForwardCertificationPath {
        struct type_AF_CrossCertificates *element_AF_3;

        struct type_AF_ForwardCertificationPath *next;
};
#define	free_AF_ForwardCertificationPath(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZForwardCertificationPathAF], &_ZAF_mod, 1)

struct type_AF_Certificates {
    struct type_AF_Certificate *certificate;

    struct type_AF_ForwardCertificationPath *certificationPath;
};
#define	free_AF_Certificates(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificatesAF], &_ZAF_mod, 1)

struct type_AF_CertificatePair {
    struct type_AF_Certificate *forward;

    struct type_AF_Certificate *reverse;
};
#define	free_AF_CertificatePair(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificatePairAF], &_ZAF_mod, 1)

struct type_AF_CertificationPath {
    struct type_AF_Certificate *userCertificate;

    struct element_AF_4 {
        struct type_AF_CertificatePair *element_AF_5;

        struct element_AF_4 *next;
    } *theCACertificates;
};
#define	free_AF_CertificationPath(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificationPathAF], &_ZAF_mod, 1)

struct type_AF_RevokedCertificatesToSign {
        struct element_AF_7 {
            struct type_AF_AlgorithmIdentifier *signature;

            struct type_IF_Name *issuer;

            struct type_AF_CertificateSerialNumber *subject;

            struct	qbuf	*revokationDate;
        } *element_AF_6;

        struct type_AF_RevokedCertificatesToSign *next;
};
#define	free_AF_RevokedCertificatesToSign(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZRevokedCertificatesToSignAF], &_ZAF_mod, 1)

struct type_AF_RevokedCertificates {
    struct type_AF_RevokedCertificatesToSign *element_AF_8;

    struct type_AF_AlgorithmIdentifier *element_AF_9;

    PE      element_AF_10;
};
#define	free_AF_RevokedCertificates(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZRevokedCertificatesAF], &_ZAF_mod, 1)

struct type_AF_CertificateListToSign {
    struct type_AF_AlgorithmIdentifier *signature;

    struct type_IF_Name *issuer;

    struct	qbuf	*lastUpdate;

    struct type_AF_RevokedCertificates *revokedCertificates;
};
#define	free_AF_CertificateListToSign(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificateListToSignAF], &_ZAF_mod, 1)

struct type_AF_CertificateList {
    struct type_AF_CertificateListToSign *element_AF_11;

    struct type_AF_AlgorithmIdentifier *element_AF_12;

    PE      element_AF_13;
};
#define	free_AF_CertificateList(parm)\
	 fre_obj((char *) parm, _ZAF_mod.md_dtab[_ZCertificateListAF], &_ZAF_mod, 1)
#endif
