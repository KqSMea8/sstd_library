﻿//  Copyright (c) 2001-2011 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/config/warning_disable.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

#include <sstd/boost/spirit/include/karma_char.hpp>
#include <sstd/boost/spirit/include/karma_string.hpp>
#include <sstd/boost/spirit/include/karma_numeric.hpp>
#include <sstd/boost/spirit/include/karma_generate.hpp>
#include <sstd/boost/spirit/include/karma_directive.hpp>
#include <sstd/boost/spirit/include/karma_upper_lower_case.hpp>

#include <string>
#include <iterator>

#include "test.hpp"

///////////////////////////////////////////////////////////////////////////////
int
main()
{
    using namespace spirit_test;
    using namespace boost::spirit;
    using namespace boost::spirit::ascii;

    {
        BOOST_TEST(test("     x    ", center[char_('x')]));
        BOOST_TEST(test("     x    ", center[char_], 'x'));
        BOOST_TEST(test("     x    ", center['x']));

        BOOST_TEST(test("     x    ", center(10)[char_('x')]));
        BOOST_TEST(test("     x    ", center(10)[char_], 'x'));
        BOOST_TEST(test("     x    ", center(10)['x']));

        BOOST_TEST(test("*****x****", center(10, char_('*'))[char_('x')]));
        BOOST_TEST(test("*****x****", center(10, '*')[char_], 'x'));
        BOOST_TEST(test("*****x****", center(10, '*')['x']));
        BOOST_TEST(test("aaaaaxaaaa", lower[center(10, 'A')['X']]));
        BOOST_TEST(test("AAAAAXAAAA", upper[center(10, 'a')['x']]));


        BOOST_TEST(test("*****x****", center(char_('*'))[char_('x')]));
        BOOST_TEST(test("*****x****", center(char_('*'))[char_], 'x'));
        BOOST_TEST(test("*****x****", center(char_('*'))['x']));

        BOOST_TEST(test("     x     ", center(11)[char_('x')]));

        BOOST_TEST(test("    abc   ", center[lit("abc")]));
        BOOST_TEST(test("    abc   ", center[string], "abc"));

        BOOST_TEST(test("    abc   ", center(10)[lit("abc")]));
        BOOST_TEST(test("    abc   ", center(10)[string], "abc"));
        BOOST_TEST(test("    abc   ", center(10)["abc"]));

        BOOST_TEST(test("    abc    ", center(11)[lit("abc")]));
        BOOST_TEST(test("     ab    ", center(11)[lit("ab")]));

        BOOST_TEST(test("****abc***", center(10, char_('*'))[lit("abc")]));
        BOOST_TEST(test("****abc***", center(10, '*')[string], "abc"));
        BOOST_TEST(test("****abc***", center(10, '*')["abc"]));

        BOOST_TEST(test("****abc***", center(char_('*'))[lit("abc")]));
        BOOST_TEST(test("****abc***", center(char_('*'))[string], "abc"));
        BOOST_TEST(test("****abc***", center(char_('*'))["abc"]));

        BOOST_TEST(test("    abc    ", center(11)[lit("abc")]));

        BOOST_TEST(test("    100   ", center[int_(100)]));
        BOOST_TEST(test("    100   ", center[int_], 100));

        BOOST_TEST(test("    100   ", center(10)[int_(100)]));
        BOOST_TEST(test("    100   ", center(10)[int_], 100));

        BOOST_TEST(test("****100***", center(10, char_('*'))[int_(100)]));
        BOOST_TEST(test("****100***", center(10, '*')[int_], 100));

        BOOST_TEST(test("    100    ", center(11)[int_(100)]));

        BOOST_TEST(test("****100***", center(char_('*'))[int_(100)]));
        BOOST_TEST(test("****100***", center(char_('*'))[int_], 100));
    }

    return boost::report_errors();
}

