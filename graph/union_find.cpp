#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"

class UnionFind {
    int components;
    std::vector<int> data;

  public:
    explicit UnionFind(const int size = 0) : components(size), data(size, (int)-1) {}

    int size() const { return data.size(); }
    int count() const { return components; }

    int leader(const int u) {
        assert(0 <= u and u < size());
        return data[u] < 0 ? u : data[u] = leader(data[u]);
    }

    int size(const int u) {
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
        components -= 1;
        data[u] += data[v];
        data[v] = u;
        return std::make_pair(u, true);
    }

    bool same(const int u, const int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        return leader(u) == leader(v);
    }

    std::vector<std::vector<int>> decompose() {
        std::vector<std::vector<int>> ret(size());
        for (const int u : rep(0, size())) {
            ret[leader(u)].push_back(u);
        }
        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const std::vector<int>& v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};