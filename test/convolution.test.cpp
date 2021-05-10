#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <iostream>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../math/static_modint.cpp"
#include "../math/convolution.cpp"

int main() {
    usize N, M;
    std::cin >> N >> M;
    std::vector<Modint998244353> A(N), B(M);
    for (const usize i: rep(0, N)) {
        u32 x;
        std::cin >> x;
        A[i] = x;
    }
    for (const usize i: rep(0, M)) {
        u32 x;
        std::cin >> x;
        B[i] = x;
    }
    const auto C = convolution(A, B);
    for (const usize i: rep(0, N + M - 1)) {
        std::cout << C[i] << " \n"[i + 1 == N + M - 1];
    }
}