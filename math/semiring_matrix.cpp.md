---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 4 \"math/semiring_matrix.cpp\"\n#include <vector>\n\
    #include <array>\n#include <initializer_list>\n#include <cassert>\n\ntemplate\
    \ <class SemiRing>\nclass SemiRingMatrix {\n    using Self = SemiRingMatrix;\n\
    \    std::vector<std::vector<SemiRing>> data;\n\npublic:\n    SemiRingMatrix()\
    \ = default;\n    explicit SemiRingMatrix(const usize h, const usize w, const\
    \ SemiRing& val = SemiRing::zero()): data(h, std::vector<SemiRing>(w, val)) {\
    \ }\n\n    SemiRingMatrix(const std::vector<std::vector<SemiRing>>& vec): data(vec)\
    \ { }\n    SemiRingMatrix(const std::initializer_list<std::initializer_list<SemiRing>>&\
    \ list) {\n        data.reserve(list.size());\n        for (const auto& v: list)\
    \ {\n            data.emplace_back(v.begin(), v.end());\n        }\n    }\n  \
    \  template <usize H, usize W>\n    SemiRingMatrix(const std::array<std::array<SemiRing,\
    \ W>, H>& arr) {\n        data.reserve(H);\n        for (const auto &v: arr) {\n\
    \            data.emplace_back(v.begin(), v.end());\n        }\n    }\n\n    usize\
    \ height() const { return data.size(); }\n    usize width() const { return data.empty()\
    \ ? 0 : data[0].size(); }\n\n    SemiRing& operator () (const usize i, const usize\
    \ j) {\n        assert(i < height());\n        assert(j < width());\n        return\
    \ data[i][j];\n    }\n    const SemiRing& operator () (const usize i, const usize\
    \ j) const {\n        assert(i < height());\n        assert(j < width());\n  \
    \      return data[i][j];\n    }\n\n    Self operator + (const Self& other) const\
    \ { return Self(*this) += other; }\n    Self& operator += (const Self& other)\
    \ {\n        assert(height() == other.height());\n        assert(width() == other.width());\n\
    \        for (const usize i: rep(0, height())) {\n            for (const usize\
    \ j: rep(0, width())) {\n                data[i][j] = data[i][j] + other.data[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Self operator *\
    \ (const Self& other) const {\n        assert(width() == other.height());\n  \
    \      Self ret(height(), other.width(), SemiRing::zero());\n        for (const\
    \ usize i: rep(0, height())) {\n            for (const usize k: rep(0, width()))\
    \ {\n                for (const usize j: rep(0, other.width())) {\n          \
    \          ret.data[i][j] = ret.data[i][j] + data[i][k] * other.data[k][j];\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   Self operator * (const SemiRing& other) const { return Self(*this) *= other;\
    \ }\n    Self& operator *= (const SemiRing& other) {\n        for (const usize\
    \ i: rep(0, height())) {\n            for (const usize j: rep(0, width())) {\n\
    \                data[i][j] = data[i][j] * other;\n            }\n        }\n\
    \    }\n\n    Self pow(u64 exp) const {\n        assert(height() == width());\n\
    \        Self ret(height(), width(), SemiRing::zero()), mult(*this);\n       \
    \ for (const usize i: rep(0, height())) {\n            ret.data[i][i] = SemiRing::one();\n\
    \        }\n        for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret\
    \ = ret * mult;\n            mult = mult * mult;\n        }\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include <vector>\n#include <array>\n#include <initializer_list>\n#include <cassert>\n\
    \ntemplate <class SemiRing>\nclass SemiRingMatrix {\n    using Self = SemiRingMatrix;\n\
    \    std::vector<std::vector<SemiRing>> data;\n\npublic:\n    SemiRingMatrix()\
    \ = default;\n    explicit SemiRingMatrix(const usize h, const usize w, const\
    \ SemiRing& val = SemiRing::zero()): data(h, std::vector<SemiRing>(w, val)) {\
    \ }\n\n    SemiRingMatrix(const std::vector<std::vector<SemiRing>>& vec): data(vec)\
    \ { }\n    SemiRingMatrix(const std::initializer_list<std::initializer_list<SemiRing>>&\
    \ list) {\n        data.reserve(list.size());\n        for (const auto& v: list)\
    \ {\n            data.emplace_back(v.begin(), v.end());\n        }\n    }\n  \
    \  template <usize H, usize W>\n    SemiRingMatrix(const std::array<std::array<SemiRing,\
    \ W>, H>& arr) {\n        data.reserve(H);\n        for (const auto &v: arr) {\n\
    \            data.emplace_back(v.begin(), v.end());\n        }\n    }\n\n    usize\
    \ height() const { return data.size(); }\n    usize width() const { return data.empty()\
    \ ? 0 : data[0].size(); }\n\n    SemiRing& operator () (const usize i, const usize\
    \ j) {\n        assert(i < height());\n        assert(j < width());\n        return\
    \ data[i][j];\n    }\n    const SemiRing& operator () (const usize i, const usize\
    \ j) const {\n        assert(i < height());\n        assert(j < width());\n  \
    \      return data[i][j];\n    }\n\n    Self operator + (const Self& other) const\
    \ { return Self(*this) += other; }\n    Self& operator += (const Self& other)\
    \ {\n        assert(height() == other.height());\n        assert(width() == other.width());\n\
    \        for (const usize i: rep(0, height())) {\n            for (const usize\
    \ j: rep(0, width())) {\n                data[i][j] = data[i][j] + other.data[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Self operator *\
    \ (const Self& other) const {\n        assert(width() == other.height());\n  \
    \      Self ret(height(), other.width(), SemiRing::zero());\n        for (const\
    \ usize i: rep(0, height())) {\n            for (const usize k: rep(0, width()))\
    \ {\n                for (const usize j: rep(0, other.width())) {\n          \
    \          ret.data[i][j] = ret.data[i][j] + data[i][k] * other.data[k][j];\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   Self operator * (const SemiRing& other) const { return Self(*this) *= other;\
    \ }\n    Self& operator *= (const SemiRing& other) {\n        for (const usize\
    \ i: rep(0, height())) {\n            for (const usize j: rep(0, width())) {\n\
    \                data[i][j] = data[i][j] * other;\n            }\n        }\n\
    \    }\n\n    Self pow(u64 exp) const {\n        assert(height() == width());\n\
    \        Self ret(height(), width(), SemiRing::zero()), mult(*this);\n       \
    \ for (const usize i: rep(0, height())) {\n            ret.data[i][i] = SemiRing::one();\n\
    \        }\n        for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret\
    \ = ret * mult;\n            mult = mult * mult;\n        }\n        return ret;\n\
    \    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: math/semiring_matrix.cpp
  requiredBy: []
  timestamp: '2021-05-02 18:39:12+09:00'
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
