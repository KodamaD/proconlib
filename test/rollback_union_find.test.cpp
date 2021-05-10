#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/rec_lambda.cpp"
#include "../graph/rollback_union_find.cpp"
#include <iostream>

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<usize, usize>> connect(Q + 1);
    std::vector<std::vector<usize>> graph(Q + 1);
    std::vector<std::vector<std::tuple<usize, usize, usize>>> query(Q + 1);
    std::vector<bool> ans(Q + 1);
    std::vector<usize> output;
    output.reserve(Q);
    for (const auto i: rep(1, Q + 1)) {
        isize t, k;
        usize u, v;
        std::cin >> t >> k >> u >> v;
        k += 1;
        if (t == 0) {
            connect[i] = {u, v};
            graph[k].push_back(i);
        }
        else {
            output.push_back(i);
            query[k].emplace_back(i, u, v);
        }
    }
    RollbackUnionFind dsu(N);
    std::vector<bool> done(Q);
    rec_lambda([&](auto&& dfs, const usize u) -> void {
        const auto f = dsu.merge(connect[u].first, connect[u].second).second;
        for (const auto [i, x, y]: query[u]) {
            ans[i] = dsu.same(x, y);
        }
        for (const auto v: graph[u]) {
            dfs(v);
        }
        dsu.rollback(f);
        done[u] = true;
    })(0);
    for (const auto i: output) {
        std::cout << ans[i] << '\n';
    }
}