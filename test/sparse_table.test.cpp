#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../container/sparse_table.cpp"
#include <iostream>
#include <numeric>
#include "../traits/lambda_semigroup.cpp"
#include "../traits/optional_monoid.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<u32> A(N);
    for (auto& x : A) {
        std::cin >> x;
    }
    const auto sg_instance = lambda_semigroup([&](const int i, const int j) { return A[i] < A[j] ? i : j; });
    std::vector<std::optional<int>> vec(N);
    for (const auto i : rep(0, N)) {
        vec[i] = i;
    }
    SparseTable<OptionalMonoid<decltype(sg_instance)>> table(vec);
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << A[*table.fold(l, r)] << '\n';
    }
    return 0;
}