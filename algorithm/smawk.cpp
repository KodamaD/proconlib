#pragma once
#include <numeric>
#include <vector>
#include "../utility/rep.cpp"

template <class T, class Select>
std::vector<T> smawk(const std::vector<T>& row, const std::vector<T>& column, const Select& select) {
    const int n = row.size();
    if (n == 0) return {};
    std::vector<T> c2;
    for (const T i : column) {
        while (!c2.empty() and select(row[c2.size() - 1], c2.back(), i)) c2.pop_back();
        if (c2.size() < n) c2.push_back(i);
    }
    std::vector<T> r2;
    for (int i = 1; i < n; i += 2) r2.push_back(row[i]);
    const std::vector<T> a2 = smawk(r2, c2, select);
    std::vector<T> ret(n);
    for (const int i : rep(a2.size())) ret[2 * i + 1] = a2[i];
    int j = 0;
    for (int i = 0; i < n; i += 2) {
        ret[i] = c2[j];
        const T end = (i + 1 == n ? c2.back() : ret[i + 1]);
        while (c2[j] != end) {
            j += 1;
            if (select(row[i], ret[i], c2[j])) ret[i] = c2[j];
        }
    }
    return ret;
}

template <class Select> std::vector<int> smawk(const int row, const int column, const Select& select) {
    std::vector<int> r(row), c(column);
    std::iota(r.begin(), r.end(), 0);
    std::iota(c.begin(), c.end(), 0);
    return smawk(r, c, select);
}
