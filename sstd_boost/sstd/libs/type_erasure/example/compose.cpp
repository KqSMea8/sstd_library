﻿// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#include <sstd/boost/type_erasure/builtin.hpp>
#include <sstd/boost/type_erasure/operators.hpp>
#include <sstd/boost/mpl/vector.hpp>

namespace mpl = boost::mpl;
using namespace boost::type_erasure;

//[compose1
/*`
    Multiple concepts can be composed using an MPL sequence.
*/
template<class T = _self>
struct arithmetic :
    mpl::vector<
        copy_constructible<T>,
        addable<T>,
        subtractable<T>,
        multipliable<T>,
        dividable<T>,
        equality_comparable<T>,
        less_than_comparable<T>
    >
{};
/*`
    Now, `arithmetic` is a concept that can be used just
    like any of the base concepts.
*/
//]

//[compose
//` (For the source of the examples in this section see
//` [@boost:/libs/type_erasure/example/compose.cpp compose.cpp])
//` [compose1]
//]

