﻿//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//  Adaptation to Boost of the libcxx
//  Copyright 2010 Vicente J. Botet Escriba
//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  conversions from floating point to integral durations disallowed

#include <sstd/boost/chrono/duration.hpp>

void test()
{
    boost::chrono::duration<double> d;
    boost::chrono::duration<int> i = d;
}

