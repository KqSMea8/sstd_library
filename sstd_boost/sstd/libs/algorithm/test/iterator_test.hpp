﻿/*
   Copyright (c) Marshall Clow 2013.

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    For more information, see http://www.boost.org
*/

#ifndef ITERATOR_TEST_H
#define ITERATOR_TEST_H

/*
    A set of iterator adapters for constructing test cases
    From an iterator (or a pointer), you can make any class of iterator.
    Assuming you want to degrade the capabilities.

    Modeled closely on work that Howard Hinnant did for libc++.
*/

#include <iterator>

// == Input Iterator ==
template <typename It>
class input_iterator {
public:
    typedef          std::input_iterator_tag                   iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    BOOST_CXX14_CONSTEXPR It base() const {return it_;}

    BOOST_CXX14_CONSTEXPR input_iterator() : it_() {}
    BOOST_CXX14_CONSTEXPR explicit input_iterator(It it) : it_(it) {}

    template <typename U>
    BOOST_CXX14_CONSTEXPR input_iterator(const input_iterator<U>& u) :it_(u.it_) {}

    BOOST_CXX14_CONSTEXPR reference operator*() const {return *it_;}
    BOOST_CXX14_CONSTEXPR pointer  operator->() const {return  it_;}

    BOOST_CXX14_CONSTEXPR input_iterator& operator++()    {++it_; return *this;}
    BOOST_CXX14_CONSTEXPR input_iterator  operator++(int) {input_iterator tmp(*this); ++(*this); return tmp;}

    BOOST_CXX14_CONSTEXPR friend bool operator==(const input_iterator& x, const input_iterator& y)
        {return x.it_ == y.it_;}
    BOOST_CXX14_CONSTEXPR friend bool operator!=(const input_iterator& x, const input_iterator& y)
        {return !(x == y);}

private:
    It it_;
    template <typename U> friend class input_iterator;
};

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator==(const input_iterator<T>& x, const input_iterator<U>& y)
{
    return x.base() == y.base();
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator!=(const input_iterator<T>& x, const input_iterator<U>& y)
{
    return !(x == y);
}


// == Forward Iterator ==
template <typename It>
class forward_iterator {
public:
    typedef          std::forward_iterator_tag                 iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    BOOST_CXX14_CONSTEXPR It base() const {return it_;}

    BOOST_CXX14_CONSTEXPR forward_iterator() : it_() {}
    BOOST_CXX14_CONSTEXPR explicit forward_iterator(It it) : it_(it) {}
    template <typename U>
    BOOST_CXX14_CONSTEXPR forward_iterator(const forward_iterator<U>& u) :it_(u.it_) {}

    BOOST_CXX14_CONSTEXPR reference operator*() const {return *it_;}
    BOOST_CXX14_CONSTEXPR pointer  operator->() const {return  it_;}

    BOOST_CXX14_CONSTEXPR forward_iterator& operator++()    {++it_; return *this;}
    BOOST_CXX14_CONSTEXPR forward_iterator  operator++(int) {forward_iterator tmp(*this); ++(*this); return tmp;}

    BOOST_CXX14_CONSTEXPR friend bool operator==(const forward_iterator& x, const forward_iterator& y)
        {return x.it_ == y.it_;}
    BOOST_CXX14_CONSTEXPR friend bool operator!=(const forward_iterator& x, const forward_iterator& y)
        {return !(x == y);}
private:
    It it_;

    template <typename U> friend class forward_iterator;
};

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator==(const forward_iterator<T>& x, const forward_iterator<U>& y)
{
    return x.base() == y.base();
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator!=(const forward_iterator<T>& x, const forward_iterator<U>& y)
{
    return !(x == y);
}

// == Bidirectional Iterator ==
template <typename It>
class bidirectional_iterator
{
public:
    typedef          std::bidirectional_iterator_tag           iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    BOOST_CXX14_CONSTEXPR It base() const {return it_;}

    BOOST_CXX14_CONSTEXPR bidirectional_iterator() : it_() {}
    BOOST_CXX14_CONSTEXPR explicit bidirectional_iterator(It it) : it_(it) {}
    template <typename U>
    BOOST_CXX14_CONSTEXPR bidirectional_iterator(const bidirectional_iterator<U>& u) :it_(u.it_) {}

    BOOST_CXX14_CONSTEXPR reference operator*() const {return *it_;}
    BOOST_CXX14_CONSTEXPR pointer  operator->() const {return  it_;}

    BOOST_CXX14_CONSTEXPR bidirectional_iterator& operator++()    {++it_; return *this;}
    BOOST_CXX14_CONSTEXPR bidirectional_iterator  operator++(int) {bidirectional_iterator tmp(*this); ++(*this); return tmp;}

    BOOST_CXX14_CONSTEXPR bidirectional_iterator& operator--()    {--it_; return *this;}
    BOOST_CXX14_CONSTEXPR bidirectional_iterator  operator--(int) {bidirectional_iterator tmp(*this); --(*this); return tmp;}
private:
    It it_;
    template <typename U> friend class bidirectional_iterator;
};

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator==(const bidirectional_iterator<T>& x, const bidirectional_iterator<U>& y)
{
    return x.base() == y.base();
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator!=(const bidirectional_iterator<T>& x, const bidirectional_iterator<U>& y)
{
    return !(x == y);
}


// == Random Access Iterator ==
template <typename It>
class random_access_iterator {
public:
    typedef          std::random_access_iterator_tag           iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    BOOST_CXX14_CONSTEXPR It base() const {return it_;}

    BOOST_CXX14_CONSTEXPR random_access_iterator() : it_() {}
    BOOST_CXX14_CONSTEXPR explicit random_access_iterator(It it) : it_(it) {}
    template <typename U>
    BOOST_CXX14_CONSTEXPR random_access_iterator(const random_access_iterator<U>& u) :it_(u.it_) {}

    BOOST_CXX14_CONSTEXPR reference operator*() const {return *it_;}
    BOOST_CXX14_CONSTEXPR pointer  operator->() const {return  it_;}

    BOOST_CXX14_CONSTEXPR random_access_iterator& operator++()    {++it_; return *this;}
    BOOST_CXX14_CONSTEXPR random_access_iterator  operator++(int) {random_access_iterator tmp(*this); ++(*this); return tmp;}

    BOOST_CXX14_CONSTEXPR random_access_iterator& operator--()    {--it_; return *this;}
    BOOST_CXX14_CONSTEXPR random_access_iterator  operator--(int) {random_access_iterator tmp(*this); --(*this); return tmp;}

    BOOST_CXX14_CONSTEXPR random_access_iterator& operator+=(difference_type n)       {it_ += n; return *this;}
    BOOST_CXX14_CONSTEXPR random_access_iterator  operator+ (difference_type n) const {random_access_iterator tmp(*this); tmp += n; return tmp;}
    BOOST_CXX14_CONSTEXPR friend random_access_iterator operator+(difference_type n, random_access_iterator x) {x += n; return x;}

    BOOST_CXX14_CONSTEXPR random_access_iterator& operator-=(difference_type n)       {return *this += -n;}
    BOOST_CXX14_CONSTEXPR random_access_iterator  operator- (difference_type n) const {random_access_iterator tmp(*this); tmp -= n; return tmp;}

    BOOST_CXX14_CONSTEXPR reference operator[](difference_type n) const {return it_[n];}
private:
    It it_;

    template <typename U> friend class random_access_iterator;
};

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator==(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return x.base() == y.base();
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator!=(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return !(x == y);
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator<(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return x.base() < y.base();
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator<=(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return !(y < x);
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator>(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return y < x;
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline bool
operator>=(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return !(x < y);
}

template <typename T, typename U>
BOOST_CXX14_CONSTEXPR inline typename std::iterator_traits<T>::difference_type
operator-(const random_access_iterator<T>& x, const random_access_iterator<U>& y)
{
    return x.base() - y.base();
}


// == Output Iterator ==
template <typename It>
class output_iterator {
public:
    typedef          std::output_iterator_tag                  iterator_category;
    typedef void                                               value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    BOOST_CXX14_CONSTEXPR It base() const {return it_;}

    BOOST_CXX14_CONSTEXPR output_iterator () {}
    BOOST_CXX14_CONSTEXPR explicit output_iterator(It it) : it_(it) {}

    template <typename U>
    BOOST_CXX14_CONSTEXPR output_iterator(const output_iterator<U>& u) :it_(u.it_) {}

    BOOST_CXX14_CONSTEXPR reference operator*() const {return *it_;}

    BOOST_CXX14_CONSTEXPR output_iterator& operator++()    {++it_; return *this;}
    BOOST_CXX14_CONSTEXPR output_iterator  operator++(int) {output_iterator tmp(*this); ++(*this); return tmp;}

private:
    It it_;
    template <typename U> friend class output_iterator;
    };

//  No comparison operators for output iterators


// == Get the base of an iterator; used for comparisons ==
template <typename Iter>
BOOST_CXX14_CONSTEXPR inline Iter base(output_iterator<Iter> i) { return i.base(); }

template <typename Iter>
BOOST_CXX14_CONSTEXPR inline Iter base(input_iterator<Iter> i) { return i.base(); }

template <typename Iter>
BOOST_CXX14_CONSTEXPR inline Iter base(forward_iterator<Iter> i) { return i.base(); }

template <typename Iter>
BOOST_CXX14_CONSTEXPR inline Iter base(bidirectional_iterator<Iter> i) { return i.base(); }

template <typename Iter>
BOOST_CXX14_CONSTEXPR inline Iter base(random_access_iterator<Iter> i) { return i.base(); }

template <typename Iter>    // everything else
BOOST_CXX14_CONSTEXPR inline Iter base(Iter i) { return i; }

#endif  // ITERATORS_H

