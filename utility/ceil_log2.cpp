#pragma once
#include "../internal/enable_avx2.cpp"
#include "bit_width.cpp"
#include "int_alias.cpp"

TARGET_AVX2 constexpr int ceil_log2(const u64 x) {
#ifdef __GNUC__
    return x == 0 ? 0 : bit_width(x - 1);
#else
    int e = 0;
    while (((u64)1 << e) < x) ++e;
    return e;
#endif
}