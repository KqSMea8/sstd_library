﻿//
// Copyright (c) 2015-2016 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef BOOST_BEAST_CORE_FILE_POSIX_HPP
#define BOOST_BEAST_CORE_FILE_POSIX_HPP

#include <sstd/boost/config.hpp>

#if ! defined(BOOST_BEAST_NO_POSIX_FILE)
# if ! defined(__APPLE__) && ! defined(__linux__)
#  define BOOST_BEAST_NO_POSIX_FILE
# endif
#endif

#if ! defined(BOOST_BEAST_USE_POSIX_FILE)
# if ! defined(BOOST_BEAST_NO_POSIX_FILE)
#  define BOOST_BEAST_USE_POSIX_FILE 1
# else
#  define BOOST_BEAST_USE_POSIX_FILE 0
# endif
#endif

#if BOOST_BEAST_USE_POSIX_FILE

#include <sstd/boost/beast/core/error.hpp>
#include <sstd/boost/beast/core/file_base.hpp>
#include <cstdint>

namespace boost {
namespace beast {

/** An implementation of File for POSIX systems.

    This class implements a @b File using POSIX interfaces.
*/
class file_posix
{
    int fd_ = -1;

public:
    /** The type of the underlying file handle.

        This is platform-specific.
    */
    using native_handle_type = int;

    /** Destructor

        If the file is open it is first closed.
    */
    ~file_posix();

    /** Constructor

        There is no open file initially.
    */
    file_posix() = default;

    /** Constructor

        The moved-from object behaves as if default constructed.
    */
    file_posix(file_posix&& other);

    /** Assignment

        The moved-from object behaves as if default constructed.
    */
    file_posix& operator=(file_posix&& other);

    /// Returns the native handle associated with the file.
    native_handle_type
    native_handle() const
    {
        return fd_;
    }

    /** Set the native handle associated with the file.

        If the file is open it is first closed.

        @param fd The native file handle to assign.
    */
    void
    native_handle(native_handle_type fd);

    /// Returns `true` if the file is open
    bool
    is_open() const
    {
        return fd_ != -1;
    }

    /** Close the file if open

        @param ec Set to the error, if any occurred.
    */
    void
    close(error_code& ec);

    /** Open a file at the given path with the specified mode

        @param path The utf-8 encoded path to the file

        @param mode The file mode to use

        @param ec Set to the error, if any occurred
    */
    void
    open(char const* path, file_mode mode, error_code& ec);

    /** Return the size of the open file

        @param ec Set to the error, if any occurred

        @return The size in bytes
    */
    std::uint64_t
    size(error_code& ec) const;

    /** Return the current position in the open file

        @param ec Set to the error, if any occurred

        @return The offset in bytes from the beginning of the file
    */
    std::uint64_t
    pos(error_code& ec) const;

    /** Adjust the current position in the open file

        @param offset The offset in bytes from the beginning of the file

        @param ec Set to the error, if any occurred
    */
    void
    seek(std::uint64_t offset, error_code& ec);

    /** Read from the open file

        @param buffer The buffer for storing the result of the read

        @param n The number of bytes to read

        @param ec Set to the error, if any occurred
    */
    std::size_t
    read(void* buffer, std::size_t n, error_code& ec) const;

    /** Write to the open file

        @param buffer The buffer holding the data to write

        @param n The number of bytes to write

        @param ec Set to the error, if any occurred
    */
    std::size_t
    write(void const* buffer, std::size_t n, error_code& ec);
};

} // beast
} // boost

#include <sstd/boost/beast/core/impl/file_posix.ipp>

#endif

#endif

