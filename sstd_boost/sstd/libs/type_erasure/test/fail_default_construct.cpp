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

using namespace boost::type_erasure;

int main()
{
    any<copy_constructible<> > y;
}
