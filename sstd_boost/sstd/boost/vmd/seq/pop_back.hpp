﻿
//  (C) Copyright Edward Diener 2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_VMD_SEQ_POP_BACK_HPP)
#define BOOST_VMD_SEQ_POP_BACK_HPP

#include <sstd/boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <sstd/boost/preprocessor/comparison/equal.hpp>
#include <sstd/boost/preprocessor/control/iif.hpp>
#include <sstd/boost/preprocessor/seq/pop_back.hpp>
#include <sstd/boost/preprocessor/seq/size.hpp>
#include <sstd/boost/vmd/empty.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def BOOST_VMD_SEQ_POP_BACK(seq)

    \brief pops an element from the end of a seq.

    seq = seq to pop an element from.

    If the seq is an empty seq the result is undefined.
    If the seq is a single element the result is an empty seq.
    Otherwise the result is a seq after removing the last element.
*/

#define BOOST_VMD_SEQ_POP_BACK(seq) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(seq),1), \
        BOOST_VMD_EMPTY, \
        BOOST_PP_SEQ_POP_BACK \
        ) \
    (seq) \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_SEQ_POP_BACK_HPP */

