﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/string.hpp>
#include <sstd/boost/hana/tuple.hpp>
#include <sstd/boost/hana/unpack.hpp>
namespace hana = boost::hana;


constexpr auto vowels = hana::tuple_c<char, 'a', 'e', 'i', 'o', 'u', 'y'>;
constexpr auto str = hana::unpack(vowels, hana::make<hana::string_tag>);
BOOST_HANA_CONSTANT_CHECK(str == BOOST_HANA_STRING("aeiouy"));

int main() { }

