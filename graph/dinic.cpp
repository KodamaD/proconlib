#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>
#include "../internal/simple_queue.cpp"
#include "../utility/index_offset.cpp"
#include "../utility/rec_lambda.cpp"
#include "../utility/rep.cpp"

template <class Flow, std::enable_if_t<std::is_integral_v<Flow>>* = nullptr> class Dinic {
  public:
    struct Edge {
        int src, dst;
        Flow flow, cap;
    };

  private:
    int node_count;
    std::vector<Edge> graph;

  public:
    Dinic() : node_count(0), graph() {}
    explicit Dinic(const int n) : node_count(n), graph() {}

    int size() const { return node_count; }
    int edge_count() const { return graph.size(); }

    int add_vertex() { return node_count++; }
    IndexOffset add_vertices(const int n) {
        assert(n >= 0);
        const IndexOffset ret(size(), n);
        node_count += n;
        return ret;
    }

    const Edge& get_edge(const int i) const {
        assert(0 <= i and i < edge_count());
        return graph[i];
    }
    int add_edge(const int src, const int dst, const Flow& cap) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(cap >= 0);
        graph.push_back(Edge{src, dst, 0, cap});
        return edge_count() - 1;
    }

    Flow flow(const int src, const int dst) { return flow(src, dst, std::numeric_limits<Flow>::max()); }
    Flow flow(const int src, const int dst, const Flow& flow_limit) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(src != dst);
        const int n = size();
        const int m = edge_count();
        struct E {
            int dst, rev;
            Flow cap;
        };
        std::vector<E> edge(2 * m);
        std::vector<int> start(n + 1), eidx(m);
        {
            std::vector<int> deg(n), reidx(m);
            for (const int i : rep(m)) {
                eidx[i] = deg[graph[i].src]++;
                reidx[i] = deg[graph[i].dst]++;
            }
            for (const int i : rep(n)) start[i + 1] = start[i] + deg[i];
            for (const int i : rep(m)) {
                const auto& e = graph[i];
                const int u = e.src, v = e.dst;
                eidx[i] += start[u];
                reidx[i] += start[v];
                edge[eidx[i]] = {v, reidx[i], e.cap - e.flow};
                edge[reidx[i]] = {u, eidx[i], e.flow};
            }
        }
        std::vector<int> level(n), iter(n);
        proconlib::SimpleQueue<int> que;
        const auto bfs = [&] {
            std::fill(level.begin(), level.end(), n);
            level[src] = 0;
            while (!que.empty()) que.pop();
            que.push(src);
            while (!que.empty()) {
                const int u = que.front();
                que.pop();
                for (const int i : rep(start[u], start[u + 1])) {
                    const auto& e = edge[i];
                    if (e.cap == 0 or level[e.dst] < n) continue;
                    level[e.dst] = level[u] + 1;
                    if (e.dst == dst) return;
                    que.push(e.dst);
                }
            }
        };
        const auto dfs = rec_lambda([&](auto&& dfs, const int u, const Flow& ub) -> Flow {
            if (u == src) return ub;
            Flow ret = 0;
            for (int& i = iter[u]; i < start[u + 1]; i += 1) {
                auto& e = edge[i];
                auto& re = edge[e.rev];
                if (level[u] <= level[e.dst] or re.cap == 0) continue;
                const Flow d = dfs(e.dst, std::min(ub - ret, re.cap));
                if (d == 0) continue;
                e.cap += d;
                re.cap -= d;
                ret += d;
                if (ret == ub) return ret;
            }
            level[u] = n;
            return ret;
        });
        Flow ret = 0;
        while (ret < flow_limit) {
            bfs();
            if (level[dst] == n) break;
            std::copy(start.begin(), start.begin() + n, iter.begin());
            const Flow f = dfs(dst, flow_limit - ret);
            if (f == 0) break;
            ret += f;
        }
        for (const int i : rep(m)) graph[i].flow = graph[i].cap - edge[eidx[i]].cap;
        return ret;
    }

    std::vector<char> min_cut(const int src) const {
        assert(0 <= src and src < size());
        const int n = size();
        std::vector<std::vector<int>> adj(n);
        for (const auto& e : graph) {
            if (e.flow < e.cap) adj[e.src].push_back(e.dst);
            if (e.flow > 0) adj[e.dst].push_back(e.src);
        }
        std::vector<char> ret(n);
        proconlib::SimpleQueue<int> que;
        que.push(src);
        ret[src] = true;
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (const int v : adj[u]) {
                if (!ret[v]) {
                    ret[v] = true;
                    que.push(v);
                }
            }
        }
        return ret;
    }
};