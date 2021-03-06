﻿// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <sstd/boost/range/adaptor/indirected.hpp>
#include <sstd/boost/optional.hpp>
#include <sstd/boost/optional/optional_io.hpp>

#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>

#include <vector>

namespace boost
{
    namespace
    {
        void test_ticket_5811_indirected_optional()
        {
            std::vector<boost::optional<int> > v;
            std::vector<int> r;
            for (int i = 0; i < 10; ++i)
            {
                v.push_back(i);
                r.push_back(i);
            }
            BOOST_CHECK_EQUAL_COLLECTIONS(r.begin(), r.end(),
                                          v.begin(), v.end());
        }
    }
}

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE("RangeTestSuite.ticket_5811_indirected_optional");

    test->add(BOOST_TEST_CASE(&boost::test_ticket_5811_indirected_optional));

    return test;
}

