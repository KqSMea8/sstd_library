﻿//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/exception/error_info.hpp>
#include <sstd/boost/exception/exception.hpp>
#include <sstd/boost/exception/info.hpp>
#include <sstd/boost/exception/get_error_info.hpp>
#include <sstd/boost/core/lightweight_test.hpp>
#include <string>
#include <string.h>

struct my_exception: virtual boost::exception {};
typedef boost::error_info<struct error_info_string_, std::string> error_info_string;

int
main()
    {
    try
        {
        throw my_exception() << error_info_string("doh");
        }
    catch( my_exception & e )
        {
        BOOST_TEST(boost::get_error_info<error_info_string>(e) && !strcmp(boost::get_error_info<error_info_string>(e)->c_str(),"doh"));
        }
    return boost::report_errors();
    }

