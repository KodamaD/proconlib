#pragma once
#include <cassert>
#include <optional>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"
#include "../utility/rep.cpp"
#include "../utility/setmin.cpp"

class StronglyConnectedComponents {
    std::vector<std::vector<usize>> graph;
    std::vector<usize> index;
    std::optional<usize> decomposed;

    void decompose_internal() {
        decomposed = 0;
        index.resize(size());
        usize time_stamp = 0;
        std::vector<usize> visited, low(size()), ord(size());
        visited.reserve(size());
        const auto dfs = rec_lambda([&](auto&& dfs, const usize u) -> void {
            low[u] = ord[u] = ++time_stamp;
            visited.push_back(u);
            for (const usize v : graph[u]) {
                if (!ord[v]) {
                    dfs(v);
                    setmin(low[u], low[v]);
                } else {
                    setmin(low[u], ord[v]);
                }
            }
            if (low[u] == ord[u]) {
                while (true) {
                    const usize v = visited.back();
                    visited.pop_back();
                    ord[v] = size();
                    index[v] = *decomposed;
                    if (u == v) break;
                }
                *decomposed += 1;
            }
        });
        for (const usize u : rep(0, size())) {
            if (!ord[u]) dfs(u);
        }
        for (auto& x : index) {
            x = *decomposed - x - 1;
        }
    }

  public:
    StronglyConnectedComponents() : graph(), index(), decomposed() {}
    explicit StronglyConnectedComponents(const usize n) : graph(n), index(), decomposed() {}

    void add_edge(const usize u, const usize v) {
        assert(u < size());
        assert(v < size());
        assert(!decomposed);
        graph[u].push_back(v);
    }

    usize size() const { return graph.size(); }
    usize count_groups() {
        if (!decomposed) decompose_internal();
        return *decomposed;
    }
    usize group_id(const usize u) {
        assert(u < size());
        if (!decomposed) decompose_internal();
        return index[u];
    }

    std::vector<std::vector<usize>> decopmose() {
        std::vector<std::vector<usize>> ret(count_groups());
        for (const usize u : rep(0, size())) {
            ret[index[u]].push_back(u);
        }
        return ret;
    }
};
