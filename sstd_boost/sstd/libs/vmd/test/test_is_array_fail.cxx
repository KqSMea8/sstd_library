﻿
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/is_array.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

  BOOST_TEST
      (
      BOOST_VMD_IS_ARRAY((y,(x,3,e,2)))
      );

#endif

  return boost::report_errors();

  }

