#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/infty.cpp"
#include "../container/sparse_table.cpp"
#include <iostream>

struct Monoid {
    static constexpr Monoid zero() {
        return Monoid { INFTY<u32> };
    }
    u32 min;
    constexpr Monoid operator + (const Monoid& other) const {
        return Monoid { std::min(min, other.min) };
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Monoid> A(N, Monoid::zero());
    for (const usize i: rep(0, N)) {
        u32 x;
        std::cin >> x;
        A[i].min = x;
    }
    SparseTable<Monoid> table(A);
    while (Q--) {
        usize l, r;
        std::cin >> l >> r;
        std::cout << table.fold(l, r).min << '\n';
    }
    return 0;
}