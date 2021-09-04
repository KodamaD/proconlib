#pragma once
#include "../utility/int_alias.cpp"

constexpr u64 ceil_log2(const u64 x) {
    u64 e = 0;
    while (((u64)1 << e) < x) ++e;
    return e;
}
