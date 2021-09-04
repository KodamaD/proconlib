#pragma once
#include "../utility/int_alias.cpp"

constexpr u64 bit_lzeros(const u64 x) { return x == 0 ? 64 : __builtin_clzll(x); }
