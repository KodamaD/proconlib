#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../container/fenwick_tree.cpp"
#include <iostream>

int main() {
    int N, Q;
    std::cin >> N >> Q;
    FenwickTree<u64> fen(N);
    for (const int i: rep(0, N)) {
        u64 x;
        std::cin >> x;
        fen.add(i, x);
    }
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            u64 x;
            std::cin >> p >> x;
            fen.add(p, x);
        }
        else {
            int l, r;
            std::cin >> l >> r;
            std::cout << fen.fold(l, r) << '\n';
        }
    }
    return 0;
}