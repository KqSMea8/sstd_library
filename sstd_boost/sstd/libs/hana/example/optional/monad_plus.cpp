﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/concat.hpp>
#include <sstd/boost/hana/empty.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/optional.hpp>
namespace hana = boost::hana;


static_assert(hana::concat(hana::nothing, hana::just('x')) == hana::just('x'), "");
BOOST_HANA_CONSTANT_CHECK(hana::concat(hana::nothing, hana::nothing) == hana::nothing);
static_assert(hana::concat(hana::just('x'), hana::just('y')) == hana::just('x'), "");
BOOST_HANA_CONSTANT_CHECK(hana::empty<hana::optional_tag>() == hana::nothing);

int main() { }

