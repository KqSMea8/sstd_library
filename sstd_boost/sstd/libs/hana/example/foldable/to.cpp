﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/core/to.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/optional.hpp>
#include <sstd/boost/hana/range.hpp>
#include <sstd/boost/hana/tuple.hpp>
namespace hana = boost::hana;


int main() {
    static_assert(hana::to<hana::tuple_tag>(hana::just(1)) == hana::make_tuple(1), "");
    BOOST_HANA_CONSTANT_CHECK(hana::to<hana::tuple_tag>(hana::nothing) == hana::make_tuple());

    BOOST_HANA_CONSTANT_CHECK(
        hana::to<hana::tuple_tag>(hana::make_range(hana::int_c<3>, hana::int_c<6>))
            ==
        hana::tuple_c<int, 3, 4, 5>
    );
}

