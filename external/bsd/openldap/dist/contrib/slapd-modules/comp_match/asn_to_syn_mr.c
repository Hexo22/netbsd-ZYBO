/*	$NetBSD: openldap2netbsd,v 1.3 2017/02/09 01:53:50 christos Exp $	*/

#include <component.h>
#include "asn.h"
#include "componentlib.h"
#include "certificate.h"

AsnTypetoMatchingRuleTable directory_component_matching_table[] = {
	"1.2.36.79672281.1.13.7",
{
	{ BASICTYPE_BOOLEAN,NULL,"1.3.6.1.4.1.1466.115.121.1.7", NULL },
        { BASICTYPE_INTEGER,NULL ,"1.3.6.1.4.1.1466.115.121.1.27", NULL },
        { BASICTYPE_BITSTRING,NULL ,"1.3.6.1.4.1.1466.115.121.1.6", NULL },
        { BASICTYPE_OCTETSTRING,NULL , "1.3.6.1.4.1.1466.115.121.1.40", NULL },
        { BASICTYPE_NULL,NULL , NULL, NULL },
        { BASICTYPE_OID,NULL ,"1.3.6.1.4.1.1466.115.121.1.38", NULL },
        { BASICTYPE_REAL,NULL , NULL, NULL },
        { BASICTYPE_ENUMERATED,NULL , NULL, NULL },
        { BASICTYPE_NUMERIC_STR, "numericStringMatch", "1.3.6.1.4.1.1466.115.121.1.36", NULL },
        { BASICTYPE_PRINTABLE_STR, "caseIgnoreMatch", "1.3.6.1.4.1.1466.115.121.1.44", NULL },
        { BASICTYPE_UNIVERSAL_STR, "caseIgnoreMatch" , NULL, NULL },
        { BASICTYPE_IA5_STR, "caseIgnoreMatch", "1.3.6.1.4.1.1466.115.121.1.26", NULL },
        { BASICTYPE_BMP_STR, "caseIgnoreMatch" , NULL, NULL },
        { BASICTYPE_UTF8_STR, "caseIgnoreMatch" , NULL, NULL },
        { BASICTYPE_UTCTIME, "uTCTimeMatch" , "1.3.6.1.4.1.1466.115.121.1.53", NULL },
        { BASICTYPE_GENERALIZEDTIME, "generalizedTimeMatch" ,"1.3.6.1.4.1.1466.115.121.1.24", NULL },
        { BASICTYPE_GRAPHIC_STR, "caseIgnoreMatch", NULL, NULL },
        { BASICTYPE_VISIBLE_STR, "caseIgnoreMatch", NULL, NULL },
        { BASICTYPE_GENERAL_STR, "caseIgnoreMatch", NULL, NULL },
        { BASICTYPE_OBJECTDESCRIPTOR, NULL , NULL, NULL },
        { BASICTYPE_VIDEOTEX_STR, "caseIgnoreMatch", NULL, NULL },
        { BASICTYPE_T61_STR, "caseIgnoreMatch", NULL, NULL },
        { BASICTYPE_OCTETCONTAINING, NULL , NULL, NULL },
        { BASICTYPE_BITCONTAINING, NULL , NULL, NULL },
        { BASICTYPE_RELATIVE_OID, NULL, "1.2.36.79672281.1.5.0", NULL },
        { RDNSequence, "distinguishedNameMatch" , NULL, NULL },
        { RelativeDistinguishedName, NULL , NULL, NULL },
        { TelephoneNumber, "telephoneNumberMatch" , "1.3.6.1.4.1.1466.115.121.1.50", NULL },
        { FacsimileTelephoneNumber__telephoneNumber, "telephoneNumberMatch","1.3.6.1.4.1.1466.115.121.1.22", NULL },
        { DirectoryString, "caseIgnoreMatch" ,"1.3.6.1.4.1.1466.115.121.1.15", NULL },
        { ASN_COMP_CERTIFICATE, NULL , "1.2.36.79672281.1.5.2" , NULL },
        { ASNTYPE_END , NULL , NULL, NULL }
},
	NULL
}; 

AsnTypetoSyntax asn_to_syntax_mapping_tbl[] = {
{ BASICTYPE_BOOLEAN,"Boolean","1.3.6.1.4.1.1466.115.121.1.7", NULL },
{ BASICTYPE_INTEGER,"Integer","1.3.6.1.4.1.1466.115.121.1.27", NULL },
{ BASICTYPE_BITSTRING,"Bit String","1.3.6.1.4.1.1466.115.121.1.6", NULL },
{ BASICTYPE_OCTETSTRING,"Octet String", "1.3.6.1.4.1.1466.115.121.1.40", NULL },
{ BASICTYPE_NULL,NULL, NULL, NULL },
{ BASICTYPE_OID,"OID","1.3.6.1.4.1.1466.115.121.1.38", NULL },
{ BASICTYPE_REAL,NULL, NULL, NULL },
{ BASICTYPE_ENUMERATED,"Integer", "1.3.6.1.4.1.1466.115.121.1.27", NULL },
{ BASICTYPE_NUMERIC_STR, "Numeric String", "1.3.6.1.4.1.1466.115.121.1.36", NULL },
{ BASICTYPE_PRINTABLE_STR, "Printable String", "1.3.6.1.4.1.1466.115.121.1.44", NULL },
{ BASICTYPE_UNIVERSAL_STR, NULL , NULL, NULL },
{ BASICTYPE_IA5_STR, "IA5 String", "1.3.6.1.4.1.1466.115.121.1.26", NULL },
{ BASICTYPE_BMP_STR, NULL , NULL, NULL },
{ BASICTYPE_UTF8_STR, "Directory String" , "1.3.6.1.4.1.1466.115.121.1.15", NULL },
{ BASICTYPE_UTCTIME, "UTC Time" , "1.3.6.1.4.1.1466.115.121.1.53", NULL },
{ BASICTYPE_GENERALIZEDTIME, "Generalized Time" ,"1.3.6.1.4.1.1466.115.121.1.24", NULL },
{ BASICTYPE_GRAPHIC_STR, NULL, NULL, NULL },
{ BASICTYPE_VISIBLE_STR, "Directory String", "1.3.6.1.4.1.1466.115.121.1.15", NULL },
{ BASICTYPE_GENERAL_STR, NULL, NULL, NULL },
{ BASICTYPE_OBJECTDESCRIPTOR, "Object Class Description", "1.3.6.1.4.1.1466.115.121.1.37", NULL },
{ BASICTYPE_VIDEOTEX_STR, NULL, NULL, NULL },
{ BASICTYPE_T61_STR, NULL, NULL, NULL },
{ BASICTYPE_OCTETCONTAINING, NULL , NULL, NULL },
{ BASICTYPE_BITCONTAINING, NULL , NULL, NULL },
{ BASICTYPE_RELATIVE_OID, "OID", "1.3.6.1.4.1.1466.115.121.1.38", NULL },
{ BASICTYPE_ANY, NULL, NULL, NULL },
{ COMPOSITE_ASN1_TYPE, NULL , NULL, NULL },
{ RDNSequence, "Distinguished Name" , "1.3.6.1.4.1.1466.115.121.1.12", NULL },
{ RelativeDistinguishedName, "RDN", "1.2.36.79672281.1.5.0", NULL },
{ TelephoneNumber, "Telephone Number" , "1.3.6.1.4.1.1466.115.121.1.50", NULL },
{ FacsimileTelephoneNumber__telephoneNumber, "Facsimile Telephone Number","1.3.6.1.4.1.1466.115.121.1.22", NULL },
{ DirectoryString, "Directory String" ,"1.3.6.1.4.1.1466.115.121.1.15", NULL },
{ ASN_COMP_CERTIFICATE, "componentCertificate", "1.2.36.79672281.1.5.2" , NULL },
{ ASNTYPE_END , NULL , NULL, NULL }
}; 

/*
 * This table describes relationship between an ASN.1 type and its
 * potential matching rules such as equality, approx, ordering, and substring
 * Based on the description of this table, the following ComponentType
 * table is initialized
 */
AsnTypetoCompMatchingRule asntype_to_compMR_mapping_tbl[] = {
{ BASICTYPE_BOOLEAN, "booleanMatch", NULL, NULL, NULL },
{ BASICTYPE_INTEGER, "integerMatch", NULL, "integerOrderingMatch", NULL },
{ BASICTYPE_BITSTRING, "bitStringMatch", NULL, NULL, NULL },
{ BASICTYPE_OCTETSTRING, "octetStringMatch", NULL, "octetStringOrderingMatch", NULL },
{ BASICTYPE_NULL, NULL, NULL, NULL, NULL },
{ BASICTYPE_OID, "objectIdentifierMatch", NULL, NULL, NULL },
{ BASICTYPE_REAL,  NULL, NULL, NULL, NULL },
{ BASICTYPE_ENUMERATED,  "integerMatch", NULL, "integerOrderingMatch", NULL },
{ BASICTYPE_NUMERIC_STR,  "numericStringMatch", NULL, "numericStringOrderingMatch", "numericStringSubstringsMatch"},
{ BASICTYPE_PRINTABLE_STR, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_UNIVERSAL_STR, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_IA5_STR, "caseIgnoreMatch", "IA5StringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_BMP_STR, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_UTF8_STR, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_UTCTIME, NULL, NULL, NULL, NULL },
{ BASICTYPE_GENERALIZEDTIME,  NULL, NULL, NULL, NULL },
{ BASICTYPE_GRAPHIC_STR, NULL, NULL, NULL, NULL },
{ BASICTYPE_VISIBLE_STR, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ BASICTYPE_GENERAL_STR, NULL, NULL, NULL, NULL },
{ BASICTYPE_OBJECTDESCRIPTOR, "objectIdentifierFirstComponentMatch", NULL, NULL, NULL },
{ BASICTYPE_VIDEOTEX_STR, NULL, NULL, NULL, NULL },
{ BASICTYPE_T61_STR, NULL, NULL, NULL, NULL },
{ BASICTYPE_OCTETCONTAINING,  NULL, NULL, NULL, NULL },
{ BASICTYPE_BITCONTAINING,  NULL, NULL, NULL, NULL },
{ BASICTYPE_RELATIVE_OID,  "objectIdentifierFirstComponentMatch", NULL, NULL, NULL },
{ BASICTYPE_ANY, NULL, NULL, NULL, NULL },
{ COMPOSITE_ASN1_TYPE,  NULL, NULL, NULL, NULL },
{ RDNSequence,  "distinguishedNameMatch", NULL, NULL, NULL },
{ RelativeDistinguishedName, "rdnMatch" , NULL, NULL, NULL },
{ TelephoneNumber, NULL, NULL, NULL, NULL },
{ FacsimileTelephoneNumber__telephoneNumber,  "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch" },
{ DirectoryString, "caseIgnoreMatch", "directoryStringApproxMatch", "caseIgnoreOrderingMatch", "caseIgnoreSubstringsMatch"},
{ ASN_COMP_CERTIFICATE, "componentFilterMatch", NULL, NULL, NULL },
{ ASNTYPE_END, NULL, NULL, NULL, NULL }
};

/*
 * This table mapps an ASN type to a corresponding ComponentType which has
 * equivalent contents of an existing AttributeType
 */
AsnTypetoCompType asntype_to_compType_mapping_tbl[] = {
{ BASICTYPE_BOOLEAN,{}},
{ BASICTYPE_INTEGER, {}},
{ BASICTYPE_BITSTRING, {}},
{ BASICTYPE_OCTETSTRING, {}},
{ BASICTYPE_NULL, {}},
{ BASICTYPE_OID, {}},
{ BASICTYPE_REAL, {}},
{ BASICTYPE_ENUMERATED, {}},
{ BASICTYPE_NUMERIC_STR, {}},
{ BASICTYPE_PRINTABLE_STR, {}},
{ BASICTYPE_UNIVERSAL_STR, {}},
{ BASICTYPE_IA5_STR, {}},
{ BASICTYPE_BMP_STR, {}},
{ BASICTYPE_UTF8_STR, {}},
{ BASICTYPE_UTCTIME, {}},
{ BASICTYPE_GENERALIZEDTIME, {}},
{ BASICTYPE_GRAPHIC_STR, {}},
{ BASICTYPE_VISIBLE_STR, {}},
{ BASICTYPE_GENERAL_STR,{}},
{ BASICTYPE_OBJECTDESCRIPTOR, {}},
{ BASICTYPE_VIDEOTEX_STR, {}},
{ BASICTYPE_T61_STR, {}},
{ BASICTYPE_OCTETCONTAINING, {}},
{ BASICTYPE_BITCONTAINING, {}},
{ BASICTYPE_RELATIVE_OID, {}},
{ BASICTYPE_ANY, {}},
{ COMPOSITE_ASN1_TYPE, {}},
{ RDNSequence, {}},
{ RelativeDistinguishedName, {}}, 
{ TelephoneNumber, {}},
{ FacsimileTelephoneNumber__telephoneNumber, {}},
{ DirectoryString, {}},
{ ASN_COMP_CERTIFICATE, {}},
{ ASNTYPE_END , {}}
};

AsnTypetoCompDesc asntype_to_compdesc_mapping_tbl[] = {
{ BASICTYPE_BOOLEAN, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_BOOLEAN,
	(encoder_func*)NULL,(encoder_func*)GEncComponentBool,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentBool,(ber_decoder_func*)BDecComponentBool,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentBool}},
{ BASICTYPE_INTEGER, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_INTEGER,
	(encoder_func*)NULL,(encoder_func*)GEncComponentInt,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentInt,(ber_decoder_func*)BDecComponentInt,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentInt}},
{ BASICTYPE_BITSTRING, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_BITSTRING,
	(encoder_func*)NULL,(encoder_func*)GEncComponentBits,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentBits,(ber_decoder_func*)BDecComponentBits,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentBits}},
{ BASICTYPE_OCTETSTRING, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_OCTETSTRING,
	(encoder_func*)NULL,(encoder_func*)GEncComponentOcts,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentOcts,(ber_decoder_func*)BDecComponentOcts,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentOcts}},
{ BASICTYPE_NULL, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_NULL,
	(encoder_func*)NULL,(encoder_func*)GEncComponentNull,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentNull,(ber_decoder_func*)BDecComponentNull,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentNull}},
{ BASICTYPE_OID, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_OID,
	(encoder_func*)NULL,(encoder_func*)GEncComponentOid,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentOid,(ber_decoder_func*)BDecComponentOid,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentOid}},
{ BASICTYPE_REAL, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_REAL,
	(encoder_func*)NULL,(encoder_func*)GEncComponentReal,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentReal,(ber_decoder_func*)BDecComponentReal,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentReal}},
{ BASICTYPE_ENUMERATED, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_ENUMERATED,
	(encoder_func*)NULL,(encoder_func*)GEncComponentEnum,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentEnum,(ber_decoder_func*)BDecComponentEnum,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentEnum}},
{ BASICTYPE_NUMERIC_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_NUMERIC_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentNumericString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentNumericString,(ber_decoder_func*)BDecComponentNumericString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentNumericString}},
{ BASICTYPE_PRINTABLE_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_PRINTABLE_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentPrintableString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentPrintableString,(ber_decoder_func*)BDecComponentPrintableString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentPrintableString}},
{ BASICTYPE_UNIVERSAL_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_UNIVERSAL_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUniversalString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUniversalString,(ber_decoder_func*)BDecComponentUniversalString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUniversalString}},
{ BASICTYPE_IA5_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_IA5_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentIA5String,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentIA5String,(ber_decoder_func*)BDecComponentIA5String,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentIA5String}},
{ BASICTYPE_BMP_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_BMP_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentBMPString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentBMPString,(ber_decoder_func*)BDecComponentBMPString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentBMPString}},
{ BASICTYPE_UTF8_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_UTF8_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTF8String,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTF8String,(ber_decoder_func*)BDecComponentUTF8String,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTF8String}},
{ BASICTYPE_UTCTIME, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_UTCTIME,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTCTime,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTCTime,(ber_decoder_func*)BDecComponentUTCTime,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTCTime}},
{ BASICTYPE_GENERALIZEDTIME, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_GENERALIZEDTIME,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTCTime,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTCTime,(ber_decoder_func*)BDecComponentUTCTime,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTCTime}},
{ BASICTYPE_GRAPHIC_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_GRAPHIC_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentPrintableString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentPrintableString,(ber_decoder_func*)BDecComponentPrintableString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentPrintableString}},
{ BASICTYPE_VISIBLE_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_VISIBLE_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentVisibleString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentVisibleString,(ber_decoder_func*)BDecComponentVisibleString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentVisibleString}},
{ BASICTYPE_GENERAL_STR,{ -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_GENERAL_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTF8String,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTF8String,(ber_decoder_func*)BDecComponentUTF8String,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTF8String}},
{ BASICTYPE_OBJECTDESCRIPTOR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_OBJECTDESCRIPTOR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTF8String,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTF8String,(ber_decoder_func*)BDecComponentUTF8String,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTF8String}},
{ BASICTYPE_VIDEOTEX_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_VIDEOTEX_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentTeletexString,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentTeletexString,(ber_decoder_func*)BDecComponentTeletexString,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentTeletexString}},
{ BASICTYPE_T61_STR, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_T61_STR,
	(encoder_func*)NULL,(encoder_func*)GEncComponentUTF8String,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentUTF8String,(ber_decoder_func*)BDecComponentUTF8String,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentUTF8String}},
{ BASICTYPE_OCTETCONTAINING, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_OCTETCONTAINING,
	(encoder_func*)NULL,(encoder_func*)NULL,(encoder_func*)NULL,
	(gser_decoder_func*)NULL,(ber_decoder_func*)NULL,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,NULL}},
{ BASICTYPE_BITCONTAINING, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_BITCONTAINING,
	(encoder_func*)NULL,(encoder_func*)NULL,(encoder_func*)NULL,
	(gser_decoder_func*)NULL,(ber_decoder_func*)NULL,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,NULL}},
{ BASICTYPE_RELATIVE_OID, { -1, NULL, {},{},0,ASN_BASIC,BASICTYPE_RELATIVE_OID,
	(encoder_func*)NULL,(encoder_func*)GEncComponentRelativeOid,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentRelativeOid,(ber_decoder_func*)BDecComponentRelativeOid,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentRelativeOid}},
{ BASICTYPE_ANY, {}},
{ COMPOSITE_ASN1_TYPE, {}},
{ RDNSequence, { -1, NULL, {},{},0,ASN_COMPOSITE,RDNSequence,
	(encoder_func*)ConvertRDNSequence2RFC2253,(encoder_func*)NULL,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentRDNSequence,(ber_decoder_func*)BDecComponentRDNSequence,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentRDNSequence}},
{ RelativeDistinguishedName, { -1, NULL, {},{},0,ASN_COMPOSITE,RDNSequence,
	(encoder_func*)ConvertRDNSequence2RFC2253,(encoder_func*)NULL,(encoder_func*)NULL,
	(gser_decoder_func*)GDecComponentRDNSequence,(ber_decoder_func*)BDecComponentRDNSequence,
	(comp_free_func*)NULL,(extract_component_from_id_func*)NULL,MatchingComponentRDNSequence}}, 
{ TelephoneNumber, {}},
{ FacsimileTelephoneNumber__telephoneNumber, {}},
{ DirectoryString, {}},
{ ASN_COMP_CERTIFICATE, {}},
{ ASNTYPE_END , {}}
};