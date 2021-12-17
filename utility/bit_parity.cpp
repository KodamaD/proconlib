#pragma once
#include "int_alias.cpp"

__attribute__((target("avx2"))) constexpr int bit_parity(const u64 x) { return __builtin_parityll(x); }
