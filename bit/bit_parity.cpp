#pragma once
#include "../utility/int_alias.cpp"

__attribute__((target("avx2"))) constexpr u64 bit_parity(const u64 x) { return __builtin_parityll(x); }
