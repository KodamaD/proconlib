#pragma once
#include <cassert>
#include <utility>
#include <vector>

class RollbackUnionFind {
    std::vector<int> data;
    std::vector<std::pair<int, int>> history;

  public:
    explicit RollbackUnionFind(const int size = 0) : data(size, -1), history() {}

    int size() const { return data.size(); }

    int leader(int u) const {
        assert(0 <= u and u < size());
        while (data[u] >= 0) u = data[u];
        return u;
    }

    int size(const int u) const {
        assert(0 <= u and u < size());
        return -data[leader(u)];
    }

    std::pair<int, bool> merge(int u, int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        u = leader(u);
        v = leader(v);
        if (u == v) return std::make_pair(u, false);
        if (data[u] > data[v]) std::swap(u, v);
        history.emplace_back(u, data[u]);
        history.emplace_back(v, data[v]);
        data[u] += data[v];
        data[v] = u;
        return std::make_pair(u, true);
    }

    bool same(const int u, const int v) const {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        return leader(u) == leader(v);
    }

    void rollback(const int steps) {
        assert(0 <= steps and 2 * steps <= history.size());
        for (int i = 2 * steps; i > 0; --i) {
            const auto [k, x] = history.back();
            history.pop_back();
            data[k] = x;
        }
    }
};