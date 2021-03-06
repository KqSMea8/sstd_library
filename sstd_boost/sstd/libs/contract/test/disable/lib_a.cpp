﻿
// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

#define BOOST_CONTRACT_TEST_LIB_A_SOURCE
#include "lib_a.hpp"
#include <sstd/boost/contract.hpp> // All headers so test ODR for entire lib.
#ifndef BOOST_CONTRACT_HEADER_ONLY
    #include "lib_a_inlined.hpp"
#endif
#include "../detail/out_inlined.hpp"


