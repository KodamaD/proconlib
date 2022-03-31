#pragma once
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class M> class ReRooting {
    using T = typename M::Type;

    std::vector<T> result;

  public:
    ReRooting() : result() {}
    template <class G, class F> explicit ReRooting(const G& graph, const F& fetch, const int root = 0) {
        const int n = graph.size();
        assert(0 <= root and root < n);
        std::vector<int> start(n + 1), dst(2 * (n - 1));
        for (const int u : rep(n)) {
            start[u + 1] = start[u];
            for (const int v : graph[u]) {
                assert(start[u + 1] < 2 * (n - 1));
                dst[start[u + 1]] = v;
                start[u + 1] += 1;
            }
        }
        std::vector<int> parent(n, -1), order, stack;
        order.reserve(n);
        stack.reserve(n);
        stack.push_back(root);
        while (!stack.empty()) {
            const int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (const int e : rep(start[u], start[u + 1])) {
                const int v = dst[e];
                if (v != parent[u]) {
                    parent[v] = u;
                    stack.push_back(v);
                }
            }
        }
        assert((int)order.size() == n);
        std::vector<T> bottom(n, M::identity());
        for (const int i : revrep(n)) {
            const int u = order[i];
            T sum = M::identity();
            for (const int e : rep(start[u], start[u + 1])) {
                if (dst[e] != parent[u]) sum = M::operation(sum, bottom[dst[e]]);
            }
            bottom[u] = fetch(u, sum);
        }
        std::vector<T> up(n, M::identity());
        result = std::vector<T>(n, M::identity());
        for (const int i : rep(n)) {
            const int u = order[i];
            std::vector<T> accum(start[u + 1] - start[u], M::identity());
            for (const int e : revrep(start[u] + 1, start[u + 1])) {
                accum[e - start[u] - 1] =
                    M::operation(dst[e] == parent[u] ? up[u] : bottom[dst[e]], accum[e - start[u]]);
            }
            T sum = M::identity();
            for (const int e : rep(start[u], start[u + 1])) {
                if (dst[e] == parent[u]) {
                    sum = M::operation(sum, up[u]);
                } else {
                    up[dst[e]] = fetch(u, M::operation(sum, accum[e - start[u]]));
                    sum = M::operation(sum, bottom[dst[e]]);
                }
            }
            result[u] = fetch(u, sum);
        }
    }

    int size() const { return result.size(); }

    T operator[](const int u) const {
        assert(0 <= u and u < size());
        return result[u];
    }
};
