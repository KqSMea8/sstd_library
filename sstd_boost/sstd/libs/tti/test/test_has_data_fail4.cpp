﻿
//  (C) Copyright Edward Diener 2012
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include "test_has_data.hpp"
#include <sstd/boost/mpl/assert.hpp>

int main()
  {

  // SomeStaticData does not exist at all

  BOOST_MPL_ASSERT((BOOST_TTI_HAS_DATA_GEN(SomeStaticData)<AnotherType,float>));

  return 0;

  }

