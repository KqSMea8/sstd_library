﻿
//  (C) Copyright Edward Diener 2012
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include "test_has_fun.hpp"
#include <sstd/boost/mpl/assert.hpp>

int main()
  {

  // Wrong function signature for sFunction

  BOOST_MPL_ASSERT((BOOST_TTI_HAS_FUNCTION_GEN(sFunction)<AnotherType,AType::AnIntType,boost::mpl::vector<short,long,double> >));

  return 0;

  }

