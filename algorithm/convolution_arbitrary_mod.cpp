#pragma once
#include <vector>
#include "../algorithm/convolution_mod.cpp"
#include "../math/mod_inv.cpp"
#include "../math/rem_euclid.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/int_alias_extended.cpp"
#include "../utility/rep.cpp"

template <class T> std::vector<T> convolution_arbitrary_mod(const std::vector<T>& a, const std::vector<T>& b, const T& mod) {
    const usize n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    static constexpr u64 MOD1 = 754974721, MOD2 = 167772161, MOD3 = 469762049;
    static constexpr u64 M1M2 = MOD1 * MOD2;
    static constexpr u64 I2 = mod_inv(MOD1, MOD2);
    static constexpr u64 I3 = mod_inv(M1M2, MOD3);
    std::vector<T> c1 = convolution_mod<T, MOD1>(a, b);
    std::vector<T> c2 = convolution_mod<T, MOD2>(a, b);
    std::vector<T> c3 = convolution_mod<T, MOD3>(a, b);
    std::vector<T> c(n + m - 1);
    for (const usize i : rep(0, n + m - 1)) {
        const u32 x = c1[i];
        const u64 y = (u64) (c2[i] + MOD2 - x % MOD2) * I2 % MOD2 * MOD1 + x;
        c[i] = ((u128) (c3[i] + MOD3 - y % MOD3) * I3 % MOD3 * M1M2 + y) % mod;
    }
    return c;
}

template <class M> std::vector<M> convolution_arbitrary_mod(const std::vector<M>& a, const std::vector<M>& b) {
    const usize n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    std::vector<u32> a2(n), b2(m);
    for (const usize i : rep(0, n)) a2[i] = a[i].val();
    for (const usize i : rep(0, m)) b2[i] = b[i].val();
    std::vector<u32> c2 = convolution_arbitrary_mod(a2, b2, M::mod());
    std::vector<M> c(n + m - 1);
    for (const usize i : rep(0, n + m - 1)) c[i] = c2[i];
    return c;
}
