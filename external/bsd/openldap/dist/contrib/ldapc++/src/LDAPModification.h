/*	$NetBSD: openldap2netbsd,v 1.3 2017/02/09 01:53:50 christos Exp $	*/

// $OpenLDAP$
/*
 * Copyright 2000-2017 The OpenLDAP Foundation, All Rights Reserved.
 * COPYING RESTRICTIONS APPLY, see COPYRIGHT file
 */


#ifndef LDAP_MODIFICATION_H
#define LDAP_MODIFICATION_H

#include <ldap.h>
#include <LDAPAttribute.h>

class LDAPModification{
	public:
		enum mod_op {OP_ADD, OP_DELETE, OP_REPLACE};

		LDAPModification(const LDAPAttribute& attr, mod_op op);
		LDAPMod *toLDAPMod() const;

		const LDAPAttribute* getAttribute() const;
		mod_op getOperation() const;

	private:
		LDAPAttribute m_attr;
		mod_op m_mod_op;

};
#endif //LDAP_MODIFICATION_H
