﻿//  Copyright (c) 2012 Robert Ramey
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <exception>

#include <sstd/boost/safe_numerics/safe_integer.hpp>
#include <sstd/boost/safe_numerics/native.hpp>

template <class T>
using safe_t = boost::safe_numerics::safe<
    T,
    boost::safe_numerics::native
>;

#include "test_xor.hpp"
#include "test.hpp"
#include "test_values.hpp"

#include <sstd/boost/preprocessor/stringize.hpp>

#define TEST_IMPL(v1, v2, result) \
    rval &= test_xor(             \
        v1,                       \
        v2,                       \
        BOOST_PP_STRINGIZE(v1),   \
        BOOST_PP_STRINGIZE(v2),   \
        result                    \
    );
/**/

#define TESTX(value_index1, value_index2)           \
    (std::cout << value_index1 << ',' << value_index2 << ','); \
    TEST_IMPL(                                      \
        BOOST_PP_ARRAY_ELEM(value_index1, VALUES),  \
        BOOST_PP_ARRAY_ELEM(value_index2, VALUES),  \
        '.'                                         \
    )
/**/
int main(int, char *[]){
    bool rval = true;
    TEST_EACH_VALUE_PAIR
    std::cout << (rval ? "success!" : "failure") << std::endl;
    return ! rval ;
}

