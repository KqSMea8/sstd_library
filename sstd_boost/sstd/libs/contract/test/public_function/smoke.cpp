﻿
// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

// Test public member function subcontracting.

#include "smoke.hpp"
#include <sstd/boost/preprocessor/control/iif.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstream>

int main() {
    std::ostringstream ok;

    a aa; // Test call to derived out-most leaf.
    s_type s; s.value = "A";
    out.str("");
    result_type& r = aa.f(s);

    ok.str(""); ok
        #ifndef BOOST_CONTRACT_NO_ENTRY_INVARIANTS
            << "d::static_inv" << std::endl
            << "d::inv" << std::endl
            << "e::static_inv" << std::endl
            << "e::inv" << std::endl
            << "c::static_inv" << std::endl
            << "c::inv" << std::endl
            << "a::static_inv" << std::endl
            << "a::inv" << std::endl
        #endif
        #ifndef BOOST_CONTRACT_NO_PRECONDITIONS
            << "d::f::pre" << std::endl
            << "e::f::pre" << std::endl
            << "c::f::pre" << std::endl
            << "a::f::pre" << std::endl
        #endif
        #ifndef BOOST_CONTRACT_NO_OLDS
            << "d::f::old" << std::endl
            << "e::f::old" << std::endl
            << "c::f::old" << std::endl
            << "a::f::old" << std::endl
        #endif
        << "a::f::body" << std::endl
        #ifndef BOOST_CONTRACT_NO_EXIT_INVARIANTS
            << "d::static_inv" << std::endl
            << "d::inv" << std::endl
            << "e::static_inv" << std::endl
            << "e::inv" << std::endl
            << "c::static_inv" << std::endl
            << "c::inv" << std::endl
            << "a::static_inv" << std::endl
            << "a::inv" << std::endl
        #endif
        #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
            << "d::f::old" << std::endl
            << "d::f::post" << std::endl
            << "e::f::old" << std::endl
            << "e::f::post" << std::endl
            << "c::f::old" << std::endl
            << "c::f::post" << std::endl
            // No old call here because not a base object.
            << "a::f::post" << std::endl
        #endif
    ;
    BOOST_TEST(out.eq(ok.str()));

    #ifndef BOOST_CONTRACT_NO_OLDS
        #define BOOST_CONTRACT_TEST_old 1u
    #else
        #define BOOST_CONTRACT_TEST_old 0u
    #endif

    BOOST_TEST_EQ(r.value, "A");
    BOOST_TEST_EQ(s.value, "acde");
    BOOST_TEST_EQ(s.copies(), BOOST_CONTRACT_TEST_old * 4);
    BOOST_TEST_EQ(s.evals(), BOOST_CONTRACT_TEST_old * 4);
    BOOST_TEST_EQ(s.ctors(), s.dtors() + 1); // 1 for local var.

    BOOST_TEST_EQ(aa.x.value, "aA");
    BOOST_TEST_EQ(aa.x.copies(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.x.evals(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.x.ctors(), aa.x.dtors() + 1); // 1 for member var.

    BOOST_TEST_EQ(aa.y.value, "cA");
    BOOST_TEST_EQ(aa.y.copies(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.y.evals(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.y.ctors(), aa.y.dtors() + 1); // 1 for member var.

    BOOST_TEST_EQ(aa.t<'d'>::z.value, "dA");
    BOOST_TEST_EQ(aa.t<'d'>::z.copies(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.t<'d'>::z.evals(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.t<'d'>::z.ctors(), aa.t<'d'>::z.dtors() + 1); // 1 member.

    BOOST_TEST_EQ(aa.t<'e'>::z.value, "eA");
    BOOST_TEST_EQ(aa.t<'e'>::z.copies(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.t<'e'>::z.evals(), BOOST_CONTRACT_TEST_old);
    BOOST_TEST_EQ(aa.t<'e'>::z.ctors(), aa.t<'e'>::z.dtors() + 1); // 1 member.

    #undef BOOST_CONTRACT_TEST_old
    return boost::report_errors();
}


