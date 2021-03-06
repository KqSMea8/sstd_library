﻿/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2014      John Fletcher
    Copyright (c) 2018      Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/config.hpp>
#include <sstd/boost/detail/workaround.hpp>

#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/phoenix/core.hpp>
#include <sstd/boost/phoenix/operator/self.hpp>
#include <sstd/boost/phoenix/bind.hpp>
#include <sstd/boost/phoenix/scope/lambda.hpp>
#include <sstd/boost/phoenix/scope/let.hpp>

int main()
{
    using boost::phoenix::lambda;
    using boost::phoenix::let;
    using boost::phoenix::val;
    using boost::phoenix::local_names::_a;

   int x = (let(_a = lambda[val(1)])[bind(_a)])();
   BOOST_TEST(x == 1);

    return boost::report_errors();
}

