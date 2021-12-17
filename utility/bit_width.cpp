#pragma once
#include "countl_zero.cpp"

__attribute__((target("avx2"))) constexpr int bit_width(const u64 x) { return 64 - countl_zero(x); }
