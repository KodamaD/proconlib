#pragma once
#include <queue>
#include <tuple>
#include <vector>
#include "../utility/rep.cpp"

template <class Select> std::vector<int> monotone_minima(const int row, const int column, const Select& select) {
    std::vector<int> ret(row);
    std::queue<std::tuple<int, int, int, int>> que;
    que.emplace(0, row, 0, column);
    while (!que.empty()) {
        const auto [l, r, d, u] = que.front();
        que.pop();
        const int m = (l + r) / 2;
        ret[m] = d;
        for (const int i : rep(d + 1, u))
            if (select(m, ret[m], i)) ret[m] = i;
        if (l != m) que.emplace(l, m, d, ret[m] + 1);
        if (m + 1 != r) que.emplace(m + 1, r, ret[m], u);
    }
    return ret;
}
