#pragma once
#include <cassert>
#include <vector>
#include "../utility/bit_width.cpp"
#include "../utility/popcount.cpp"
#include "../utility/rep.cpp"

template <class G>
std::vector<typename G::Type> ranked_subset_mobius_transform(std::vector<std::vector<typename G::Type>> f) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    const int logn = bit_width(n);
    for (int i = n; i >>= 1;) {
        for (const int j : rep(n)) {
            if (j & i) {
                auto& a = f[j];
                const auto& b = f[j & ~i];
                for (const int k : rep(logn)) a[k] = G::operation(G::inverse(b[k]), a[k]);
            }
        }
    }
    std::vector<typename G::Type> g(n, G::identity());
    for (const int i : rep(n)) g[i] = f[i][popcount(i)];
    return g;
}
