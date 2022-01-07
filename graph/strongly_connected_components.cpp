#pragma once
#include <cassert>
#include <vector>
#include "../utility/rec_lambda.cpp"
#include "../utility/rep.cpp"
#include "../utility/setmin.cpp"

template <class G> class StronglyConnectedComponents {
    int count;
    std::vector<int> index;

  public:
    StronglyConnectedComponents() : count(0), index() {}
    explicit StronglyConnectedComponents(const G& graph) : count(0), index(graph.size()) {
        const int n = size();
        int time_stamp = 0;
        std::vector<int> visited, low(n), ord(n);
        visited.reserve(n);
        const auto dfs = rec_lambda([&](auto&& dfs, const int u) -> void {
            low[u] = ord[u] = ++time_stamp;
            visited.push_back(u);
            for (const int v : graph[u]) {
                if (!ord[v]) {
                    dfs(v);
                    setmin(low[u], low[v]);
                } else {
                    setmin(low[u], ord[v]);
                }
            }
            if (low[u] == ord[u]) {
                while (true) {
                    const int v = visited.back();
                    visited.pop_back();
                    ord[v] = n;
                    index[v] = count;
                    if (u == v) break;
                }
                count += 1;
            }
        });
        for (const int u : rep(n))
            if (!ord[u]) dfs(u);
        for (auto& x : index) x = count - x - 1;
    }

    int size() const { return index.size(); }
    int group_count() const { return count; }
    int group_id(const int u) const {
        assert(0 <= u and u < size());
        return index[u];
    }

    std::vector<std::vector<int>> decopmose() const {
        std::vector<std::vector<int>> ret(group_count());
        std::vector<int> len(group_count());
        for (const int i : index) len[i] += 1;
        for (const int i : rep(0, group_count())) ret[i].reserve(len[i]);
        for (const int u : rep(size())) ret[index[u]].push_back(u);
        return ret;
    }
};
