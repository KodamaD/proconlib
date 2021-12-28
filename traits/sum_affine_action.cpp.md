---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: traits/affine_composite_monoid.cpp
    title: traits/affine_composite_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/pair_monoid.cpp
    title: traits/pair_monoid.cpp
  - icon: ':question:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/affine_composite_monoid.cpp\"\n\ntemplate <class\
    \ T> struct Affine {\n    T a, b;\n    constexpr Affine(const T& a = 1, const\
    \ T& b = 0) : a(a), b(b) {}\n    constexpr T eval(const T& x) const { return a\
    \ * x + b; }\n    constexpr Affine operator+(const Affine& other) const { return\
    \ affine(a + other.a, b + other.b); }\n    constexpr Affine composite(const Affine&\
    \ other) const { return Affine(a * other.a, b * other.a + other.b); }\n};\n\n\
    template <class T> struct AffineCompositeMonoid {\n    using Type = Affine<T>;\n\
    \    static constexpr Type identity() { return Type(); }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) noexcept { return l.composite(r);\
    \ }\n};\n#line 2 \"traits/pair_monoid.cpp\"\n#include <utility>\n\ntemplate <class\
    \ M, class N> struct PairMonoid {\n    using Type = std::pair<typename M::Type,\
    \ typename N::Type>;\n    static constexpr Type identity() { return {M::identity(),\
    \ N::identity()}; }\n    static constexpr Type operation(const Type& l, const\
    \ Type& r) {\n        return {M::operation(l.first, r.first), N::operation(l.second,\
    \ r.second)};\n    }\n};\n#line 2 \"traits/sum_group.cpp\"\n\ntemplate <class\
    \ T> struct SumGroup {\n    using Type = T;\n    static constexpr T identity()\
    \ { return T(0); }\n    static constexpr T operation(const T& l, const T& r) {\
    \ return l + r; }\n    static constexpr T inverse(const T& x) { return -x; }\n\
    };\n#line 5 \"traits/sum_affine_action.cpp\"\n\ntemplate <class T> struct SumAffineAction\
    \ {\n    using Monoid = PairMonoid<SumGroup<T>, SumGroup<T>>;\n    using Effector\
    \ = AffineCompositeMonoid<T>;\n    static constexpr std::pair<T, T> operation(const\
    \ std::pair<T, T>& m, const Affine<T>& e) {\n        return {e.a * m.first + e.b\
    \ * m.second, m.second};\n    }\n};\n"
  code: "#pragma once\n#include \"affine_composite_monoid.cpp\"\n#include \"pair_monoid.cpp\"\
    \n#include \"sum_group.cpp\"\n\ntemplate <class T> struct SumAffineAction {\n\
    \    using Monoid = PairMonoid<SumGroup<T>, SumGroup<T>>;\n    using Effector\
    \ = AffineCompositeMonoid<T>;\n    static constexpr std::pair<T, T> operation(const\
    \ std::pair<T, T>& m, const Affine<T>& e) {\n        return {e.a * m.first + e.b\
    \ * m.second, m.second};\n    }\n};"
  dependsOn:
  - traits/affine_composite_monoid.cpp
  - traits/pair_monoid.cpp
  - traits/sum_group.cpp
  isVerificationFile: false
  path: traits/sum_affine_action.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/sum_affine_action.cpp
layout: document
redirect_from:
- /library/traits/sum_affine_action.cpp
- /library/traits/sum_affine_action.cpp.html
title: traits/sum_affine_action.cpp
---
