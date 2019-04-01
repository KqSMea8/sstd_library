﻿///////////////////////////////////////////////////////////////
//  Copyright 2012 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_

#ifdef _MSC_VER
#  define _SCL_SECURE_NO_WARNINGS
#endif

#define NO_MIXED_OPS

#include <sstd/boost/multiprecision/debug_adaptor.hpp>
#include <sstd/boost/multiprecision/cpp_dec_float.hpp>
#include "test_arithmetic.hpp"

int main()
{
   test<boost::multiprecision::number<boost::multiprecision::debug_adaptor<boost::multiprecision::cpp_dec_float<50> > > >();
   return boost::report_errors();
}

