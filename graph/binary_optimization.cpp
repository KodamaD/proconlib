#pragma once
#include <cassert>
#include <limits>
#include <vector>
#include "../utility/index_offset.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "graph/dinic.cpp"

template <class T> class BinaryOptimization {
    Dinic<T> graph;
    T constant;
    std::vector<usize> var_id;
    usize src, dst;

  public:
    BinaryOptimization() : graph(), constant(), var_id(), src(graph.add_vertex()), dst(graph.add_vertex()) {}
    explicit BinaryOptimization(const usize n) : BinaryOptimization() { add_variables(n); }

    usize count_variables() const { return var_id.size(); }

    usize add_variable() {
        var_id.push_back(graph.add_vertex());
        return count_variables() - 1;
    }
    IndexOffset add_variables(usize n) {
        IndexOffset ret(count_variables(), n);
        while (n--) var_id.push_back(graph.add_vertex());
        return ret;
    }

    void add_cost(const T& c) { constant += c; }

    template <class F> void add_cost(const usize x, const F& f) {
        assert(x < count_variables());
        const T a = f(0), b = f(1);
        if (a <= b) {
            graph.add_edge(src, var_id[x], b - a);
            add_cost(a);
        } else {
            graph.add_edge(var_id[x], dst, a - b);
            add_cost(b);
        }
    }

    template <class F> void add_cost(const usize x, const usize y, const F& f) {
        assert(x < count_variables());
        assert(y < count_variables());
        const T a = f(0, 0), b = f(0, 1), c = f(1, 0), d = f(1, 1);
        assert(b + c >= a + d);
        add_cost(a);
        add_cost(x, [&](const bool v) { return v ? c - a : 0; });
        add_cost(y, [&](const bool v) { return v ? d - c : 0; });
        graph.add_edge(var_id[x], var_id[y], (b + c) - (a + d));
    }

    void disable(const usize x, const bool f) {
        assert(x < count_variables());
        if (f)
            graph.add_edge(src, var_id[x], std::numeric_limits<T>::max());
        else
            graph.add_edge(var_id[x], dst, std::numeric_limits<T>::max());
    }

    void disable(const usize x, const usize y, const bool f, const bool g) {
        assert(x < count_variables());
        assert(y < count_variables());
        assert((f ^ g));
        if (f)
            graph.add_edge(var_id[y], var_id[x], std::numeric_limits<T>::max());
        else
            graph.add_edge(var_id[x], var_id[y], std::numeric_limits<T>::max());
    }

    T solve() { return constant + graph.flow(src, dst); }
    std::vector<char> restore() {
        const std::vector<char> cut = graph.min_cut(src);
        const usize n = count_variables();
        std::vector<char> ret(n);
        for (const usize i : rep(0, n)) ret[i] = !cut[var_id[i]];
        return ret;
    }
};