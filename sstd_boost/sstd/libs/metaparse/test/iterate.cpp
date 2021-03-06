﻿// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/metaparse/iterate.hpp>
#include <sstd/boost/metaparse/is_error.hpp>
#include <sstd/boost/metaparse/start.hpp>
#include <sstd/boost/metaparse/get_result.hpp>
#include <sstd/boost/metaparse/one_char.hpp>

#include "common.hpp"

#include <sstd/boost/mpl/equal_to.hpp>
#include <sstd/boost/mpl/apply_wrap.hpp>
#include <sstd/boost/mpl/equal.hpp>
#include <sstd/boost/mpl/vector_c.hpp>
#include <sstd/boost/mpl/assert.hpp>

#include "test_case.hpp"

BOOST_METAPARSE_TEST_CASE(iterate)
{
  using boost::metaparse::is_error;
  using boost::metaparse::iterate;
  using boost::metaparse::one_char;
  using boost::metaparse::start;
  using boost::metaparse::get_result;

  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;
  using boost::mpl::list;
  using boost::mpl::vector_c;

  // test_empty_input
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<iterate<one_char, int13>, str_, start> >
  ));

  // test0
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int0>, str_hello, start> >::type,
      list<>
    >
  ));

  // test1
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int1>, str_hello, start> >::type,
      vector_c<char, 'h'>
    >
  ));

  // test2
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int2>, str_hello, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  ));

  // test3
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int3>, str_hello, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  ));
}



