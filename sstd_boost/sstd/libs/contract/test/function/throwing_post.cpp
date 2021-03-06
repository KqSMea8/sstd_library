﻿
// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

// Test throw from free function .post().

#include "../detail/oteststream.hpp"
#include <sstd/boost/contract/function.hpp>
#include <sstd/boost/contract/check.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstream>

boost::contract::test::detail::oteststream out;

struct err {}; // Global decl so visible in MSVC10 lambdas.

void f() {
    boost::contract::check c = boost::contract::function()
        .precondition([] { out << "f::pre" << std::endl; })
        .old([] { out << "f::old" << std::endl; })
        .postcondition([] {
            out << "f::post" << std::endl;
            throw err(); // Test this throws.
        })
        .except([] { out << "f::except" << std::endl; })
    ;
    out << "f::body" << std::endl;
}

int main() {
    std::ostringstream ok;

    boost::contract::set_postcondition_failure(
            [] (boost::contract::from) { throw; });

    try {
        out.str("");
        f();
        #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
                BOOST_TEST(false);
            } catch(err const&) {
        #endif
        ok.str(""); ok << "" // Suppress a warning.
            #ifndef BOOST_CONTRACT_NO_PRECONDITIONS
                << "f::pre" << std::endl
            #endif
            #ifndef BOOST_CONTRACT_NO_OLDS
                << "f::old" << std::endl
            #endif
            << "f::body" << std::endl
            #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
                << "f::post" << std::endl // Test this threw.
            #endif
        ;
        BOOST_TEST(out.eq(ok.str()));
    } catch(...) { BOOST_TEST(false); }

    return boost::report_errors();
}


