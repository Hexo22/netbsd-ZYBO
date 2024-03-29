/* $NetBSD: t_fmod.c$ */

/*-
 * Copyright (c) 2014 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Joerg Sonnenberger.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <atf-c.h>
#include <float.h>
#include <math.h>

ATF_TC(modf);
ATF_TC_HEAD(modf, tc)
{
	atf_tc_set_md_var(tc, "descr","Check modf family");
}

ATF_TC_BODY(modf, tc)
{
	float basef;
	double base;
	long double basel;
	ATF_CHECK(modff(1.0, &basef) == 0.0);
	ATF_CHECK(basef == 1.0);
	ATF_CHECK(modf(1.0, &base) == 0.0);
	ATF_CHECK(base == 1.0);
	ATF_CHECK(modfl(1.0, &basel) == 0.0);
	ATF_CHECK(basel == 1.0);

	ATF_CHECK(modff(-1 - FLT_EPSILON, &basef) == -FLT_EPSILON);
	ATF_CHECK(basef == -1.0);
	ATF_CHECK(modf(-1 - DBL_EPSILON, &base) == -DBL_EPSILON);
	ATF_CHECK(base == -1.0);
	ATF_CHECK(modfl(-1 - LDBL_EPSILON, &basel) == -LDBL_EPSILON);
	ATF_CHECK(basel == -1.0);
}

ATF_TP_ADD_TCS(tp)
{

	ATF_TP_ADD_TC(tp, modf);

	return atf_no_error();
}
