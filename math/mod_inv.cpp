#pragma once
#include "inv_gcd.cpp"

template <class T>
constexpr T mod_inv(const T& a, const T& mod) {
    const auto [g, x] = inv_gcd(a, mod);
    assert(g == 1);
    return x;
}
