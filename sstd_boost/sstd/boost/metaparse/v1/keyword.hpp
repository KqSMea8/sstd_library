﻿#ifndef BOOST_METAPARSE_V1_KEYWORD_HPP
#define BOOST_METAPARSE_V1_KEYWORD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/metaparse/v1/impl/void_.hpp>
#include <sstd/boost/metaparse/v1/lit.hpp>
#include <sstd/boost/metaparse/v1/return_.hpp>
#include <sstd/boost/metaparse/v1/is_error.hpp>
#include <sstd/boost/metaparse/v1/get_remaining.hpp>
#include <sstd/boost/metaparse/v1/get_position.hpp>

#include <sstd/boost/mpl/if.hpp>
#include <sstd/boost/mpl/eval_if.hpp>
#include <sstd/boost/mpl/empty.hpp>
#include <sstd/boost/mpl/pop_front.hpp>
#include <sstd/boost/mpl/front.hpp>

namespace boost
{
  namespace metaparse
  {
    namespace v1
    {
      // Does not consume/check anything after the keyword
      template <class Kw, class ResultType = impl::void_>
      struct keyword
      {
      private:
        struct nonempty
        {
        private:
          typedef lit<typename boost::mpl::front<Kw>::type> next_char_parser;

          typedef
            keyword<typename boost::mpl::pop_front<Kw>::type, ResultType>
            rest_parser;

          template <class S, class Pos>
          struct apply_unchecked :
            rest_parser::template apply<
              typename get_remaining<
                typename next_char_parser::template apply<S, Pos>
              >::type,
              typename get_position<
                typename next_char_parser::template apply<S, Pos>
              >::type
            >
          {};
        public:
          template <class S, class Pos>
          struct apply :
            boost::mpl::eval_if<
              typename is_error<
                typename next_char_parser::template apply<S, Pos>
              >::type,
              typename next_char_parser::template apply<S, Pos>,
              apply_unchecked<S, Pos>
            >
          {};
        };
      public:
        typedef keyword type;

        template <class S, class Pos>
        struct apply :
          boost::mpl::if_<
            boost::mpl::empty<Kw>,
            return_<ResultType>,
            nonempty
          >::type::template apply<S, Pos>
        {};
      };
    }
  }
}

#endif


