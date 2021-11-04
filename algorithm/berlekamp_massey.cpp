#pragma once
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class T> std::vector<T> berlekamp_massey(const std::vector<T>& a) {
    const usize n = a.size();
    std::vector<T> c = {T(-1)}, c2 = {T(0)};
    T r2 = 1;
    usize i2 = 0;
    for (const usize i : rep(0, n)) {
        T r = 0;
        const usize d = c.size();
        for (const usize j : rep(0, d)) r += c[j] * a[i - j];
        if (r == T(0)) continue;
        T coeff = -r / r2;
        const usize d2 = c2.size(), shift = i - i2 + 1;
        if (d2 + shift <= d) {
            for (const usize j : rep(0, d2)) c[j + shift] += c2[j] * coeff;
        } else {
            std::vector<T> tmp = c;
            c.resize(d2 + shift);
            for (const usize j : rep(0, d2)) c[j + shift] += c2[j] * coeff;
            c2 = std::move(tmp);
            i2 = i + 1;
            r2 = r;
        }
    }
    c.erase(c.begin());
    return c;
}