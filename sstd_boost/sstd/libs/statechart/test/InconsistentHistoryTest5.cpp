﻿//////////////////////////////////////////////////////////////////////////////
// Copyright 2005-2006 Andreas Huber Doenni
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//////////////////////////////////////////////////////////////////////////////



#include <sstd/boost/statechart/state_machine.hpp>
#include <sstd/boost/statechart/simple_state.hpp>



namespace sc = boost::statechart;
namespace mpl = boost::mpl;



struct A;
struct InconsistentHistoryTest : sc::state_machine<
  InconsistentHistoryTest, A > {};

struct B;
struct A : sc::simple_state< A, InconsistentHistoryTest, B > {};

  struct B : sc::simple_state< B, A > {};


int main()
{
  InconsistentHistoryTest machine;
  machine.initiate();
  // A does not have history
  machine.clear_shallow_history< A, 0 >();
  return 0;
}

