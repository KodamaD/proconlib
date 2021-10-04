#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../algorithm/and_convolution.cpp"
#include "../math/static_modint.cpp"
#include <iostream>
#include <vector>

using Fp = Modint998244353;

int main() {
    usize N;
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
    const auto C = and_convolution(A, B);
    for (const auto i : rep(0, N)) {
        std::cout << C[i] << " \n"[i + 1 == N];
    }
}