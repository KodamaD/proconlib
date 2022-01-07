---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':question:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/segment_tree.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define\
    \ TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n\
    #endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
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
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\n\n\
    class ReversedRange {\n    struct Iter {\n        int itr;\n        constexpr\
    \ Iter(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const Iter& other) const\
    \ noexcept { return itr != other.itr; }\n        constexpr int operator*() const\
    \ noexcept { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n\
    \    explicit constexpr ReversedRange(const int first, const int last) noexcept\n\
    \        : first(last - 1), last(std::min(first, last) - 1) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr ReversedRange revrep(const int l,\
    \ const int r) noexcept { return ReversedRange(l, r); }\nconstexpr ReversedRange\
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 7 \"container/segment_tree.cpp\"\
    \n\ntemplate <class M> class SegmentTree {\n    using T = typename M::Type;\n\
    \    int internal_size, seg_size;\n    std::vector<T> data;\n\n    void fetch(const\
    \ int k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]); }\n\n  public:\n\
    \    explicit SegmentTree(const int size = 0, const T& value = M::identity())\n\
    \        : SegmentTree(std::vector<T>(size, value)) {}\n    explicit SegmentTree(const\
    \ std::vector<T>& vec) : internal_size(vec.size()) {\n        seg_size = 1 <<\
    \ ceil_log2(internal_size);\n        data = std::vector<T>(2 * seg_size, M::identity());\n\
    \        for (const int i : rep(internal_size)) data[seg_size + i] = vec[i];\n\
    \        for (const int i : revrep(1, seg_size)) fetch(i);\n    }\n\n    int size()\
    \ const { return internal_size; }\n\n    void assign(int i, const T& value) {\n\
    \        assert(0 <= i and i < internal_size);\n        i += seg_size;\n     \
    \   data[i] = value;\n        while (i > 1) {\n            i >>= 1;\n        \
    \    fetch(i);\n        }\n    }\n\n    T fold() const { return data[1]; }\n \
    \   T fold(int l, int r) const {\n        assert(0 <= l and l <= r and r <= internal_size);\n\
    \        l += seg_size;\n        r += seg_size;\n        T ret_l = M::identity(),\
    \ ret_r = M::identity();\n        while (l < r) {\n            if (l & 1) ret_l\
    \ = M::operation(ret_l, data[l++]);\n            if (r & 1) ret_r = M::operation(data[--r],\
    \ ret_r);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::operation(ret_l, ret_r);\n    }\n\n    template <class F> int max_right(int\
    \ l, const F& f) const {\n        assert(0 <= l and l <= internal_size);\n   \
    \     assert(f(M::identity()));\n        if (l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        T sum = M::identity();\n        do {\n      \
    \      while (!(l & 1)) l >>= 1;\n            if (!f(M::operation(sum, data[l])))\
    \ {\n                while (l < seg_size) {\n                    l = 2 * l;\n\
    \                    if (f(M::operation(sum, data[l]))) sum = M::operation(sum,\
    \ data[l++]);\n                }\n                return l - seg_size;\n     \
    \       }\n            sum = M::operation(sum, data[l++]);\n        } while ((l\
    \ & -l) != l);\n        return internal_size;\n    }\n\n    template <class F>\
    \ int min_left(int r, const F& f) const {\n        assert(0 <= r and r <= internal_size);\n\
    \        assert(f(M::identity()));\n        if (r == 0) return 0;\n        r +=\
    \ seg_size;\n        T sum = M::identity();\n        do {\n            r -= 1;\n\
    \            while (r > 1 and (r & 1)) r >>= 1;\n            if (!f(M::operation(data[r],\
    \ sum))) {\n                while (r < seg_size) {\n                    r = 2\
    \ * r + 1;\n                    if (f(M::operation(data[r], sum))) sum = M::operation(data[r--],\
    \ sum);\n                }\n                return r + 1 - seg_size;\n       \
    \     }\n            sum = M::operation(data[r], sum);\n        } while ((r &\
    \ -r) != r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/ceil_log2.cpp\"\
    \n#include \"../utility/rep.cpp\"\n#include \"../utility/revrep.cpp\"\n\ntemplate\
    \ <class M> class SegmentTree {\n    using T = typename M::Type;\n    int internal_size,\
    \ seg_size;\n    std::vector<T> data;\n\n    void fetch(const int k) { data[k]\
    \ = M::operation(data[2 * k], data[2 * k + 1]); }\n\n  public:\n    explicit SegmentTree(const\
    \ int size = 0, const T& value = M::identity())\n        : SegmentTree(std::vector<T>(size,\
    \ value)) {}\n    explicit SegmentTree(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<T>(2\
    \ * seg_size, M::identity());\n        for (const int i : rep(internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const int i : revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    int size() const { return internal_size; }\n\n    void\
    \ assign(int i, const T& value) {\n        assert(0 <= i and i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    T fold()\
    \ const { return data[1]; }\n    T fold(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= internal_size);\n        l += seg_size;\n        r\
    \ += seg_size;\n        T ret_l = M::identity(), ret_r = M::identity();\n    \
    \    while (l < r) {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n\
    \            if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return M::operation(ret_l,\
    \ ret_r);\n    }\n\n    template <class F> int max_right(int l, const F& f) const\
    \ {\n        assert(0 <= l and l <= internal_size);\n        assert(f(M::identity()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        T sum = M::identity();\n        do {\n            while (!(l & 1)) l\
    \ >>= 1;\n            if (!f(M::operation(sum, data[l]))) {\n                while\
    \ (l < seg_size) {\n                    l = 2 * l;\n                    if (f(M::operation(sum,\
    \ data[l]))) sum = M::operation(sum, data[l++]);\n                }\n        \
    \        return l - seg_size;\n            }\n            sum = M::operation(sum,\
    \ data[l++]);\n        } while ((l & -l) != l);\n        return internal_size;\n\
    \    }\n\n    template <class F> int min_left(int r, const F& f) const {\n   \
    \     assert(0 <= r and r <= internal_size);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n        r += seg_size;\n        T sum = M::identity();\n\
    \        do {\n            r -= 1;\n            while (r > 1 and (r & 1)) r >>=\
    \ 1;\n            if (!f(M::operation(data[r], sum))) {\n                while\
    \ (r < seg_size) {\n                    r = 2 * r + 1;\n                    if\
    \ (f(M::operation(data[r], sum))) sum = M::operation(data[r--], sum);\n      \
    \          }\n                return r + 1 - seg_size;\n            }\n      \
    \      sum = M::operation(data[r], sum);\n        } while ((r & -r) != r);\n \
    \       return 0;\n    }\n};\n"
  dependsOn:
  - utility/ceil_log2.cpp
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: false
  path: container/segment_tree.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/larsch.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
documentation_of: container/segment_tree.cpp
layout: document
redirect_from:
- /library/container/segment_tree.cpp
- /library/container/segment_tree.cpp.html
title: container/segment_tree.cpp
---
