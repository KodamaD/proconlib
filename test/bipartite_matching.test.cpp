#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../utility/rep.cpp"
#include "../graph/dinic.cpp"
#include <iostream>
#include <vector>

int main() {
    int L, R, M;
    std::cin >> L >> R >> M;
    Dinic<int> dinic;
    const auto src = dinic.add_vertex();
    const auto dst = dinic.add_vertex();
    const auto left = dinic.add_vertices(L);
    const auto right = dinic.add_vertices(R);
    std::vector<int> eidx(M);
    for (const auto i : rep(0, L)) {
        dinic.add_edge(src, left[i], 1);
    }
    for (const auto i : rep(0, R)) {
        dinic.add_edge(right[i], dst, 1);
    }
    for (const auto i : rep(0, M)) {
        int a, b;
        std::cin >> a >> b;
        eidx[i] = dinic.add_edge(left[a], right[b], 1);
    }
    std::cout << dinic.flow(src, dst) << '\n';
    for (const auto i : rep(0, M)) {
        const auto& [src, dst, flow, _] = dinic.get_edge(eidx[i]);
        if (flow == 1) {
            std::cout << left.to_idx(src) << ' ' << right.to_idx(dst) << '\n';
        }
    }
    return 0;
}