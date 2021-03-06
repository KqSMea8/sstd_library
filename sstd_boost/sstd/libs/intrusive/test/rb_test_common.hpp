﻿/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2015-2015.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_INTRUSIVE_TEST_RB_TEST_COMMON_HPP
#define BOOST_INTRUSIVE_TEST_RB_TEST_COMMON_HPP

#include <sstd/boost/intrusive/set_hook.hpp>
#include <sstd/boost/intrusive/detail/mpl.hpp>
#include "bs_test_common.hpp"

namespace boost {
namespace intrusive {

template<class VoidPointer>
struct rb_hooks
{
   typedef set_base_hook<void_pointer<VoidPointer> >        base_hook_type;
   typedef set_base_hook
      <link_mode<auto_unlink>
      , void_pointer<VoidPointer>
      , tag<void>
      , optimize_size<true> >                               auto_base_hook_type;
   typedef set_member_hook
      <void_pointer<VoidPointer>
      , optimize_size<true> >                               member_hook_type;
   typedef set_member_hook
      < link_mode<auto_unlink>
      , void_pointer<VoidPointer> >                         auto_member_hook_type;
   typedef nonhook_node_member< rbtree_node_traits<VoidPointer>,
                                rbtree_algorithms
                              > nonhook_node_member_type;
};

}  //namespace intrusive {
}  //namespace boost {

#endif   //BOOST_INTRUSIVE_TEST_RB_TEST_COMMON_HPP

