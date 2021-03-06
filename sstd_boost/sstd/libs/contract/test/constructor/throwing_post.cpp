﻿
// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

// Test throw form constructor .post() (in middle branch of inheritance tree).

#include "../detail/oteststream.hpp"
#include <sstd/boost/contract/constructor.hpp>
#include <sstd/boost/contract/base_types.hpp>
#include <sstd/boost/contract/check.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstream>

boost::contract::test::detail::oteststream out;

struct c
    #define BASES private boost::contract::constructor_precondition<c>
    : BASES
{
    typedef BOOST_CONTRACT_BASE_TYPES(BASES) base_types;
    #undef BASES

    static void static_invariant() { out << "c::static_inv" << std::endl; }
    void invariant() const { out << "c::inv" << std::endl; }

    c() :
        boost::contract::constructor_precondition<c>([] {
            out << "c::ctor::pre" << std::endl;
        })
    {
        boost::contract::check c = boost::contract::constructor(this)
            .old([] { out << "c::ctor::old" << std::endl; })
            .postcondition([] { out << "c::ctor::post" << std::endl; })
            .except([] { out << "c::ctor::except" << std::endl; })
        ;
        out << "c::ctor::body" << std::endl;
        // Do not throw (from inheritance root).
    }
};

struct b_err {}; // Global decl so visible in MSVC10 lambdas.

struct b
    #define BASES private boost::contract::constructor_precondition<b>, public c
    : BASES
{
    typedef BOOST_CONTRACT_BASE_TYPES(BASES) base_types;
    #undef BASES

    static void static_invariant() { out << "b::static_inv" << std::endl; }
    void invariant() const { out << "b::inv" << std::endl; }

    b() :
        boost::contract::constructor_precondition<b>([] {
            out << "b::ctor::pre" << std::endl;
        })
    {
        boost::contract::check c = boost::contract::constructor(this)
            .old([] { out << "b::ctor::old" << std::endl; })
            .postcondition([] {
                out << "b::ctor::post" << std::endl;
                throw b_err(); // Test this throws (from mid branch).
            })
            .except([] { out << "b::ctor::except" << std::endl; })
        ;
        out << "b::ctor::body" << std::endl;
    }
};

struct a
    #define BASES private boost::contract::constructor_precondition<a>, public b
    : BASES
{
    typedef BOOST_CONTRACT_BASE_TYPES(BASES) base_types;
    #undef BASES

    static void static_invariant() { out << "a::static_inv" << std::endl; }
    void invariant() const { out << "a::inv" << std::endl; }

    a() :
        boost::contract::constructor_precondition<a>([] {
            out << "a::ctor::pre" << std::endl;
        })
    {
        boost::contract::check c = boost::contract::constructor(this)
            .old([] { out << "a::ctor::old" << std::endl; })
            .postcondition([] { out << "a::ctor::post" << std::endl; })
            .except([] { out << "a::ctor::except" << std::endl; })
        ;
        out << "a::ctor::body" << std::endl;
        // Do not throw (from inheritance leaf).
    }
};

int main() {
    std::ostringstream ok;

    boost::contract::set_postcondition_failure(
            [] (boost::contract::from) { throw; });

    try {
        out.str("");
        a aa;
        #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
                BOOST_TEST(false);
            } catch(b_err const&) {
        #endif
        ok.str(""); ok
            #ifndef BOOST_CONTRACT_NO_PRECONDITIONS
                << "a::ctor::pre" << std::endl
                << "b::ctor::pre" << std::endl
                << "c::ctor::pre" << std::endl
            #endif

            #ifndef BOOST_CONTRACT_NO_ENTRY_INVARIANTS
                << "c::static_inv" << std::endl
            #endif
            #ifndef BOOST_CONTRACT_NO_OLDS
                << "c::ctor::old" << std::endl
            #endif
            << "c::ctor::body" << std::endl
            #ifndef BOOST_CONTRACT_NO_EXIT_INVARIANTS
                << "c::static_inv" << std::endl
                << "c::inv" << std::endl
            #endif
            #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
                << "c::ctor::post" << std::endl
            #endif

            #ifndef BOOST_CONTRACT_NO_ENTRY_INVARIANTS
                << "b::static_inv" << std::endl
            #endif
            #ifndef BOOST_CONTRACT_NO_OLDS
                << "b::ctor::old" << std::endl
            #endif
            << "b::ctor::body" << std::endl
            #ifndef BOOST_CONTRACT_NO_EXIT_INVARIANTS
                << "b::static_inv" << std::endl
                << "b::inv" << std::endl
            #endif
            #ifndef BOOST_CONTRACT_NO_POSTCONDITIONS
                << "b::ctor::post" << std::endl // Test this threw.
            #else
                #ifndef BOOST_CONTRACT_NO_ENTRY_INVARIANTS
                    << "a::static_inv" << std::endl
                #endif
                #ifndef BOOST_CONTRACT_NO_OLDS
                    << "a::ctor::old" << std::endl
                #endif
                << "a::ctor::body" << std::endl
                #ifndef BOOST_CONTRACT_NO_EXIT_INVARIANTS
                    << "a::static_inv" << std::endl
                    << "a::inv" << std::endl
                #endif
            #endif
        ;
        BOOST_TEST(out.eq(ok.str()));
    } catch(...) { BOOST_TEST(false); }

    return boost::report_errors();
}


