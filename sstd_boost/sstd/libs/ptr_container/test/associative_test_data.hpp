﻿//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2003-2005. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/ptr_container/
//

#include "test_data.hpp"
#include <sstd/boost/ptr_container/exception.hpp>
#include <sstd/boost/ptr_container/detail/ptr_container_disable_deprecated.hpp>
#include <sstd/boost/range/sub_range.hpp>

#if defined(BOOST_PTR_CONTAINER_DISABLE_DEPRECATED)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

template< typename C, typename B, typename T, bool Ordered >
void ptr_set_test();

template< class T, bool Ordered >
struct test_algorithms
{
    template< class Cont >
    void operator()( Cont& c, const Cont& c2 ) const
    {
        typename Cont::iterator i;
        typename Cont::const_iterator ci;

        T* t = new T;
        i  = c.lower_bound( *t );
        ci = c2.lower_bound( *t );
        i  = c.upper_bound( *t );
        ci = c2.upper_bound( *t );
        delete t;

        BOOST_DEDUCED_TYPENAME Cont::reverse_iterator ri         = c.rbegin();
        hide_warning(ri);
        BOOST_DEDUCED_TYPENAME Cont::const_reverse_iterator cri  = c2.rbegin();
        BOOST_DEDUCED_TYPENAME Cont::reverse_iterator rv2        = c.rend();
        hide_warning(rv2);
        BOOST_DEDUCED_TYPENAME Cont::const_reverse_iterator cvr2 = c2.rend();
        hide_warning(cvr2);
        cri = c.crbegin();
        cri = c.crend();
    }
};

template< class T >
struct test_algorithms<T,false>
{
    template< class Cont>
    void operator()( Cont& c, const Cont& c2 ) const
    {
    }
};

template< typename C, typename B, typename T, bool Ordered >
void ptr_set_test()
{
    using namespace boost;

    BOOST_TEST_MESSAGE( "starting associative container test" );
    enum { max_cnt = 10, size = 100 };
    C  c;
    BOOST_CHECK( c.size() == 0 );
    c.insert( c.end(), new T );
    c.insert( c.end(), new T );

    const C c2( c.begin(), c.end() );
    BOOST_CHECK( c.size() == c2.size() );

    C c3;

    BOOST_TEST_MESSAGE( "finished construction test" );

    C a_copy( c );
    BOOST_CHECK_EQUAL( a_copy.size(), c.size() );
    a_copy = a_copy;
    BOOST_CHECK_EQUAL( a_copy.size(), c.size() );
    c.clear();
    a_copy = c;
    a_copy = a_copy;
    BOOST_CHECK( a_copy.empty() );

    BOOST_TEST_MESSAGE( "finished copying test" );

    BOOST_DEDUCED_TYPENAME C::allocator_type alloc        = c.get_allocator();
    BOOST_DEDUCED_TYPENAME C::iterator i                  = c.begin();
    BOOST_DEDUCED_TYPENAME C::const_iterator ci           = c2.begin();
    ci = c.cbegin();
    ci = c.cend();
    BOOST_DEDUCED_TYPENAME C::iterator i2                 = c.end();
    hide_warning(i2);
    BOOST_DEDUCED_TYPENAME C::const_iterator ci2          = c2.begin();
    hide_warning(ci2);

    BOOST_TEST_MESSAGE( "finished iterator test" );

    BOOST_DEDUCED_TYPENAME C::size_type s                 = c.size();
    BOOST_DEDUCED_TYPENAME C::size_type s2                = c.max_size();
    hide_warning(s2);
    BOOST_CHECK_EQUAL( c.size(), s );
    bool b                                                = c.empty();
    hide_warning(b);
    BOOST_TEST_MESSAGE( "finished accessors test" );

    T* t = new T;
    c.insert( c.end(), t );
    c.insert( new T );
#ifndef BOOST_NO_AUTO_PTR
    c.insert( c.end(), std::auto_ptr<T>( new T ) );
    std::auto_ptr<T> ap( new T );
    c.insert( ap );
#endif
#ifndef BOOST_NO_CXX11_SMART_PTR
    c.insert( c.end(), std::unique_ptr<T>( new T ) );
    std::unique_ptr<T> up( new T );
    c.insert( std::move( up ) );
#endif
    c3.insert( c.begin(), c.end() );
    c.erase( c.begin() );
    c3.erase( c3.begin(), c3.end() );
    t = new T;
    c.insert( new T );
    c.erase( *t );
    delete t;

    BOOST_CHECK( c3.empty() );
    c.swap( c3 );
    BOOST_CHECK( !c3.empty() );
    BOOST_CHECK( c.empty() );
    c3.clear();

    //
    // remark: we cannot pass c3 directly as it would
    //         extract const iterators ... and the
    //         current standard does not allow erase()
    //         to be given const iterators
    //
    c3.erase( boost::make_iterator_range(c3) );
    BOOST_CHECK( c3.empty() );
    BOOST_TEST_MESSAGE( "finished modifiers test" );

    c.insert( c.end(), new T );
    typename C::auto_type ptr2  = c.release( c.begin() );
#ifndef BOOST_NO_AUTO_PTR
    std::auto_ptr<C> ap2        = c.release();
#else
    std::unique_ptr<C> up2      = c.release();
#endif
    c                           = c2.clone();
    BOOST_TEST_MESSAGE( "finished release/clone test" );

    c3.insert( new T );
    c3.insert( new T );
    BOOST_CHECK_EQUAL( c3.size(), 2u );
#if defined(BOOST_NO_SFINAE) || defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
#else
    c3.insert( make_iterator_range( c ) );
//    BOOST_CHECK_EQUAL( c3.size(), 4u );
#endif
    c. BOOST_NESTED_TEMPLATE transfer<C>( c3.begin(), c3 );
    BOOST_CHECK( c3.empty() == false );
    c.clear();
    unsigned long c3size = c3.size();
    hide_warning( c3size );
    unsigned long num  = c. BOOST_NESTED_TEMPLATE transfer<C>( c3.begin(),
                                                               c3.end(),
                                                              c3 );

    BOOST_CHECK( num > 0 );
    BOOST_CHECK_EQUAL( num, c.size() );
    BOOST_CHECK( c3.empty() );
    BOOST_CHECK( !c.empty() );
    c3. BOOST_NESTED_TEMPLATE transfer<C>( c );
    BOOST_CHECK( !c3.empty() );
    BOOST_CHECK( c.empty() );
#ifdef BOOST_NO_SFINAE
#else
    c.  BOOST_NESTED_TEMPLATE transfer<C>( make_iterator_range( c3 ), c3 );
    BOOST_CHECK( !c.empty() );
    BOOST_CHECK( c3.empty() );
#endif

    BOOST_TEST_MESSAGE( "finished transfer test" );

    C c4;
    c4.swap(c3);
    swap(c4,c3);
    BOOST_TEST_MESSAGE( "finished set/map interface test" );

    sub_range<C>        sub;
    sub_range<const C> csub;

    t = new T;
    i  = c.find( *t );
    ci = c2.find( *t );
    c2.count( *t );

    test_algorithms<T,Ordered>()( c, c2 );
    sub  = c.equal_range( *t );
    csub = c2.equal_range( *t );
    delete t;

    BOOST_TEST_MESSAGE( "finished algorithms interface test" );

}

#if defined(BOOST_PTR_CONTAINER_DISABLE_DEPRECATED)
#pragma GCC diagnostic pop
#endif

