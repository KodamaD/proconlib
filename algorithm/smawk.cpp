#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <vector>
#include <numeric>

template <class Index, class Select>
std::vector<Index> smawk(const std::vector<Index>& row, const std::vector<Index>& column, const Select& select) {
    const usize N = row.size();
    if (N == 0) return { };
    std::vector<Index> c2;
    for (const Index i: column) {
        while (!c2.empty() and select(row[c2.size() - 1], c2.back(), i)) c2.pop_back();
        if (c2.size() < N) c2.push_back(i);
    }
    std::vector<Index> r2;
    for (usize i = 1; i < N; i += 2) r2.push_back(row[i]);
    const std::vector<Index> a2 = smawk(r2, c2, select);
    std::vector<Index> ret(N);
    for (const usize i: rep(0, a2.size())) ret[2 * i + 1] = a2[i];
    usize j = 0;
    for (usize i = 0; i < N; i += 2) {
        ret[i] = c2[j];
        const Index end = (i + 1 == N ? c2.back() : ret[i + 1]);
        while (c2[j] != end) {
            j += 1;
            if (select(row[i], ret[i], c2[j])) ret[i] = c2[j];
        }
    }
    return ret;
}

template <class Select>
std::vector<usize> smawk(const usize row, const usize column, const Select& select) {
    std::vector<usize> r(row), c(column);
    std::iota(r.begin(), r.end(), (usize) 0);
    std::iota(c.begin(), c.end(), (usize) 0);
    return smawk(row, column, select);
}
