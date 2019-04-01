﻿
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/assert_is_seq.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

#if BOOST_VMD_ASSERT_DATA

  BOOST_VMD_ASSERT_IS_SEQ(y(z)(x))

#else

  typedef char BOOST_VMD_ASSERT_IS_SEQ_ERROR[-1];

#endif

#endif

  return boost::report_errors();

  }
