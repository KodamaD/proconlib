#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../utility/int_alias.cpp"
#include "../container/integer_hash_table.cpp"
#include <iostream>

int main() {
    usize Q;
    std::cin >> Q;
    IntegerHashTable<u64, u64> map;
    while (Q--) {
        char c;
        u64 k;
        std::cin >> c >> k;
        if (c == '0') {
            u64 v;
            std::cin >> v;
            map[k] = v;
        } else {
            std::cout << map[k] << '\n';
        }
    }
    return 0;
}