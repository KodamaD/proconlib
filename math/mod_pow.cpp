#pragma once
#include <cassert>
#include <type_traits>
#include "../utility/int_alias.cpp"
#include "../internal/barret_reduction.cpp"
#include "rem_euclid.cpp"

template <class T> constexpr u32 mod_pow(T x, u64 exp, const u32 mod) {
    assert(mod > 0);
    if (mod == 1) return 0;
    const proconlib::BarretReduction bt(mod);
    u32 ret = 1, mul = rem_euclid<std::common_type_t<T, i64>>(x, mod);
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) ret = bt.product(ret, mul);
        mul = bt.product(mul, mul);
    }
    return ret;
}
