#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>
#include "../utility/index_offset.cpp"
#include "../utility/rep.cpp"

template <class Flow,
          class Cost,
          std::enable_if_t<std::is_integral_v<Flow> and std::is_integral_v<Cost> and std::is_signed_v<Cost>>* = nullptr>
class PrimalDual {
  public:
    struct Edge {
        int src, dst;
        Flow flow, cap;
        Cost cost;
    };

  private:
    int node_count;
    std::vector<Edge> graph;
    std::vector<Cost> potential;

  public:
    PrimalDual() : node_count(0), graph() {}
    explicit PrimalDual(const int n) : node_count(n), graph() {}

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
    int add_edge(const int src, const int dst, const Flow& cap, const Cost& cost) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(cap >= 0);
        graph.push_back(Edge{src, dst, 0, cap, cost});
        return edge_count() - 1;
    }

    Cost get_potential(const int u) const {
        assert(!potential.empty());
        assert(0 <= u and u < size());
        return potential[u];
    }
    void set_potential(const std::vector<Cost>& p) {
        assert((int)p.size() == size());
        for (const auto& e : graph) {
            if (e.cap == 0) continue;
            assert(e.cost - p[e.dst] + p[e.src] >= 0);
        }
        potential = p;
    }

    std::pair<Flow, Cost> flow(const int src, const int dst) {
        return flow(src, dst, std::numeric_limits<Flow>::max());
    }
    std::pair<Flow, Cost> flow(const int src, const int dst, const Flow& flow_limit) {
        return slope(src, dst, flow_limit).back();
    }
    std::vector<std::pair<Flow, Cost>> slope(const int src, const int dst) {
        return slope(src, dst, std::numeric_limits<Flow>::max());
    }
    std::vector<std::pair<Flow, Cost>> slope(const int src, const int dst, const Flow& flow_limit) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(src != dst);
        const int n = size();
        const int m = edge_count();
        struct E {
            int dst, rev;
            Flow cap;
            Cost cost;
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
                edge[eidx[i]] = {v, reidx[i], e.cap - e.flow, e.cost};
                edge[reidx[i]] = {u, eidx[i], e.flow, -e.cost};
            }
        }
        if (potential.empty()) set_potential(std::vector<Cost>(n));
        std::vector<Cost> dist(n);
        std::vector<int> prev_e(n);
        std::vector<char> visited(n);
        struct Q {
            Cost key;
            int to;
            bool operator<(const Q& r) const { return key > r.key; }
        };
        std::vector<int> que_min;
        std::vector<Q> que;
        const auto dual = [&]() {
            for (const int i : rep(n)) dist[i] = std::numeric_limits<Cost>::max();
            std::fill(visited.begin(), visited.end(), false);
            que_min.clear();
            que.clear();
            int heap_size = 0;
            dist[src] = 0;
            que_min.push_back(src);
            while (!que_min.empty() || !que.empty()) {
                int u;
                if (!que_min.empty()) {
                    u = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_size < (int)que.size()) {
                        heap_size++;
                        std::push_heap(que.begin(), que.begin() + heap_size);
                    }
                    u = que.front().to;
                    std::pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_size--;
                }
                if (visited[u]) continue;
                visited[u] = true;
                if (u == dst) break;
                for (const int i : rep(start[u], start[u + 1])) {
                    const auto& e = edge[i];
                    if (e.cap == 0) continue;
                    const int v = e.dst;
                    const Cost cost = e.cost - potential[v] + potential[u];
                    if (dist[v] - dist[u] > cost) {
                        dist[v] = dist[u] + cost;
                        prev_e[v] = e.rev;
                        if (cost == 0) {
                            que_min.push_back(v);
                        } else {
                            que.push_back(Q{dist[v], v});
                        }
                    }
                }
            }
            if (!visited[dst]) return false;
            for (const int u : rep(n)) {
                if (!visited[u]) continue;
                potential[u] -= dist[dst] - dist[u];
            }
            return true;
        };
        Flow flow = 0;
        Cost cost = 0, ratio = 0;
        std::vector<std::pair<Flow, Cost>> result = {{Flow(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual()) break;
            Flow push = flow_limit - flow;
            for (int u = dst; u != src; u = edge[prev_e[u]].dst) {
                push = std::min(push, edge[edge[prev_e[u]].rev].cap);
            }
            for (int u = dst; u != src; u = edge[prev_e[u]].dst) {
                auto& e = edge[prev_e[u]];
                e.cap += push;
                edge[e.rev].cap -= push;
            }
            const Cost per_flow = potential[dst] - potential[src];
            flow += push;
            cost += push * per_flow;
            if (flow != 0 and ratio == per_flow) result.pop_back();
            result.emplace_back(flow, cost);
            ratio = per_flow;
        }
        for (const int i : rep(m)) graph[i].flow = graph[i].cap - edge[eidx[i]].cap;
        return result;
    }
};