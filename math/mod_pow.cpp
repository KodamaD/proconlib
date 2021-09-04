#pragma once
#include <cassert>
#include "../math/rem_euclid.cpp"

template <class T> constexpr T mod_pow(T x, u64 exp, const T& mod) {
    assert(mod > 0);
    T ret = T(1) % mod;
    x = rem_euclid(x, mod);
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}
