#define PROBLEM "https://yukicoder.me/problems/no/843"
#include "../math/prime_sieve.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <iostream>

int main() {
    u32 N;
    std::cin >> N;
    if (N == 1) {
        std::cout << 0 << '\n';
        return 0;
    }
    u32 ans = 1;
    for (const u32 r: rep(3, N + 1)) {
        if (r * r - 2 > N) break;
        if (PrimeUtil::is_prime(r) && PrimeUtil::is_prime(r * r - 2)) {
            ans += 2;
        }
    }
    std::cout << ans << '\n';
    return 0;
}