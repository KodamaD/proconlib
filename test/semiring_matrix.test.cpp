#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../math/static_modint.cpp"
#include "../math/semiring_matrix.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/num_semiring.cpp"
#include <iostream>
#include <vector>

using Fp = Modint998244353;
using Num = NumSemiRing<Fp>;
using Matrix = SemiRingMatrix<Num>;

int main() {
    usize N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<Num>> A(N, std::vector<Num>(M));
    std::vector<std::vector<Num>> B(M, std::vector<Num>(K));
    for (auto& v: A) {
        for (auto& x: v) {
            u32 t;
            std::cin >> t;
            x.val = Fp(t);
        }
    }
    for (auto& v: B) {
        for (auto& x: v) {
            u32 t;
            std::cin >> t;
            x.val = Fp(t);
        }
    }
    const auto C = Matrix(A) * Matrix(B);
    for (const auto i: rep(0, N)) {
        for (const auto j: rep(0, K)) {
            std::cout << C[i][j].val << " \n"[j + 1 == K];
        }
    }
}