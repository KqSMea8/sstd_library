﻿//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <sstd/boost/math/tools/toms748_solve.hpp>
// #includes all the files that it needs to.
//
#include <sstd/boost/math/tools/toms748_solve.hpp>

#define T double
#define Tol boost::math::tools::eps_tolerance<double>

typedef T (*F)(T);

template std::pair<T, T> boost::math::tools::toms748_solve<F, T, Tol >(F, const T&, const T&, const T&, const T&, Tol, boost::uintmax_t&);
template std::pair<T, T> boost::math::tools::toms748_solve<F, T, Tol>(F f, const T& ax, const T& bx, Tol tol, boost::uintmax_t& max_iter);
template std::pair<T, T> boost::math::tools::bracket_and_solve_root<F, T, Tol>(F f, const T& guess, const T& factor, bool rising, Tol tol, boost::uintmax_t& max_iter);

