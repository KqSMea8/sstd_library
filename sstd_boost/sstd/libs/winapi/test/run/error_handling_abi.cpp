﻿/*
 *             Copyright Andrey Semashev 2018.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   error_handling_abi.cpp
 * \author Andrey Semashev
 * \date   10.03.2018
 *
 * \brief  This file contains ABI test for error_handling.hpp
 */

#include <sstd/boost/winapi/error_handling.hpp>
#include <windows.h>
#include "abi_test_tools.hpp"

int main()
{
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_ALLOCATE_BUFFER);
#endif

    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_IGNORE_INSERTS);
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_FROM_STRING);
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_FROM_HMODULE);
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_FROM_SYSTEM);
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_ARGUMENT_ARRAY);
    BOOST_WINAPI_TEST_CONSTANT(FORMAT_MESSAGE_MAX_WIDTH_MASK);

    BOOST_WINAPI_TEST_CONSTANT(LANG_NEUTRAL);
    BOOST_WINAPI_TEST_CONSTANT(LANG_INVARIANT);

    BOOST_WINAPI_TEST_CONSTANT(SUBLANG_DEFAULT);

#if BOOST_WINAPI_PARTITION_DESKTOP
    BOOST_WINAPI_TEST_CONSTANT(SEM_FAILCRITICALERRORS);
    BOOST_WINAPI_TEST_CONSTANT(SEM_NOGPFAULTERRORBOX);
    BOOST_WINAPI_TEST_CONSTANT(SEM_NOALIGNMENTFAULTEXCEPT);
    BOOST_WINAPI_TEST_CONSTANT(SEM_NOOPENFILEERRORBOX);
#endif

    BOOST_TEST_EQ(MAKELANGID(1, 2), boost::winapi::MAKELANGID_(1, 2));

#if !defined(BOOST_NO_ANSI_APIS)
    BOOST_WINAPI_TEST_FUNCTION_SIGNATURE(FormatMessageA);
#endif
    BOOST_WINAPI_TEST_FUNCTION_SIGNATURE(FormatMessageW);
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
    BOOST_WINAPI_TEST_FUNCTION_SIGNATURE(SetErrorMode);
#endif

    return boost::report_errors();
}

