#pragma once
#include "../internal/enable_avx2.cpp"
#include "countl_zero.cpp"

TARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x); }
