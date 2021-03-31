#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include "../utility/int_alias.cpp"
#include "../container/dual_segment_tree.cpp"
#include <iostream>
#include <optional>

struct Effector {
    static Effector one() {
        return Effector { std::nullopt };
    }
    std::optional<u32> val;
    Effector operator * (const Effector& other) const {
        if (!other.val) return *this;
        return other;
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    DualSegmentTree<Effector> seg(N);
    while (Q--) {
        usize t;
        std::cin >> t;
        if (t == 0) {
            usize l, r;
            std::cin >> l >> r;
            u32 x;
            std::cin >> x;
            seg.operate(l, r + 1, Effector { x });
        }
        else {
            usize p;
            std::cin >> p;
            const auto e = seg.get(p);
            if (!e.val) {
                std::cout << (1u << 31) - 1 << '\n';
            }
            else {
                std::cout << *e.val << '\n';
            }
        }
    }
    return 0;
}