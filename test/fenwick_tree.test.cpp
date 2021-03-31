#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../container/fenwick_tree.cpp"
#include <iostream>

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    FenwickTree<u64> fen(N);
    for (const usize i: rep(0, N)) {
        u64 x;
        std::cin >> x;
        fen.add(i, x);
    }
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize p;
            u64 x;
            std::cin >> p >> x;
            fen.add(p, x);
        }
        else {
            usize l, r;
            std::cin >> l >> r;
            std::cout << fen.fold(l, r) << '\n';
        }
    }
    return 0;
}