#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include <iostream>
#include <vector>
#include "../algorithm/convolution_arbitrary_mod.cpp"
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

using Fp = Modint1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Fp> a(n), b(m);
    for (auto& x : a) {
        u32 t;
        std::cin >> t;
        x = t;
    }
    for (auto& x : b) {
        u32 t;
        std::cin >> t;
        x = t;
    }
    const auto c = convolution_arbitrary_mod(std::move(a), std::move(b));
    for (const auto i : rep(0, c.size())) {
        std::cout << c[i] << " \n"[i + 1 == c.size()];
    }
    return 0;
}