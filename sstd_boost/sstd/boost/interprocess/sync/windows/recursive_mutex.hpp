﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_DETAIL_WINDOWS_RECURSIVE_MUTEX_HPP
#define BOOST_INTERPROCESS_DETAIL_WINDOWS_RECURSIVE_MUTEX_HPP

#ifndef BOOST_CONFIG_HPP
#  include <sstd/boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include <sstd/boost/interprocess/detail/workaround.hpp>
#include <sstd/boost/interprocess/sync/windows/mutex.hpp>

namespace boost {
namespace interprocess {
namespace ipcdetail {

//Windows mutex is already recursive
class windows_recursive_mutex
   : public windows_mutex
{
   windows_recursive_mutex(const windows_recursive_mutex &);
   windows_recursive_mutex &operator=(const windows_recursive_mutex &);
   public:
   windows_recursive_mutex() : windows_mutex() {}
};

}  //namespace ipcdetail {
}  //namespace interprocess {
}  //namespace boost {


#include <sstd/boost/interprocess/detail/config_end.hpp>

#endif   //BOOST_INTERPROCESS_DETAIL_WINDOWS_RECURSIVE_MUTEX_HPP
