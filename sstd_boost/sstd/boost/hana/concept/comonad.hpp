﻿/*!
@file
Defines `boost::hana::Comonad`.

@copyright Louis Dionne 2013-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_COMONAD_HPP
#define BOOST_HANA_CONCEPT_COMONAD_HPP

#include <sstd/boost/hana/fwd/concept/comonad.hpp>

#include <sstd/boost/hana/config.hpp>
#include <sstd/boost/hana/core/default.hpp>
#include <sstd/boost/hana/core/tag_of.hpp>
#include <sstd/boost/hana/detail/integral_constant.hpp>
#include <sstd/boost/hana/duplicate.hpp>
#include <sstd/boost/hana/extend.hpp>
#include <sstd/boost/hana/extract.hpp>


BOOST_HANA_NAMESPACE_BEGIN
    template <typename W>
    struct Comonad
        : hana::integral_constant<bool,
            !is_default<extract_impl<typename tag_of<W>::type>>::value &&
                (!is_default<duplicate_impl<typename tag_of<W>::type>>::value ||
                 !is_default<extend_impl<typename tag_of<W>::type>>::value)
        >
    { };
BOOST_HANA_NAMESPACE_END

#endif // !BOOST_HANA_CONCEPT_COMONAD_HPP

