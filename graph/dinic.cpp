#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rec_lambda.cpp"

template <class Cap, std::enable_if_t<std::is_integral_v<Cap>>* = nullptr> class Dinic {
    struct Edge {
        usize dst, rev;
        Cap cap;
    };

    std::vector<std::vector<Edge>> graph;

  public:
    Dinic() : graph() {}

    class EdgePtr {
        friend class Dinic;
        Dinic* self;
        usize u, e;

        explicit EdgePtr(Dinic* p, const usize u, const usize e) : self(p), u(u), e(e) {}

        const Edge& edge() const { return self->graph[u][e]; }
        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev]; }

      public:
        EdgePtr() : self(nullptr), u(0), e(0) {}
        usize src() const { return u; }
        usize dst() const { return edge().dst; }
        Cap flow() const { return rev_edge().cap; }
        Cap capacity() const { return edge().cap + rev_edge().cap; }
    };

    class VerList {
        friend class Dinic;
        usize offset, len;
        explicit VerList(const usize o, const usize l) : offset(o), len(l) {}

      public:
        VerList() : offset(0), len(0) {}
        usize operator[](const usize i) const {
            assert(i < len);
            return offset + i;
        }
        usize to_idx(const usize i) const {
            assert(offset <= i and i < offset + len);
            return i - offset;
        }
    };

    usize size() const { return graph.size(); }

    usize add_vertex() {
        graph.emplace_back();
        return size() - 1;
    }
    VerList add_vertices(usize n) {
        VerList ret{size(), n};
        while (n--) graph.emplace_back();
        return ret;
    }

    EdgePtr add_edge(const usize src, const usize dst, const Cap capacity) {
        assert(src < size());
        assert(dst < size());
        assert(capacity >= 0);
        usize src_id = graph[src].size();
        usize dst_id = graph[dst].size();
        if (dst == src) dst_id += 1;
        graph[src].push_back(Edge{dst, dst_id, capacity});
        graph[dst].push_back(Edge{src, src_id, 0});
        return EdgePtr(this, src, src_id);
    }

    Cap flow(const usize src, const usize dst) { return flow(src, dst, std::numeric_limits<Cap>::max()); }
    Cap flow(const usize src, const usize dst, const Cap flow_limit) {
        assert(src < size());
        assert(dst < size());
        assert(src != dst);
        std::vector<usize> level(size()), iter(size());
        std::queue<usize> que;
        const auto bfs = [&] {
            std::fill(level.begin(), level.end(), size());
            level[src] = 0;
            while (!que.empty()) que.pop();
            que.push(src);
            while (!que.empty()) {
                const usize u = que.front();
                que.pop();
                for (const Edge& e : graph[u]) {
                    if (e.cap == 0 or level[e.dst] < size()) continue;
                    level[e.dst] = level[u] + 1;
                    if (e.dst == dst) return;
                    que.push(e.dst);
                }
            }
        };
        const auto dfs = rec_lambda([&](auto&& dfs, const usize u, const Cap ub) -> Cap {
            if (u == src) return ub;
            Cap ret = 0;
            for (usize& i = iter[u]; i < graph[u].size(); i += 1) {
                Edge& e = graph[u][i];
                Edge& re = graph[e.dst][e.rev];
                if (level[u] <= level[e.dst] or re.cap == 0) continue;
                const Cap d = dfs(e.dst, std::min(ub - ret, re.cap));
                if (d == 0) continue;
                e.cap += d;
                re.cap -= d;
                ret += d;
                if (ret == ub) return ret;
            }
            level[u] = size();
            return ret;
        });
        Cap ret = 0;
        while (ret < flow_limit) {
            bfs();
            if (level[dst] == size()) break;
            std::fill(iter.begin(), iter.end(), (usize)0);
            const Cap f = dfs(dst, flow_limit - ret);
            if (f == 0) break;
            ret += f;
        }
        return ret;
    }
};
