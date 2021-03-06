﻿
// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sstd/boost/mpl/is_sequence.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/mpl/list.hpp>
#include <sstd/boost/mpl/vector.hpp>
#include <sstd/boost/mpl/range_c.hpp>
#include <sstd/boost/mpl/aux_/test.hpp>

template< typename T > struct std_vector
{
    T* begin();
};

MPL_TEST_CASE()
{
    MPL_ASSERT_NOT(( is_sequence< std_vector<int> > ));
    MPL_ASSERT_NOT(( is_sequence< int_<0> > ));
    MPL_ASSERT_NOT(( is_sequence< int > ));
    MPL_ASSERT_NOT(( is_sequence< int& > ));
    MPL_ASSERT_NOT(( is_sequence< UDT > ));
    MPL_ASSERT_NOT(( is_sequence< UDT* > ));
    MPL_ASSERT(( is_sequence< range_c<int,0,0> > ));
    MPL_ASSERT(( is_sequence< list<> > ));
    MPL_ASSERT(( is_sequence< list<int> > ));
    MPL_ASSERT(( is_sequence< vector<> > ));
    MPL_ASSERT(( is_sequence< vector<int> > ));
}

