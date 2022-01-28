#pragma once
#include <cassert>
#include <vector>
#include "../utility/bit_width.cpp"
#include "../utility/rep.cpp"
#include "ranked_subset_mobius_transform.cpp"
#include "ranked_subset_zeta_transform.cpp"

template <class R>
std::vector<typename R::Type> subset_convolution(const std::vector<typename R::Type>& a,
                                                 const std::vector<typename R::Type>& b) {
    assert(a.size() == b.size());
    const auto f = ranked_subset_zeta_transform<typename R::Sum>(a);
    const auto g = ranked_subset_zeta_transform<typename R::Sum>(b);
    const int n = a.size();
    const int logn = bit_width(n);
    std::vector<std::vector<typename R::Type>> h(n, std::vector<typename R::Type>(logn, R::Sum::identity()));
    for (const int i : rep(n))
        for (const int j : rep(logn))
            for (const int k : rep(logn - j))
                h[i][j + k] = R::Sum::operation(h[i][j + k], R::Product::operation(f[i][j], g[i][k]));
    return ranked_subset_mobius_transform<typename R::Sum>(std::move(h));
}