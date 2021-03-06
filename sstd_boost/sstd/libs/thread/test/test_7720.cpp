﻿// Copyright (C) 2013 Vicente Botet
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

////////////////////////////////////////////

//#define BOOST_THREAD_PROVIDES_GENERIC_SHARED_MUTEX_ON_WIN
#include <sstd/boost/thread/thread_only.hpp>
#include <sstd/boost/thread/shared_mutex.hpp>
using namespace boost;

shared_mutex mtx;

const int max_count = 100;
void f()
{
    int count =max_count;
    while (count--)
    {
        upgrade_lock<shared_mutex> lock(mtx);
    }
}

void g()
{
    int count =max_count;
    while (count--)
    {
        shared_lock<shared_mutex> lock(mtx);
    }
}

void h()
{
    int count =max_count;
    while (count--)
    {
        unique_lock<shared_mutex> lock(mtx);
    }
}

int main()
{
    thread t0(f);
    thread t1(g);
    thread t2(h);

    t0.join();
    t1.join();
    t2.join();

    return 0;
}



