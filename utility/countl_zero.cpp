#pragma once
#include "../internal/enable_avx2.cpp"
#include "int_alias.cpp"

TARGET_AVX2 constexpr int countl_zero(u64 x) {
#ifdef __GNUC__
    return x == 0 ? 64 : __builtin_clzll(x);
#else
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return 64 - countr_zero(~x);
#endif
}
