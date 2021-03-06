﻿// Copyright (C) 2016-2018 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//[hello_world

#include <sstd/boost/yap/expression.hpp>

#include <iostream>


int main ()
{
    evaluate(boost::yap::make_terminal(std::cout) << "Hello" << ',' << " world!\n");

    return 0;
}
//]

