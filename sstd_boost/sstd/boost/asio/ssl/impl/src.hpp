﻿//
// impl/ssl/src.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_SSL_IMPL_SRC_HPP
#define BOOST_ASIO_SSL_IMPL_SRC_HPP

#define BOOST_ASIO_SOURCE

#include <sstd/boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HEADER_ONLY)
# error Do not compile Asio library source with BOOST_ASIO_HEADER_ONLY defined
#endif

#include <sstd/boost/asio/ssl/impl/context.ipp>
#include <sstd/boost/asio/ssl/impl/error.ipp>
#include <sstd/boost/asio/ssl/detail/impl/engine.ipp>
#include <sstd/boost/asio/ssl/detail/impl/openssl_init.ipp>
#include <sstd/boost/asio/ssl/impl/rfc2818_verification.ipp>

#endif // BOOST_ASIO_SSL_IMPL_SRC_HPP

