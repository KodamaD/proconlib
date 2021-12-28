#pragma once
#include <algorithm>
#include <type_traits>
#include <vector>
#include "../math/mod_inv.cpp"
#include "../math/rem_euclid.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "convolution_mod.cpp"

template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
std::vector<T> convolution_int(const std::vector<T>& a, const std::vector<T>& b) {
    const int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    static constexpr u64 MOD1 = 754974721, MOD2 = 167772161, MOD3 = 469762049;
    static constexpr u64 M2M3 = MOD2 * MOD3, M1M3 = MOD1 * MOD3, M1M2 = MOD1 * MOD2;
    static constexpr u64 M1M2M3 = MOD1 * MOD2 * MOD3;
    static constexpr u64 I1 = mod_inv(MOD2 * MOD3, MOD1);
    static constexpr u64 I2 = mod_inv(MOD1 * MOD3, MOD2);
    static constexpr u64 I3 = mod_inv(MOD1 * MOD2, MOD3);
    static constexpr u64 OFFSET[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
    std::vector<T> c1 = convolution_mod<T, MOD1>(a, b);
    std::vector<T> c2 = convolution_mod<T, MOD2>(a, b);
    std::vector<T> c3 = convolution_mod<T, MOD3>(a, b);
    std::vector<T> c(n + m - 1);
    for (const int i : rep(n + m - 1)) {
        u64 x = 0;
        x += (c1[i] * I1) % MOD1 * M2M3;
        x += (c2[i] * I2) % MOD2 * M1M3;
        x += (c3[i] * I3) % MOD3 * M1M2;
        i64 diff = c1[i] - rem_euclid<i64>(x, MOD1);
        if (diff < 0) diff += MOD1;
        c[i] = x - OFFSET[diff % 5];
    }
    return c;
}