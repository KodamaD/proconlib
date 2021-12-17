#pragma once
#include <algorithm>
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>
#include "../utility/index_offset.cpp"
#include "../utility/rep.cpp"
#include "../utility/setmin.cpp"

template <class Flow,
          class Cost,
          std::enable_if_t<std::is_integral_v<Flow> and std::is_integral_v<Cost> and std::is_signed_v<Flow> and
                           std::is_signed_v<Cost>>* = nullptr>
class PrimalDual {
    struct Edge {
        int dst, rev;
        Flow flow, cap;
        Cost cost;
    };

    std::vector<std::vector<Edge>> graph;
    std::vector<Flow> gap;
    std::vector<Cost> potential;

  public:
    PrimalDual() : graph() {}
    explicit PrimalDual(const int n) : graph(n), gap(n) {}

    class EdgePtr {
        friend class PrimalDual;
        PrimalDual* self;
        int u, e;

        explicit EdgePtr(PrimalDual* p, const int u, const int e) : self(p), u(u), e(e) {}

        const Edge& edge() const { return self->graph[u][e]; }
        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev]; }

      public:
        EdgePtr() : self(nullptr), u(0), e(0) {}
        int src() const { return u; }
        int dst() const { return edge().dst; }
        Flow flow() const { return edge().flow; }
        Flow lower() const { return -rev_edge().cap; }
        Flow upper() const { return edge().cap; }
        Cost cost() const { return edge().cost; }
    };

    int size() const { return graph.size(); }

    int add_vertex() {
        graph.emplace_back();
        gap.emplace_back();
        return size() - 1;
    }
    IndexOffset add_vertices(int n) {
        IndexOffset ret(size(), n);
        while (n--) {
            graph.emplace_back();
            gap.emplace_back();
        }
        return ret;
    }

    EdgePtr add_edge(const int src, const int dst, const Flow lower, const Flow upper, const Cost cost) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(lower <= upper);
        const int src_id = graph[src].size();
        const int dst_id = graph[dst].size() + (src == dst);
        graph[src].push_back(Edge{dst, dst_id, 0, upper, cost});
        graph[dst].push_back(Edge{src, src_id, 0, -lower, -cost});
        return EdgePtr(this, src, src_id);
    }

    void add_supply(const int u, const Flow f) {
        assert(0 <= u and u < size());
        gap[u] += f;
    }
    void add_demand(const int u, const Flow f) {
        assert(0 <= u and u < size());
        gap[u] -= f;
    }
    void set_potential(const std::vector<Cost>& p) {
        assert(p.size() == size());
        potential = p;
    }

    template <class Result = Cost> std::pair<Result, bool> solve_bflow() {
        potential.resize(size(), 0);
        for (const int u : rep(0, size())) {
            for (Edge& e : graph[u]) {
                if (e.flow > e.cap or e.cost + potential[u] - potential[e.dst] < 0) {
                    const Flow dif = e.cap - e.flow;
                    e.flow += dif;
                    graph[e.dst][e.rev].flow -= dif;
                    gap[u] -= dif;
                    gap[e.dst] += dif;
                }
            }
        }
        std::vector<int> over, lack;
        for (const int u : rep(0, size())) {
            if (gap[u] > 0) over.push_back(u);
            if (gap[u] < 0) lack.push_back(u);
        }
        struct State {
            Cost cost;
            int vertex;
            bool operator<(const State& other) const { return cost > other.cost; }
        };
        std::vector<State> heap;
        std::vector<Edge*> parent;
        std::vector<int> que_min;
        std::vector<Cost> dist;
        std::vector<char> seen;
        Cost farthest;
        const auto dual = [&] {
            over.erase(std::remove_if(over.begin(), over.end(), [&](const int u) { return gap[u] <= 0; }),
                       over.end());
            lack.erase(std::remove_if(lack.begin(), lack.end(), [&](const int u) { return gap[u] >= 0; }),
                       lack.end());
            if (over.empty() or lack.empty()) return false;
            dist.assign(size(), std::numeric_limits<Cost>::max());
            parent.assign(size(), nullptr);
            seen.assign(size(), false);
            que_min.clear();
            heap.clear();
            int heap_size = 0, lack_cnt = 0;
            farthest = 0;
            for (const int src : over) {
                dist[src] = 0;
                que_min.push_back(src);
            }
            while (!que_min.empty() or !heap.empty()) {
                int u;
                if (!que_min.empty()) {
                    u = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_size < heap.size()) {
                        heap_size += 1;
                        std::push_heap(heap.begin(), heap.begin() + heap_size);
                    }
                    u = heap.front().vertex;
                    std::pop_heap(heap.begin(), heap.end());
                    heap.pop_back();
                    heap_size -= 1;
                }
                if (seen[u]) continue;
                seen[u] = true;
                farthest = dist[u];
                if (gap[u] < 0) {
                    lack_cnt += 1;
                    if (lack_cnt == lack.size()) break;
                }
                for (const int i : rep(0, graph[u].size())) {
                    const Edge& e = graph[u][i];
                    if (e.flow >= e.cap) continue;
                    const int v = e.dst;
                    if (setmin(dist[v], dist[u] + e.cost + potential[u] - potential[v])) {
                        parent[v] = &graph[e.dst][e.rev];
                        if (dist[v] == dist[u]) {
                            que_min.push_back(v);
                        } else {
                            heap.push_back(State{dist[v], v});
                        }
                    }
                }
            }
            if (lack_cnt == 0) return false;
            for (const int u : rep(0, size())) {
                potential[u] += std::min(farthest, dist[u]);
            }
            return true;
        };
        while (dual()) {
            for (const int dst : lack) {
                if (dist[dst] > farthest) continue;
                Flow f = -gap[dst];
                int u = dst;
                while (parent[u] and f > 0) {
                    const Edge& e = graph[parent[u]->dst][parent[u]->rev];
                    setmin(f, e.cap - e.flow);
                    u = parent[u]->dst;
                }
                setmin(f, gap[u]);
                if (f <= 0) continue;
                u = dst;
                while (parent[u]) {
                    Edge& e = graph[parent[u]->dst][parent[u]->rev];
                    e.flow += f;
                    graph[e.dst][e.rev].flow -= f;
                    u = parent[u]->dst;
                }
                gap[u] -= f;
                gap[dst] += f;
            }
        }
        Result sum = 0;
        for (const auto& v : graph) {
            for (const Edge& e : v) {
                if (e.flow > 0) sum += (Result)e.flow * (Result)e.cost;
            }
        }
        return std::make_pair(sum, over.empty() and lack.empty());
    }

    template <class Result = Cost> std::pair<Flow, Result> flow(const int src, const int dst) {
        return flow<Result>(src, dst, std::numeric_limits<Flow>::max());
    }
    template <class Result = Cost>
    std::pair<Flow, Result> flow(const int src, const int dst, const Flow flow_limit) {
        assert(0 <= src and src < size());
        assert(0 <= dst and dst < size());
        assert(src != dst);
        assert(std::all_of(gap.begin(), gap.end(), [&](const Flow f) { return f == 0; }));
        Flow inf_flow = 0;
        for (const Edge& e : graph[src]) inf_flow += std::max<Flow>(e.cap, 0);
        add_edge(dst, src, 0, inf_flow, 0);
        assert(solve_bflow<Result>().second);
        gap[src] = flow_limit;
        gap[dst] = -flow_limit;
        const Result cost = solve_bflow<Result>().first;
        const Flow flow = flow_limit - gap[src];
        graph[src].pop_back();
        graph[dst].pop_back();
        return std::make_pair(flow, cost);
    }
};
