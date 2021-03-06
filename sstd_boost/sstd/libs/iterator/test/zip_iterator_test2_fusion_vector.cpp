﻿#include <sstd/boost/config.hpp>

#include <sstd/boost/fusion/include/vector.hpp>
#include <sstd/boost/fusion/include/make_vector.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/at_c.hpp>

#define ZI_TUPLE      boost::fusion::vector
#define ZI_MAKE_TUPLE boost::fusion::make_vector
#define ZI_TUPLE_GET(n) boost::fusion::at_c<n>

#include "detail/zip_iterator_test_original.ipp"

