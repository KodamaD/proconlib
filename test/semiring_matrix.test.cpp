#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <iostream>
#include <vector>
#include "../math/semiring_matrix.cpp"
#include "../math/static_modint.cpp"
#include "../traits/num_ring.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

using Fp = Modint998244353;
using Matrix = SemiRingMatrix<NumRing<Fp>>;

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<Fp>> A(N, std::vector<Fp>(M));
    std::vector<std::vector<Fp>> B(M, std::vector<Fp>(K));
    for (auto& v : A) {
        for (auto& x : v) {
            u32 t;
            std::cin >> t;
            x = Fp(t);
        }
    }
    for (auto& v : B) {
        for (auto& x : v) {
            u32 t;
            std::cin >> t;
            x = Fp(t);
        }
    }
    const auto C = Matrix(A) * Matrix(B);
    for (const auto i : rep(0, N)) {
        for (const auto j : rep(0, K)) {
            std::cout << C(i, j) << " \n"[j + 1 == K];
        }
    }
}