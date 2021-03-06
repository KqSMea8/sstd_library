﻿/*<-
Copyright (c) 2016 Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
->*/

//[ is_const_member
#include <type_traits>
#include <sstd/boost/callable_traits/is_const_member.hpp>

namespace ct = boost::callable_traits;

struct foo;

static_assert(ct::is_const_member<int(foo::*)() const>::value, "");
static_assert(!ct::is_const_member<int(foo::*)()>::value, "");

int main() {}
//]

