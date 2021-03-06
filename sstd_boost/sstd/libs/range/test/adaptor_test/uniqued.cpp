﻿// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <sstd/boost/range/adaptor/uniqued.hpp>
#include <sstd/boost/range/adaptor/transformed.hpp>
#include <sstd/boost/range/algorithm/unique_copy.hpp>
#include <sstd/boost/range/algorithm_ext/push_back.hpp>
#include <sstd/boost/algorithm/string/predicate.hpp>

#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>

#include <sstd/boost/assign.hpp>
#include <sstd/boost/range/algorithm_ext.hpp>

#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace boost
{
    namespace
    {
        template< class Container >
        void uniqued_test_impl( Container& c )
        {
            using namespace boost::adaptors;

            std::vector< int > test_result1;
            boost::push_back(test_result1, c | uniqued);

            std::vector< int > test_result2;
            boost::push_back(test_result2, adaptors::unique(c));

            std::vector< int > reference(c.begin(), c.end());
            reference.erase(
                std::unique(reference.begin(), reference.end()),
                reference.end());

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test_result1.begin(), test_result1.end() );

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test_result2.begin(), test_result2.end() );
        }

        template< class Container >
        void uniqued_test_impl()
        {
            using namespace boost::assign;

            Container c;

            // Test empty
            uniqued_test_impl(c);

            // Test one
            c += 1;
            uniqued_test_impl(c);

            // Test many
            c += 1,1,1,2,2,2,2,2,3,3,3,3,4,5,6,6,6,7,7,7,8,8,9,9,9,9,9,10;
            uniqued_test_impl(c);
        }

        void uniqued_test()
        {
            uniqued_test_impl< std::vector< int > >();
            uniqued_test_impl< std::list< int > >();
            uniqued_test_impl< std::set< int > >();
            uniqued_test_impl< std::multiset< int > >();
        }

class istring
{
public:
    istring()
        : m_value("")
    {
    }

    explicit istring(const char* value)
        : m_value(value)
    {
    }

    bool operator==(istring r) const
    {
        return boost::iequals(m_value, r.m_value);
    }

    bool operator!=(istring r) const
    {
        return !operator==(r);
    }

    inline friend std::ostream& operator<<(std::ostream& out, istring o)
    {
        return out << o.m_value;
    }

    const char* get() const { return m_value; }

private:
    const char* m_value;
};

struct istring_to_string
{
    typedef std::string result_type;

    std::string operator()(istring s) const
    {
        return s.get();
    }
};

// This is based on a test-case provided by Eric Neibler.
void uniqued_return_first()
{
    using namespace boost::adaptors;

    std::vector<istring> strs;
    strs.push_back(istring("hello"));
    strs.push_back(istring("hElLo"));
    strs.push_back(istring("HELLO"));
    strs.push_back(istring("ZZZZ"));

    std::vector<istring> output1;

    boost::unique_copy(strs, std::back_inserter(output1));

    std::vector<istring> output2;
    boost::push_back(output2, strs | uniqued);

    std::vector<std::string> test1;
    boost::push_back(test1, output1 | transformed(istring_to_string()));

    std::vector<std::string> test2;
    boost::push_back(test2, output2 | transformed(istring_to_string()));

    BOOST_CHECK_EQUAL_COLLECTIONS(test1.begin(), test1.end(),
                                  test2.begin(), test2.end());
}

    } // anonymous namespace
} // namespace boost

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.uniqued" );

    test->add( BOOST_TEST_CASE( &boost::uniqued_test ) );

    test->add(BOOST_TEST_CASE(&boost::uniqued_return_first));

    return test;
}

