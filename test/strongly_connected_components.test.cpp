#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../utility/int_alias.cpp"
#include "../graph/strongly_connected_components.cpp"
#include <iostream>

int main() {
    usize N, M;
    std::cin >> N >> M;
    StronglyConnectedComponents scc(N);
    while (M--) {
        usize a, b;
        std::cin >> a >> b;
        scc.add_edge(a, b);
    }
    const auto ans = scc.decopmose();
    std::cout << ans.size() << '\n';
    for (const auto& v : ans) {
        std::cout << v.size();
        for (const auto x : v) {
            std::cout << ' ' << x;
        }
        std::cout << '\n';
    }
}