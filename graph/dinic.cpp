#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>
#include <vector>
#include "../utility/index_offset.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"

template <class Flow, std::enable_if_t<std::is_integral_v<Flow>>* = nullptr> class Dinic {
    struct Edge {
        int dst, rev;
        Flow cap;
    };

    std::vector<std::vector<Edge>> graph;

  public:
    Dinic() : graph() {}
    explicit Dinic(const int n) : graph(n) {}

    class EdgePtr {
        friend class Dinic;
        Dinic* self;
        int u, e;

        explicit EdgePtr(Dinic* p, const int u, const int e) : self(p), u(u), e(e) {}

        const Edge& edge() const { return self->graph[u][e]; }
        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev]; }

      public:
        EdgePtr() : self(nullptr), u(0), e(0) {}
        int src() const { return u; }
        int dst() const { return edge().dst; }
        Flow flow() const { return rev_edge().cap; }
        Flow cap() const { return edge().cap + rev_edge().cap; }
    };

    int size() const { return graph.size(); }

    int add_vertex() {
        graph.emplace_back();
        return size() - 1;
    }
    IndexOffset add_vertices(int n) {
        IndexOffset ret(size(), n);
        while (n--) graph.emplace_back();
        return ret;
    }

    EdgePtr add_edge(const int src, const int dst, const Flow cap) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(cap >= 0);
        const int src_id = graph[src].size();
        const int dst_id = graph[dst].size() + (src == dst);
        graph[src].push_back(Edge{dst, dst_id, cap});
        graph[dst].push_back(Edge{src, src_id, 0});
        return EdgePtr(this, src, src_id);
    }

    Flow flow(const int src, const int dst) { return flow(src, dst, std::numeric_limits<Flow>::max()); }
    Flow flow(const int src, const int dst, const Flow flow_limit) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(src != dst);
        std::vector<int> level(size()), iter(size());
        std::queue<int> que;
        const auto bfs = [&] {
            std::fill(level.begin(), level.end(), size());
            level[src] = 0;
            while (!que.empty()) que.pop();
            que.push(src);
            while (!que.empty()) {
                const int u = que.front();
                que.pop();
                for (const Edge& e : graph[u]) {
                    if (e.cap == 0 or level[e.dst] < size()) continue;
                    level[e.dst] = level[u] + 1;
                    if (e.dst == dst) return;
                    que.push(e.dst);
                }
            }
        };
        const auto dfs = rec_lambda([&](auto&& dfs, const int u, const Flow ub) -> Flow {
            if (u == src) return ub;
            Flow ret = 0;
            for (int& i = iter[u]; i < (int)graph[u].size(); i += 1) {
                Edge& e = graph[u][i];
                Edge& re = graph[e.dst][e.rev];
                if (level[u] <= level[e.dst] or re.cap == 0) continue;
                const Flow d = dfs(e.dst, std::min(ub - ret, re.cap));
                if (d == 0) continue;
                e.cap += d;
                re.cap -= d;
                ret += d;
                if (ret == ub) return ret;
            }
            level[u] = size();
            return ret;
        });
        Flow ret = 0;
        while (ret < flow_limit) {
            bfs();
            if (level[dst] == size()) break;
            std::fill(iter.begin(), iter.end(), (int)0);
            const Flow f = dfs(dst, flow_limit - ret);
            if (f == 0) break;
            ret += f;
        }
        return ret;
    }

    std::vector<char> min_cut(const int src) const {
        std::vector<char> ret(size());
        std::queue<int> que;
        ret[src] = true;
        que.push(src);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (const Edge& e : graph[u]) {
                if (e.cap > 0 and !ret[e.dst]) {
                    ret[e.dst] = true;
                    que.push(e.dst);
                }
            }
        }
        return ret;
    }
};
