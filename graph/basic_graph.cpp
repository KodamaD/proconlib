#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../utility/index_offset.cpp"

template <class E = int> class BasicGraph {
    std::vector<std::vector<E>> graph;

  public:
    BasicGraph() : graph() {}
    explicit BasicGraph(const int n) : graph(n) {}

    class EdgePtr {
        friend class BasicGraph;
        int u, e;
        BasicGraph* self;

        explicit EdgePtr(const int u, const int e, BasicGraph* p) : u(u), e(e), self(p) {}

      public:
        EdgePtr() : u(0), e(0), self(nullptr) {}
        int src() const { return u; }
        E& operator*() const { return self->graph[u][e]; }
        E* operator->() const { return &self->graph[u][e]; }
    };

    int size() const { return graph.size(); }
    std::vector<E>& operator[](const int u) {
        assert(0 <= u and u < size());
        return graph[u];
    }
    const std::vector<E>& operator[](const int u) const {
        assert(0 <= u and u < size());
        return graph[u];
    }

    int add_vertex() {
        graph.emplace_back();
        return size() - 1;
    }
    IndexOffset add_vertices(int n) {
        IndexOffset ret(size(), n);
        while (n--) graph.emplace_back();
        return ret;
    }

    template <class... Args> EdgePtr add_edge(const int u, Args&&... args) {
        assert(0 <= u and u < size());
        const int e = graph[u].size();
        graph[u].emplace_back(std::forward<Args>(args)...);
        return EdgePtr(u, e, this);
    }
};
