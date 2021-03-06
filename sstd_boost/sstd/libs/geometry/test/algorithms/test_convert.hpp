﻿// Boost.Geometry (aka GGL, Generic Geometry Library)
// Unit Test

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_TEST_CONVERT_HPP
#define BOOST_GEOMETRY_TEST_CONVERT_HPP


#include <sstd/boost/geometry/algorithms/assign.hpp>
#include <sstd/boost/geometry/algorithms/convert.hpp>
#include <sstd/boost/geometry/algorithms/make.hpp>
#include <sstd/boost/geometry/algorithms/num_points.hpp>

#include <sstd/boost/geometry/io/wkt/wkt.hpp>

#include <sstd/boost/geometry/geometries/geometries.hpp>
#include <sstd/boost/geometry/geometries/adapted/c_array.hpp>
#include <sstd/boost/geometry/geometries/adapted/boost_tuple.hpp>

#include <sstd/boost/variant/variant.hpp>

#include <geometry_test_common.hpp>

#include <test_common/test_point.hpp>

BOOST_GEOMETRY_REGISTER_C_ARRAY_CS(cs::cartesian)
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)



template <typename Geometry2, typename Geometry1>
void check_mixed(Geometry1 const& geometry1, std::string const& expected, int expected_point_count)
{
    Geometry2 geometry2;
    bg::convert(geometry1, geometry2);

    std::ostringstream out;
    out << bg::wkt(geometry2);
    BOOST_CHECK_EQUAL(out.str(), expected);

    std::size_t n = bg::num_points(geometry2);
    BOOST_CHECK_MESSAGE(expected_point_count < 0 || int(n) == expected_point_count,
            "convert: "
            << " #points expected: " << expected_point_count
            << " detected: " << n
            << " expected wkt: " << expected
            );
}

template <typename Geometry1, typename Geometry2>
void test_mixed(std::string const& wkt, std::string const& expected, int expected_point_count)
{
    Geometry1 geometry1;
    bg::read_wkt(wkt, geometry1);
    check_mixed<Geometry2>(geometry1, expected, expected_point_count);
    check_mixed<Geometry2>(boost::variant<Geometry1>(geometry1), expected, expected_point_count);
}

template <typename Geometry1, typename Geometry2>
void test_mixed_identical_result(std::string const& wkt)
{
    test_mixed<Geometry1, Geometry2>(wkt, wkt, -1);
    test_mixed<Geometry2, Geometry1>(wkt, wkt, -1);
}

template <typename Geometry1, typename Geometry2>
void test_mixed_reversible_result(std::string const& wkt1, std::string const& wkt2)
{
    test_mixed<Geometry1, Geometry2>(wkt1, wkt2, -1);
    test_mixed<Geometry2, Geometry1>(wkt2, wkt1, -1);
}

#endif

