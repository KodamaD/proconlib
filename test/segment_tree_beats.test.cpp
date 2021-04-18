#define PROBLEM "https://yukicoder.me/problems/no/880"
#include "../container/segment_tree_beats.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>

constexpr u32 MAX = 1000000000;

struct Monoid {
    static constexpr Monoid zero() {
        return Monoid { 0, 1, 0, 0 };
    }
    static constexpr Monoid all_same(const u32 x, const usize l) {
        return Monoid { x, x, (u64) x * l, l };
    };
    u32 max, lcm;
    u64 sum;
    usize len;
    constexpr Monoid operator + (const Monoid& other) const {
        return Monoid {
            std::max(max, other.max),
            (u32) std::min<u64>(std::lcm<u64>(lcm, other.lcm), MAX + 1),
            sum + other.sum,
            len + other.len,
        };
    }
};

struct Effector {
    static constexpr Effector one() {
        return Effector { 0, 0 };
    }
    u32 assign, gcd;
    constexpr Effector operator * (const Effector& other) const {
        if (other.assign) {
            return other;
        }
        if (assign) {
            return Effector { std::gcd(assign, other.gcd), 0 };
        }
        else {
            return Effector { 0, std::gcd(gcd, other.gcd) };
        }
    }    
};

std::optional<Monoid> mapping(Monoid m, Effector e) {
    if (m.len == 0) return m;
    if (e.assign) return Monoid::all_same(e.assign, m.len);
    if (e.gcd % m.lcm == 0) return m;
    if (m.len == 1) return Monoid::all_same(std::gcd(m.max, e.gcd), 1);
    return std::nullopt;
}

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Monoid> build;
    build.reserve(N);
    while (N--) {
        u32 x;
        std::cin >> x;
        build.push_back(Monoid::all_same(x, 1));
    }
    SegmentTreeBeats<Monoid, Effector, mapping> seg(build);
    while (Q--) {
        usize t, l, r;
        std::cin >> t >> l >> r;
        l -= 1;
        if (t <= 2) {
            u32 x;
            std::cin >> x;
            seg.operate(l, r, (t == 1 ? Effector { x, 0 } : Effector { 0, x }));
        }
        else {
            const auto m = seg.fold(l, r);
            std::cout << (t == 3 ? m.max : m.sum) << '\n';
        }
    }
    return 0;
}