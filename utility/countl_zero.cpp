#pragma once
#include "int_alias.cpp"

__attribute__((target("avx2"))) constexpr int countl_zero(const u64 x) { return x == 0 ? 64 : __builtin_clzll(x); }
