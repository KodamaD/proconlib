#pragma once
#include <vector>
#include "../utility/rep.cpp"

template <class T> std::vector<T> berlekamp_massey(const std::vector<T>& a) {
    const int n = a.size();
    std::vector<T> c = {T(-1)}, c2 = {T(0)};
    T r2 = 1;
    int i2 = 0;
    for (const int i : rep(0, n)) {
        T r = 0;
        const int d = c.size();
        for (const int j : rep(0, d)) r += c[j] * a[i - j];
        if (r == T(0)) continue;
        T coeff = -r / r2;
        const int d2 = c2.size(), shift = i - i2 + 1;
        if (d2 + shift <= d) {
            for (const int j : rep(0, d2)) c[j + shift] += c2[j] * coeff;
        } else {
            std::vector<T> tmp = c;
            c.resize(d2 + shift);
            for (const int j : rep(0, d2)) c[j + shift] += c2[j] * coeff;
            c2 = std::move(tmp);
            i2 = i + 1;
            r2 = r;
        }
    }
    c.erase(c.begin());
    return c;
}