﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_CONTAINERS_SET_HPP
#define BOOST_INTERPROCESS_CONTAINERS_SET_HPP

#ifndef BOOST_CONFIG_HPP
#  include <sstd/boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include <sstd/boost/container/set.hpp>
#include <sstd/boost/interprocess/containers/containers_fwd.hpp>

namespace boost {
namespace interprocess {

using boost::container::set;
using boost::container::multiset;

}  //namespace interprocess {
}  //namespace boost {

#include <sstd/boost/interprocess/detail/config_end.hpp>

#endif //   #ifndef  BOOST_INTERPROCESS_CONTAINERS_SET_HPP

