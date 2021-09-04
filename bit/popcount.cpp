#pragma once
#include "../utility/int_alias.cpp"

constexpr u64 popcount(const u64 x) { return __builtin_popcountll(x); }
