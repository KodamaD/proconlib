---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':question:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':x:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':question:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/880
    links:
    - https://yukicoder.me/problems/no/880
  bundledCode: "#line 1 \"test/segment_tree_beats.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/880\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\
    \n\nclass revrep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { --itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr revrep(const usize first, const usize last) noexcept\n        : first(last\
    \ - 1), last(std::min(first, last) - 1) {}\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 3 \"bit/ceil_log2.cpp\"\n\nconstexpr u64 ceil_log2(const u64 x) {\n\
    \    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 3\
    \ \"bit/bit_rzeros.cpp\"\n\nconstexpr u64 bit_rzeros(const u64 x) { return x ==\
    \ 0 ? 64 : __builtin_ctzll(x); }\n#line 7 \"container/segment_tree_beats.cpp\"\
    \n#include <vector>\n#include <cassert>\n#include <optional>\n\ntemplate <class\
    \ Monoid, class Effector, std::optional<Monoid> (*mapping) (Monoid, Effector)>\n\
    class SegmentTreeBeats {\n    using M = Monoid;\n    using E = Effector;\n   \
    \ usize internal_size, logn, seg_size;\n    std::vector<M> data;\n    std::vector<E>\
    \ lazy;\n\n    void fetch(const usize k) { data[k] = data[2 * k] + data[2 * k\
    \ + 1]; }\n    void apply(const usize k, const E& e) {\n        if (k >= seg_size)\
    \ {\n            data[k] = mapping(data[k], e).value();\n            return;\n\
    \        }\n        lazy[k] = lazy[k] * e;\n        const auto result = mapping(data[k],\
    \ e);\n        if (result.has_value()) {\n            data[k] = result.value();\n\
    \        }\n        else { \n            flush(k); \n            fetch(k); \n\
    \        }\n    }\n    void flush(const usize k) {\n        apply(2 * k, lazy[k]);\n\
    \        apply(2 * k + 1, lazy[k]);\n        lazy[k] = E::one();\n    }\n\n  \
    \  void push(const usize k) { for (const usize d: revrep(bit_rzeros(k) + 1, logn\
    \ + 1)) flush(k >> d); }\n    void pull(usize k) { for (k >>= bit_rzeros(k); k\
    \ > 1;) fetch(k >>= 1); }\n\npublic:\n    explicit SegmentTreeBeats(const usize\
    \ size = 0, const M& value = M::zero()):\n        SegmentTreeBeats(std::vector<M>(size,\
    \ value)) { }\n    explicit SegmentTreeBeats(const std::vector<M>& vec): internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        seg_size = 1 << logn;\n\
    \        data = std::vector<M>(2 * seg_size, M::zero());\n        lazy = std::vector<E>(seg_size,\
    \ E::one());\n        for (const usize i: rep(0, internal_size)) data[seg_size\
    \ + i] = vec[i];\n        for (const usize i: revrep(1, seg_size)) fetch(i);\n\
    \    }\n\n    usize size() const { return internal_size; }\n\n    void assign(usize\
    \ i, const M& value) {\n        assert(i < internal_size);\n        i += seg_size;\n\
    \        for (const usize d: revrep(1, logn + 1)) flush(i >> d);\n        data[i]\
    \ = value;\n        for (const usize d: rep(1, logn + 1)) fetch(i >> d);\n   \
    \ }\n    void operate(usize l, usize r, const E& e) {\n        assert(l <= r and\
    \ r <= internal_size);\n        l += seg_size; r += seg_size;\n        push(l);\
    \ push(r);\n        for (usize l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {\n\
    \            if (l0 & 1) apply(l0++, e);\n            if (r0 & 1) apply(--r0,\
    \ e);\n        }\n        pull(l); pull(r);\n    }\n    \n    M fold() const {\
    \ return data[1]; }\n    M fold(usize l, usize r) {\n        assert(l <= r and\
    \ r <= internal_size);\n        l += seg_size; r += seg_size;\n        push(l);\
    \ push(r);\n        M ret_l = M::zero(), ret_r = M::zero();\n        while (l\
    \ < r) {\n            if (l & 1) ret_l = ret_l + data[l++];\n            if (r\
    \ & 1) ret_r = data[--r] + ret_r;\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return ret_l + ret_r;\n    }\n\n    template <class F>\n \
    \   usize max_right(usize l, const F& f) {\n        assert(l <= internal_size);\n\
    \        assert(f(M::zero()));\n        if (l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        for (const usize d: revrep(1, logn + 1)) flush(l\
    \ >> d);\n        M sum = M::zero();\n        do {\n            while (!(l & 1))\
    \ l >>= 1;\n            if (!f(sum + data[l])) {\n                while (l < seg_size)\
    \ {\n                    flush(l);\n                    l = 2 * l;\n         \
    \           if (f(sum + data[l])) sum = sum + data[l++];\n                }\n\
    \                return l - seg_size;\n            }\n            sum = sum +\
    \ data[l++];\n        } while ((l & -l) != l);\n        return internal_size;\n\
    \    }\n\n    template <class F>\n    usize min_left(usize r, const F& f) {\n\
    \        assert(r <= internal_size);\n        assert(f(M::zero()));\n        if\
    \ (r == 0) return 0;\n        r += seg_size;\n        for (const usize d: revrep(1,\
    \ logn + 1)) flush((r - 1) >> d);\n        M sum = M::zero();\n        do {\n\
    \            r -= 1;\n            while (r > 1 and (r & 1)) r >>= 1;\n       \
    \     if (!f(data[r] + sum)) {\n                while (r < seg_size) {\n     \
    \               flush(r);\n                    r = 2 * r + 1;\n              \
    \      if (f(data[r] + sum)) sum = data[r--] + sum;\n                }\n     \
    \           return r + 1 - seg_size;\n            }\n            sum = data[r]\
    \ + sum;\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n#line\
    \ 5 \"test/segment_tree_beats.test.cpp\"\n#include <iostream>\n#include <numeric>\n\
    #line 9 \"test/segment_tree_beats.test.cpp\"\n\nconstexpr u32 MAX = 1000000000;\n\
    \nstruct Monoid {\n    static constexpr Monoid zero() {\n        return Monoid\
    \ { 0, 1, 0, 0 };\n    }\n    static constexpr Monoid all_same(const u32 x, const\
    \ usize l) {\n        return Monoid { x, x, (u64) x * l, l };\n    };\n    u32\
    \ max, lcm;\n    u64 sum;\n    usize len;\n    constexpr Monoid operator + (const\
    \ Monoid& other) const {\n        return Monoid {\n            std::max(max, other.max),\n\
    \            (u32) std::min<u64>(std::lcm<u64>(lcm, other.lcm), MAX + 1),\n  \
    \          sum + other.sum,\n            len + other.len,\n        };\n    }\n\
    };\n\nstruct Effector {\n    static constexpr Effector one() {\n        return\
    \ Effector { 0, 0 };\n    }\n    u32 assign, gcd;\n    constexpr Effector operator\
    \ * (const Effector& other) const {\n        if (other.assign) {\n           \
    \ return other;\n        }\n        if (assign) {\n            return Effector\
    \ { std::gcd(assign, other.gcd), 0 };\n        }\n        else {\n           \
    \ return Effector { 0, std::gcd(gcd, other.gcd) };\n        }\n    }    \n};\n\
    \nstd::optional<Monoid> mapping(Monoid m, Effector e) {\n    if (m.len == 0) return\
    \ m;\n    if (e.assign) return Monoid::all_same(e.assign, m.len);\n    if (e.gcd\
    \ % m.lcm == 0) return m;\n    if (m.len == 1) return Monoid::all_same(std::gcd(m.max,\
    \ e.gcd), 1);\n    return std::nullopt;\n}\n\nint main() {\n    usize N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<Monoid> build;\n    build.reserve(N);\n\
    \    while (N--) {\n        u32 x;\n        std::cin >> x;\n        build.push_back(Monoid::all_same(x,\
    \ 1));\n    }\n    SegmentTreeBeats<Monoid, Effector, mapping> seg(build);\n \
    \   while (Q--) {\n        usize t, l, r;\n        std::cin >> t >> l >> r;\n\
    \        l -= 1;\n        if (t <= 2) {\n            u32 x;\n            std::cin\
    \ >> x;\n            seg.operate(l, r, (t == 1 ? Effector { x, 0 } : Effector\
    \ { 0, x }));\n        }\n        else {\n            const auto m = seg.fold(l,\
    \ r);\n            std::cout << (t == 3 ? m.max : m.sum) << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/880\"\n#include \"../container/segment_tree_beats.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ <iostream>\n#include <numeric>\n#include <optional>\n#include <vector>\n\nconstexpr\
    \ u32 MAX = 1000000000;\n\nstruct Monoid {\n    static constexpr Monoid zero()\
    \ {\n        return Monoid { 0, 1, 0, 0 };\n    }\n    static constexpr Monoid\
    \ all_same(const u32 x, const usize l) {\n        return Monoid { x, x, (u64)\
    \ x * l, l };\n    };\n    u32 max, lcm;\n    u64 sum;\n    usize len;\n    constexpr\
    \ Monoid operator + (const Monoid& other) const {\n        return Monoid {\n \
    \           std::max(max, other.max),\n            (u32) std::min<u64>(std::lcm<u64>(lcm,\
    \ other.lcm), MAX + 1),\n            sum + other.sum,\n            len + other.len,\n\
    \        };\n    }\n};\n\nstruct Effector {\n    static constexpr Effector one()\
    \ {\n        return Effector { 0, 0 };\n    }\n    u32 assign, gcd;\n    constexpr\
    \ Effector operator * (const Effector& other) const {\n        if (other.assign)\
    \ {\n            return other;\n        }\n        if (assign) {\n           \
    \ return Effector { std::gcd(assign, other.gcd), 0 };\n        }\n        else\
    \ {\n            return Effector { 0, std::gcd(gcd, other.gcd) };\n        }\n\
    \    }    \n};\n\nstd::optional<Monoid> mapping(Monoid m, Effector e) {\n    if\
    \ (m.len == 0) return m;\n    if (e.assign) return Monoid::all_same(e.assign,\
    \ m.len);\n    if (e.gcd % m.lcm == 0) return m;\n    if (m.len == 1) return Monoid::all_same(std::gcd(m.max,\
    \ e.gcd), 1);\n    return std::nullopt;\n}\n\nint main() {\n    usize N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<Monoid> build;\n    build.reserve(N);\n\
    \    while (N--) {\n        u32 x;\n        std::cin >> x;\n        build.push_back(Monoid::all_same(x,\
    \ 1));\n    }\n    SegmentTreeBeats<Monoid, Effector, mapping> seg(build);\n \
    \   while (Q--) {\n        usize t, l, r;\n        std::cin >> t >> l >> r;\n\
    \        l -= 1;\n        if (t <= 2) {\n            u32 x;\n            std::cin\
    \ >> x;\n            seg.operate(l, r, (t == 1 ? Effector { x, 0 } : Effector\
    \ { 0, x }));\n        }\n        else {\n            const auto m = seg.fold(l,\
    \ r);\n            std::cout << (t == 3 ? m.max : m.sum) << '\\n';\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - container/segment_tree_beats.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - bit/ceil_log2.cpp
  - bit/bit_rzeros.cpp
  isVerificationFile: true
  path: test/segment_tree_beats.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment_tree_beats.test.cpp
layout: document
redirect_from:
- /verify/test/segment_tree_beats.test.cpp
- /verify/test/segment_tree_beats.test.cpp.html
title: test/segment_tree_beats.test.cpp
---
