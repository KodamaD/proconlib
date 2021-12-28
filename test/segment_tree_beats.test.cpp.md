---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countr_zero.cpp
    title: utility/countr_zero.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/880
    links:
    - https://yukicoder.me/problems/no/880
  bundledCode: "#line 1 \"test/segment_tree_beats.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/880\"\
    \n#line 2 \"container/segment_tree_beats.cpp\"\n#include <cassert>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n#line 3 \"utility/ceil_log2.cpp\"\n\nconstexpr int ceil_log2(const\
    \ u64 x) {\n    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n\
    }\n#line 3 \"utility/countr_zero.cpp\"\n\nconstexpr int countr_zero(const u64\
    \ x) { return x == 0 ? 64 : __builtin_ctzll(x); }\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\n\nclass ReversedRange\
    \ {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int pos)\
    \ noexcept : itr(pos) {}\n        constexpr void operator++() noexcept { --itr;\
    \ }\n        constexpr bool operator!=(const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr int operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ ReversedRange(const int first, const int last) noexcept\n        : first(last\
    \ - 1), last(std::min(first, last) - 1) {}\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n\nconstexpr ReversedRange revrep(const int l, const int r) noexcept { return\
    \ ReversedRange(l, r); }\nconstexpr ReversedRange revrep(const int n) noexcept\
    \ { return ReversedRange(0, n); }\n#line 10 \"container/segment_tree_beats.cpp\"\
    \n\ntemplate <class A> class SegmentTreeBeats {\n    using M = typename A::Monoid;\n\
    \    using E = typename A::Effector;\n    using T = typename M::Type;\n    using\
    \ U = typename E::Type;\n    int internal_size, logn, seg_size;\n    std::vector<T>\
    \ data;\n    std::vector<U> lazy;\n\n    void fetch(const int k) { data[k] = M::operation(data[2\
    \ * k], data[2 * k + 1]); }\n    void apply(const int k, const U& e) {\n     \
    \   if (k >= seg_size) {\n            data[k] = A::operation(data[k], e).value();\n\
    \            return;\n        }\n        lazy[k] = E::operation(lazy[k], e);\n\
    \        std::optional<T> result = A::operation(data[k], e);\n        if (result)\
    \ {\n            data[k] = std::move(*result);\n        } else {\n           \
    \ flush(k);\n            fetch(k);\n        }\n    }\n    void flush(const int\
    \ k) {\n        apply(2 * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n \
    \       lazy[k] = E::identity();\n    }\n\n    void push(const int k) {\n    \
    \    for (const int d : revrep(countr_zero(k) + 1, logn + 1)) flush(k >> d);\n\
    \    }\n    void pull(int k) {\n        for (k >>= countr_zero(k); k > 1;) fetch(k\
    \ >>= 1);\n    }\n\n  public:\n    explicit SegmentTreeBeats(const int size =\
    \ 0, const T& value = M::identity())\n        : SegmentTreeBeats(std::vector<T>(size,\
    \ value)) {}\n    explicit SegmentTreeBeats(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        seg_size = 1 << logn;\n\
    \        data = std::vector<T>(2 * seg_size, M::identity());\n        lazy = std::vector<U>(seg_size,\
    \ E::identity());\n        for (const int i : rep(internal_size)) data[seg_size\
    \ + i] = vec[i];\n        for (const int i : revrep(1, seg_size)) fetch(i);\n\
    \    }\n\n    int size() const { return internal_size; }\n\n    void assign(int\
    \ i, const T& value) {\n        assert(0 <= i and i < internal_size);\n      \
    \  i += seg_size;\n        for (const int d : revrep(1, logn + 1)) flush(i >>\
    \ d);\n        data[i] = value;\n        for (const int d : rep(1, logn + 1))\
    \ fetch(i >> d);\n    }\n    void operate(int l, int r, const U& e) {\n      \
    \  assert(0 <= l and l <= r and r <= internal_size);\n        l += seg_size;\n\
    \        r += seg_size;\n        push(l);\n        push(r);\n        for (int\
    \ l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {\n            if (l0 & 1) apply(l0++,\
    \ e);\n            if (r0 & 1) apply(--r0, e);\n        }\n        pull(l);\n\
    \        pull(r);\n    }\n\n    T fold() const { return data[1]; }\n    T fold(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= internal_size);\n   \
    \     l += seg_size;\n        r += seg_size;\n        push(l);\n        push(r);\n\
    \        T ret_l = M::identity(), ret_r = M::identity();\n        while (l < r)\
    \ {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n        \
    \    if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return M::operation(ret_l, ret_r);\n\
    \    }\n\n    template <class F> int max_right(int l, const F& f) {\n        assert(0\
    \ <= l and l <= internal_size);\n        assert(f(M::identity()));\n        if\
    \ (l == internal_size) return internal_size;\n        l += seg_size;\n       \
    \ for (const int d : revrep(1, logn + 1)) flush(l >> d);\n        T sum = M::identity();\n\
    \        do {\n            while (!(l & 1)) l >>= 1;\n            if (!f(M::operation(sum,\
    \ data[l]))) {\n                while (l < seg_size) {\n                    flush(l);\n\
    \                    l = 2 * l;\n                    if (f(M::operation(sum, data[l])))\
    \ sum = M::operation(sum, data[l++]);\n                }\n                return\
    \ l - seg_size;\n            }\n            sum = M::operation(sum, data[l++]);\n\
    \        } while ((l & -l) != l);\n        return internal_size;\n    }\n\n  \
    \  template <class F> int min_left(int r, const F& f) {\n        assert(0 <= r\
    \ and r <= internal_size);\n        assert(f(M::identity()));\n        if (r ==\
    \ 0) return 0;\n        r += seg_size;\n        for (const int d : revrep(1, logn\
    \ + 1)) flush((r - 1) >> d);\n        T sum = M::identity();\n        do {\n \
    \           r -= 1;\n            while (r > 1 and (r & 1)) r >>= 1;\n        \
    \    if (!f(M::operation(data[r], sum))) {\n                while (r < seg_size)\
    \ {\n                    flush(r);\n                    r = 2 * r + 1;\n     \
    \               if (f(M::operation(data[r], sum))) sum = M::operation(data[r--],\
    \ sum);\n                }\n                return r + 1 - seg_size;\n       \
    \     }\n            sum = M::operation(data[r], sum);\n        } while ((r &\
    \ -r) != r);\n        return 0;\n    }\n};\n#line 3 \"test/segment_tree_beats.test.cpp\"\
    \n#include <iostream>\n#include <numeric>\n#line 9 \"test/segment_tree_beats.test.cpp\"\
    \n\nconstexpr u32 MAX = 1000000000;\n\nstruct Info {\n    u32 max, lcm;\n    u64\
    \ sum;\n    int len;\n    static Info all_same(const u32 x, const int l) { return\
    \ {x, x, (u64)x * l, l}; }\n};\n\nstruct Operate {\n    u32 assign, gcd;\n};\n\
    \nstruct Structure {\n    struct Monoid {\n        using Type = Info;\n      \
    \  static Info identity() { return {0, 1, 0, 0}; }\n        static Info operation(const\
    \ Info& l, const Info& r) {\n            return {\n                std::max(l.max,\
    \ r.max),\n                (u32)std::min<u64>(std::lcm<u64>(l.lcm, r.lcm), MAX\
    \ + 1),\n                l.sum + r.sum,\n                l.len + r.len,\n    \
    \        };\n        }\n    };\n    struct Effector {\n        using Type = Operate;\n\
    \        static Operate identity() { return {0, 0}; }\n        static Operate\
    \ operation(const Operate& l, const Operate& r) {\n            if (r.assign) return\
    \ r;\n            if (l.assign) return {std::gcd(l.assign, r.gcd), 0};\n     \
    \       return {0, std::gcd(l.gcd, r.gcd)};\n        }\n    };\n    static std::optional<Info>\
    \ operation(const Info& m, const Operate& e) {\n        if (m.len == 0) return\
    \ m;\n        if (e.assign) return Info::all_same(e.assign, m.len);\n        if\
    \ (e.gcd % m.lcm == 0) return m;\n        if (m.len == 1) return Info::all_same(std::gcd(m.max,\
    \ e.gcd), 1);\n        return std::nullopt;\n    }\n};\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    std::vector<Info> build;\n    build.reserve(N);\n\
    \    while (N--) {\n        u32 x;\n        std::cin >> x;\n        build.push_back(Info::all_same(x,\
    \ 1));\n    }\n    SegmentTreeBeats<Structure> seg(build);\n    while (Q--) {\n\
    \        int t, l, r;\n        std::cin >> t >> l >> r;\n        l -= 1;\n   \
    \     if (t <= 2) {\n            u32 x;\n            std::cin >> x;\n        \
    \    if (t == 1) seg.operate(l, r, {x, 0});\n            else seg.operate(l, r,\
    \ {0, x});\n        } else {\n            const auto m = seg.fold(l, r);\n   \
    \         std::cout << (t == 3 ? m.max : m.sum) << '\\n';\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/880\"\n#include \"../container/segment_tree_beats.cpp\"\
    \n#include <iostream>\n#include <numeric>\n#include <optional>\n#include <vector>\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\nconstexpr\
    \ u32 MAX = 1000000000;\n\nstruct Info {\n    u32 max, lcm;\n    u64 sum;\n  \
    \  int len;\n    static Info all_same(const u32 x, const int l) { return {x, x,\
    \ (u64)x * l, l}; }\n};\n\nstruct Operate {\n    u32 assign, gcd;\n};\n\nstruct\
    \ Structure {\n    struct Monoid {\n        using Type = Info;\n        static\
    \ Info identity() { return {0, 1, 0, 0}; }\n        static Info operation(const\
    \ Info& l, const Info& r) {\n            return {\n                std::max(l.max,\
    \ r.max),\n                (u32)std::min<u64>(std::lcm<u64>(l.lcm, r.lcm), MAX\
    \ + 1),\n                l.sum + r.sum,\n                l.len + r.len,\n    \
    \        };\n        }\n    };\n    struct Effector {\n        using Type = Operate;\n\
    \        static Operate identity() { return {0, 0}; }\n        static Operate\
    \ operation(const Operate& l, const Operate& r) {\n            if (r.assign) return\
    \ r;\n            if (l.assign) return {std::gcd(l.assign, r.gcd), 0};\n     \
    \       return {0, std::gcd(l.gcd, r.gcd)};\n        }\n    };\n    static std::optional<Info>\
    \ operation(const Info& m, const Operate& e) {\n        if (m.len == 0) return\
    \ m;\n        if (e.assign) return Info::all_same(e.assign, m.len);\n        if\
    \ (e.gcd % m.lcm == 0) return m;\n        if (m.len == 1) return Info::all_same(std::gcd(m.max,\
    \ e.gcd), 1);\n        return std::nullopt;\n    }\n};\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    std::vector<Info> build;\n    build.reserve(N);\n\
    \    while (N--) {\n        u32 x;\n        std::cin >> x;\n        build.push_back(Info::all_same(x,\
    \ 1));\n    }\n    SegmentTreeBeats<Structure> seg(build);\n    while (Q--) {\n\
    \        int t, l, r;\n        std::cin >> t >> l >> r;\n        l -= 1;\n   \
    \     if (t <= 2) {\n            u32 x;\n            std::cin >> x;\n        \
    \    if (t == 1) seg.operate(l, r, {x, 0});\n            else seg.operate(l, r,\
    \ {0, x});\n        } else {\n            const auto m = seg.fold(l, r);\n   \
    \         std::cout << (t == 3 ? m.max : m.sum) << '\\n';\n        }\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - container/segment_tree_beats.cpp
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/countr_zero.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: true
  path: test/segment_tree_beats.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment_tree_beats.test.cpp
layout: document
redirect_from:
- /verify/test/segment_tree_beats.test.cpp
- /verify/test/segment_tree_beats.test.cpp.html
title: test/segment_tree_beats.test.cpp
---
