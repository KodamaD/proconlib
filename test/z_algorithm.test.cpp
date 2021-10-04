#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../algorithm/z_algorithm.cpp"
#include "../utility/rep.cpp"
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    const auto a = z_algorithm(s);
    for (const auto i : rep(0, s.size())) {
        std::cout << a[i] << " \n"[i + 1 == s.size()];
    }
    return 0;
}