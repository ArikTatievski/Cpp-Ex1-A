#include <iostream>
#include "mat.hpp"
#include <string>
#include <algorithm>
#include "doctest.h"

using namespace ariel;
TEST_CASE("Good short input") {
    CHECK(mat(1, 1, 'x', '-') == "x");
    CHECK(mat(3, 3, '6', '9') == "666\n696\n666");
    CHECK(mat(1, 3, 'x', '-') == "x\nx\nx");
    CHECK(mat(3, 1, 'k', '-') == "kkk");
    CHECK(mat(1, 5, 'x', '-') == "x\nx\nx\nx\nx");
    CHECK(mat(5, 1, 'k', '-') == "kkkkk");
}

TEST_CASE("Good long input") {
    CHECK(mat(5,11,'a','b') == "aaaaa\nabbba\nababa\nababa\nababa\nababa\nababa\nababa\nababa\nabbba\naaaaa");
    CHECK(mat(11,5,'a','b') == "aaaaaaaaaaa\nabbbbbbbbba\nabaaaaaaaba\nabbbbbbbbba\naaaaaaaaaaa");
    CHECK(mat(11,11,'a','b') == "aaaaaaaaaaa\nabbbbbbbbba\nabaaaaaaaba\nababbbbbaba\nababaaababa\nabababababa\nababaaababa\nababbbbbaba\nabaaaaaaaba\nabbbbbbbbba\naaaaaaaaaaa");
    CHECK(mat(21,13,'a','b') == "aaaaaaaaaaaaaaaaaaaaa\nabbbbbbbbbbbbbbbbbbba\nabaaaaaaaaaaaaaaaaaba\nababbbbbbbbbbbbbbbaba\nababaaaaaaaaaaaaababa\nabababbbbbbbbbbbababa\nabababaaaaaaaaabababa\nabababbbbbbbbbbbababa\nababaaaaaaaaaaaaababa\nababbbbbbbbbbbbbbbaba\nabaaaaaaaaaaaaaaaaaba\nabbbbbbbbbbbbbbbbbbba\naaaaaaaaaaaaaaaaaaaaa");
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(0, 0, 'x', '-'));
    CHECK_THROWS(mat(0, 7, 'x', '-'));
    CHECK_THROWS(mat(7, 0, 'x', '-'));
    CHECK_THROWS(mat(-1, 7, 'x', '-'));
    CHECK_THROWS(mat(7, -1, 'x', '-'));
    CHECK_THROWS(mat(-10, 0, 'x', '-'));
    CHECK_THROWS(mat(0, -10, 'x', '-'));
    CHECK_THROWS(mat(10, 11, 'x', '-'));
    CHECK_THROWS(mat(11, 10, 'x', '-'));
    CHECK_THROWS(mat(12, 12, 'x', '-'));
    CHECK_THROWS(mat(10, -6, 'x', '-'));
    CHECK_THROWS(mat(-6, 10, 'x', '-'));
    CHECK_THROWS(mat(-30, -30, 'x', '-'));
}
