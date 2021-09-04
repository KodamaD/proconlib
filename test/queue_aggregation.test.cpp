#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../container/queue_aggregation.cpp"
#include <iostream>
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"

using Fp = Modint998244353;

struct Monoid {
    Fp a, b;
    static constexpr Monoid zero() { return {Fp::raw(1), Fp::raw(0)}; }
    constexpr Monoid operator+(const Monoid& other) const { return Monoid{other.a * a, other.a * b + other.b}; }
    constexpr Fp get(const Fp& x) const { return a * x + b; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    usize Q;
    std::cin >> Q;
    QueueAggregation<Monoid> que;
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            u32 a, b;
            std::cin >> a >> b;
            que.push(Monoid{Fp(a), Fp(b)});
        } else if (t == 1) {
            que.pop();
        } else {
            u32 x;
            std::cin >> x;
            std::cout << que.fold().get(Fp(x)) << '\n';
        }
    }
}