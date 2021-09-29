#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/3086"
#include "../algorithm/larsch.cpp"
#include "../container/segment_tree.cpp"
#include "../traits/max_monoid.cpp"
#include "../utility/infty.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <iostream>
#include <vector>

int main() {
    usize N, L;
    std::cin >> N >> L;
    std::vector<i64> A(N);
    for (auto& x : A) {
        std::cin >> x;
    }
    SegmentTree<MaxMonoid<i64>> seg(A);
    std::vector<i64> dp(N + 1);
    const auto transit = [&](usize i, const usize j) {
        i += 1;
        if (j + L > i) return -INFTY<i64>;
        return dp[j] + seg.fold(j, i);
    };
    CompLARSCH<i64, std::greater<i64>> larsch(N, transit);
    for (const auto i : rep(0, N)) {
        larsch.add_column();
        dp[i + 1] = transit(i, larsch.get_argmin());
    }
    std::cout << dp[N] << '\n';
    return 0;
}