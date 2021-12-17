#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../container/lazy_segment_tree.cpp"
#include <iostream>
#include "../math/static_modint.cpp"
#include "../traits/sum_affine_action.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

using Fp = Modint998244353;
using Action = SumAffineAction<Fp>;

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<Fp, Fp>> initial(N);
    for (const int i : rep(0, N)) {
        u32 a;
        std::cin >> a;
        initial[i] = {a, 1};
    }
    LazySegmentTree<Action> seg(initial);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            std::cin >> l >> r;
            u32 b, c;
            std::cin >> b >> c;
            seg.operate(l, r, {Fp(b), Fp(c)});
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r).first << '\n';
        }
    }
    return 0;
}