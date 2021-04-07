#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <vector>
#include <queue>
#include <tuple>

template <class Select>
std::vector<usize> monotone_minima(const usize row, const usize column, const Select& select) {
    std::vector<usize> ret(row);
    std::queue<std::tuple<usize, usize, usize, usize>> que;
    que.emplace(0, row, 0, column);
    while (!que.empty()) {
        const auto [l, r, d, u] = que.front();
        que.pop();
        const usize m = (l + r) / 2;
        ret[m] = d;
        for (const usize i: rep(d + 1, u)) {
            if (select(m, ret[m], i)) {
                ret[m] = i;
            }
        }
        if (l != m) {
            que.emplace(l, m, d, ret[m] + 1);
        }
        if (m + 1 != r) {
            que.emplace(m + 1, r, ret[m], u);
        }
    }
    return ret;
}
