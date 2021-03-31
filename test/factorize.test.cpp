#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../math/factorize.cpp"
#include "../utility/int_alias.cpp"
#include <iostream>

int main() {
    u32 n;
    std::cin >> n;
    std::cout << n << ':';
    for (auto [p, e]: factorize(n)) {
        while (e--) {
            std::cout << ' ' << p;
        }
    }
    std::cout << '\n';
    return 0;
}