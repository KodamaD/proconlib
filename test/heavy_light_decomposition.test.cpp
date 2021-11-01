#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <iostream>
#include <vector>
#include "../container/segment_tree.cpp"
#include "../graph/basic_graph.cpp"
#include "../graph/tree_manager.cpp"
#include "../math/static_modint.cpp"
#include "../traits/affine_composite_monoid.cpp"
#include "../traits/reversed_monoid.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

using Fp = Modint998244353;
using Line = Affine<Fp>;
using Monoid = AffineCompositeMonoid<Fp>;
using RevMonoid = ReversedMonoid<Monoid>;

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Line> F(N);
    for (auto& f : F) {
        u32 x, y;
        std::cin >> x >> y;
        f = Line(x, y);
    }
    BasicGraph graph(N);
    for (const auto _ : rep(1, N)) {
        usize x, y;
        std::cin >> x >> y;
        graph.add_edge(x, y);
        graph.add_edge(y, x);
    }
    TreeManager tree(graph);
    SegmentTree<Monoid> seg;
    SegmentTree<RevMonoid> seg_rev;
    {
        std::vector<Line> build(N);
        for (const auto i : rep(0, N)) {
            build[tree[i].enter] = F[i];
        }
        seg = SegmentTree<Monoid>(build);
        seg_rev = SegmentTree<RevMonoid>(build);
    }
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize p;
            u32 c, d;
            std::cin >> p >> c >> d;
            F[p] = Line(c, d);
            seg.assign(tree[p].enter, F[p]);
            seg_rev.assign(tree[p].enter, F[p]);
        } else {
            usize u, v;
            u32 x;
            std::cin >> u >> v >> x;
            const auto lca = tree.lca(u, v);
            Line sum_u, sum_v;
            for (const auto [a, b] : tree.path(u, lca)) {
                sum_u = sum_u.composite(seg_rev.fold(tree[b].enter, tree[a].enter + 1));
            }
            for (const auto [a, b] : tree.path(v, lca)) {
                sum_v = seg.fold(tree[b].enter, tree[a].enter + 1).composite(sum_v);
            }
            std::cout << sum_u.composite(F[lca]).composite(sum_v).eval(x) << '\n';
        }
    }
    return 0;
}