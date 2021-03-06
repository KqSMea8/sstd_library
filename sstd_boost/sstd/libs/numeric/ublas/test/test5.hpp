﻿//
//  Copyright (c) 2000-2002
//  Joerg Walter, Mathias Koch
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  The authors gratefully acknowledge the support of
//  GeNeSys mbH & Co. KG in producing this work.
//

#ifndef TEST5_H
#define TEST5_H

#include <iostream>

#include <sstd/boost/numeric/ublas/vector.hpp>
#include <sstd/boost/numeric/ublas/matrix.hpp>
#include <sstd/boost/numeric/ublas/matrix_proxy.hpp>
#include <sstd/boost/numeric/ublas/triangular.hpp>
#include <sstd/boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

#include "common/init.hpp"

void test_matrix_vector ();
void test_matrix ();


// FIXME slice are failing in assignment to zero elements
#undef USE_SLICE

#endif

