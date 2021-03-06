﻿
// Copyright 2006-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "./containers.hpp"

#include "../helpers/input_iterator.hpp"
#include "../helpers/invariants.hpp"
#include "../helpers/random_values.hpp"
#include "../helpers/tracker.hpp"

template <typename T> inline void avoid_unused_warning(T const&) {}

test::seed_t initialize_seed(91274);

struct objects
{
  test::exception::object obj;
  test::exception::hash hash;
  test::exception::equal_to equal_to;
  test::exception::allocator<test::exception::object> allocator;
};

template <class T> struct construct_test1 : public objects, test::exception_base
{
  void run() const
  {
    T x;

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct construct_test2 : public objects, test::exception_base
{
  void run() const
  {
    T x(300);

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct construct_test3 : public objects, test::exception_base
{
  void run() const
  {
    T x(0, hash);

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct construct_test4 : public objects, test::exception_base
{
  void run() const
  {
    T x(0, hash, equal_to);

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct construct_test5 : public objects, test::exception_base
{
  void run() const
  {
    T x(50, hash, equal_to, allocator);

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct construct_test6 : public objects, test::exception_base
{
  void run() const
  {
    T x(allocator);

    DISABLE_EXCEPTIONS;
    BOOST_TEST(x.empty());
    test::check_equivalent_keys(x);
  }
};

template <class T> struct range : public test::exception_base
{
  test::random_values<T> values;

  range() : values(5, test::limited_range) {}
  range(unsigned int count) : values(count, test::limited_range) {}
};

template <class T> struct range_construct_test1 : public range<T>, objects
{
  void run() const
  {
    T x(this->values.begin(), this->values.end());

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

template <class T> struct range_construct_test2 : public range<T>, objects
{
  void run() const
  {
    T x(this->values.begin(), this->values.end(), 0);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

template <class T> struct range_construct_test3 : public range<T>, objects
{
  void run() const
  {
    T x(this->values.begin(), this->values.end(), 0, hash);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

template <class T> struct range_construct_test4 : public range<T>, objects
{
  void run() const
  {
    T x(this->values.begin(), this->values.end(), 100, hash, equal_to);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

// Need to run at least one test with a fairly large number
// of objects in case it triggers a rehash.
template <class T> struct range_construct_test5 : public range<T>, objects
{
  range_construct_test5() : range<T>(60) {}

  void run() const
  {
    T x(this->values.begin(), this->values.end(), 0, hash, equal_to, allocator);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

template <class T> struct input_range_construct_test : public range<T>, objects
{
  input_range_construct_test() : range<T>(60) {}

  void run() const
  {
    typename test::random_values<T>::const_iterator begin =
                                                      this->values.begin(),
                                                    end = this->values.end();
    T x(test::input_iterator(begin), test::input_iterator(end), 0, hash,
      equal_to, allocator);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

template <class T> struct copy_range_construct_test : public range<T>, objects
{
  copy_range_construct_test() : range<T>(60) {}

  void run() const
  {
    T x(test::copy_iterator(this->values.begin()),
      test::copy_iterator(this->values.end()), 0, hash, equal_to, allocator);

    DISABLE_EXCEPTIONS;
    test::check_container(x, this->values);
    test::check_equivalent_keys(x);
  }
};

// clang-format off
EXCEPTION_TESTS(
  (construct_test1)(construct_test2)(construct_test3)(construct_test4)
  (construct_test5)(construct_test6)(range_construct_test1)
  (range_construct_test2)(range_construct_test3)(range_construct_test4)
  (range_construct_test5)(input_range_construct_test)
  (copy_range_construct_test),
  CONTAINER_SEQ)
// clang-format on

RUN_TESTS()

