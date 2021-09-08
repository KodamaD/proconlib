#pragma once
#include "../utility/int_alias.cpp"

__attribute__((target("avx2"))) constexpr u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }
