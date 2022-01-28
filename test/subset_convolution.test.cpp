#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include "../algorithm/subset_convolution.cpp"
#include "../math/static_modint.cpp"
#include "../traits/num_ring.cpp"
#include <iostream>
#include <vector>

using Fp = Modint998244353;

int main() {
    int N;
    std::cin >> N;
    N = 1 << N;
    std::vector<Fp> A(N), B(N);
    for (auto& x : A) {
        u32 t;
        std::cin >> t;
        x = t;
    }
    for (auto& x : B) {
        u32 t;
        std::cin >> t;
        x = t;
    }
    const auto C = subset_convolution<NumRing<Fp>>(A, B);
    for (const int i : rep(N)) {
        std::cout << C[i] << " \n"[i + 1 == N];
    }
}