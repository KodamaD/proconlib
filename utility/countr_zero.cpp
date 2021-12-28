#pragma once
#include "int_alias.cpp"

constexpr int countr_zero(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }
