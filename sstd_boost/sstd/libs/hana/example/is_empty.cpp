﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/is_empty.hpp>
#include <sstd/boost/hana/not.hpp>
#include <sstd/boost/hana/tuple.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(!hana::is_empty(hana::make_tuple(1, '2')));
BOOST_HANA_CONSTANT_CHECK( hana::is_empty(hana::make_tuple()));

int main() { }
