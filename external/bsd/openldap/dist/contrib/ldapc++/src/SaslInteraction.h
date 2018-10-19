/*	$NetBSD: openldap2netbsd,v 1.3 2017/02/09 01:53:50 christos Exp $	*/

// $OpenLDAP$
/*
 * Copyright 2007-2017 The OpenLDAP Foundation, All Rights Reserved.
 * COPYING RESTRICTIONS APPLY, see COPYRIGHT file
 */

#ifndef SASL_INTERACTION_H
#define SASL_INTERACTION_H

#include <string>
#include <sasl/sasl.h>

class SaslInteraction {
    public:
        SaslInteraction( sasl_interact_t *interact );
        ~SaslInteraction();
        unsigned long getId() const;
        const std::string getPrompt() const;
        const std::string getChallenge() const;
        const std::string getDefaultResult() const;

        void setResult(const std::string &res);

    private:
        sasl_interact_t *m_interact;
        std::string m_result;

};
#endif /* SASL_INTERACTION_H */