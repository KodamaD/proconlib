#pragma once
#include <cassert>
#include <vector>
#include "../bit/bit_width.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class M> class SparseTable {
    using T = typename M::Type;
    std::vector<std::vector<T>> table;

  public:
    SparseTable() : SparseTable(std::vector<T>()) {}
    explicit SparseTable(const std::vector<T>& vec) {
        const usize size = vec.size();
        const usize height = bit_width(size);
        table.reserve(height);
        table.push_back(vec);
        for (const usize d : rep(1, height)) {
            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));
            for (const usize i : rep(0, table[d].size())) {
                table[d][i] = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);
            }
        }
    }

    usize size() const { return table[0].size(); }

    T fold(const usize l, const usize r) const {
        if (l == r) return M::identity();
        assert(l < r);
        const auto d = bit_width(r - l) - 1;
        return M::operation(table[d][l], table[d][r - (1 << d)]);
    }
};
