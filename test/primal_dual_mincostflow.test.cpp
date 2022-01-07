#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"
#include "../utility/int_alias.cpp"
#include "../graph/primal_dual.cpp"
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    i32 F;
    std::cin >> F;
    PrimalDual<i32, i32> graph(N);
    while (M--) {
        int u, v;
        i32 c, d;
        std::cin >> u >> v >> c >> d;
        graph.add_edge(u, v, c, d);
    }
    const auto [flow, cost] = graph.flow(0, N - 1, F);
    std::cout << (flow == F ? cost : -1) << '\n';
}