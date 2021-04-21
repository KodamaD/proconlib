#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../utility/int_alias.cpp"
#include "../math/static_modint.cpp"
#include "../container/segment_tree.cpp"
#include "../graph/heavy_light_decomposition.cpp"
#include <iostream>

using Fp = Modint998244353;

struct Line {
    Fp a, b;
    Fp get(const Fp& x) const {
        return a * x + b;
    }
    Line operator + (const Line& other) const {
        return Line { other.a * a, other.a * b + other.b };
    }
};

struct Monoid {
    static Monoid zero() {
        return Monoid(1, 0);
    }
    Line line, line_rev;
    explicit Monoid(const Fp& a, const Fp& b): line({a, b}), line_rev({a, b}) { }
    explicit Monoid(const Line& line, const Line& line_rev): line(line), line_rev(line_rev) { }
    Monoid operator + (const Monoid& other) const {
        return Monoid(line + other.line, other.line_rev + line_rev);
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<std::vector<usize>> graph(N);
    std::vector<Fp> A(N), B(N);
    for (const auto i: rep(0, N)) {
        u32 a, b;
        std::cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    for (const auto i: rep(0, N - 1)) {
        usize u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    HeavyLightDecomposition hld(graph);
    SegmentTree<Monoid> seg;
    {
        std::vector<Monoid> build(N, Monoid::zero());
        for (const auto i: rep(0, N)) {
            build[hld.info(i).enter] = Monoid(A[i], B[i]);
        }
        seg = SegmentTree(build);
    }
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize p;
            u32 c, d;
            std::cin >> p >> c >> d;
            seg.assign(hld.info(p).enter, Monoid(c, d));
        }
        else {
            usize u, v;
            u32 x;
            std::cin >> u >> v >> x;
            const auto lca = hld.lca(u, v);
            Line sum_u { 1, 0 };
            for (const auto [a, b]: hld.path(u, lca)) {
                sum_u = sum_u + seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line_rev;
            }
            Line sum_v { 1, 0 };
            for (const auto [a, b]: hld.path(v, lca)) {
                if (b == lca) {
                    sum_v = seg.fold(hld.info(b).enter + 1, hld.info(a).enter + 1).line + sum_v;
                }
                else {
                    sum_v = seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line + sum_v;
                }
            }
            std::cout << (sum_u + sum_v).get(x) << '\n';
        }
    }
    return 0;
}