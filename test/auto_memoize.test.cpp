#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A"
#include "../utility/int_alias.cpp"
#include "../utility/auto_memoize.cpp"
#include <iostream>

int main() {
    u64 x;
    std::cin >> x;
    std::cout << AutoMemoize([](auto&& fib, const u64 x) -> u64 {
        if (x <= 1) return 1;
        return fib(x - 1) + fib(x - 2);
    })(x) << '\n';
    return 0;
}
