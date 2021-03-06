﻿/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/fusion/container/list/list.hpp>
#include <sstd/boost/fusion/container/generation/make_list.hpp>
#include <sstd/boost/fusion/container/generation/list_tie.hpp>

#define FUSION_SEQUENCE list
#include "copy.hpp"

int
main()
{
    test<test_detail::can_copy>();
    return boost::report_errors();
}


