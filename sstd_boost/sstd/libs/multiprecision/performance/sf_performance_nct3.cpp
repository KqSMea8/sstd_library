﻿///////////////////////////////////////////////////////////////
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_

#include "sf_performance.hpp"

void nct_tests_3()
{
#ifdef TEST_MPREAL
   mpfr::mpreal::set_default_prec(50 * 1000L / 301L);
#endif
#ifdef TEST_CPP_DEC_FLOAT
   time_proc("cpp_dec_float_50", test_nct<cpp_dec_float_50>);
#endif
#ifdef TEST_CPP_BIN_FLOAT
   time_proc("cpp_bin_float_50", test_nct<cpp_bin_float_50>, 3);
#endif
#ifdef TEST_MPFR_CLASS
   time_proc("mpfr_class", test_nct<mpfr_class>);
#endif
#ifdef TEST_MPREAL
   time_proc("mpfr::mpreal", test_nct<mpfr::mpreal>);
#endif
}

