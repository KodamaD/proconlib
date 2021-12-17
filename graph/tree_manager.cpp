#pragma once
#include <cassert>
#include <utility>
#include <variant>
#include <vector>
#include "../utility/rec_lambda.cpp"

template <class G> class TreeManager {
  public:
    class NodeInfo {
        friend class TreeManager;
        NodeInfo() : parent(0), subtree(0), head(0), enter(0), exit(0) {}

      public:
        int parent, subtree, head, next, enter, exit;
    };

  private:
    using Self = TreeManager;
    std::vector<NodeInfo> node;

  public:
    TreeManager() : node() {}
    explicit TreeManager(const G& graph, const int root = 0) : Self(graph, std::vector<int>({root})) {}
    explicit TreeManager(const G& graph, const std::vector<int>& root) : node(graph.size(), NodeInfo()) {
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
            assert(0 <= r < n);
            assert(node[r].subtree == 0);
            build(r, r);
            decompose(r, r);
        }
    }

    class Path {
        friend class TreeManager;
        int src, dst;
        const Self* self;

        explicit Path(const int s, const int d, const Self* p) : src(s), dst(d), self(p) {}

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
            return std::make_pair(x, src);
        }
    };

    int size() const { return node.size(); }
    const NodeInfo& operator[](const int u) const {
        assert(u < size());
        return node[u];
    }

    int lca(int u, int v) const {
        assert(u < size());
        assert(v < size());
        if (node[u].enter > node[v].enter) std::swap(u, v);
        while (node[u].enter < node[v].enter) {
            if (node[u].head == node[v].head) return u;
            v = node[node[v].head].parent;
        }
        return v;
    }

    Path path(const int des, const int anc) const {
        assert(des < size());
        assert(anc < size());
        assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);
        return Path(des, anc, this);
    }
};