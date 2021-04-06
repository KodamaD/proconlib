#define PROBLEM https://judge.yosupo.jp/problem/unionfind
#include "../utility/int_alias.cpp"
#include "../graph/union_find.cpp"
#include <iostream>

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    UnionFind dsu(N);
    while (Q--) {
        usize t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            dsu.merge(u, v);
        }
        else {
            std::cout << dsu.same(u, v) << '\n';
        }
    }
    return 0;
}