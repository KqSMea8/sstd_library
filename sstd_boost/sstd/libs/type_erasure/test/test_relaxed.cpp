﻿// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#include <sstd/boost/type_erasure/any.hpp>
#include <sstd/boost/type_erasure/tuple.hpp>
#include <sstd/boost/type_erasure/builtin.hpp>
#include <sstd/boost/type_erasure/operators.hpp>
#include <sstd/boost/type_erasure/any_cast.hpp>
#include <sstd/boost/type_erasure/relaxed.hpp>
#include <sstd/boost/mpl/vector.hpp>

#define BOOST_TEST_MAIN
#include <sstd/boost/test/unit_test.hpp>

using namespace boost::type_erasure;

template<class T = _self>
struct common : ::boost::mpl::vector<
    copy_constructible<T>,
    typeid_<T>
> {};

BOOST_AUTO_TEST_CASE(test_simple)
{
    typedef ::boost::mpl::vector<copy_constructible<>, addable<>, relaxed> src_concept;
    any<src_concept> x(1);
    any<src_concept> y(2.0);
    BOOST_CHECK_THROW(x + y, bad_function_call);
}

