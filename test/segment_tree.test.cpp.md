---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: traits/affine_composite_monoid.cpp
    title: traits/affine_composite_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/segment_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"math/rem_euclid.cpp\"\n#include <cassert>\n\ntemplate <class T> constexpr\
    \ T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n    return (value\
    \ %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/totient.cpp\"\n\ntemplate\
    \ <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T i = 2; i *\
    \ i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n         \
    \   ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n    }\n\
    \    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n    return\
    \ ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32 MOD, std::enable_if_t<((u32)1\
    \ <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class StaticModint {\n    using\
    \ Self = StaticModint;\n\n    static inline constexpr u32 PHI = totient(MOD);\n\
    \    u32 v;\n\n  public:\n    static constexpr u32 mod() noexcept { return MOD;\
    \ }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\n\
    \    static constexpr T normalize(const T& x) noexcept {\n        return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, MOD);\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n \
    \   template <class T> constexpr StaticModint(const T& x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Self raw(const T& x) noexcept {\n\
    \        Self ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 val() const noexcept { return v; }\n    constexpr Self neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Self inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Self pow(u64 exp) const noexcept {\n\
    \        Self ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Self operator-() const noexcept { return\
    \ neg(); }\n    constexpr Self operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Self operator+(const Self& rhs) const noexcept { return Self(*this)\
    \ += rhs; }\n    constexpr Self& operator+=(const Self& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator-(const Self& rhs) const noexcept { return Self(*this) -= rhs;\
    \ }\n    constexpr Self& operator-=(const Self& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Self operator*(const Self& rhs) const noexcept { return Self(*this)\
    \ *= rhs; }\n    constexpr Self& operator*=(const Self& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs;\
    \ }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 3 \"container/segment_tree.cpp\"\n#include <vector>\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\n__attribute__((target(\"avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n\
    \    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 2\
    \ \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass\
    \ rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const usize\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n    struct Iter {\n    \
    \    usize itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos) {}\n\
    \        constexpr void operator++() noexcept { --itr; }\n        constexpr bool\
    \ operator!=(const Iter& other) const noexcept { return itr != other.itr; }\n\
    \        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr revrep(const\
    \ usize first, const usize last) noexcept\n        : first(last - 1), last(std::min(first,\
    \ last) - 1) {}\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n#line 8 \"container/segment_tree.cpp\"\
    \n\ntemplate <class M> class SegmentTree {\n    using T = typename M::Type;\n\
    \    usize internal_size, seg_size;\n    std::vector<T> data;\n\n    void fetch(const\
    \ usize k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]); }\n\n  public:\n\
    \    explicit SegmentTree(const usize size = 0, const T& value = M::identity())\n\
    \        : SegmentTree(std::vector<T>(size, value)) {}\n    explicit SegmentTree(const\
    \ std::vector<T>& vec) : internal_size(vec.size()) {\n        seg_size = 1 <<\
    \ ceil_log2(internal_size);\n        data = std::vector<T>(2 * seg_size, M::identity());\n\
    \        for (const usize i : rep(0, internal_size)) data[seg_size + i] = vec[i];\n\
    \        for (const usize i : revrep(1, seg_size)) fetch(i);\n    }\n\n    usize\
    \ size() const { return internal_size; }\n\n    void assign(usize i, const T&\
    \ value) {\n        assert(i < internal_size);\n        i += seg_size;\n     \
    \   data[i] = value;\n        while (i > 1) {\n            i >>= 1;\n        \
    \    fetch(i);\n        }\n    }\n\n    T fold() const { return data[1]; }\n \
    \   T fold(usize l, usize r) const {\n        assert(l <= r and r <= internal_size);\n\
    \        l += seg_size;\n        r += seg_size;\n        T ret_l = M::identity(),\
    \ ret_r = M::identity();\n        while (l < r) {\n            if (l & 1) ret_l\
    \ = M::operation(ret_l, data[l++]);\n            if (r & 1) ret_r = M::operation(data[--r],\
    \ ret_r);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::operation(ret_l, ret_r);\n    }\n\n    template <class F> usize max_right(usize\
    \ l, const F& f) const {\n        assert(l <= internal_size);\n        assert(f(M::identity()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        T sum = M::identity();\n        do {\n            while (!(l & 1)) l\
    \ >>= 1;\n            if (!f(M::operation(sum, data[l]))) {\n                while\
    \ (l < seg_size) {\n                    l = 2 * l;\n                    if (f(M::operation(sum,\
    \ data[l]))) sum = M::operation(sum, data[l++]);\n                }\n        \
    \        return l - seg_size;\n            }\n            sum = M::operation(sum,\
    \ data[l++]);\n        } while ((l & -l) != l);\n        return internal_size;\n\
    \    }\n\n    template <class F> usize min_left(usize r, const F& f) const {\n\
    \        assert(r <= internal_size);\n        assert(f(M::identity()));\n    \
    \    if (r == 0) return 0;\n        r += seg_size;\n        T sum = M::identity();\n\
    \        do {\n            r -= 1;\n            while (r > 1 and (r & 1)) r >>=\
    \ 1;\n            if (!f(M::operation(data[r], sum))) {\n                while\
    \ (r < seg_size) {\n                    r = 2 * r + 1;\n                    if\
    \ (f(M::operation(data[r], sum))) sum = M::operation(data[r--], sum);\n      \
    \          }\n                return r + 1 - seg_size;\n            }\n      \
    \      sum = M::operation(data[r], sum);\n        } while ((r & -r) != r);\n \
    \       return 0;\n    }\n};\n#line 2 \"traits/affine_composite_monoid.cpp\"\n\
    \ntemplate <class T> struct Affine {\n    T a, b;\n    constexpr Affine(const\
    \ T& a = 1, const T& b = 0) : a(a), b(b) {}\n    constexpr T eval(const T& x)\
    \ const { return a * x + b; }\n    constexpr Affine operator+(const Affine& other)\
    \ const { return affine(a + other.a, b + other.b); }\n    constexpr Affine composite(const\
    \ Affine& other) const { return Affine(a * other.a, b * other.a + other.b); }\n\
    };\n\ntemplate <class T> struct AffineCompositeMonoid {\n    using Type = Affine<T>;\n\
    \    static constexpr Type identity() { return Type(); }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) noexcept { return l.composite(r);\
    \ }\n};\n#line 7 \"test/segment_tree.test.cpp\"\n#include <iostream>\n\nusing\
    \ Fp = StaticModint<998244353>;\n\nint main() {\n    usize N, Q;\n    std::cin\
    \ >> N >> Q;\n    std::vector<Affine<Fp>> initial(N);\n    for (const usize i:\
    \ rep(0, N)) {\n        u32 a, b;\n        std::cin >> a >> b;\n        initial[i]\
    \ = {a, b};\n    }\n    SegmentTree<AffineCompositeMonoid<Fp>> seg(initial);\n\
    \    while (Q--) {\n        usize t;\n        std::cin >> t;\n        if (t ==\
    \ 0) {\n            usize p;\n            std::cin >> p;\n            u32 c, d;\n\
    \            std::cin >> c >> d;\n            seg.assign(p, {Fp(c), Fp(d)});\n\
    \        }\n        else {\n            usize l, r;\n            std::cin >> l\
    \ >> r;\n            u32 x;\n            std::cin >> x;\n            std::cout\
    \ << seg.fold(l, r).eval(Fp(x)) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../math/static_modint.cpp\"\n#include \"../container/segment_tree.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../traits/affine_composite_monoid.cpp\"\n#include <iostream>\n\nusing Fp =\
    \ StaticModint<998244353>;\n\nint main() {\n    usize N, Q;\n    std::cin >> N\
    \ >> Q;\n    std::vector<Affine<Fp>> initial(N);\n    for (const usize i: rep(0,\
    \ N)) {\n        u32 a, b;\n        std::cin >> a >> b;\n        initial[i] =\
    \ {a, b};\n    }\n    SegmentTree<AffineCompositeMonoid<Fp>> seg(initial);\n \
    \   while (Q--) {\n        usize t;\n        std::cin >> t;\n        if (t ==\
    \ 0) {\n            usize p;\n            std::cin >> p;\n            u32 c, d;\n\
    \            std::cin >> c >> d;\n            seg.assign(p, {Fp(c), Fp(d)});\n\
    \        }\n        else {\n            usize l, r;\n            std::cin >> l\
    \ >> r;\n            u32 x;\n            std::cin >> x;\n            std::cout\
    \ << seg.fold(l, r).eval(Fp(x)) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - math/static_modint.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - container/segment_tree.cpp
  - bit/ceil_log2.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - traits/affine_composite_monoid.cpp
  isVerificationFile: true
  path: test/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/segment_tree.test.cpp
- /verify/test/segment_tree.test.cpp.html
title: test/segment_tree.test.cpp
---
