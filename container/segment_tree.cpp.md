---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/segment_tree.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr u64\
    \ ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n\
    \    return e;\n}\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4\
    \ \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr rep(const usize first, const usize\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep\
    \ {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const usize\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ --itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr revrep(const usize first, const usize last) noexcept\n        : first(last\
    \ - 1), last(std::min(first, last) - 1) {}\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 8 \"container/segment_tree.cpp\"\n\ntemplate <class M> class SegmentTree\
    \ {\n    using T = typename M::Type;\n    usize internal_size, seg_size;\n   \
    \ std::vector<T> data;\n\n    void fetch(const usize k) { data[k] = M::operation(data[2\
    \ * k], data[2 * k + 1]); }\n\n  public:\n    explicit SegmentTree(const usize\
    \ size = 0, const T& value = M::identity())\n        : SegmentTree(std::vector<T>(size,\
    \ value)) {}\n    explicit SegmentTree(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<T>(2\
    \ * seg_size, M::identity());\n        for (const usize i : rep(0, internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const usize i : revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    usize size() const { return internal_size; }\n\n   \
    \ void assign(usize i, const T& value) {\n        assert(i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    T fold()\
    \ const { return data[1]; }\n    T fold(usize l, usize r) const {\n        assert(l\
    \ <= r and r <= internal_size);\n        l += seg_size;\n        r += seg_size;\n\
    \        T ret_l = M::identity(), ret_r = M::identity();\n        while (l < r)\
    \ {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n        \
    \    if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return M::operation(ret_l, ret_r);\n\
    \    }\n\n    template <class F> usize max_right(usize l, const F& f) const {\n\
    \        assert(l <= internal_size);\n        assert(f(M::identity()));\n    \
    \    if (l == internal_size) return internal_size;\n        l += seg_size;\n \
    \       T sum = M::identity();\n        do {\n            while (!(l & 1)) l >>=\
    \ 1;\n            if (!f(M::operation(sum, data[l]))) {\n                while\
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
    \       return 0;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../bit/ceil_log2.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../utility/revrep.cpp\"\n\ntemplate <class M> class SegmentTree {\n    using\
    \ T = typename M::Type;\n    usize internal_size, seg_size;\n    std::vector<T>\
    \ data;\n\n    void fetch(const usize k) { data[k] = M::operation(data[2 * k],\
    \ data[2 * k + 1]); }\n\n  public:\n    explicit SegmentTree(const usize size\
    \ = 0, const T& value = M::identity())\n        : SegmentTree(std::vector<T>(size,\
    \ value)) {}\n    explicit SegmentTree(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<T>(2\
    \ * seg_size, M::identity());\n        for (const usize i : rep(0, internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const usize i : revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    usize size() const { return internal_size; }\n\n   \
    \ void assign(usize i, const T& value) {\n        assert(i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    T fold()\
    \ const { return data[1]; }\n    T fold(usize l, usize r) const {\n        assert(l\
    \ <= r and r <= internal_size);\n        l += seg_size;\n        r += seg_size;\n\
    \        T ret_l = M::identity(), ret_r = M::identity();\n        while (l < r)\
    \ {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n        \
    \    if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return M::operation(ret_l, ret_r);\n\
    \    }\n\n    template <class F> usize max_right(usize l, const F& f) const {\n\
    \        assert(l <= internal_size);\n        assert(f(M::identity()));\n    \
    \    if (l == internal_size) return internal_size;\n        l += seg_size;\n \
    \       T sum = M::identity();\n        do {\n            while (!(l & 1)) l >>=\
    \ 1;\n            if (!f(M::operation(sum, data[l]))) {\n                while\
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
    \       return 0;\n    }\n};\n"
  dependsOn:
  - bit/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: false
  path: container/segment_tree.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree.test.cpp
  - test/larsch.test.cpp
  - test/heavy_light_decomposition.test.cpp
documentation_of: container/segment_tree.cpp
layout: document
redirect_from:
- /library/container/segment_tree.cpp
- /library/container/segment_tree.cpp.html
title: container/segment_tree.cpp
---
