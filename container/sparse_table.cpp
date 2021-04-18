#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../bit/bit_width.cpp"
#include <vector>
#include <cassert>

template <class IdempotentMonoid>
class SparseTable {
    using M = IdempotentMonoid;
    std::vector<std::vector<M>> table;

public:
    SparseTable(): SparseTable(std::vector<M>()) { }
    explicit SparseTable(const std::vector<M>& vec) {
        const auto size = vec.size();
        const auto height = bit_width(size);
        table.reserve(height);
        table.push_back(vec);
        for (const usize d: rep(1, height)) {
            table.push_back(std::vector<M>(size - (1 << d) + 1, M::zero()));
            for (const usize i: rep(0, table[d].size())) {
                table[d][i] = table[d - 1][i] + table[d - 1][i + (1 << (d - 1))];
            }
        }
    }

    usize size() const { return table[0].size(); }

    M fold(const usize l, const usize r) const {
        if (l == r) return M::zero();
        assert(l < r);
        const auto d = bit_width(r - l) - 1;
        return table[d][l] + table[d][r - (1 << d)];
    }
};
