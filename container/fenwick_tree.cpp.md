---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 4 \"container/fenwick_tree.cpp\"\n\
    #include <vector>\n#include <cassert>\n\ntemplate <class T>\nclass FenwickTree\
    \ {\n    usize logn;\n    std::vector<T> data;\n    \npublic:\n    explicit FenwickTree(const\
    \ usize size = 0) {\n        logn = ceil_log2(size + 1) - 1;\n        data = std::vector<T>(size\
    \ + 1, T(0));\n    }\n\n    usize size() const { return data.size() - 1; }\n\n\
    \    void add(usize i, const T& x) { \n        assert(i < size());\n        i\
    \ += 1;\n        while (i < data.size()) {\n            data[i] += x;\n      \
    \      i += i & -i;\n        }\n    }\n    void subtract(usize i, const T& x)\
    \ { \n        assert(i < size());\n        i += 1;\n        while (i < data.size())\
    \ {\n            data[i] -= x;\n            i += i & -i;\n        }\n    }\n\n\
    \    T fold(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        T ret(0);\n        while (l < r) {\n            ret += data[r];\n   \
    \         r -= r & -r;\n        }\n        while (r < l) {\n            ret -=\
    \ data[l];\n            l -= l & -l;\n        }\n        return ret;\n    }\n\n\
    \    template <class F>\n    usize max_right(const F &f) const {\n        assert(f(T(0)));\n\
    \        usize i = 0;\n        T sum(0);\n        for (usize k = (1 << logn);\
    \ k > 0; k >>= 1) {\n            if (i + k <= size() && f(sum + data[i + k]))\
    \ {\n                i += k;\n                sum += data[i];\n            }\n\
    \        }\n        return i;\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../bit/ceil_log2.cpp\"\
    \n#include <vector>\n#include <cassert>\n\ntemplate <class T>\nclass FenwickTree\
    \ {\n    usize logn;\n    std::vector<T> data;\n    \npublic:\n    explicit FenwickTree(const\
    \ usize size = 0) {\n        logn = ceil_log2(size + 1) - 1;\n        data = std::vector<T>(size\
    \ + 1, T(0));\n    }\n\n    usize size() const { return data.size() - 1; }\n\n\
    \    void add(usize i, const T& x) { \n        assert(i < size());\n        i\
    \ += 1;\n        while (i < data.size()) {\n            data[i] += x;\n      \
    \      i += i & -i;\n        }\n    }\n    void subtract(usize i, const T& x)\
    \ { \n        assert(i < size());\n        i += 1;\n        while (i < data.size())\
    \ {\n            data[i] -= x;\n            i += i & -i;\n        }\n    }\n\n\
    \    T fold(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        T ret(0);\n        while (l < r) {\n            ret += data[r];\n   \
    \         r -= r & -r;\n        }\n        while (r < l) {\n            ret -=\
    \ data[l];\n            l -= l & -l;\n        }\n        return ret;\n    }\n\n\
    \    template <class F>\n    usize max_right(const F &f) const {\n        assert(f(T(0)));\n\
    \        usize i = 0;\n        T sum(0);\n        for (usize k = (1 << logn);\
    \ k > 0; k >>= 1) {\n            if (i + k <= size() && f(sum + data[i + k]))\
    \ {\n                i += k;\n                sum += data[i];\n            }\n\
    \        }\n        return i;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: false
  path: container/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2021-04-06 09:35:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fenwick_tree.test.cpp
documentation_of: container/fenwick_tree.cpp
layout: document
redirect_from:
- /library/container/fenwick_tree.cpp
- /library/container/fenwick_tree.cpp.html
title: container/fenwick_tree.cpp
---