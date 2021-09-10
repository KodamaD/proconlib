#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../graph/dinic.cpp"
#include <iostream>
#include <vector>

int main() {
    usize L, R, M;
    std::cin >> L >> R >> M;
    Dinic<usize> dinic;
    const auto src = dinic.add_vertex();
    const auto dst = dinic.add_vertex();
    const auto left = dinic.add_vertices(L);
    const auto right = dinic.add_vertices(R);
    std::vector<Dinic<usize>::EdgePtr> ptr(M);
    for (const auto i : rep(0, L)) {
        dinic.add_edge(src, left[i], 1);
    }
    for (const auto i : rep(0, R)) {
        dinic.add_edge(right[i], dst, 1);
    }
    for (const auto i : rep(0, M)) {
        usize a, b;
        std::cin >> a >> b;
        ptr[i] = dinic.add_edge(left[a], right[b], 1);
    }
    std::cout << dinic.flow(src, dst) << '\n';
    for (const auto i : rep(0, M)) {
        if (ptr[i].flow() == 1) {
            std::cout << left.to_idx(ptr[i].src()) << ' ' << right.to_idx(ptr[i].dst()) << '\n';
        }
    }
    return 0;
}