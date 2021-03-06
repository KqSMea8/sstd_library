﻿///////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_

#ifdef _MSC_VER
#  define _SCL_SECURE_NO_WARNINGS
#endif

#include <sstd/boost/multiprecision/tommath.hpp>

#define NO_MIXED_OPS
#define BOOST_MP_NOT_TESTING_NUMBER

#include "test_arithmetic.hpp"

#include <sstd/boost/rational.hpp>

template <class T>
struct is_boost_rational<boost::rational<T> > : public boost::mpl::true_{};

namespace boost{ namespace multiprecision{

template<>
struct number_category<rational<tom_int> > : public mpl::int_<number_kind_rational> {};

}}

int main()
{
   test<boost::rational<boost::multiprecision::tom_int> >();
   return boost::report_errors();
}


