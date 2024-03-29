#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include "../graph/primal_dual.cpp"
#include "../utility/int_alias.cpp"
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    PrimalDual<i32, i32> graph(N);
    while (M--) {
        int u, v;
        i32 c;
        std::cin >> u >> v >> c;
        graph.add_edge(u, v, c, 0);
    }
    std::cout << graph.flow(0, N - 1).first << '\n';
}