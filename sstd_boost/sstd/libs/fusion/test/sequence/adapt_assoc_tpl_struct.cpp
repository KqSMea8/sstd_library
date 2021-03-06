﻿/*=============================================================================
    Copyright (c) 2010 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/at.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/size.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/empty.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/front.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/back.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/has_key.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/at_key.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/value_at_key.hpp>
#include <sstd/boost/fusion/sequence/io/out.hpp>
#include <sstd/boost/fusion/container/vector/vector.hpp>
#include <sstd/boost/fusion/container/list/list.hpp>
#include <sstd/boost/fusion/container/generation/make_vector.hpp>
#include <sstd/boost/fusion/container/vector/convert.hpp>
#include <sstd/boost/fusion/sequence/comparison/equal_to.hpp>
#include <sstd/boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <sstd/boost/fusion/sequence/comparison/less.hpp>
#include <sstd/boost/fusion/sequence/comparison/less_equal.hpp>
#include <sstd/boost/fusion/sequence/comparison/greater.hpp>
#include <sstd/boost/fusion/sequence/comparison/greater_equal.hpp>
#include <sstd/boost/fusion/support/is_view.hpp>
#include <sstd/boost/mpl/assert.hpp>
#include <sstd/boost/mpl/not.hpp>
#include <sstd/boost/type_traits/is_same.hpp>
#include <sstd/boost/static_assert.hpp>
#include <iostream>
#include <string>

namespace ns
{
    struct x_member;
    struct y_member;
    struct z_member;

    struct non_member;

    template<typename X, typename Y, typename Z>
    struct point
    {
        X x;
        Y y;
        Z z;
    };
}

#if BOOST_PP_VARIADICS
  BOOST_FUSION_ADAPT_ASSOC_TPL_STRUCT(
        (X)(Y)(Z),
        (ns::point)(X)(Y)(Z),
        (int, x, ns::x_member)
        (auto, y, ns::y_member)
        (z, ns::z_member)
    )

#else // BOOST_PP_VARIADICS
  BOOST_FUSION_ADAPT_ASSOC_TPL_STRUCT(
      (X)(Y)(Z),
      (ns::point)(X)(Y)(Z),
      (int, x, ns::x_member)
      (Y, y, ns::y_member)
      (auto, z, ns::z_member)
  )
#endif

template <typename TypeToConstruct>
struct empty_struct_templated_factory {

  TypeToConstruct operator()() {
    return TypeToConstruct();
  }

};

BOOST_FUSION_ADAPT_ASSOC_TPL_STRUCT(
    (TypeToConstruct),
    (empty_struct_templated_factory)(TypeToConstruct),
)

int
main()
{
    using namespace boost::fusion;

    typedef ns::point<int,int,float> point;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
        BOOST_MPL_ASSERT_NOT((traits::is_view<point>));
        BOOST_STATIC_ASSERT(!traits::is_view<point>::value);
        point p = {123, 456, 789.43f};

        std::cout << at_c<0>(p) << std::endl;
        std::cout << at_c<1>(p) << std::endl;
        std::cout << at_c<2>(p) << std::endl;
        std::cout << p << std::endl;
        BOOST_TEST(p == make_vector(123, 456, 789.43f));

        at_c<0>(p) = 6;
        at_c<1>(p) = 9;
        at_c<2>(p) = 12;
        BOOST_TEST(p == make_vector(6, 9, 12));

        BOOST_STATIC_ASSERT(boost::fusion::result_of::size<point>::value == 3);
        BOOST_STATIC_ASSERT(!boost::fusion::result_of::empty<point>::value);

        BOOST_TEST(front(p) == 6);
        BOOST_TEST(back(p) == 12);
    }

    {
        vector<int, float, int> v1(4, 2.f, 2);
        point v2 = {5, 3, 3.f};
        vector<long, double, float> v3(5, 4., 4.13f);
        BOOST_TEST(v1 < v2);
        BOOST_TEST(v1 <= v2);
        BOOST_TEST(v2 > v1);
        BOOST_TEST(v2 >= v1);
        BOOST_TEST(v2 < v3);
        BOOST_TEST(v2 <= v3);
        BOOST_TEST(v3 > v2);
        BOOST_TEST(v3 >= v2);
    }

    {
        // conversion from point to vector
        point p = {5, 3, 3.f};
        vector<int, long, int> v(p);
        v = p;
    }

    {
        // conversion from point to list
        point p = {5, 3, 3.f};
        list<int, long, int> l(p);
        l = p;
    }

    {
        // assoc stuff
        BOOST_MPL_ASSERT((boost::fusion::result_of::has_key<point, ns::x_member>));
        BOOST_MPL_ASSERT((boost::fusion::result_of::has_key<point, ns::y_member>));
        BOOST_MPL_ASSERT((boost::fusion::result_of::has_key<point, ns::z_member>));
        BOOST_MPL_ASSERT((boost::mpl::not_<boost::fusion::result_of::has_key<point, ns::non_member> >));

        BOOST_MPL_ASSERT((boost::is_same<boost::fusion::result_of::value_at_key<point, ns::x_member>::type, int>));
        BOOST_MPL_ASSERT((boost::is_same<boost::fusion::result_of::value_at_key<point, ns::y_member>::type, int>));
        BOOST_MPL_ASSERT((boost::is_same<boost::fusion::result_of::value_at_key<point, ns::z_member>::type, float>));

        point p = {5, 3, 9.f};

        BOOST_TEST(at_key<ns::x_member>(p) == 5);
        BOOST_TEST(at_key<ns::y_member>(p) == 3);
        BOOST_TEST(at_key<ns::z_member>(p) == 9);
    }

    return boost::report_errors();
}


