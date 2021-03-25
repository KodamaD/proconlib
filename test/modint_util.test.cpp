#define PROBLEM "https://yukicoder.me/problems/no/117"
#include "../math/static_modint.cpp"
#include "../math/modint_util.cpp"
#include "../utility/int_alias.cpp"
#include <iostream>

using Fp = StaticModint<1000000007>;
using FpUtil = ModintUtil<Fp>;

int main() {
    usize T;
    std::cin >> T;
    while (T--) {
        char type, dust;
        usize N, K;
        std::cin >> type >> dust >> N >> dust >> K >> dust;
        if (type == 'C') {
            if (N < K) std::cout << 0 << '\n';
            else std::cout << FpUtil::binom(N, K) << '\n';
        }
        if (type == 'P') {
            if (N < K) std::cout << 0 << '\n';
            else std::cout << FpUtil::factpow(N, K) << '\n';
        }
        if (type == 'H') {
            if (N == 0 && K > 0) std::cout << 0 << '\n';
            else std::cout << FpUtil::homo(N, K) << '\n';
        }
    }
    return 0;
}