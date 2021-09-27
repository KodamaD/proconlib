#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../container/queue_aggregation.cpp"
#include <iostream>
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"
#include "../traits/affine_composite_monoid.cpp"

using Fp = Modint998244353;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    usize Q;
    std::cin >> Q;
    QueueAggregation<AffineCompositeMonoid<Fp>> que;
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            u32 a, b;
            std::cin >> a >> b;
            que.push(Affine<Fp>(Fp(a), Fp(b)));
        } else if (t == 1) {
            que.pop();
        } else {
            u32 x;
            std::cin >> x;
            std::cout << que.fold().eval(Fp(x)) << '\n';
        }
    }
}