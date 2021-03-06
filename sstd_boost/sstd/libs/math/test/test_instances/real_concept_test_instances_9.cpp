﻿// Copyright John Maddock 2011.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "pch.hpp"

#ifndef BOOST_BUILD_PCH_ENABLED
#define BOOST_MATH_OVERFLOW_ERROR_POLICY ignore_error
#include <sstd/boost/math/special_functions/expint.hpp>
#include <sstd/boost/math/special_functions/zeta.hpp>
#endif

#include <sstd/boost/math/tools/config.hpp>
#include <sstd/boost/math/concepts/real_concept.hpp>

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS

#define BOOST_MATH_TEST_TYPE boost::math::concepts::real_concept
#define TEST_GROUP_9
#include "test_instances.hpp"

#endif

