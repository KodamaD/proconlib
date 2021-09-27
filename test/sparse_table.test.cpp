#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/infty.cpp"
#include "../traits/min_monoid.cpp"
#include "../container/sparse_table.cpp"
#include <iostream>

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<u32> A(N);
    for (auto& x : A) {
        std::cin >> x;
    }
    SparseTable<MinMonoid<u32>> table(A);
    while (Q--) {
        usize l, r;
        std::cin >> l >> r;
        std::cout << table.fold(l, r) << '\n';
    }
    return 0;
}