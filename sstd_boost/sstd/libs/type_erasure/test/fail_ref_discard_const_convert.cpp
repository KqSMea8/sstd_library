﻿// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#include <sstd/boost/type_erasure/any.hpp>
#include <sstd/boost/type_erasure/builtin.hpp>
#include <sstd/boost/mpl/vector.hpp>

using namespace boost::type_erasure;

int main()
{
    const any<boost::mpl::vector<copy_constructible<>, typeid_<> > > x(1);
    any<copy_constructible<>, _self&> y(x);
}

