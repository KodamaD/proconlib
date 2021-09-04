---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: container/queue_aggregation.cpp
    title: container/queue_aggregation.cpp
  - icon: ':x:'
    path: container/stack_aggregation.cpp
    title: container/stack_aggregation.cpp
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':x:'
    path: utility/reversed_monoid.cpp
    title: utility/reversed_monoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/queue_aggregation.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#line 2 \"container/stack_aggregation.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class Monoid> class StackAggregation {\n    using M = Monoid;\n\n\
    \    struct Node {\n        M value, fold;\n        explicit Node(const M value,\
    \ const M fold) : value(value), fold(fold) {}\n    };\n\n    std::vector<Node>\
    \ st;\n\n  public:\n    StackAggregation() = default;\n\n    bool empty() const\
    \ { return st.empty(); }\n    M top() const {\n        assert(!empty());\n   \
    \     return st.back().value;\n    }\n    M fold() const { return st.empty() ?\
    \ M::zero() : st.back().fold; }\n\n    void push(const M& x) { st.emplace_back(x,\
    \ fold() + x); }\n    void pop() {\n        assert(!empty());\n        st.pop_back();\n\
    \    }\n};\n#line 2 \"utility/reversed_monoid.cpp\"\n\ntemplate <class Monoid>\
    \ struct ReversedMonoid {\n    using M = Monoid;\n    using Self = ReversedMonoid;\n\
    \    M raw;\n    constexpr ReversedMonoid(const M& m): raw(m) {}\n    static constexpr\
    \ Self zero() { return Self(M::zero()); }\n    constexpr Self operator+(const\
    \ Self& other) const { return other.raw + raw; }\n};\n#line 4 \"container/queue_aggregation.cpp\"\
    \n\ntemplate <class Monoid> class QueueAggregation {\n    using M = Monoid;\n\n\
    \    StackAggregation<ReversedMonoid<M>> front_st;\n    StackAggregation<M> back_st;\n\
    \n  public:\n    QueueAggregation() = default;\n\n    bool empty() const { return\
    \ front_st.empty(); }\n    M fold() const { return front_st.fold().raw + back_st.fold();\
    \ }\n\n    void push(const M& x) {\n        if (empty())\n            front_st.push(x);\n\
    \        else\n            back_st.push(x);\n    }\n    void pop() {\n       \
    \ assert(!empty());\n        front_st.pop();\n        if (front_st.empty()) {\n\
    \            while (!back_st.empty()) {\n                front_st.push(back_st.top());\n\
    \                back_st.pop();\n            }\n        }\n    }\n};\n#line 3\
    \ \"test/queue_aggregation.test.cpp\"\n#include <iostream>\n#line 2 \"math/static_modint.cpp\"\
    \n#include <ostream>\n#include <type_traits>\n#line 2 \"math/totient.cpp\"\n\n\
    template <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T i =\
    \ 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n  \
    \          ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n\
    \    }\n    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n  \
    \  return ret;\n}\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"math/rem_euclid.cpp\"\n\ntemplate <class T> constexpr T rem_euclid(T\
    \ value, const T& mod) { return (value %= mod) >= 0 ? value : value + mod; }\n\
    #line 7 \"math/static_modint.cpp\"\n\ntemplate <u32 MOD, std::enable_if_t<((u32)1\
    \ <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class StaticModint {\n    using\
    \ Mint = StaticModint;\n\n    static inline constexpr u32 PHI = totient(MOD);\n\
    \    u32 v;\n\n  public:\n    static constexpr u32 mod() noexcept { return MOD;\
    \ }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept {\n       \
    \ return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n    template\
    \ <class T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept {\n       \
    \ return x % MOD;\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n\
    \    template <class T> constexpr StaticModint(const T x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Mint raw(const T x) noexcept {\n\
    \        Mint ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 get() const noexcept { return v; }\n    constexpr Mint neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Mint inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Mint pow(u64 exp) const noexcept {\n\
    \        Mint ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Mint operator-() const noexcept { return\
    \ neg(); }\n    constexpr Mint operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this)\
    \ += rhs; }\n    constexpr Mint& operator+=(const Mint& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs;\
    \ }\n    constexpr Mint& operator-=(const Mint& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this)\
    \ *= rhs; }\n    constexpr Mint& operator*=(const Mint& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs;\
    \ }\n    constexpr Mint& operator/=(const Mint& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Mint& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Mint& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Mint& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 6 \"test/queue_aggregation.test.cpp\"\n\nusing Fp = Modint998244353;\n\n\
    struct Monoid {\n    Fp a, b;\n    static constexpr Monoid zero() { return {Fp::raw(1),\
    \ Fp::raw(0)}; }\n    constexpr Monoid operator+(const Monoid& other) const {\
    \ return Monoid{other.a * a, other.a * b + other.b}; }\n    constexpr Fp get(const\
    \ Fp& x) const { return a * x + b; }\n};\n\nint main() {\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    usize Q;\n    std::cin >> Q;\n    QueueAggregation<Monoid>\
    \ que;\n    while (Q--) {\n        usize t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            u32 a, b;\n            std::cin >> a >> b;\n       \
    \     que.push(Monoid{Fp(a), Fp(b)});\n        } else if (t == 1) {\n        \
    \    que.pop();\n        } else {\n            u32 x;\n            std::cin >>\
    \ x;\n            std::cout << que.fold().get(Fp(x)) << '\\n';\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../container/queue_aggregation.cpp\"\n#include <iostream>\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../utility/int_alias.cpp\"\n\nusing\
    \ Fp = Modint998244353;\n\nstruct Monoid {\n    Fp a, b;\n    static constexpr\
    \ Monoid zero() { return {Fp::raw(1), Fp::raw(0)}; }\n    constexpr Monoid operator+(const\
    \ Monoid& other) const { return Monoid{other.a * a, other.a * b + other.b}; }\n\
    \    constexpr Fp get(const Fp& x) const { return a * x + b; }\n};\n\nint main()\
    \ {\n    std::ios_base::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    usize Q;\n    std::cin >> Q;\n    QueueAggregation<Monoid> que;\n    while\
    \ (Q--) {\n        usize t;\n        std::cin >> t;\n        if (t == 0) {\n \
    \           u32 a, b;\n            std::cin >> a >> b;\n            que.push(Monoid{Fp(a),\
    \ Fp(b)});\n        } else if (t == 1) {\n            que.pop();\n        } else\
    \ {\n            u32 x;\n            std::cin >> x;\n            std::cout <<\
    \ que.fold().get(Fp(x)) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - container/queue_aggregation.cpp
  - container/stack_aggregation.cpp
  - utility/reversed_monoid.cpp
  - math/static_modint.cpp
  - math/totient.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  isVerificationFile: true
  path: test/queue_aggregation.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 18:33:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/queue_aggregation.test.cpp
layout: document
redirect_from:
- /verify/test/queue_aggregation.test.cpp
- /verify/test/queue_aggregation.test.cpp.html
title: test/queue_aggregation.test.cpp
---
