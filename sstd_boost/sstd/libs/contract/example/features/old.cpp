﻿
// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

#include <sstd/boost/contract.hpp>
#include <string>
#include <cassert>

//[old
char replace(std::string& s, unsigned index, char x) {
    char result;
    boost::contract::old_ptr<char> old_y; // Null, old value copied later...
    boost::contract::check c = boost::contract::function()
        .precondition([&] {
            BOOST_CONTRACT_ASSERT(index < s.size());
        })
        .old([&] { // ...after preconditions (and invariants) checked.
            old_y = BOOST_CONTRACT_OLDOF(s[index]);
        })
        .postcondition([&] {
            BOOST_CONTRACT_ASSERT(s[index] == x);
            BOOST_CONTRACT_ASSERT(result == *old_y);
        })
    ;

    result = s[index];
    s[index] = x;
    return result;
}
//]

int main() {
    std::string s = "abc";
    char r = replace(s, 1, '_');
    assert(s == "a_c");
    assert(r == 'b');
    return 0;
}


