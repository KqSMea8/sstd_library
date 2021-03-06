﻿//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
///@file
/// Keywords used in generator interfaces
// ***************************************************************************

#ifndef BOOST_TEST_DATA_MONOMORPHIC_GENERATORS_KEYWORDS_HPP_101512GER
#define BOOST_TEST_DATA_MONOMORPHIC_GENERATORS_KEYWORDS_HPP_101512GER

// Boost.Test
#include <sstd/boost/test/data/config.hpp>
#include <sstd/boost/test/utils/named_params.hpp>

#include <sstd/boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace boost {
namespace unit_test {
namespace data {

namespace {
nfp::keyword<struct begin_t>    begin;
nfp::keyword<struct end_t>      end;
nfp::keyword<struct step_t>     step;
} // local namespace

} // namespace data
} // namespace unit_test
} // namespace boost

#include <sstd/boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_DATA_MONOMORPHIC_GENERATORS_KEYWORDS_HPP_101512GER

