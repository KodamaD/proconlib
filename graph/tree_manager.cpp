#pragma once
#include <utility>
#include <variant>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"

template <class G> class TreeManager {
  public:
    class NodeInfo {
        friend class TreeManager;
        NodeInfo() : parent(0), subtree(0), head(0), enter(0), exit(0) {}

      public:
        usize parent, subtree, head, next, enter, exit;
    };

  private:
    using Self = TreeManager;
    std::vector<NodeInfo> node;

  public:
    TreeManager() : node() {}
    explicit TreeManager(const G& graph, const usize root = 0) : Self(graph, std::vector<usize>({root})) {}
    explicit TreeManager(const G& graph, const std::vector<usize>& root) : node(graph.size(), NodeInfo()) {
        const usize n = size();
        const auto build = rec_lambda([&](auto&& dfs, const usize u, const usize p) -> void {
            node[u].parent = p;
            node[u].subtree = 1;
            for (const usize v : graph[u]) {
                if (v != p) {
                    dfs(v, u);
                    node[u].subtree += node[v].subtree;
                }
            }
        });
        usize time_stamp = 0;
        const auto decompose = rec_lambda([&](auto&& dfs, const usize u, const usize h) -> void {
            node[u].head = h;
            node[u].enter = time_stamp++;
            usize& s = node[u].next;
            s = u;
            for (const usize v : graph[u])
                if (v != node[u].parent and (s == u or node[s].subtree < node[v].subtree)) s = v;
            if (s != u) {
                dfs(s, h);
                for (const usize v : graph[u])
                    if (v != node[u].parent and v != s) dfs(v, v);
            }
            node[u].exit = time_stamp;
        });
        for (const usize r : root) {
            assert(r < n);
            assert(node[r].subtree == 0);
            build(r, r);
            decompose(r, r);
        }
    }

    class Path {
        friend class TreeManager;
        usize src, dst;
        const Self* self;

        explicit Path(const usize s, const usize d, const Self* p) : src(s), dst(d), self(p) {}

      public:
        Path begin() const { return *this; }
        std::monostate end() const { return {}; }
        bool operator!=(std::monostate) const { return src != dst; }
        void operator++() { src = self->node[src].parent; }
        std::pair<usize, usize> operator*() {
            const usize x = src;
            const usize y = self->node[src].head;
            const usize z = self->node[dst].next;
            src = (y != self->node[dst].head ? y : z);
            return std::make_pair(x, src);
        }
    };

    usize size() const { return node.size(); }
    const NodeInfo& operator[](const usize u) const {
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

    Path path(const usize des, const usize anc) const {
        assert(des < size());
        assert(anc < size());
        assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);
        return Path(des, anc, this);
    }
};