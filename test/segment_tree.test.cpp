#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../math/static_modint.cpp"
#include "../container/segment_tree.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <iostream>

using Fp = StaticModint<998244353>;

struct Monoid {
    static constexpr Monoid zero() {
        return { Fp::raw(1), Fp::raw(0) };
    }
    Fp a, b;
    constexpr Monoid operator + (const Monoid& other) const {
        return Monoid { other.a * a, other.a * b + other.b };
    }
    constexpr Fp get(const Fp& x) const {
        return a * x + b;
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Monoid> initial(N, Monoid::zero());
    for (const usize i: rep(0, N)) {
        u32 a, b;
        std::cin >> a >> b;
        initial[i].a = Fp::raw(a);
        initial[i].b = Fp::raw(b);
    }
    SegmentTree<Monoid> seg(initial);
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize p;
            std::cin >> p;
            u32 c, d;
            std::cin >> c >> d;
            seg.assign(p, Monoid { Fp::raw(c), Fp::raw(d) });
        }
        else {
            usize l, r;
            std::cin >> l >> r;
            u32 x;
            std::cin >> x;
            std::cout << seg.fold(l, r).get(Fp::raw(x)) << '\n';
        }
    }
    return 0;
}