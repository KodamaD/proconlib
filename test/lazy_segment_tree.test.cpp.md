---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
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
    path: traits/pair_monoid.cpp
    title: traits/pair_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_affine_action.cpp
    title: traits/sum_affine_action.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countr_zero.cpp
    title: utility/countr_zero.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/lazy_segment_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#line 2 \"container/lazy_segment_tree.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define TARGET_AVX2\
    \ __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n#endif\n#line\
    \ 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n#line 5 \"utility/ceil_log2.cpp\"\n\nTARGET_AVX2 constexpr int ceil_log2(const\
    \ u64 x) {\n#ifdef __GNUC__\n    return x == 0 ? 0 : bit_width(x - 1);\n#else\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n#endif\n}\n\
    #line 2 \"utility/countr_zero.cpp\"\n#include <array>\n#line 5 \"utility/countr_zero.cpp\"\
    \n\nconstexpr int countr_zero(u64 x) {\n    if (x == 0) return 64;\n#ifdef __GNUC__\n\
    \    return __builtin_ctzll(x);\n#else\n    constexpr std::array<int, 64> table\
    \ = {0,  1,  2,  7,  3,  13, 8,  27, 4,  33, 14, 36, 9,  49, 28, 19,\n       \
    \                                      5,  25, 34, 17, 15, 53, 37, 55, 10, 46,\
    \ 50, 39, 29, 42, 20, 57,\n                                             63, 6,\
    \  12, 26, 32, 35, 48, 18, 24, 16, 52, 54, 45, 38, 41, 56,\n                 \
    \                            62, 11, 31, 47, 23, 51, 44, 40, 61, 30, 22, 43, 60,\
    \ 21, 59, 58};\n    return table[(x & (~x + 1)) * 0x218A7A392DD9ABF >> 58 & 0x3F];\n\
    #endif\n}\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n\
    \    struct Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr int operator*() const noexcept { return itr;\
    \ }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\
    \n\nclass ReversedRange {\n    struct Iter {\n        int itr;\n        constexpr\
    \ Iter(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const Iter& other) const\
    \ noexcept { return itr != other.itr; }\n        constexpr int operator*() const\
    \ noexcept { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n\
    \    explicit constexpr ReversedRange(const int first, const int last) noexcept\n\
    \        : first(last - 1), last(std::min(first, last) - 1) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr ReversedRange revrep(const int l,\
    \ const int r) noexcept { return ReversedRange(l, r); }\nconstexpr ReversedRange\
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 8 \"container/lazy_segment_tree.cpp\"\
    \n\ntemplate <class A> class LazySegmentTree {\n    using M = typename A::Monoid;\n\
    \    using E = typename A::Effector;\n    using T = typename M::Type;\n    using\
    \ U = typename E::Type;\n    int internal_size, logn, seg_size;\n    std::vector<T>\
    \ data;\n    std::vector<U> lazy;\n\n    void fetch(const int k) { data[k] = M::operation(data[2\
    \ * k], data[2 * k + 1]); }\n    void apply(const int k, const U& e) {\n     \
    \   data[k] = A::operation(data[k], e);\n        if (k < seg_size) lazy[k] = E::operation(lazy[k],\
    \ e);\n    }\n    void flush(const int k) {\n        apply(2 * k, lazy[k]);\n\
    \        apply(2 * k + 1, lazy[k]);\n        lazy[k] = E::identity();\n    }\n\
    \n    void push(const int k) {\n        for (const int d : revrep(countr_zero(k)\
    \ + 1, logn + 1)) flush(k >> d);\n    }\n    void pull(int k) {\n        for (k\
    \ >>= countr_zero(k); k > 1;) fetch(k >>= 1);\n    }\n\n  public:\n    explicit\
    \ LazySegmentTree(const int size = 0, const T& value = M::identity())\n      \
    \  : LazySegmentTree(std::vector<T>(size, value)) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& vec) : internal_size(vec.size()) {\n        logn = ceil_log2(internal_size);\n\
    \        seg_size = 1 << logn;\n        data = std::vector<T>(2 * seg_size, M::identity());\n\
    \        lazy = std::vector<U>(seg_size, E::identity());\n        for (const int\
    \ i : rep(internal_size)) data[seg_size + i] = vec[i];\n        for (const int\
    \ i : revrep(1, seg_size)) fetch(i);\n    }\n\n    int size() const { return internal_size;\
    \ }\n\n    void assign(int i, const T& value) {\n        assert(0 <= i and i <\
    \ internal_size);\n        i += seg_size;\n        for (const int d : revrep(1,\
    \ logn + 1)) flush(i >> d);\n        data[i] = value;\n        for (const int\
    \ d : rep(1, logn + 1)) fetch(i >> d);\n    }\n    void operate(int l, int r,\
    \ const U& e) {\n        assert(0 <= l and l <= r and r <= internal_size);\n \
    \       l += seg_size;\n        r += seg_size;\n        push(l);\n        push(r);\n\
    \        for (int l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {\n           \
    \ if (l0 & 1) apply(l0++, e);\n            if (r0 & 1) apply(--r0, e);\n     \
    \   }\n        pull(l);\n        pull(r);\n    }\n\n    T fold() const { return\
    \ data[1]; }\n    T fold(int l, int r) {\n        assert(0 <= l and l <= r and\
    \ r <= internal_size);\n        l += seg_size;\n        r += seg_size;\n     \
    \   push(l);\n        push(r);\n        T ret_l = M::identity(), ret_r = M::identity();\n\
    \        while (l < r) {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n\
    \            if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return M::operation(ret_l,\
    \ ret_r);\n    }\n\n    template <class F> int max_right(int l, const F& f) {\n\
    \        assert(0 <= l and l <= internal_size);\n        assert(f(M::identity()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        for (const int d : revrep(1, logn + 1)) flush(l >> d);\n        T sum\
    \ = M::identity();\n        do {\n            while (!(l & 1)) l >>= 1;\n    \
    \        if (!f(M::operation(sum, data[l]))) {\n                while (l < seg_size)\
    \ {\n                    flush(l);\n                    l = 2 * l;\n         \
    \           if (f(M::operation(sum, data[l]))) sum = M::operation(sum, data[l++]);\n\
    \                }\n                return l - seg_size;\n            }\n    \
    \        sum = M::operation(sum, data[l++]);\n        } while ((l & -l) != l);\n\
    \        return internal_size;\n    }\n\n    template <class F> int min_left(int\
    \ r, const F& f) {\n        assert(0 <= r and r <= internal_size);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n        r += seg_size;\n        for (const int\
    \ d : revrep(1, logn + 1)) flush((r - 1) >> d);\n        T sum = M::identity();\n\
    \        do {\n            r -= 1;\n            while (r > 1 and (r & 1)) r >>=\
    \ 1;\n            if (!f(M::operation(data[r], sum))) {\n                while\
    \ (r < seg_size) {\n                    flush(r);\n                    r = 2 *\
    \ r + 1;\n                    if (f(M::operation(data[r], sum))) sum = M::operation(data[r--],\
    \ sum);\n                }\n                return r + 1 - seg_size;\n       \
    \     }\n            sum = M::operation(data[r], sum);\n        } while ((r &\
    \ -r) != r);\n        return 0;\n    }\n};\n#line 3 \"test/lazy_segment_tree.test.cpp\"\
    \n#include <iostream>\n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n\
    #include <type_traits>\n#line 3 \"math/rem_euclid.cpp\"\n\ntemplate <class T>\
    \ constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n    return\
    \ (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/totient.cpp\"\n\
    \ntemplate <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T i\
    \ = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n\
    \            ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n\
    \    }\n    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n  \
    \  return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32 MOD, std::enable_if_t<((u32)1\
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
    #line 2 \"traits/affine_composite_monoid.cpp\"\n\ntemplate <class T> struct Affine\
    \ {\n    T a, b;\n    constexpr Affine(const T& a = 1, const T& b = 0) : a(a),\
    \ b(b) {}\n    constexpr T eval(const T& x) const { return a * x + b; }\n    constexpr\
    \ Affine operator+(const Affine& other) const { return affine(a + other.a, b +\
    \ other.b); }\n    constexpr Affine composite(const Affine& other) const { return\
    \ Affine(a * other.a, b * other.a + other.b); }\n};\n\ntemplate <class T> struct\
    \ AffineCompositeMonoid {\n    using Type = Affine<T>;\n    static constexpr Type\
    \ identity() { return Type(); }\n    static constexpr Type operation(const Type&\
    \ l, const Type& r) noexcept { return l.composite(r); }\n};\n#line 2 \"traits/pair_monoid.cpp\"\
    \n#include <utility>\n\ntemplate <class M, class N> struct PairMonoid {\n    using\
    \ Type = std::pair<typename M::Type, typename N::Type>;\n    static constexpr\
    \ Type identity() { return {M::identity(), N::identity()}; }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) {\n        return {M::operation(l.first,\
    \ r.first), N::operation(l.second, r.second)};\n    }\n};\n#line 2 \"traits/sum_group.cpp\"\
    \n\ntemplate <class T> struct SumGroup {\n    using Type = T;\n    static constexpr\
    \ T identity() { return T(0); }\n    static constexpr T operation(const T& l,\
    \ const T& r) { return l + r; }\n    static constexpr T inverse(const T& x) {\
    \ return -x; }\n};\n#line 5 \"traits/sum_affine_action.cpp\"\n\ntemplate <class\
    \ T> struct SumAffineAction {\n    using Monoid = PairMonoid<SumGroup<T>, SumGroup<T>>;\n\
    \    using Effector = AffineCompositeMonoid<T>;\n    static constexpr std::pair<T,\
    \ T> operation(const std::pair<T, T>& m, const Affine<T>& e) {\n        return\
    \ {e.a * m.first + e.b * m.second, m.second};\n    }\n};\n#line 8 \"test/lazy_segment_tree.test.cpp\"\
    \n\nusing Fp = Modint998244353;\nusing Action = SumAffineAction<Fp>;\n\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<Fp, Fp>>\
    \ initial(N);\n    for (const int i : rep(0, N)) {\n        u32 a;\n        std::cin\
    \ >> a;\n        initial[i] = {a, 1};\n    }\n    LazySegmentTree<Action> seg(initial);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int l, r;\n            std::cin >> l >> r;\n            u32 b,\
    \ c;\n            std::cin >> b >> c;\n            seg.operate(l, r, {Fp(b), Fp(c)});\n\
    \        } else {\n            int l, r;\n            std::cin >> l >> r;\n  \
    \          std::cout << seg.fold(l, r).first << '\\n';\n        }\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../container/lazy_segment_tree.cpp\"\n#include <iostream>\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../traits/sum_affine_action.cpp\"\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\nusing\
    \ Fp = Modint998244353;\nusing Action = SumAffineAction<Fp>;\n\nint main() {\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<Fp, Fp>> initial(N);\n\
    \    for (const int i : rep(0, N)) {\n        u32 a;\n        std::cin >> a;\n\
    \        initial[i] = {a, 1};\n    }\n    LazySegmentTree<Action> seg(initial);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int l, r;\n            std::cin >> l >> r;\n            u32 b,\
    \ c;\n            std::cin >> b >> c;\n            seg.operate(l, r, {Fp(b), Fp(c)});\n\
    \        } else {\n            int l, r;\n            std::cin >> l >> r;\n  \
    \          std::cout << seg.fold(l, r).first << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - container/lazy_segment_tree.cpp
  - utility/ceil_log2.cpp
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - utility/countr_zero.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - traits/sum_affine_action.cpp
  - traits/affine_composite_monoid.cpp
  - traits/pair_monoid.cpp
  - traits/sum_group.cpp
  isVerificationFile: true
  path: test/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_segment_tree.test.cpp
- /verify/test/lazy_segment_tree.test.cpp.html
title: test/lazy_segment_tree.test.cpp
---
