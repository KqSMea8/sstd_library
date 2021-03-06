﻿/*=============================================================================
  Copyright (c) 2001-2007 Joel de Guzman

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
  ==============================================================================*/
#include <iostream>
#include <cmath>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/phoenix/core.hpp>
#include <sstd/boost/phoenix/bind.hpp>

namespace test
{
    void
    test()
    {
        std::cout << "Test binding functions...\n";
    }

    int
    negate(int n)
    {
        return -n;
    }

    int
    plus(int a, int b)
    {
        return a + b;
    }

    int
    plus4(int a, int b, int c, int d)
    {
        return a + b + c + d;
    }
}

int
main()
{
    using boost::phoenix::bind;
    using boost::phoenix::arg_names::arg1;
    using boost::phoenix::arg_names::arg2;

    int a = 123;
    int b = 256;

    bind(test::test)();
    BOOST_TEST(bind(test::negate, arg1)(a) == -a);
    BOOST_TEST(bind(test::plus, arg1, arg2)(a, b) == a+b);
    BOOST_TEST(bind(test::plus4, arg1, arg2, 3, 4)(a, b) == a+b+3+4);

    return boost::report_errors();
}

