﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/ext/boost/fusion/vector.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/transform.hpp>

#include <sstd/boost/fusion/include/make_vector.hpp>
#include <sstd/boost/fusion/include/vector.hpp>

#include <string>
namespace fusion = boost::fusion;
namespace hana = boost::hana;


struct Fish { std::string name; };
struct Cat  { std::string name; };
struct Dog  { std::string name; };

int main() {
    fusion::vector<Fish, Cat, Dog> animals{Fish{"Nemo"}, Cat{"Garfield"}, Dog{"Snoopy"}};
    hana::front(animals).name = "Moby Dick";

    auto names = hana::transform(animals, [](auto a) {
      return a.name;
    });

    BOOST_HANA_RUNTIME_CHECK(hana::equal(
        names,
        fusion::make_vector("Moby Dick", "Garfield", "Snoopy")
    ));
}

