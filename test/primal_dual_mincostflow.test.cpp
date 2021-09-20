#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"
#include "../graph/primal_dual.cpp"
#include <iostream>

int main() {
    usize N, M;
    std::cin >> N >> M;
    i32 F;
    std::cin >> F;
    PrimalDual<i32, i32> graph(N);
    while (M--) {
        usize u, v;
        i32 c, d;
        std::cin >> u >> v >> c >> d;
        graph.add_edge(u, v, 0, c, d);
    }
    graph.add_supply(0, F);
    graph.add_demand(N - 1, F);
    const auto [cost, feasible] = graph.solve_bflow();
    std::cout << (feasible ? cost : -1) << '\n';
}