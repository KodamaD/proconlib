#pragma once
#include "../utility/int_alias.cpp"
#include <vector>
#include <stack>
#include <utility>
#include <cassert>

class UnionFindRollback {
    std::vector<usize> data;
    std::stack<std::pair<usize, usize>> history;

public:
    explicit UnionFindRollback(const usize size = 0): data(size, -1), history() { }

    usize size() const { return data.size(); }

    usize leader(usize u) const {
        assert(u < size());
        while (data[u] < size()) u = data[u];
        return u;
    }

    usize size(const usize u) const {
        assert(u < size());
        return -data[leader(u)];
    }

    std::pair<usize, bool> merge(usize u, usize v) {
        assert(u < size());
        assert(v < size());
        u = leader(u); 
        v = leader(v);
        if (u == v) return std::make_pair(u, false);
        if (data[u] > data[v]) std::swap(u, v);
        history.emplace(u, data[u]);
        history.emplace(v, data[v]);
        data[u] += data[v];
        data[v] = u;
        return std::make_pair(u, true);
    }

    bool same(const usize u, const usize v) const {
        assert(u < size());
        assert(v < size());
        return leader(u) == leader(v);
    }

    void rollback(const usize steps) {
        assert(2 * steps <= history.size());
        for (usize i = 2 * steps; i > 0; --i) {
            const auto [k, x] = history.top();
            history.pop();
            data[k] = x;
        }
    }
};