﻿/*==============================================================================
    Copyright (c) 2010 Thomas Heller
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_ARITY_HPP
#define BOOST_PHOENIX_CORE_ARITY_HPP

#include <sstd/boost/phoenix/core/limits.hpp>
#include <sstd/boost/is_placeholder.hpp>
#include <sstd/boost/mpl/max.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/phoenix/core/meta_grammar.hpp>
#include <sstd/boost/phoenix/core/terminal_fwd.hpp>
#include <sstd/boost/phoenix/support/vector.hpp>
#include <sstd/boost/proto/matches.hpp>
#include <sstd/boost/proto/transform/fold.hpp>

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    //  Calculate the arity of an expression using proto transforms
    //
    /////////////////////////////////////////////////////////////////////////////

    struct arity;

    namespace result_of
    {
        template <typename Expr>
        struct arity
            : mpl::int_<
                evaluator::impl<
                    Expr const&
                  , vector2<
                        mpl::int_<0>
                      , boost::phoenix::arity
                    >&
                  , proto::empty_env
                >::result_type::value
            >
        {};
    }

    struct arity
    {
        template <typename Rule, typename Dummy = void>
        struct when
            : proto::fold<
                proto::_
              , mpl::int_<0>
              , proto::make<mpl::max<
                    proto::_state
                  , proto::call<
                        evaluator(
                            proto::_
                          , proto::call<
                                functional::context(_env, _actions)
                            >
                        )
                    >
                >()>
            >
        {};
    };

    template <typename Dummy>
    struct arity::when<rule::argument, Dummy>
        : proto::make<is_placeholder<proto::_value>()>
    {};

    template <typename Dummy>
    struct arity::when<rule::custom_terminal, Dummy>
        : proto::make<mpl::int_<0>()>
    {};

    template <typename Dummy>
    struct arity::when<rule::terminal, Dummy>
        : proto::make<mpl::int_<0>()>
    {};
}}

#endif

