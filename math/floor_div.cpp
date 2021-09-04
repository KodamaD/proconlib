#pragma once
#include <cassert>

template <class T> constexpr T floor_div(const T& x, const T& y) {
    assert(y != 0);
    return x / y - (((x ^ y) < 0) && (x % y));
}
