﻿// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_NULL_IN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_NULL_IN_HPP

#include <sstd/boost/winapi/process.hpp>
#include <sstd/boost/winapi/handles.hpp>
#include <sstd/boost/winapi/handle_info.hpp>
#include <sstd/boost/process/detail/handler_base.hpp>
#include <sstd/boost/process/detail/windows/file_descriptor.hpp>

namespace boost { namespace process { namespace detail { namespace windows {

struct null_in : public ::boost::process::detail::handler_base
{
    file_descriptor source{"NUL", file_descriptor::read};

public:
    template <class WindowsExecutor>
    void on_setup(WindowsExecutor &e) const
    {
        boost::winapi::SetHandleInformation(source.handle(),
                boost::winapi::HANDLE_FLAG_INHERIT_,
                boost::winapi::HANDLE_FLAG_INHERIT_);

        e.startup_info.hStdInput = source.handle();
        e.startup_info.dwFlags  |= boost::winapi::STARTF_USESTDHANDLES_;
        e.inherit_handles = true;
    }
};

}}}}

#endif

