#pragma once
#include "int_alias.cpp"

__attribute__((target("avx2"))) constexpr int ceil_log2(const u64 x) {
    int e = 0;
    while (((u64)1 << e) < x) ++e;
    return e;
}