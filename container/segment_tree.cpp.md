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
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
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
    \ { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n   \
    \ struct Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept:\
    \ itr(pos) { }\n        constexpr void operator ++ () noexcept { --itr; }\n  \
    \      constexpr bool operator != (const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr usize operator * () const noexcept {\
    \ return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit constexpr\
    \ revrep(const usize first, const usize last) noexcept: first(last - 1), last(std::min(first,\
    \ last) - 1) { }\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 6 \"container/segment_tree.cpp\"\n\
    #include <vector>\n#include <cassert>\n\ntemplate <class Monoid>\nclass SegmentTree\
    \ {\n    using M = Monoid;\n    usize internal_size, seg_size;\n    std::vector<M>\
    \ data;\n\n    void fetch(const usize k) { data[k] = data[2 * k] + data[2 * k\
    \ + 1]; }\n\npublic:\n    explicit SegmentTree(const usize size = 0, const M&\
    \ value = M::zero()): \n        SegmentTree(std::vector<M>(size, value)) { }\n\
    \    explicit SegmentTree(const std::vector<M>& vec): internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<M>(2\
    \ * seg_size, M::zero());\n        for (const usize i: rep(0, internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const usize i: revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    usize size() const { return internal_size; }\n\n   \
    \ void assign(usize i, const M& value) {\n        assert(i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    M fold()\
    \ const { return data[1]; }\n    M fold(usize l, usize r) const {\n        assert(l\
    \ <= r and r <= internal_size);\n        l += seg_size; r += seg_size;\n     \
    \   M ret_l = M::zero(), ret_r = M::zero();\n        while (l < r) {\n       \
    \     if (l & 1) ret_l = ret_l + data[l++];\n            if (r & 1) ret_r = data[--r]\
    \ + ret_r;\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ ret_l + ret_r;\n    }\n\n    template <class F>\n    usize max_right(usize l,\
    \ const F& f) const {\n        assert(l <= internal_size);\n        assert(f(M::zero()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            while (!(l & 1)) l >>=\
    \ 1;\n            if (!f(sum + data[l])) {\n                while (l < seg_size)\
    \ {\n                    l = 2 * l;\n                    if (f(sum + data[l]))\
    \ sum = sum + data[l++];\n                }\n                return l - seg_size;\n\
    \            }\n            sum = sum + data[l++];\n        } while ((l & -l)\
    \ != l);\n        return internal_size;\n    }\n\n    template <class F>\n   \
    \ usize min_left(usize r, const F& f) const {\n        assert(r <= internal_size);\n\
    \        assert(f(M::zero()));\n        if (r == 0) return 0;\n        r += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            r -= 1;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!f(data[r] + sum)) {\n       \
    \         while (r < seg_size) {\n                    r = 2 * r + 1;\n       \
    \             if (f(data[r] + sum)) sum = data[r--] + sum;\n                }\n\
    \                return r + 1 - seg_size;\n            }\n            sum = data[r]\
    \ + sum;\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/revrep.cpp\"\n#include \"../bit/ceil_log2.cpp\"\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate <class Monoid>\nclass SegmentTree {\n\
    \    using M = Monoid;\n    usize internal_size, seg_size;\n    std::vector<M>\
    \ data;\n\n    void fetch(const usize k) { data[k] = data[2 * k] + data[2 * k\
    \ + 1]; }\n\npublic:\n    explicit SegmentTree(const usize size = 0, const M&\
    \ value = M::zero()): \n        SegmentTree(std::vector<M>(size, value)) { }\n\
    \    explicit SegmentTree(const std::vector<M>& vec): internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<M>(2\
    \ * seg_size, M::zero());\n        for (const usize i: rep(0, internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const usize i: revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    usize size() const { return internal_size; }\n\n   \
    \ void assign(usize i, const M& value) {\n        assert(i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    M fold()\
    \ const { return data[1]; }\n    M fold(usize l, usize r) const {\n        assert(l\
    \ <= r and r <= internal_size);\n        l += seg_size; r += seg_size;\n     \
    \   M ret_l = M::zero(), ret_r = M::zero();\n        while (l < r) {\n       \
    \     if (l & 1) ret_l = ret_l + data[l++];\n            if (r & 1) ret_r = data[--r]\
    \ + ret_r;\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ ret_l + ret_r;\n    }\n\n    template <class F>\n    usize max_right(usize l,\
    \ const F& f) const {\n        assert(l <= internal_size);\n        assert(f(M::zero()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            while (!(l & 1)) l >>=\
    \ 1;\n            if (!f(sum + data[l])) {\n                while (l < seg_size)\
    \ {\n                    l = 2 * l;\n                    if (f(sum + data[l]))\
    \ sum = sum + data[l++];\n                }\n                return l - seg_size;\n\
    \            }\n            sum = sum + data[l++];\n        } while ((l & -l)\
    \ != l);\n        return internal_size;\n    }\n\n    template <class F>\n   \
    \ usize min_left(usize r, const F& f) const {\n        assert(r <= internal_size);\n\
    \        assert(f(M::zero()));\n        if (r == 0) return 0;\n        r += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            r -= 1;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!f(data[r] + sum)) {\n       \
    \         while (r < seg_size) {\n                    r = 2 * r + 1;\n       \
    \             if (f(data[r] + sum)) sum = data[r--] + sum;\n                }\n\
    \                return r + 1 - seg_size;\n            }\n            sum = data[r]\
    \ + sum;\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: false
  path: container/segment_tree.cpp
  requiredBy: []
  timestamp: '2021-03-31 14:58:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree.test.cpp
documentation_of: container/segment_tree.cpp
layout: document
redirect_from:
- /library/container/segment_tree.cpp
- /library/container/segment_tree.cpp.html
title: container/segment_tree.cpp
---
