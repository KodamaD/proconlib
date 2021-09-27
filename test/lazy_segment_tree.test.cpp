#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../container/lazy_segment_tree.cpp"
#include <iostream>
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"
#include "../traits/affine_composite_monoid.cpp"
#include "../traits/pair_monoid.cpp"
#include "../traits/plus_monoid.cpp"
#include "../utility/rep.cpp"

using Fp = StaticModint<998244353>;

struct SumAffine {
    using Monoid = PairMonoid<PlusMonoid<Fp>, PlusMonoid<usize>>;
    using Effector = AffineCompositeMonoid<Fp>;
    static constexpr std::pair<Fp, usize> operation(const std::pair<Fp, usize>& m, const Affine<Fp>& e) {
        return {e.a * m.first + e.b * m.second, m.second};
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<Fp, usize>> initial(N);
    for (const usize i : rep(0, N)) {
        u32 a;
        std::cin >> a;
        initial[i] = {a, 1};
    }
    LazySegmentTree<SumAffine> seg(initial);
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize l, r;
            std::cin >> l >> r;
            u32 b, c;
            std::cin >> b >> c;
            seg.operate(l, r, {Fp(b), Fp(c)});
        } else {
            usize l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r).first << '\n';
        }
    }
    return 0;
}