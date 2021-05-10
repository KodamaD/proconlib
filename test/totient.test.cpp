#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../utility/int_alias.cpp"
#include "../math/totient.cpp"
#include <iostream>

int main() {
    u32 x;
    std::cin >> x;
    std::cout << totient(x) << '\n';
    return 0;
}