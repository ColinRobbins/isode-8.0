/* automatically generated by pepsy 8.0 #11 (Mercury), do not edit! */

#ifndef	_module_Quipu_defined_
#define	_module_Quipu_defined_

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



extern modtyp	_ZQuipu_mod;
#define _ZGetEntryDataBlockResultQuipu	16
#define _ZOptionalDNQuipu	21
#define _ZAuthenticationPolicySyntaxQuipu	1
#define _ZCallQuipu	22
#define _ZDSAControlQuipu	20
#define _ZAccessCategoriesQuipu	3
#define _ZEDBInfoSyntaxQuipu	10
#define _ZRelativeEntryQuipu	11
#define _ZNameListQuipu	9
#define _ZInheritedAttributeQuipu	19
#define _ZAttributeACLQuipu	5
#define _ZOperationQuipu	24
#define _ZAccessSelectorQuipu	2
#define _ZListACLSyntaxQuipu	8
#define _ZAuthLevelQuipu	23
#define _ZGetEntryDataBlockArgumentQuipu	15
#define _ZACLInfoQuipu	4
#define _ZInheritedListQuipu	18
#define _ZAuthenticationPolicyQuipu	0
#define _ZSubChainOpsQuipu	25
#define _ZProtectedPasswordQuipu	17
#define _ZACLSyntaxQuipu	6
#define _ZEntryDataBlockQuipu	13
#define _ZEDBVersionQuipu	14
#define _ZSearchACLSyntaxQuipu	7
#define _ZTreeStructureSyntaxQuipu	12

#ifndef	lint
#define encode_Quipu_AuthenticationPolicy(pe, top, len, buffer, parm) \
    enc_f(_ZAuthenticationPolicyQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AuthenticationPolicy(pe, top, len, buffer, parm) \
    dec_f(_ZAuthenticationPolicyQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AuthenticationPolicy(pe, top, len, buffer, parm) \
    prnt_f(_ZAuthenticationPolicyQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AuthenticationPolicy_P    _ZAuthenticationPolicyQuipu, &_ZQuipu_mod

#define encode_Quipu_AuthenticationPolicySyntax(pe, top, len, buffer, parm) \
    enc_f(_ZAuthenticationPolicySyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AuthenticationPolicySyntax(pe, top, len, buffer, parm) \
    dec_f(_ZAuthenticationPolicySyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AuthenticationPolicySyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZAuthenticationPolicySyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AuthenticationPolicySyntax_P    _ZAuthenticationPolicySyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_AccessSelector(pe, top, len, buffer, parm) \
    enc_f(_ZAccessSelectorQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AccessSelector(pe, top, len, buffer, parm) \
    dec_f(_ZAccessSelectorQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AccessSelector(pe, top, len, buffer, parm) \
    prnt_f(_ZAccessSelectorQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AccessSelector_P    _ZAccessSelectorQuipu, &_ZQuipu_mod

#define encode_Quipu_AccessCategories(pe, top, len, buffer, parm) \
    enc_f(_ZAccessCategoriesQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AccessCategories(pe, top, len, buffer, parm) \
    dec_f(_ZAccessCategoriesQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AccessCategories(pe, top, len, buffer, parm) \
    prnt_f(_ZAccessCategoriesQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AccessCategories_P    _ZAccessCategoriesQuipu, &_ZQuipu_mod

#define encode_Quipu_ACLInfo(pe, top, len, buffer, parm) \
    enc_f(_ZACLInfoQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_ACLInfo(pe, top, len, buffer, parm) \
    dec_f(_ZACLInfoQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_ACLInfo(pe, top, len, buffer, parm) \
    prnt_f(_ZACLInfoQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_ACLInfo_P    _ZACLInfoQuipu, &_ZQuipu_mod

#define encode_Quipu_AttributeACL(pe, top, len, buffer, parm) \
    enc_f(_ZAttributeACLQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AttributeACL(pe, top, len, buffer, parm) \
    dec_f(_ZAttributeACLQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AttributeACL(pe, top, len, buffer, parm) \
    prnt_f(_ZAttributeACLQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AttributeACL_P    _ZAttributeACLQuipu, &_ZQuipu_mod

#define encode_Quipu_ACLSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_ACLSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_ACLSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_ACLSyntax_P    _ZACLSyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_SearchACLSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZSearchACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_SearchACLSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZSearchACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_SearchACLSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZSearchACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_SearchACLSyntax_P    _ZSearchACLSyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_ListACLSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZListACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_ListACLSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZListACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_ListACLSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZListACLSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_ListACLSyntax_P    _ZListACLSyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_NameList(pe, top, len, buffer, parm) \
    enc_f(_ZNameListQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_NameList(pe, top, len, buffer, parm) \
    dec_f(_ZNameListQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_NameList(pe, top, len, buffer, parm) \
    prnt_f(_ZNameListQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_NameList_P    _ZNameListQuipu, &_ZQuipu_mod

#define encode_Quipu_EDBInfoSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZEDBInfoSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_EDBInfoSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZEDBInfoSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_EDBInfoSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZEDBInfoSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_EDBInfoSyntax_P    _ZEDBInfoSyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_RelativeEntry(pe, top, len, buffer, parm) \
    enc_f(_ZRelativeEntryQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_RelativeEntry(pe, top, len, buffer, parm) \
    dec_f(_ZRelativeEntryQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_RelativeEntry(pe, top, len, buffer, parm) \
    prnt_f(_ZRelativeEntryQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_RelativeEntry_P    _ZRelativeEntryQuipu, &_ZQuipu_mod

#define encode_Quipu_TreeStructureSyntax(pe, top, len, buffer, parm) \
    enc_f(_ZTreeStructureSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_TreeStructureSyntax(pe, top, len, buffer, parm) \
    dec_f(_ZTreeStructureSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_TreeStructureSyntax(pe, top, len, buffer, parm) \
    prnt_f(_ZTreeStructureSyntaxQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_TreeStructureSyntax_P    _ZTreeStructureSyntaxQuipu, &_ZQuipu_mod

#define encode_Quipu_EntryDataBlock(pe, top, len, buffer, parm) \
    enc_f(_ZEntryDataBlockQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_EntryDataBlock(pe, top, len, buffer, parm) \
    dec_f(_ZEntryDataBlockQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_EntryDataBlock(pe, top, len, buffer, parm) \
    prnt_f(_ZEntryDataBlockQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_EntryDataBlock_P    _ZEntryDataBlockQuipu, &_ZQuipu_mod

#define encode_Quipu_EDBVersion(pe, top, len, buffer, parm) \
    enc_f(_ZEDBVersionQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_EDBVersion(pe, top, len, buffer, parm) \
    dec_f(_ZEDBVersionQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_EDBVersion(pe, top, len, buffer, parm) \
    prnt_f(_ZEDBVersionQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_EDBVersion_P    _ZEDBVersionQuipu, &_ZQuipu_mod

#define encode_Quipu_GetEntryDataBlockArgument(pe, top, len, buffer, parm) \
    enc_f(_ZGetEntryDataBlockArgumentQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_GetEntryDataBlockArgument(pe, top, len, buffer, parm) \
    dec_f(_ZGetEntryDataBlockArgumentQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_GetEntryDataBlockArgument(pe, top, len, buffer, parm) \
    prnt_f(_ZGetEntryDataBlockArgumentQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_GetEntryDataBlockArgument_P    _ZGetEntryDataBlockArgumentQuipu, &_ZQuipu_mod

#define encode_Quipu_GetEntryDataBlockResult(pe, top, len, buffer, parm) \
    enc_f(_ZGetEntryDataBlockResultQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_GetEntryDataBlockResult(pe, top, len, buffer, parm) \
    dec_f(_ZGetEntryDataBlockResultQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_GetEntryDataBlockResult(pe, top, len, buffer, parm) \
    prnt_f(_ZGetEntryDataBlockResultQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_GetEntryDataBlockResult_P    _ZGetEntryDataBlockResultQuipu, &_ZQuipu_mod

#define encode_Quipu_ProtectedPassword(pe, top, len, buffer, parm) \
    enc_f(_ZProtectedPasswordQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_ProtectedPassword(pe, top, len, buffer, parm) \
    dec_f(_ZProtectedPasswordQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_ProtectedPassword(pe, top, len, buffer, parm) \
    prnt_f(_ZProtectedPasswordQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_ProtectedPassword_P    _ZProtectedPasswordQuipu, &_ZQuipu_mod

#define encode_Quipu_InheritedList(pe, top, len, buffer, parm) \
    enc_f(_ZInheritedListQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_InheritedList(pe, top, len, buffer, parm) \
    dec_f(_ZInheritedListQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_InheritedList(pe, top, len, buffer, parm) \
    prnt_f(_ZInheritedListQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_InheritedList_P    _ZInheritedListQuipu, &_ZQuipu_mod

#define encode_Quipu_InheritedAttribute(pe, top, len, buffer, parm) \
    enc_f(_ZInheritedAttributeQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_InheritedAttribute(pe, top, len, buffer, parm) \
    dec_f(_ZInheritedAttributeQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_InheritedAttribute(pe, top, len, buffer, parm) \
    prnt_f(_ZInheritedAttributeQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_InheritedAttribute_P    _ZInheritedAttributeQuipu, &_ZQuipu_mod

#define encode_Quipu_DSAControl(pe, top, len, buffer, parm) \
    enc_f(_ZDSAControlQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_DSAControl(pe, top, len, buffer, parm) \
    dec_f(_ZDSAControlQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_DSAControl(pe, top, len, buffer, parm) \
    prnt_f(_ZDSAControlQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_DSAControl_P    _ZDSAControlQuipu, &_ZQuipu_mod

#define encode_Quipu_OptionalDN(pe, top, len, buffer, parm) \
    enc_f(_ZOptionalDNQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_OptionalDN(pe, top, len, buffer, parm) \
    dec_f(_ZOptionalDNQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_OptionalDN(pe, top, len, buffer, parm) \
    prnt_f(_ZOptionalDNQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_OptionalDN_P    _ZOptionalDNQuipu, &_ZQuipu_mod

#define encode_Quipu_Call(pe, top, len, buffer, parm) \
    enc_f(_ZCallQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_Call(pe, top, len, buffer, parm) \
    dec_f(_ZCallQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_Call(pe, top, len, buffer, parm) \
    prnt_f(_ZCallQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_Call_P    _ZCallQuipu, &_ZQuipu_mod

#define encode_Quipu_AuthLevel(pe, top, len, buffer, parm) \
    enc_f(_ZAuthLevelQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_AuthLevel(pe, top, len, buffer, parm) \
    dec_f(_ZAuthLevelQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_AuthLevel(pe, top, len, buffer, parm) \
    prnt_f(_ZAuthLevelQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_AuthLevel_P    _ZAuthLevelQuipu, &_ZQuipu_mod

#define encode_Quipu_Operation(pe, top, len, buffer, parm) \
    enc_f(_ZOperationQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_Operation(pe, top, len, buffer, parm) \
    dec_f(_ZOperationQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_Operation(pe, top, len, buffer, parm) \
    prnt_f(_ZOperationQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_Operation_P    _ZOperationQuipu, &_ZQuipu_mod

#define encode_Quipu_SubChainOps(pe, top, len, buffer, parm) \
    enc_f(_ZSubChainOpsQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char *) parm)

#define decode_Quipu_SubChainOps(pe, top, len, buffer, parm) \
    dec_f(_ZSubChainOpsQuipu, &_ZQuipu_mod, pe, top, len, buffer, (char **) parm)

#define print_Quipu_SubChainOps(pe, top, len, buffer, parm) \
    prnt_f(_ZSubChainOpsQuipu, &_ZQuipu_mod, pe, top, len, buffer)
#define print_Quipu_SubChainOps_P    _ZSubChainOpsQuipu, &_ZQuipu_mod


#endif   /* lint */
#include "qu-cdefs.h"
#ifndef	PEPYPATH
#include "IF-types.h"
#include "AF-types.h"
#else
#include "IF-types.h"
#include "AF-types.h"
#endif



#define	type_Quipu_ListACLSyntax	type_Quipu_SearchACLSyntax

#define	type_Quipu_TreeStructureSyntax	PElement

#define	type_Quipu_EntryDataBlock	PElement

#define	type_Quipu_EDBVersion	type_UNIV_UTCTime

struct type_Quipu_AuthenticationPolicy {
    integer     parm;
#define	int_Quipu_AuthenticationPolicy_trust__name	0
#define	int_Quipu_AuthenticationPolicy_simple	1
#define	int_Quipu_AuthenticationPolicy_strong	2
};
#define	free_Quipu_AuthenticationPolicy(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAuthenticationPolicyQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_AuthenticationPolicySyntax {
    struct type_Quipu_AuthenticationPolicy *modification;

    struct type_Quipu_AuthenticationPolicy *read__and__compare;

    struct type_Quipu_AuthenticationPolicy *list__and__search;
};
#define	free_Quipu_AuthenticationPolicySyntax(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAuthenticationPolicySyntaxQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_AccessSelector {
    int         offset;
#define	type_Quipu_AccessSelector_entry	1
#define	type_Quipu_AccessSelector_other	2
#define	type_Quipu_AccessSelector_prefix	3
#define	type_Quipu_AccessSelector_group	4

    union {
        char    entry;

        char    other;

        struct type_Quipu_NameList *prefix;

        struct type_Quipu_NameList *group;
    }       un;
};
#define	free_Quipu_AccessSelector(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAccessSelectorQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_AccessCategories {
    integer     parm;
#define	int_Quipu_AccessCategories_none	0
#define	int_Quipu_AccessCategories_detect	1
#define	int_Quipu_AccessCategories_compare	2
#define	int_Quipu_AccessCategories_read	3
#define	int_Quipu_AccessCategories_add	4
#define	int_Quipu_AccessCategories_write	5
};
#define	free_Quipu_AccessCategories(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAccessCategoriesQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_ACLInfo {
        struct element_Quipu_0 {
            struct type_Quipu_AccessSelector *element_Quipu_1;

            struct type_Quipu_AccessCategories *element_Quipu_2;
        } *member_Quipu_0;

        struct type_Quipu_ACLInfo *next;
};
#define	free_Quipu_ACLInfo(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZACLInfoQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_AttributeACL {
    struct member_Quipu_1 {
        OID     member_Quipu_2;

        struct member_Quipu_1 *next;
    } *element_Quipu_3;

    struct type_Quipu_ACLInfo *element_Quipu_4;
};
#define	free_Quipu_AttributeACL(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAttributeACLQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_ACLSyntax {
    struct type_Quipu_ACLInfo *childACL;

    struct type_Quipu_ACLInfo *entryACL;

    struct type_Quipu_ACLInfo *defaultAttributeACL;

    struct member_Quipu_3 {
        struct type_Quipu_AttributeACL *member_Quipu_4;

        struct member_Quipu_3 *next;
    } *element_Quipu_5;
};
#define	free_Quipu_ACLSyntax(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZACLSyntaxQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_SearchACLSyntax {
    struct type_Quipu_AccessSelector *who;

    PE      scope;
#define	bits_Quipu_scope	"\020\01subtree\02single-level\03base-object"
#define	bit_Quipu_scope_subtree	0
#define	bit_Quipu_scope_single__level	1
#define	bit_Quipu_scope_base__object	2

    struct choice_Quipu_0 {
        int         offset;
#define	choice_Quipu_0_unsearchable__attributes	1
#define	choice_Quipu_0_searchable	2

        union {
            struct member_Quipu_5 {
                OID     member_Quipu_6;

                struct member_Quipu_5 *next;
            } *unsearchable__attributes;

            struct element_Quipu_6 {
                integer     optionals;
#define	opt_Quipu_element_Quipu_6_min__key__length__in__substring (000000001)

                struct member_Quipu_7 {
                    OID     member_Quipu_8;

                    struct member_Quipu_7 *next;
                } *searchable__attributes;

                integer     max__results;

                integer     min__key__length__in__substring;

                char    zero__results__if__limit__exceeded;
            } *searchable;
        }       un;
    } *access;
};
#define	free_Quipu_SearchACLSyntax(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZSearchACLSyntaxQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_NameList {
        struct type_IF_DistinguishedName *member_Quipu_9;

        struct type_Quipu_NameList *next;
};
#define	free_Quipu_NameList(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZNameListQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_EDBInfoSyntax {
    struct type_IF_DistinguishedName *edb;

    struct type_IF_DistinguishedName *getFromDSA;

    struct type_Quipu_NameList *sendToDSAs;

    struct type_Quipu_NameList *getEDBAllowed;
};
#define	free_Quipu_EDBInfoSyntax(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZEDBInfoSyntaxQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_RelativeEntry {
    struct type_IF_RelativeDistinguishedName *element_Quipu_7;

    struct member_Quipu_10 {
        struct type_IF_Attribute *member_Quipu_11;

        struct member_Quipu_10 *next;
    } *element_Quipu_8;
};
#define	free_Quipu_RelativeEntry(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZRelativeEntryQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_GetEntryDataBlockArgument {
    integer     optionals;
#define	opt_Quipu_GetEntryDataBlockArgument_maxEntries (000000001)

    struct type_IF_DistinguishedName *entry;

    struct choice_Quipu_1 {
        int         offset;
#define	choice_Quipu_1_sendIfMoreRecentThan	1
#define	choice_Quipu_1_getVersionNumber	2
#define	choice_Quipu_1_getEDB	3
#define	choice_Quipu_1_continuation	4

        union {
            struct type_Quipu_EDBVersion *sendIfMoreRecentThan;

            char    getVersionNumber;

            char    getEDB;

            struct element_Quipu_9 {
                struct type_Quipu_EDBVersion *element_Quipu_10;

                integer     nextEntryPosition;
            } *continuation;
        }       un;
    } *member_Quipu_12;

    integer     maxEntries;
};
#define	free_Quipu_GetEntryDataBlockArgument(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZGetEntryDataBlockArgumentQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_GetEntryDataBlockResult {
    integer     optionals;
#define	opt_Quipu_GetEntryDataBlockResult_nextEntryPostion (000000001)

    struct type_Quipu_EDBVersion *versionHeld;

    struct type_Quipu_EntryDataBlock *element_Quipu_11;

    integer     nextEntryPostion;
};
#define	free_Quipu_GetEntryDataBlockResult(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZGetEntryDataBlockResultQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_ProtectedPassword {
    struct type_AF_AlgorithmIdentifier *algorithm;

    struct member_Quipu_13 {
        struct	qbuf	*time1;

        struct	qbuf	*time2;

        PE      random1;

        PE      random2;
    } *salt;

    struct qbuf *password;
};
#define	free_Quipu_ProtectedPassword(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZProtectedPasswordQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_InheritedList {
        struct choice_Quipu_2 {
            int         offset;
#define	choice_Quipu_2_1	1
#define	choice_Quipu_2_2	2

            union {
                struct type_IF_AttributeType *choice_Quipu_3;

                struct type_IF_Attribute *choice_Quipu_4;
            }       un;
        } *member_Quipu_14;

        struct type_Quipu_InheritedList *next;
};
#define	free_Quipu_InheritedList(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZInheritedListQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_InheritedAttribute {
    struct type_Quipu_InheritedList *idefault;

    struct type_Quipu_InheritedList *always;

    OID     objectclass;
};
#define	free_Quipu_InheritedAttribute(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZInheritedAttributeQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_DSAControl {
    int         offset;
#define	type_Quipu_DSAControl_lockdsa	1
#define	type_Quipu_DSAControl_setLogLevel	2
#define	type_Quipu_DSAControl_refresh	3
#define	type_Quipu_DSAControl_stopDSA	4
#define	type_Quipu_DSAControl_unlock	5
#define	type_Quipu_DSAControl_resynch	6
#define	type_Quipu_DSAControl_changeTailor	7
#define	type_Quipu_DSAControl_updateSlaveEDBs	8

    union {
        struct type_Quipu_OptionalDN *lockdsa;

        struct	qbuf	*setLogLevel;

        struct type_Quipu_OptionalDN *refresh;

        char    stopDSA;

        struct type_Quipu_OptionalDN *unlock;

        struct type_Quipu_OptionalDN *resynch;

        struct	qbuf	*changeTailor;

        struct	qbuf	*updateSlaveEDBs;
    }       un;
};
#define	free_Quipu_DSAControl(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZDSAControlQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_OptionalDN {
    int         offset;
#define	type_Quipu_OptionalDN_no__dn	1
#define	type_Quipu_OptionalDN_selectedDN	2

    union {
        char    no__dn;

        struct type_IF_DistinguishedName *selectedDN;
    }       un;
};
#define	free_Quipu_OptionalDN(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZOptionalDNQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_Call {
    integer     protocol;
#define	int_Quipu_protocol_dap	0
#define	int_Quipu_protocol_dsp	1
#define	int_Quipu_protocol_quipudsp	2
#define	int_Quipu_protocol_internetdsp	3

    integer     association__id;

    struct type_Quipu_AuthLevel *authorizationLevel;

    char    initiated__by__dsa;

    struct type_IF_DistinguishedName *usersDN;

    struct qbuf *net__address;

    struct	qbuf	*start__time;

    struct	qbuf	*finish__time;

    struct member_Quipu_15 {
        struct type_Quipu_Operation *member_Quipu_16;

        struct member_Quipu_15 *next;
    } *pending__operations;

    struct member_Quipu_17 {
        struct type_Quipu_Operation *member_Quipu_18;

        struct member_Quipu_17 *next;
    } *invoked__operations;
};
#define	free_Quipu_Call(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZCallQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_AuthLevel {
    integer     parm;
#define	int_Quipu_AuthLevel_none	0
#define	int_Quipu_AuthLevel_indentified	1
#define	int_Quipu_AuthLevel_simple	2
#define	int_Quipu_AuthLevel_protected__simple	3
#define	int_Quipu_AuthLevel_strong	4
};
#define	free_Quipu_AuthLevel(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZAuthLevelQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_Operation {
    integer     invoke__id;

    integer     operation__id;

    struct type_IF_DistinguishedName *base__object;

    struct	qbuf	*start__time;

    struct	qbuf	*finish__time;

    struct element_Quipu_12 {
        struct type_Quipu_SubChainOps *element_Quipu_13;

        struct element_Quipu_12 *next;
    } *chained__operations;
};
#define	free_Quipu_Operation(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZOperationQuipu], &_ZQuipu_mod, 1)

struct type_Quipu_SubChainOps {
    integer     association__id;

    integer     invoke__id;
};
#define	free_Quipu_SubChainOps(parm)\
	 fre_obj((char *) parm, _ZQuipu_mod.md_dtab[_ZSubChainOpsQuipu], &_ZQuipu_mod, 1)
#endif
