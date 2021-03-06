﻿// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2004-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef BOOST_IOSTREAMS_TEST_READ_SEEKABLE_HPP_INCLUDED
#define BOOST_IOSTREAMS_TEST_READ_SEEKABLE_HPP_INCLUDED

#include <fstream>
#include <sstd/boost/iostreams/device/file.hpp>
#include <sstd/boost/iostreams/filtering_stream.hpp>
#include <sstd/boost/test/test_tools.hpp>
#include "detail/temp_file.hpp"
#include "detail/verification.hpp"

void read_seekable_test()
{
    using namespace std;
    using namespace boost;
    using namespace boost::iostreams;
    using namespace boost::iostreams::test;

    test_file test1;
    test_file test2;

    {
        filtering_stream<seekable> first(file(test1.name(), in_mode), 0);
        ifstream second(test2.name().c_str(), in_mode);
        BOOST_CHECK_MESSAGE(
            compare_streams_in_chars(first, second),
            "failed reading from filtering_stream<seekable>"
            "in chars with no buffer"
        );
    }

    {
        filtering_stream<seekable> first(file(test1.name(), in_mode), 0);
        ifstream second(test2.name().c_str(), in_mode);
        BOOST_CHECK_MESSAGE(
            compare_streams_in_chunks(first, second),
            "failed reading from filtering_stream<seekable>"
            "in chars with no buffer"
        );
    }

    {
        filtering_stream<seekable> first(file(test1.name(), in_mode));
        ifstream second(test2.name().c_str(), in_mode);
        BOOST_CHECK_MESSAGE(
            compare_streams_in_chars(first, second),
            "failed reading from filtering_stream<seekable>"
            "in chars with large buffer"
        );
    }

    {
        filtering_stream<seekable> first(file(test1.name(), in_mode));
        ifstream second(test2.name().c_str(), in_mode);
        BOOST_CHECK_MESSAGE(
            compare_streams_in_chunks(first, second),
            "failed reading from filtering_stream<seekable>"
            "in chars with large buffer"
        );
    }
}

#endif // #ifndef BOOST_IOSTREAMS_TEST_READ_SEEKABLE_HPP_INCLUDED

