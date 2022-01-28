#pragma once
#include <cassert>
#include <vector>
#include "../utility/bit_width.cpp"
#include "../utility/popcount.cpp"
#include "../utility/rep.cpp"

template <class S>
std::vector<std::vector<typename S::Type>> ranked_subset_zeta_transform(const std::vector<typename S::Type>& f) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    const int logn = bit_width(n);
    std::vector<std::vector<typename S::Type>> g(n, std::vector<typename S::Type>(logn, S::identity()));
    for (const int i : rep(n)) g[i][popcount(i)] = f[i];
    for (int i = 1; i < n; i <<= 1) {
        for (const int j : rep(n)) {
            if (j & i) {
                auto& a = g[j];
                const auto& b = g[j & ~i];
                for (const int k : rep(logn)) a[k] = S::operation(b[k], a[k]);
            }
        }
    }
    return g;
}
