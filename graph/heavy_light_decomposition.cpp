#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/rec_lambda.cpp"
#include <vector>
#include <utility>
#include <cassert>

class HeavyLightDecomposition {
    struct Node {
        std::vector<usize> adjacent;
        usize parent, subtree, head, enter, exit;
        Node() = default;
    };
    std::vector<Node> node;

public:
    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>& tree, const usize root = 0):
        HeavyLightDecomposition(tree, std::vector<usize>({ root })) { }
    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>& forest, const std::vector<usize>& root): node(forest.size()) {
        for (const auto i: rep(0, size())) node[i].adjacent = forest[i];
        const auto setup = rec_lambda([&](auto&& dfs, const usize u, const usize p) -> void {
            node[u].parent = p;
            node[u].subtree = 1;
            for (const auto v: node[u].adjacent) {
                if (v != p) {
                    dfs(v, u);
                    node[u].subtree += node[v].subtree;
                }
            }
        });
        for (const auto r: root) setup(r, r);
        usize time = 0;
        const auto decompose = rec_lambda([&](auto&& dfs, const usize u, const usize h) -> void {
            node[u].head = h;
            node[u].enter = time;
            time += 1;
            usize select = size();
            for (const auto v: node[u].adjacent) {
                if (v != node[u].parent and (select == size() or node[select].subtree < node[v].subtree)) {
                    select = v;
                }
            }
            if (select != size()) {
                dfs(select, h);
                for (const auto v: node[u].adjacent) {
                    if (v != node[u].parent and v != select) {
                        dfs(v, v);
                    }
                }
            }
            node[u].exit = time;
        });
        for (const auto r: root) decompose(r, r);
    }

    usize size() const { return node.size(); }
    const Node& info(const usize u) const {
        assert(u < size());
        return node[u];
    }

    usize lca(usize u, usize v) const {
        assert(u < size());
        assert(v < size());
        if (node[u].enter > node[v].enter) std::swap(u, v);
        while (node[u].enter < node[v].enter) {
            if (node[u].head == node[v].head) return u;
            v = node[node[v].head].parent;
        }
        return v;
    }

    std::vector<std::pair<usize, usize>> path(usize u, usize p) const {
        assert(u < size());
        assert(p < size());
        assert(node[p].enter <= node[u].enter and node[u].exit <= node[p].exit);
        std::vector<std::pair<usize, usize>> ret;
        while (node[u].head != node[p].head) {
            ret.emplace_back(u, node[u].head);
            u = node[node[u].head].parent;
        }
        ret.emplace_back(u, p);
        return ret;
    }
};