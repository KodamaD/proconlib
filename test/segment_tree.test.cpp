#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../math/static_modint.cpp"
#include "../container/segment_tree.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../traits/affine_composite_monoid.cpp"
#include <iostream>

using Fp = StaticModint<998244353>;

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Affine<Fp>> initial(N);
    for (const usize i: rep(0, N)) {
        u32 a, b;
        std::cin >> a >> b;
        initial[i] = {a, b};
    }
    SegmentTree<AffineCompositeMonoid<Fp>> seg(initial);
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize p;
            std::cin >> p;
            u32 c, d;
            std::cin >> c >> d;
            seg.assign(p, {Fp(c), Fp(d)});
        }
        else {
            usize l, r;
            std::cin >> l >> r;
            u32 x;
            std::cin >> x;
            std::cout << seg.fold(l, r).eval(Fp(x)) << '\n';
        }
    }
    return 0;
}