#pragma once
#include <cassert>
#include <utility>
#include <variant>
#include <vector>
#include "../utility/rec_lambda.cpp"

template <class G> class TreeManager {
  public:
    struct NodeInfo {
        int parent, subtree, head, next, enter, exit;
    };

    class Path {
        friend class TreeManager;
        int src, dst;
        const TreeManager* self;

        explicit Path(const int s, const int d, const TreeManager* p) : src(s), dst(d), self(p) {}

      public:
        Path begin() const { return *this; }
        std::monostate end() const { return {}; }
        bool operator!=(std::monostate) const { return src != dst; }
        void operator++() { src = self->node[src].parent; }
        std::pair<int, int> operator*() {
            const int x = src;
            const int y = self->node[src].head;
            const int z = self->node[dst].next;
            src = (y != self->node[dst].head ? y : z);
            return {x, src};
        }
    };

  private:
    std::vector<NodeInfo> node;

  public:
    TreeManager() : node() {}
    explicit TreeManager(const G& graph, const int root = 0) : TreeManager(graph, std::vector<int>({root})) {}
    explicit TreeManager(const G& graph, const std::vector<int>& root) : node(graph.size(), NodeInfo{0, 0, 0, 0, 0, 0}) {
        const int n = size();
        const auto build = rec_lambda([&](auto&& dfs, const int u, const int p) -> void {
            node[u].parent = p;
            node[u].subtree = 1;
            for (const int v : graph[u]) {
                if (v != p) {
                    dfs(v, u);
                    node[u].subtree += node[v].subtree;
                }
            }
        });
        int time_stamp = 0;
        const auto decompose = rec_lambda([&](auto&& dfs, const int u, const int h) -> void {
            node[u].head = h;
            node[u].enter = time_stamp++;
            int& s = node[u].next;
            s = u;
            for (const int v : graph[u])
                if (v != node[u].parent and (s == u or node[s].subtree < node[v].subtree)) s = v;
            if (s != u) {
                dfs(s, h);
                for (const int v : graph[u])
                    if (v != node[u].parent and v != s) dfs(v, v);
            }
            node[u].exit = time_stamp;
        });
        for (const int r : root) {
            assert(0 <= r and r < n);
            assert(node[r].subtree == 0);
            build(r, r);
            decompose(r, r);
        }
    }

    int size() const { return node.size(); }
    const NodeInfo& operator[](const int u) const {
        assert(0 <= u and u < size());
        return node[u];
    }

    int lca(int u, int v) const {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        if (node[u].enter > node[v].enter) std::swap(u, v);
        while (node[u].enter < node[v].enter) {
            if (node[u].head == node[v].head) return u;
            v = node[node[v].head].parent;
        }
        return v;
    }

    Path path(const int des, const int anc) const {
        assert(0 <= des and des < size());
        assert(0 <= anc and anc < size());
        assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);
        return Path(des, anc, this);
    }
};