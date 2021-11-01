#pragma once
#include <cassert>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"
#include "../utility/rep.cpp"
#include "../utility/setmin.cpp"

template <class G> class StronglyConnectedComponents {
    usize count;
    std::vector<usize> index;

  public:
    StronglyConnectedComponents() : count(0), index() {}
    explicit StronglyConnectedComponents(const G& graph) : count(0), index(graph.size()) {
        const usize n = size();
        usize time_stamp = 0;
        std::vector<usize> visited, low(n), ord(n);
        visited.reserve(n);
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
                    ord[v] = n;
                    index[v] = count;
                    if (u == v) break;
                }
                count += 1;
            }
        });
        for (const usize u : rep(0, n))
            if (!ord[u]) dfs(u);
        for (auto& x : index) x = count - x - 1;
    }

    usize size() const { return index.size(); }
    usize group_count() const { return count; }
    usize group_id(const usize u) const {
        assert(u < size());
        return index[u];
    }

    std::vector<std::vector<usize>> decopmose() const {
        std::vector<std::vector<usize>> ret(group_count());
        for (const usize u : rep(0, size())) ret[index[u]].push_back(u);
        return ret;
    }
};
