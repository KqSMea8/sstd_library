﻿/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2014      John Fletcher
    Copyright (c) 2018      Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/phoenix/core.hpp>
#include <sstd/boost/phoenix/scope/lambda.hpp>

int main()
{
    using boost::phoenix::lambda;
    using boost::phoenix::arg_names::_1;

    int x = 1;
    int y = lambda[_1]()(x);
    BOOST_TEST(x == y);

    return boost::report_errors();
}

