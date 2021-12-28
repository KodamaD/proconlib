---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/semiring_matrix.cpp\"\n#include <array>\n#include <cassert>\n\
    #include <initializer_list>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\
    \nclass Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const\
    \ int pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 8 \"math/semiring_matrix.cpp\"\
    \n\ntemplate <class S> class SemiRingMatrix {\n    using T = typename S::Type;\n\
    \    using Self = SemiRingMatrix;\n    std::vector<std::vector<T>> data;\n\n \
    \ public:\n    SemiRingMatrix() = default;\n    explicit SemiRingMatrix(const\
    \ int h, const int w, const T& val = S::zero()) : data(h, std::vector<T>(w, val))\
    \ {}\n\n    SemiRingMatrix(const std::vector<std::vector<T>>& vec) : data(vec)\
    \ {\n        for (const auto& v : data) assert(v.size() == width());\n    }\n\
    \    SemiRingMatrix(const std::initializer_list<std::initializer_list<T>>& list)\
    \ {\n        data.reserve(list.size());\n        for (const auto& v : list) data.emplace_back(v.begin(),\
    \ v.end());\n        for (const auto& v : data) assert(v.size() == width());\n\
    \    }\n\n    int height() const { return data.size(); }\n    int width() const\
    \ { return data.empty() ? 0 : data[0].size(); }\n\n    T& operator()(const int\
    \ i, const int j) {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n    const T& operator()(const int i, const\
    \ int j) const {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n\n    Self operator+(const Self& other) const\
    \ { return Self(*this) += other; }\n    Self& operator+=(const Self& other) {\n\
    \        assert(height() == other.height());\n        assert(width() == other.width());\n\
    \        for (const int i : rep(0, height())) {\n            for (const int j\
    \ : rep(0, width())) {\n                data[i][j] = S::sum(data[i][j], other.data[i][j]);\n\
    \            }\n        }\n        return *this;\n    }\n\n    Self operator*(const\
    \ Self& other) const {\n        assert(width() == other.height());\n        Self\
    \ ret(height(), other.width(), S::zero());\n        for (const int i : rep(0,\
    \ height())) {\n            for (const int k : rep(0, width())) {\n          \
    \      for (const int j : rep(0, other.width())) {\n                    ret.data[i][j]\
    \ = S::sum(ret.data[i][j], S::product(data[i][k], other.data[k][j]));\n      \
    \          }\n            }\n        }\n        return ret;\n    }\n\n    Self\
    \ operator*(const T& other) const { return Self(*this) *= other; }\n    Self&\
    \ operator*=(const T& other) {\n        for (const int i : rep(0, height())) {\n\
    \            for (const int j : rep(0, width())) {\n                data[i][j]\
    \ = S::product(data[i][j], other);\n            }\n        }\n    }\n\n    Self\
    \ pow(u64 exp) const {\n        assert(height() == width());\n        Self ret(height(),\
    \ width(), S::zero()), mult(*this);\n        for (const int i : rep(0, height()))\
    \ {\n            ret.data[i][i] = S::one();\n        }\n        for (; exp > 0;\
    \ exp >>= 1) {\n            if (exp & 1) ret = ret * mult;\n            mult =\
    \ mult * mult;\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <initializer_list>\n\
    #include <vector>\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n\ntemplate <class S> class SemiRingMatrix {\n    using T = typename S::Type;\n\
    \    using Self = SemiRingMatrix;\n    std::vector<std::vector<T>> data;\n\n \
    \ public:\n    SemiRingMatrix() = default;\n    explicit SemiRingMatrix(const\
    \ int h, const int w, const T& val = S::zero()) : data(h, std::vector<T>(w, val))\
    \ {}\n\n    SemiRingMatrix(const std::vector<std::vector<T>>& vec) : data(vec)\
    \ {\n        for (const auto& v : data) assert(v.size() == width());\n    }\n\
    \    SemiRingMatrix(const std::initializer_list<std::initializer_list<T>>& list)\
    \ {\n        data.reserve(list.size());\n        for (const auto& v : list) data.emplace_back(v.begin(),\
    \ v.end());\n        for (const auto& v : data) assert(v.size() == width());\n\
    \    }\n\n    int height() const { return data.size(); }\n    int width() const\
    \ { return data.empty() ? 0 : data[0].size(); }\n\n    T& operator()(const int\
    \ i, const int j) {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n    const T& operator()(const int i, const\
    \ int j) const {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n\n    Self operator+(const Self& other) const\
    \ { return Self(*this) += other; }\n    Self& operator+=(const Self& other) {\n\
    \        assert(height() == other.height());\n        assert(width() == other.width());\n\
    \        for (const int i : rep(0, height())) {\n            for (const int j\
    \ : rep(0, width())) {\n                data[i][j] = S::sum(data[i][j], other.data[i][j]);\n\
    \            }\n        }\n        return *this;\n    }\n\n    Self operator*(const\
    \ Self& other) const {\n        assert(width() == other.height());\n        Self\
    \ ret(height(), other.width(), S::zero());\n        for (const int i : rep(0,\
    \ height())) {\n            for (const int k : rep(0, width())) {\n          \
    \      for (const int j : rep(0, other.width())) {\n                    ret.data[i][j]\
    \ = S::sum(ret.data[i][j], S::product(data[i][k], other.data[k][j]));\n      \
    \          }\n            }\n        }\n        return ret;\n    }\n\n    Self\
    \ operator*(const T& other) const { return Self(*this) *= other; }\n    Self&\
    \ operator*=(const T& other) {\n        for (const int i : rep(0, height())) {\n\
    \            for (const int j : rep(0, width())) {\n                data[i][j]\
    \ = S::product(data[i][j], other);\n            }\n        }\n    }\n\n    Self\
    \ pow(u64 exp) const {\n        assert(height() == width());\n        Self ret(height(),\
    \ width(), S::zero()), mult(*this);\n        for (const int i : rep(0, height()))\
    \ {\n            ret.data[i][i] = S::one();\n        }\n        for (; exp > 0;\
    \ exp >>= 1) {\n            if (exp & 1) ret = ret * mult;\n            mult =\
    \ mult * mult;\n        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: math/semiring_matrix.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/semiring_matrix.test.cpp
documentation_of: math/semiring_matrix.cpp
layout: document
redirect_from:
- /library/math/semiring_matrix.cpp
- /library/math/semiring_matrix.cpp.html
title: math/semiring_matrix.cpp
---
