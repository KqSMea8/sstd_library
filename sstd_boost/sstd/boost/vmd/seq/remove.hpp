﻿
//  (C) Copyright Edward Diener 2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_VMD_SEQ_REMOVE_HPP)
#define BOOST_VMD_SEQ_REMOVE_HPP

#include <sstd/boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <sstd/boost/preprocessor/comparison/equal.hpp>
#include <sstd/boost/preprocessor/control/iif.hpp>
#include <sstd/boost/preprocessor/logical/bitand.hpp>
#include <sstd/boost/preprocessor/seq/remove.hpp>
#include <sstd/boost/preprocessor/seq/size.hpp>
#include <sstd/boost/vmd/empty.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def BOOST_VMD_SEQ_REMOVE(seq,index)

    \brief removes an element from a seq.

    seq = seq from which an element is to be removed.
    index = The zero-based position in seq of the element to be removed.

    If index is greater or equal to the seq size the result is undefined.
    If the seq is a single element and the index is 0 the result is an empty seq.
    Otherwise the result is a seq after removing the index element.
*/

#define BOOST_VMD_SEQ_REMOVE(seq,index) \
    BOOST_PP_IIF \
        ( \
        BOOST_PP_BITAND \
            ( \
            BOOST_PP_EQUAL(index,0), \
            BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(seq),1) \
            ), \
        BOOST_VMD_EMPTY, \
        BOOST_PP_SEQ_REMOVE \
        ) \
    (seq,index) \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_SEQ_REMOVE_HPP */

