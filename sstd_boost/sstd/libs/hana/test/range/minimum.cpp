﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/core/make.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/minimum.hpp>
#include <sstd/boost/hana/range.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::minimum(hana::make_range(hana::int_c<3>, hana::int_c<4>)),
        hana::int_c<3>
    ));
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::minimum(hana::make_range(hana::int_c<3>, hana::int_c<5>)),
        hana::int_c<3>
    ));
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::minimum(hana::make_range(hana::int_c<-1>, hana::int_c<5>)),
        hana::int_c<-1>
    ));
}

