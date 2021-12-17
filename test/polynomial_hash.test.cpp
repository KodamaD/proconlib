#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "../utility/rep.cpp"
#include "../container/polynomial_hash.cpp"
#include <iostream>

int main() {
    std::string T, P;
    std::cin >> T >> P;
    if (T.size() < P.size()) {
        return 0;
    }
    PolynomialHash rh(std::vector<char>(T.begin(), T.end()));
    const auto match = PolynomialHash(std::vector<char>(P.begin(), P.end())).fold();
    for (const int i: rep(0, T.size() - P.size() + 1)) {
        if (rh.fold(i, i + P.size()) == match) {
            std::cout << i << '\n';
        }
    }
    return 0;
}