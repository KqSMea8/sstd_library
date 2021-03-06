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
#include <sstd/boost/mpl/vector.hpp>
#include <sstd/boost/fusion/include/at_c.hpp>
#include <sstd/boost/fusion/include/front.hpp>
#include <sstd/boost/fusion/include/back.hpp>
#include <sstd/boost/fusion/include/size.hpp>
#include <sstd/boost/fusion/include/empty.hpp>
#include <sstd/boost/fusion/include/begin.hpp>
#include <sstd/boost/fusion/include/end.hpp>
#include <sstd/boost/fusion/include/distance.hpp>
#include <sstd/boost/fusion/include/next.hpp>
#include <sstd/boost/fusion/include/prior.hpp>
#include <sstd/boost/fusion/include/equal_to.hpp>
#include <sstd/boost/fusion/include/advance.hpp>
#include <sstd/boost/fusion/include/deref.hpp>
#include <sstd/boost/fusion/include/value_of.hpp>

#define BOOST_TEST_MAIN
#include <sstd/boost/test/unit_test.hpp>

using namespace boost::type_erasure;

template<class T = _self>
struct common : ::boost::mpl::vector<
    copy_constructible<T>,
    typeid_<T>
> {};

BOOST_AUTO_TEST_CASE(test_same)
{
    tuple<common<_a>, _a, _a> t(1, 2);
    BOOST_CHECK_EQUAL(any_cast<int&>(get<0>(t)), 1);
    BOOST_CHECK_EQUAL(any_cast<int&>(get<1>(t)), 2);
}

BOOST_AUTO_TEST_CASE(test_degenerate)
{
    tuple<boost::mpl::vector<> > t;
}

template<class T>
typename T::value_type get_static(T) { return T::value; }

BOOST_AUTO_TEST_CASE(test_fusion)
{
    typedef boost::mpl::vector<common<_a>, common<_b>, addable<_a, _b> > test_concept;
    tuple<test_concept, _a, _b> t(2.0, 1);
    BOOST_CHECK_EQUAL(any_cast<double&>(boost::fusion::at_c<0>(t)), 2.0);
    BOOST_CHECK_EQUAL(any_cast<int&>(boost::fusion::at_c<1>(t)), 1);
    BOOST_CHECK_EQUAL(any_cast<double&>(boost::fusion::front(t)), 2.0);
    BOOST_CHECK_EQUAL(any_cast<int&>(boost::fusion::back(t)), 1);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::empty(t)), false);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::size(t)), 2);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::begin(t), boost::fusion::end(t))), 2);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::next(boost::fusion::begin(t)), boost::fusion::end(t))), 1);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::begin(t), boost::fusion::prior(boost::fusion::end(t)))), 1);

    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::advance_c<2>(boost::fusion::begin(t)), boost::fusion::end(t))), 0);
    BOOST_CHECK_EQUAL(any_cast<double&>(boost::fusion::deref(boost::fusion::begin(t))), 2.0);
}

BOOST_AUTO_TEST_CASE(test_fusion_const)
{
    typedef boost::mpl::vector<common<_a>, common<_b>, addable<_a, _b> > test_concept;
    const tuple<test_concept, _a, _b> t(2.0, 1);
    BOOST_CHECK_EQUAL(any_cast<const double&>(boost::fusion::at_c<0>(t)), 2.0);
    BOOST_CHECK_EQUAL(any_cast<const int&>(boost::fusion::at_c<1>(t)), 1);
    BOOST_CHECK_EQUAL(any_cast<const double&>(boost::fusion::front(t)), 2.0);
    BOOST_CHECK_EQUAL(any_cast<const int&>(boost::fusion::back(t)), 1);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::empty(t)), false);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::size(t)), 2);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::begin(t), boost::fusion::end(t))), 2);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::next(boost::fusion::begin(t)), boost::fusion::end(t))), 1);
    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::begin(t), boost::fusion::prior(boost::fusion::end(t)))), 1);

    BOOST_CHECK_EQUAL(get_static(boost::fusion::distance(boost::fusion::advance_c<2>(boost::fusion::begin(t)), boost::fusion::end(t))), 0);
    BOOST_CHECK_EQUAL(any_cast<const double&>(boost::fusion::deref(boost::fusion::begin(t))), 2.0);
}

