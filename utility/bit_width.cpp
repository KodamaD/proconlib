#pragma once
#include "countl_zero.cpp"

constexpr int bit_width(const u64 x) { return 64 - countl_zero(x); }
