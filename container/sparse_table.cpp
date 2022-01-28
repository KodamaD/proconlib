#pragma once
#include <cassert>
#include <vector>
#include "../utility/bit_width.cpp"
#include "../utility/rep.cpp"

template <class M> class SparseTable {
    using T = typename M::Type;
    std::vector<std::vector<T>> table;

  public:
    SparseTable() : SparseTable(std::vector<T>()) {}
    explicit SparseTable(const std::vector<T>& vec) {
        const int size = vec.size();
        const int height = bit_width(size);
        table.reserve(height);
        table.push_back(vec);
        for (const int d : rep(1, height)) {
            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));
            for (const int i : rep(table[d].size())) {
                table[d][i] = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);
            }
        }
    }

    int size() const { return table[0].size(); }

    T fold(const int l, const int r) const {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return M::identity();
        const int d = bit_width(r - l) - 1;
        return M::operation(table[d][l], table[d][r - (1 << d)]);
    }
};
