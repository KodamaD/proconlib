#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include <iostream>
#include <vector>
#include "../algorithm/berlekamp_massey.cpp"
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"

using Fp = Modint998244353;

int main() { 
    usize n;
    std::cin >> n;
    std::vector<Fp> a(n);
    for (auto& x : a) {
        u32 t;
        std::cin >> t;
        x = t;
    }
    const auto c = berlekamp_massey(a);
    std::cout << c.size() << '\n';
    for (const usize i : rep(0, c.size())) {
        std::cout << c[i] << " \n"[i + 1 == c.size()];
    }
    return 0; 
}