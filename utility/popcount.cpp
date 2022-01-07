#pragma once
#include "../internal/enable_avx2.cpp"
#include "int_alias.cpp"

TARGET_AVX2 constexpr int popcount(u64 x) {
#ifdef __GNUC__
    return __builtin_popcountll(x);
#else
    x -= x >> 1 & 0x5555555555555555;
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;
    return x * 0x0101010101010101 >> 56 & 0x7f;
#endif
}