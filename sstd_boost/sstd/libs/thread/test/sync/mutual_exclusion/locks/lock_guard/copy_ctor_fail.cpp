﻿//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <sstd/boost/thread/locks.hpp>

// template <class Mutex> class lock_guard;

// lock_guard(lock_guard const&) = delete;


#include <sstd/boost/thread/lock_guard.hpp>
#include <sstd/boost/thread/mutex.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

boost::mutex m0;
boost::mutex m1;

int main()
{
  boost::lock_guard<boost::mutex> lk0(m0);
  boost::lock_guard<boost::mutex> lk1 = lk0;
}

#include "../../../../remove_error_code_unused_warning.hpp"


