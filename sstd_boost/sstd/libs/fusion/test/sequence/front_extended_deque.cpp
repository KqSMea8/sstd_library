﻿/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/detail/lightweight_test.hpp>

#include <sstd/boost/fusion/container/deque/deque.hpp>
#include <sstd/boost/fusion/container/deque/front_extended_deque.hpp>
#include <sstd/boost/fusion/sequence/comparison.hpp>
#include <sstd/boost/fusion/container/generation/make_vector.hpp>
#include <sstd/boost/fusion/mpl.hpp>

#include <sstd/boost/fusion/sequence/intrinsic.hpp>
#include <sstd/boost/fusion/iterator.hpp>

#include <sstd/boost/mpl/assert.hpp>
#include <sstd/boost/type_traits/is_same.hpp>

int main()
{
    using namespace boost::fusion;
    {
        typedef deque<> initial_deque_type;
        initial_deque_type initial_deque;
        typedef front_extended_deque<initial_deque_type, int> extended_type;
        extended_type extended(initial_deque, 1);

        BOOST_TEST(size(extended) == 1);
        BOOST_TEST(extended == make_vector(1));
        BOOST_TEST(*begin(extended) == 1);
        BOOST_TEST(*prior(end(extended)) == 1);
        BOOST_TEST(distance(begin(extended), end(extended)) == 1);
    }
    {
        namespace mpl = boost::mpl;
        typedef deque<> initial_deque_type;
        typedef front_extended_deque<initial_deque_type, int> extended_type;

        BOOST_MPL_ASSERT((boost::is_same<mpl::at_c<extended_type, 0>::type, int>));
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<mpl::begin<extended_type>::type>::type, int>));
        BOOST_MPL_ASSERT((mpl::equal_to<mpl::size<extended_type>::type, mpl::int_<1> >));
    }
    {
        int i(1);
        typedef deque<> initial_deque_type;
        initial_deque_type initial_deque;
        typedef front_extended_deque<initial_deque_type, int&> extended_type;
        extended_type extended(initial_deque, i);
        BOOST_TEST(extended == make_vector(1));

        int i2(2);
        extended_type extended2(initial_deque_type(), i2);

        extended = extended2;

        BOOST_TEST(extended == make_vector(2));

        BOOST_TEST(i == i2);
    }

    {
        typedef deque<char, long> initial_deque_type;
        initial_deque_type initial_deque('a', 101L);
        typedef front_extended_deque<initial_deque_type, int> extended_type;
        extended_type extended(initial_deque, 1);

        BOOST_TEST(size(extended) == 3);
        BOOST_TEST(extended == make_vector(1, 'a', 101L));
        BOOST_TEST(*begin(extended) == 1);
        BOOST_TEST(*next(begin(extended)) == 'a');
        BOOST_TEST(*prior(end(extended)) == 101L);
        BOOST_TEST(distance(begin(extended), end(extended)) == 3);
        BOOST_TEST(*advance_c<2>(begin(extended)) == 101L);
    }
    {
        namespace mpl = boost::mpl;
        typedef deque<char, long> initial_deque_type;
        typedef front_extended_deque<initial_deque_type, int> extended_type;

        BOOST_MPL_ASSERT((boost::is_same<mpl::at_c<extended_type, 0>::type, int>));
        BOOST_MPL_ASSERT((boost::is_same<mpl::at_c<extended_type, 1>::type, char>));
        BOOST_MPL_ASSERT((boost::is_same<mpl::at_c<extended_type, 2>::type, long>));
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<mpl::begin<extended_type>::type>::type, int>));
        BOOST_MPL_ASSERT((mpl::equal_to<mpl::size<extended_type>::type, mpl::int_<3> >));
    }
    {
        char ch('a');
        long l(101L);
        int i(1);
        typedef deque<char&, long&> initial_deque_type;
        initial_deque_type initial_deque(ch, l);
        typedef front_extended_deque<initial_deque_type, int&> extended_type;
        extended_type extended(initial_deque, i);
        BOOST_TEST(extended == make_vector(1, 'a', 101L));

        char ch2('b');
        long l2(202L);
        int i2(2);
        extended_type extended2(initial_deque_type(ch2, l2), i2);

        extended = extended2;

        BOOST_TEST(extended == make_vector(2, 'b', 202L));

        BOOST_TEST(i == i2);
        BOOST_TEST(ch == ch2);
        BOOST_TEST(l == l2);
    }
    return boost::report_errors();
}

