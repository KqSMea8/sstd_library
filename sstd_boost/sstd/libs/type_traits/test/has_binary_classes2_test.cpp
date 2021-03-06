﻿//  (C) Copyright 2009-2011 Frederic Bron.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/type_traits/has_operator.hpp>
#include "test.hpp"
#include "check_integral_constant.hpp"
#include "has_binary_classes.hpp"

TT_TEST_BEGIN(BOOST_TT_TRAIT_NAME)
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C046 const &, C046 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C046 const &, C046 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C046 const &, C046 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C046 const &, C046 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047, C047 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const, C047 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 &, C047 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C047 const &, C047 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050, C050 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const, C050 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 &, C050 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C050 const &, C050 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051, C051 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const, C051 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 &, C051 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C051 const &, C051 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 const &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072, C072 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const, C072 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 &, C072 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C072 const &, C072 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073, C073 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const, C073, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const, C073 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const, C073 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const, C073 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const, C073 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 &, C073, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 &, C073, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 &, C073, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 &, C073 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 &, C073 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C073 const &, C073 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074, C074 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const, C074 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 &, C074 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C074 const &, C074 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077, C077 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const, C077 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 &, C077, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 &, C077 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 &, C077 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 &, C077 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C077 const &, C077 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078, C078 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 const, C078 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 &, C078, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 &, C078, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C078 &, C078 const, void >::value), 0);
TT_TEST_END

