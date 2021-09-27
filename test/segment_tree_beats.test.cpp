#define PROBLEM "https://yukicoder.me/problems/no/880"
#include "../container/segment_tree_beats.cpp"
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

constexpr u32 MAX = 1000000000;

struct Info {
    u32 max, lcm;
    u64 sum;
    usize len;
    static Info all_same(const u32 x, const usize l) { return {x, x, x * l, l}; }
};

struct Operate {
    u32 assign, gcd;
};

struct Structure {
    struct Monoid {
        using Type = Info;
        static Info identity() { return {0, 1, 0, 0}; }
        static Info operation(const Info& l, const Info& r) {
            return {
                std::max(l.max, r.max),
                (u32)std::min<u64>(std::lcm<u64>(l.lcm, r.lcm), MAX + 1),
                l.sum + r.sum,
                l.len + r.len,
            };
        }
    };
    struct Effector {
        using Type = Operate;
        static Operate identity() { return {0, 0}; }
        static Operate operation(const Operate& l, const Operate& r) {
            if (r.assign) return r;
            if (l.assign) return {std::gcd(l.assign, r.gcd), 0};
            return {0, std::gcd(l.gcd, r.gcd)};
        }
    };
    static std::optional<Info> operation(const Info& m, const Operate& e) {
        if (m.len == 0) return m;
        if (e.assign) return Info::all_same(e.assign, m.len);
        if (e.gcd % m.lcm == 0) return m;
        if (m.len == 1) return Info::all_same(std::gcd(m.max, e.gcd), 1);
        return std::nullopt;
    }
};

int main() {
    usize N, Q;
    std::cin >> N >> Q;
    std::vector<Info> build;
    build.reserve(N);
    while (N--) {
        u32 x;
        std::cin >> x;
        build.push_back(Info::all_same(x, 1));
    }
    SegmentTreeBeats<Structure> seg(build);
    while (Q--) {
        usize t, l, r;
        std::cin >> t >> l >> r;
        l -= 1;
        if (t <= 2) {
            u32 x;
            std::cin >> x;
            if (t == 1) seg.operate(l, r, {x, 0});
            else seg.operate(l, r, {0, x});
        } else {
            const auto m = seg.fold(l, r);
            std::cout << (t == 3 ? m.max : m.sum) << '\n';
        }
    }
    return 0;
}