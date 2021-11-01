#pragma once
#include <cassert>

template <class T> constexpr T rem_euclid(T value, const T& mod) {
    assert(mod > 0);
    return (value %= mod) >= 0 ? value : value + mod;
}
