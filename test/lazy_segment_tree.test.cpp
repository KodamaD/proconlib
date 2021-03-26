#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../math/static_modint.cpp"
#include "../container/lazy_segment_tree.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <iostream>

using Fp = StaticModint<998244353>;

struct Monoid {
    static constexpr Monoid zero() {
        return Monoid { Fp::raw(0), 0 };
    }
    Fp sum;
    usize size;
    constexpr Monoid operator + (const Monoid& other) const {
        return Monoid { sum + other.sum, size + other.size };
    }
};

struct Effector {
    static constexpr Effector one() {
        return Effector { Fp::raw(1), Fp::raw(0) };
    }
    Fp a, b;
    constexpr Effector operator * (const Effector& other) const {
        return Effector { other.a * a, other.a * b + other.b };
    }
};

constexpr Monoid operator * (const Monoid& m, const Effector& e) {
    return Monoid { e.a * m.sum + e.b * Fp::raw(m.size), m.size };
}

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Monoid> initial(N, Monoid::zero());
    for (const usize i: rep(0, N)) {
        u32 a;
        std::cin >> a;
        initial[i].sum = Fp::raw(a);
        initial[i].size = 1;
    }
    LazySegmentTree<Monoid, Effector> seg(initial);
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize l, r;
            std::cin >> l >> r;
            u32 b, c;
            std::cin >> b >> c;
            seg.operate(l, r, Effector { Fp::raw(b), Fp::raw(c) });
        }
        else {
            usize l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r).sum << '\n';
        }
    }
    return 0;
}