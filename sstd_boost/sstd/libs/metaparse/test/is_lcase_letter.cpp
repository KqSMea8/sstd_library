﻿// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/metaparse/util/is_lcase_letter.hpp>

#include "common.hpp"

#include <sstd/boost/mpl/apply_wrap.hpp>
#include <sstd/boost/mpl/not.hpp>
#include <sstd/boost/mpl/assert.hpp>

#include "test_case.hpp"

BOOST_METAPARSE_TEST_CASE(util_is_lcase_letter)
{
  using boost::metaparse::util::is_lcase_letter;

  using boost::mpl::apply_wrap1;
  using boost::mpl::not_;

  // test_letter
  BOOST_MPL_ASSERT((apply_wrap1<is_lcase_letter<>, char_k>));

  // test_non_letter
  BOOST_MPL_ASSERT((not_<apply_wrap1<is_lcase_letter<>, char_K> >));
}


