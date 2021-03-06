#pragma once
#include "../utility/int_alias.cpp"
#include "../math/mod_pow.cpp"
#include <array>

constexpr u32 primitive_root(const u32 mod) {
    std::array<u32, 32> exp{};
    u32 cur = mod - 1;
    usize size = 0;
    for (u32 i = 2; i * i <= cur; ++i) {
        if (cur % i == 0) {
            exp[size++] = (mod - 1) / i;
            while (cur % i == 0) cur /= i;
        }
    }
    if (cur != 1) exp[size++] = (mod - 1) / cur;
    for (u32 check = 1; check < mod; ++check) {
        for (const auto e: exp) {
            if (e == 0) return check;
            if (mod_pow<u64>(check, e, mod) == 1) break;
        }
    }
    return mod;
}
