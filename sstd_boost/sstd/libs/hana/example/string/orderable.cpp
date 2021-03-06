﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/greater.hpp>
#include <sstd/boost/hana/less.hpp>
#include <sstd/boost/hana/string.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTANT_CHECK(
        BOOST_HANA_STRING("abc") < BOOST_HANA_STRING("bcd")
    );

    BOOST_HANA_CONSTANT_CHECK(
        BOOST_HANA_STRING("abcd") > BOOST_HANA_STRING("abc")
    );
}

