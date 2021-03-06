﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/insert.hpp>
#include <sstd/boost/hana/map.hpp>
#include <sstd/boost/hana/pair.hpp>
#include <sstd/boost/hana/type.hpp>

#include <string>
namespace hana = boost::hana;
using namespace std::literals;


int main() {
    auto m = hana::make_map(
        hana::make_pair(hana::type_c<int>, "abcd"s),
        hana::make_pair(hana::type_c<void>, 1234)
    );

    BOOST_HANA_RUNTIME_CHECK(
        hana::insert(m, hana::make_pair(hana::type_c<float>, 'x')) ==
        hana::make_map(
            hana::make_pair(hana::type_c<int>, "abcd"s),
            hana::make_pair(hana::type_c<void>, 1234),
            hana::make_pair(hana::type_c<float>, 'x')
        )
    );

    BOOST_HANA_RUNTIME_CHECK(hana::insert(m, hana::make_pair(hana::type_c<void>, 'x')) == m);
}

