#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../graph/strongly_connected_components.cpp"
#include "../graph/basic_graph.cpp"
#include "../utility/int_alias.cpp"
#include <iostream>

int main() {
    usize N, M;
    std::cin >> N >> M;
    BasicGraph graph(N);
    while (M--) {
        usize a, b;
        std::cin >> a >> b;
        graph.add_edge(a, b);
    }
    const auto ans = StronglyConnectedComponents(graph).decopmose();
    std::cout << ans.size() << '\n';
    for (const auto& v : ans) {
        std::cout << v.size();
        for (const auto x : v) {
            std::cout << ' ' << x;
        }
        std::cout << '\n';
    }
}