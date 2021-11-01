#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../utility/index_offset.cpp"
#include "../utility/int_alias.cpp"

template <class E = usize> class BasicGraph {
    std::vector<std::vector<E>> graph;

  public:
    BasicGraph() : graph() {}
    explicit BasicGraph(const usize n) : graph(n) {}

    class EdgePtr {
        friend class BasicGraph;
        usize u, e;
        BasicGraph* self;

        explicit EdgePtr(const usize u, const usize e, BasicGraph* p) : u(u), e(e), self(p) {}

      public:
        EdgePtr() : u(0), e(0), self(nullptr) {}
        usize src() const { return u; }
        E& operator*() const { return self->graph[u][e]; }
        E* operator->() const { return &self->graph[u][e]; }
    };

    usize size() const { return graph.size(); }
    std::vector<E>& operator[](const usize u) {
        assert(u < size());
        return graph[u];
    }
    const std::vector<E>& operator[](const usize u) const {
        assert(u < size());
        return graph[u];
    }

    usize add_vertex() {
        graph.emplace_back();
        return size() - 1;
    }
    IndexOffset add_vertices(usize n) {
        IndexOffset ret(size(), n);
        while (n--) graph.emplace_back();
        return ret;
    }

    template <class... Args> EdgePtr add_edge(const usize u, Args&&... args) {
        assert(u < size());
        const usize e = graph[u].size();
        graph[u].emplace_back(std::forward<Args>(args)...);
        return EdgePtr(u, e, this);
    }
};
