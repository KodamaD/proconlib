#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include "../container/dual_segment_tree.cpp"
#include <iostream>
#include <optional>
#include "../utility/int_alias.cpp"
#include "../traits/assign_monoid.cpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    DualSegmentTree<AssignMonoid<u32>> seg(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            std::cin >> l >> r;
            u32 x;
            std::cin >> x;
            seg.operate(l, r + 1, x);
        } else {
            int p;
            std::cin >> p;
            const auto e = seg.get(p);
            if (!e) {
                std::cout << (1u << 31) - 1 << '\n';
            } else {
                std::cout << *e << '\n';
            }
        }
    }
    return 0;
}