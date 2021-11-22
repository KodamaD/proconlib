---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/queue_aggregation.cpp
    title: container/queue_aggregation.cpp
  - icon: ':heavy_check_mark:'
    path: container/stack_aggregation.cpp
    title: container/stack_aggregation.cpp
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
    path: traits/reversed_monoid.cpp
    title: traits/reversed_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/queue_aggregation.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#line 2 \"traits/reversed_monoid.cpp\"\n\ntemplate <class M> struct ReversedMonoid\
    \ {\n    using Type = typename M::Type;\n    static constexpr Type identity()\
    \ { return M::identity(); }\n    static constexpr Type operation(const Type& l,\
    \ const Type& r) { return M::operation(r, l); }\n};\n#line 2 \"container/stack_aggregation.cpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate <class M> class StackAggregation\
    \ {\n    using T = typename M::Type;\n\n    struct Node {\n        T value, fold;\n\
    \        explicit Node(const T value, const T fold) : value(value), fold(fold)\
    \ {}\n    };\n\n    std::vector<Node> st;\n\n  public:\n    StackAggregation()\
    \ = default;\n\n    bool empty() const { return st.empty(); }\n    T top() const\
    \ {\n        assert(!empty());\n        return st.back().value;\n    }\n    T\
    \ fold() const { return st.empty() ? M::identity() : st.back().fold; }\n\n   \
    \ void push(const T& x) { st.emplace_back(x, M::operation(fold(), x)); }\n   \
    \ void pop() {\n        assert(!empty());\n        st.pop_back();\n    }\n};\n\
    #line 4 \"container/queue_aggregation.cpp\"\n\ntemplate <class M> class QueueAggregation\
    \ {\n    using T = typename M::Type;\n    using R = ReversedMonoid<M>;\n\n   \
    \ StackAggregation<R> front_st;\n    StackAggregation<M> back_st;\n\n  public:\n\
    \    QueueAggregation() = default;\n\n    bool empty() const { return front_st.empty();\
    \ }\n    T fold() const { return M::operation(front_st.fold(), back_st.fold());\
    \ }\n\n    void push(const T& x) {\n        if (empty())\n            front_st.push(x);\n\
    \        else\n            back_st.push(x);\n    }\n    void pop() {\n       \
    \ assert(!empty());\n        front_st.pop();\n        if (front_st.empty()) {\n\
    \            while (!back_st.empty()) {\n                front_st.push(back_st.top());\n\
    \                back_st.pop();\n            }\n        }\n    }\n};\n#line 3\
    \ \"test/queue_aggregation.test.cpp\"\n#include <iostream>\n#line 2 \"math/static_modint.cpp\"\
    \n#include <ostream>\n#include <type_traits>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"\
    math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T x) {\n    T ret\
    \ = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n    \
    \        ret /= i;\n            ret *= i - 1;\n            while (x % i == 0)\
    \ x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n        ret\
    \ *= x - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\n\
    template <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>*\
    \ = nullptr> class StaticModint {\n    using Self = StaticModint;\n\n    static\
    \ inline constexpr u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static\
    \ constexpr u32 mod() noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T& x) noexcept {\n      \
    \  return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n\n    constexpr\
    \ StaticModint() noexcept : v(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T& x) noexcept : v(normalize(x)) {}\n    template <class T> static constexpr\
    \ Self raw(const T& x) noexcept {\n        Self ret;\n        ret.v = x;\n   \
    \     return ret;\n    }\n\n    constexpr u32 val() const noexcept { return v;\
    \ }\n    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v);\
    \ }\n    constexpr Self inv() const noexcept { return pow(PHI - 1); }\n    constexpr\
    \ Self pow(u64 exp) const noexcept {\n        Self ret(1), mult(*this);\n    \
    \    for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n   \
    \         mult *= mult;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ Self operator-() const noexcept { return neg(); }\n    constexpr Self operator~()\
    \ const noexcept { return inv(); }\n\n    constexpr Self operator+(const Self&\
    \ rhs) const noexcept { return Self(*this) += rhs; }\n    constexpr Self& operator+=(const\
    \ Self& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator-(const Self& rhs) const noexcept\
    \ { return Self(*this) -= rhs; }\n    constexpr Self& operator-=(const Self& rhs)\
    \ noexcept {\n        if (v < rhs.v) v += MOD;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    constexpr Self& operator*=(const Self& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\
    \n    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this)\
    \ /= rhs; }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const\
    \ noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs)\
    \ const noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
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
    \ l, const Type& r) noexcept { return l.composite(r); }\n};\n#line 7 \"test/queue_aggregation.test.cpp\"\
    \n\nusing Fp = Modint998244353;\n\nint main() {\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    usize Q;\n    std::cin >> Q;\n    QueueAggregation<AffineCompositeMonoid<Fp>>\
    \ que;\n    while (Q--) {\n        usize t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            u32 a, b;\n            std::cin >> a >> b;\n       \
    \     que.push(Affine<Fp>(Fp(a), Fp(b)));\n        } else if (t == 1) {\n    \
    \        que.pop();\n        } else {\n            u32 x;\n            std::cin\
    \ >> x;\n            std::cout << que.fold().eval(Fp(x)) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../container/queue_aggregation.cpp\"\n#include <iostream>\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../utility/int_alias.cpp\"\n#include\
    \ \"../traits/affine_composite_monoid.cpp\"\n\nusing Fp = Modint998244353;\n\n\
    int main() {\n    std::ios_base::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    usize Q;\n    std::cin >> Q;\n    QueueAggregation<AffineCompositeMonoid<Fp>>\
    \ que;\n    while (Q--) {\n        usize t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            u32 a, b;\n            std::cin >> a >> b;\n       \
    \     que.push(Affine<Fp>(Fp(a), Fp(b)));\n        } else if (t == 1) {\n    \
    \        que.pop();\n        } else {\n            u32 x;\n            std::cin\
    \ >> x;\n            std::cout << que.fold().eval(Fp(x)) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - container/queue_aggregation.cpp
  - traits/reversed_monoid.cpp
  - container/stack_aggregation.cpp
  - math/static_modint.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - traits/affine_composite_monoid.cpp
  isVerificationFile: true
  path: test/queue_aggregation.test.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/queue_aggregation.test.cpp
layout: document
redirect_from:
- /verify/test/queue_aggregation.test.cpp
- /verify/test/queue_aggregation.test.cpp.html
title: test/queue_aggregation.test.cpp
---
