#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"
#include <vector>
#include <algorithm>

template <class T>
std::vector<T> divisors_from_factors(const std::vector<std::pair<T, usize>>& factors, const bool sort = true) {
    usize size = 1;
    for (const std::pair<T, usize>& f: factors) size *= f.second;
    std::vector<T> ret;
    ret.reserve(size);
    rec_lambda([&](auto&& dfs, const usize i, T x) -> void {
        if (i == factors.size()) {
            ret.push_back(x);
            return;
        }
        dfs(i + 1, x);
        const T p = factors[i].first;
        usize e = factors[i].second;
        while (e--) {
            x *= p;
            dfs(i + 1, x);
        }
    })(0, 1);
    if (sort) std::sort(ret.begin(), ret.end());
    return ret;
}
