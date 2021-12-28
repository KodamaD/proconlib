#pragma once
#include "int_alias.cpp"

constexpr int bit_parity(const u64 x) { return __builtin_parityll(x); }
