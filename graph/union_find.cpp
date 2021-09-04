#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

class UnionFind {
    usize components;
    std::vector<usize> data;

  public:
    explicit UnionFind(const usize size = 0) : components(size), data(size, (usize)-1) {}

    usize size() const { return data.size(); }
    usize count() const { return components; }

    usize leader(const usize u) {
        assert(u < size());
        if (data[u] >= size()) return u;
        return data[u] = leader(data[u]);
    }

    usize size(const usize u) {
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
        components -= 1;
        data[u] += data[v];
        data[v] = u;
        return std::make_pair(u, true);
    }

    bool same(const usize u, const usize v) {
        assert(u < size());
        assert(v < size());
        return leader(u) == leader(v);
    }

    std::vector<std::vector<usize>> decompose() {
        std::vector<std::vector<usize>> ret(size());
        for (const usize u : rep(0, size())) {
            ret[leader(u)].push_back(u);
        }
        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const std::vector<usize>& v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};