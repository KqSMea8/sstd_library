﻿
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/local_function

#include "const_block.hpp"
#include <cassert>

int main(void) {
    int x = 0, y = 0;
    CONST_BLOCK(x, y) {
        assert(x == y);
    } CONST_BLOCK_END
    return 0;
}


