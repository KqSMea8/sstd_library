﻿/*=============================================================================
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <sstd/boost/phoenix.hpp>
#include <sstd/boost/typeof/typeof.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using boost::phoenix::lambda;
    using boost::phoenix::let;
    using boost::phoenix::ref;
    using boost::phoenix::construct;
    using boost::phoenix::local_names::_a;
    using boost::phoenix::arg_names::_1;

    BOOST_AUTO(
       generator
     , (lambda
          (
             _a = val(_1)
          )
        [
           std::cout << _a << " "
         , _a++
        ] )
       );

    int i = 0;
    std::vector<int> v(10);
    std::for_each(v.begin(), v.end(), generator(0));
}

