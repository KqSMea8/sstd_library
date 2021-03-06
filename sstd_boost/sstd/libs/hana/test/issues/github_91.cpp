﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/concept/comparable.hpp>
#include <sstd/boost/hana/concept/euclidean_ring.hpp>
#include <sstd/boost/hana/concept/group.hpp>
#include <sstd/boost/hana/concept/monoid.hpp>
#include <sstd/boost/hana/concept/orderable.hpp>
#include <sstd/boost/hana/concept/ring.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
namespace hana = boost::hana;


using T = decltype(hana::int_c<1>);

static_assert(hana::Comparable<T>::value, "");
static_assert(hana::Orderable<T>::value, "");
static_assert(hana::Monoid<T>::value, "");
static_assert(hana::Group<T>::value, "");
static_assert(hana::Ring<T>::value, "");
static_assert(hana::EuclideanRing<T>::value, "");

int main() { }

