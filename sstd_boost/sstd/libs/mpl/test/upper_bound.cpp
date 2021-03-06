﻿
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sstd/boost/mpl/upper_bound.hpp>

#include <sstd/boost/mpl/distance.hpp>
#include <sstd/boost/mpl/list_c.hpp>
#include <sstd/boost/mpl/less.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef list_c<int,1,2,3,3,3,5,8> numbers;
    typedef upper_bound< numbers, int_<3> >::type iter;

    MPL_ASSERT_RELATION( (mpl::distance< begin<numbers>::type,iter >::value), ==, 5 );
    MPL_ASSERT_RELATION( deref<iter>::type::value, ==, 5 );
}

