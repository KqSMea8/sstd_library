﻿//  Copyright (c) 2012 Robert Ramey
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <exception>
#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>
#include <cassert>
#include <typeinfo>
#include <sstd/boost/core/demangle.hpp>

#include <sstd/boost/safe_numerics/checked_result.hpp>
#include <sstd/boost/safe_numerics/checked_result_operations.hpp>
#include <sstd/boost/safe_numerics/checked_integer.hpp>

template<class T>
bool test_checked_divide(
    boost::safe_numerics::checked_result<T> v1,
    boost::safe_numerics::checked_result<T> v2,
    char expected_result
){
    using namespace boost::safe_numerics;
    const checked_result<T> result = v1 / v2;
    std::cout
        << "testing  "
        << v1 << " / " << v2 << " -> " << result
        << std::endl;

    switch(expected_result){
    case '.':
    case '0':
        if(result.exception()){
            std::cout
                << "erroneously detected error in division"
                << std::endl;
            v1 / v2;
            return false;
        }
        if(expected_result == '0'
        && result != checked_result<T>(0)
        ){
            std::cout
                << "failed to get expected zero result "
                << std::endl;
            v1 / v2;
            return false;
        }
        return true;
    case '-':
        if(safe_numerics_error::negative_overflow_error == result.m_e)
            return true;
    case '+':
        if(safe_numerics_error::positive_overflow_error == result.m_e)
            return true;
    case '!':
        if(safe_numerics_error::range_error == result.m_e)
            return true;
    }
    std::cout
        << "failed to detect error in division "
        << std::hex << result << "(" << std::dec << result << ")"
        << " != "<< v1 << " / " << v2
        << std::endl;
    v1 / v2;
    return false;
}

// values
template<typename T>
const boost::safe_numerics::checked_result<T> signed_value[] = {
    boost::safe_numerics::safe_numerics_error::range_error,
    boost::safe_numerics::safe_numerics_error::domain_error,
    boost::safe_numerics::safe_numerics_error::positive_overflow_error,
    std::numeric_limits<T>::max(),
    T(1),
    T(0),
    T(-1),
    std::numeric_limits<T>::lowest(),
    boost::safe_numerics::safe_numerics_error::negative_overflow_error,
};

template<typename T>
const boost::safe_numerics::checked_result<T> unsigned_value[] = {
    boost::safe_numerics::safe_numerics_error::range_error,
    boost::safe_numerics::safe_numerics_error::domain_error,
    boost::safe_numerics::safe_numerics_error::positive_overflow_error,
    std::numeric_limits<T>::max(),
    T(1),
    T(0),
    boost::safe_numerics::safe_numerics_error::negative_overflow_error,
};

// test result matrices

// key
// . success
// - negative_overflow_error
// + positive_overflow_error
// ! range_error

const char * signed_division_results[] = {
//      012345678
/* 0*/ "!!!!!!!!!",
/* 1*/ "!!!!!!!!!",
/* 2*/ "!!!+++---",
/* 3*/ "!!0..+..0",
/* 4*/ "!!0..+.00",
/* 5*/ "!!000!000",
/* 6*/ "!!0..-.00",
/* 7*/ "!!0..-+.0",
/* 8*/ "!!----+++",
};

const char * unsigned_division_results[] = {
//      0123456
/* 0*/ "!!!!!!!",
/* 1*/ "!!!!!!!",
/* 2*/ "!!!+++-",
/* 3*/ "!!0..+.",
/* 4*/ "!!0..+.",
/* 5*/ "!!000!0",
/* 6*/ "!!----!",
};

// given an array of values of particula
// test all value pairs of a given collection
// note: the following can't be used because it can't be made
// to work with msvc !!! So use he kludgy alternatives below.
#if 0
template<typename T, unsigned int N>
bool test_pairs(const T (&value)[N], const char * (&results)[N]) {
    using namespace boost::safe_numerics;
    // for each pair of values p1, p2 (100)
    for(unsigned int i = 0; i < N; i++)
    for(unsigned int j = 0; j < N; j++){
        std::cout << std::dec << i << ',' << j << ',';
        if(! test_checked_divide(value[i], value[j], results[i][j]))
            return false;
    }
    return true;
}
#endif

template<typename T, unsigned int N>
bool test_signed_pairs() {
    using namespace boost::safe_numerics;
    // for each pair of values p1, p2 (100)
    for(unsigned int i = 0; i < N; i++)
    for(unsigned int j = 0; j < N; j++){
        std::cout << std::dec << i << ',' << j << ',';
        if(! test_checked_divide(
            signed_value<T>[i],
            signed_value<T>[j],
            signed_division_results[i][j]
        ))
            return false;
    }
    return true;
}

template<typename T, unsigned int N>
bool test_unsigned_pairs() {
    using namespace boost::safe_numerics;
    // for each pair of values p1, p2 (100)
    for(unsigned int i = 0; i < N; i++)
    for(unsigned int j = 0; j < N; j++){
        std::cout << std::dec << i << ',' << j << ',';
        if(! test_checked_divide(
            unsigned_value<T>[i],
            unsigned_value<T>[j],
            unsigned_division_results[i][j]
        ))
            return false;
    }
    return true;
}

struct t {
    static bool m_error;
    template<typename T>
    void operator()(const T &){        std::cout
            << "** testing "
            << boost::core::demangle(typeid(T).name())
            << std::endl;
        m_error &=
            std::numeric_limits<T>::is_signed
            ? test_signed_pairs<T,9>()
            : test_unsigned_pairs<T,7>()
        ;
    }
};
bool t::m_error = true;

#include <sstd/boost/mp11/algorithm.hpp>

bool test_all_types(){
    t rval;
    boost::mp11::mp_for_each<
        boost::mp11::mp_list<
            std::int8_t, std::int16_t, std::int32_t, std::int64_t,
            std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t
        >
    >(rval);
    return rval.m_error;
}

int main(int , char *[]){
    bool rval = test_all_types();
    std::cout << (rval ? "success!" : "failure") << std::endl;
    return ! rval ;
}

