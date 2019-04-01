﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2004-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#define BOOST_CONTAINER_ADAPTIVE_NODE_POOL_CHECK_INVARIANTS
#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include <sstd/boost/interprocess/managed_shared_memory.hpp>
#include <sstd/boost/interprocess/containers/list.hpp>
#include <sstd/boost/interprocess/containers/vector.hpp>
#include <sstd/boost/interprocess/allocators/adaptive_pool.hpp>
#include "print_container.hpp"
#include "dummy_test_allocator.hpp"
#include "movable_int.hpp"
#include "list_test.hpp"
#include "vector_test.hpp"

using namespace boost::interprocess;

//We will work with wide characters for shared memory objects
//Alias an adaptive pool that allocates ints
typedef adaptive_pool
   <int, managed_shared_memory::segment_manager> shmem_node_allocator_t;

typedef ipcdetail::adaptive_pool_v1
   <int, managed_shared_memory::segment_manager> shmem_node_allocator_v1_t;

namespace boost {
namespace interprocess {

//Explicit instantiations to catch compilation errors
template class adaptive_pool<int, managed_shared_memory::segment_manager>;
template class adaptive_pool<void, managed_shared_memory::segment_manager>;

namespace ipcdetail {

template class ipcdetail::adaptive_pool_v1<int, managed_shared_memory::segment_manager>;
template class ipcdetail::adaptive_pool_v1<void, managed_shared_memory::segment_manager>;

}}}

//Alias list types
typedef list<int, shmem_node_allocator_t>    MyShmList;
typedef list<int, shmem_node_allocator_v1_t> MyShmListV1;

//Alias vector types
typedef vector<int, shmem_node_allocator_t>    MyShmVector;
typedef vector<int, shmem_node_allocator_v1_t> MyShmVectorV1;

int main ()
{
   if(test::list_test<managed_shared_memory, MyShmList, true>())
      return 1;

   if(test::list_test<managed_shared_memory, MyShmListV1, true>())
      return 1;

   if(test::vector_test<managed_shared_memory, MyShmVector>())
      return 1;

   if(test::vector_test<managed_shared_memory, MyShmVectorV1>())
      return 1;

   return 0;
}

#include <sstd/boost/interprocess/detail/config_end.hpp>
