#pragma once
#include "../utility/int_alias.cpp"
#include "bit_lzeros.cpp"

__attribute__((target("avx2"))) constexpr u64 bit_width(const u64 x) { return 64 - bit_lzeros(x); }
