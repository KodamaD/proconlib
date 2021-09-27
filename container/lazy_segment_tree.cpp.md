---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/lazy_segment_tree.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 3 \"bit/bit_rzeros.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x);\
    \ }\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x)\
    \ ++e;\n    return e;\n}\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\
    #line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
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
    };\n#line 9 \"container/lazy_segment_tree.cpp\"\n\ntemplate <class A> class LazySegmentTree\
    \ {\n    using M = typename A::Monoid;\n    using E = typename A::Effector;\n\
    \    using T = typename M::Type;\n    using U = typename E::Type;\n    usize internal_size,\
    \ logn, seg_size;\n    std::vector<T> data;\n    std::vector<U> lazy;\n\n    void\
    \ fetch(const usize k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]);\
    \ }\n    void apply(const usize k, const U& e) {\n        data[k] = A::operation(data[k],\
    \ e);\n        if (k < seg_size) lazy[k] = E::operation(lazy[k], e);\n    }\n\
    \    void flush(const usize k) {\n        apply(2 * k, lazy[k]);\n        apply(2\
    \ * k + 1, lazy[k]);\n        lazy[k] = E::identity();\n    }\n\n    void push(const\
    \ usize k) {\n        for (const usize d : revrep(bit_rzeros(k) + 1, logn + 1))\
    \ flush(k >> d);\n    }\n    void pull(usize k) {\n        for (k >>= bit_rzeros(k);\
    \ k > 1;) fetch(k >>= 1);\n    }\n\n  public:\n    explicit LazySegmentTree(const\
    \ usize size = 0, const T& value = M::identity())\n        : LazySegmentTree(std::vector<T>(size,\
    \ value)) {}\n    explicit LazySegmentTree(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        seg_size = 1 << logn;\n\
    \        data = std::vector<T>(2 * seg_size, M::identity());\n        lazy = std::vector<U>(seg_size,\
    \ E::identity());\n        for (const usize i : rep(0, internal_size)) data[seg_size\
    \ + i] = vec[i];\n        for (const usize i : revrep(1, seg_size)) fetch(i);\n\
    \    }\n\n    usize size() const { return internal_size; }\n\n    void assign(usize\
    \ i, const T& value) {\n        assert(i < internal_size);\n        i += seg_size;\n\
    \        for (const usize d : revrep(1, logn + 1)) flush(i >> d);\n        data[i]\
    \ = value;\n        for (const usize d : rep(1, logn + 1)) fetch(i >> d);\n  \
    \  }\n    void operate(usize l, usize r, const U& e) {\n        assert(l <= r\
    \ and r <= internal_size);\n        l += seg_size;\n        r += seg_size;\n \
    \       push(l);\n        push(r);\n        for (usize l0 = l, r0 = r; l0 < r0;\
    \ l0 >>= 1, r0 >>= 1) {\n            if (l0 & 1) apply(l0++, e);\n           \
    \ if (r0 & 1) apply(--r0, e);\n        }\n        pull(l);\n        pull(r);\n\
    \    }\n\n    T fold() const { return data[1]; }\n    T fold(usize l, usize r)\
    \ {\n        assert(l <= r and r <= internal_size);\n        l += seg_size;\n\
    \        r += seg_size;\n        push(l);\n        push(r);\n        T ret_l =\
    \ M::identity(), ret_r = M::identity();\n        while (l < r) {\n           \
    \ if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n            if (r & 1) ret_r\
    \ = M::operation(data[--r], ret_r);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return M::operation(ret_l, ret_r);\n    }\n\n    template\
    \ <class F> usize max_right(usize l, const F& f) {\n        assert(l <= internal_size);\n\
    \        assert(f(M::identity()));\n        if (l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        for (const usize d : revrep(1, logn + 1)) flush(l\
    \ >> d);\n        T sum = M::identity();\n        do {\n            while (!(l\
    \ & 1)) l >>= 1;\n            if (!f(M::operation(sum, data[l]))) {\n        \
    \        while (l < seg_size) {\n                    flush(l);\n             \
    \       l = 2 * l;\n                    if (f(M::operation(sum, data[l]))) sum\
    \ = M::operation(sum, data[l++]);\n                }\n                return l\
    \ - seg_size;\n            }\n            sum = M::operation(sum, data[l++]);\n\
    \        } while ((l & -l) != l);\n        return internal_size;\n    }\n\n  \
    \  template <class F> usize min_left(usize r, const F& f) {\n        assert(r\
    \ <= internal_size);\n        assert(f(M::identity()));\n        if (r == 0) return\
    \ 0;\n        r += seg_size;\n        for (const usize d : revrep(1, logn + 1))\
    \ flush((r - 1) >> d);\n        T sum = M::identity();\n        do {\n       \
    \     r -= 1;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if\
    \ (!f(M::operation(data[r], sum))) {\n                while (r < seg_size) {\n\
    \                    flush(r);\n                    r = 2 * r + 1;\n         \
    \           if (f(M::operation(data[r], sum))) sum = M::operation(data[r--], sum);\n\
    \                }\n                return r + 1 - seg_size;\n            }\n\
    \            sum = M::operation(data[r], sum);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../bit/bit_rzeros.cpp\"\
    \n#include \"../bit/ceil_log2.cpp\"\n#include \"../utility/int_alias.cpp\"\n#include\
    \ \"../utility/rep.cpp\"\n#include \"../utility/revrep.cpp\"\n\ntemplate <class\
    \ A> class LazySegmentTree {\n    using M = typename A::Monoid;\n    using E =\
    \ typename A::Effector;\n    using T = typename M::Type;\n    using U = typename\
    \ E::Type;\n    usize internal_size, logn, seg_size;\n    std::vector<T> data;\n\
    \    std::vector<U> lazy;\n\n    void fetch(const usize k) { data[k] = M::operation(data[2\
    \ * k], data[2 * k + 1]); }\n    void apply(const usize k, const U& e) {\n   \
    \     data[k] = A::operation(data[k], e);\n        if (k < seg_size) lazy[k] =\
    \ E::operation(lazy[k], e);\n    }\n    void flush(const usize k) {\n        apply(2\
    \ * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n        lazy[k] = E::identity();\n\
    \    }\n\n    void push(const usize k) {\n        for (const usize d : revrep(bit_rzeros(k)\
    \ + 1, logn + 1)) flush(k >> d);\n    }\n    void pull(usize k) {\n        for\
    \ (k >>= bit_rzeros(k); k > 1;) fetch(k >>= 1);\n    }\n\n  public:\n    explicit\
    \ LazySegmentTree(const usize size = 0, const T& value = M::identity())\n    \
    \    : LazySegmentTree(std::vector<T>(size, value)) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& vec) : internal_size(vec.size()) {\n        logn = ceil_log2(internal_size);\n\
    \        seg_size = 1 << logn;\n        data = std::vector<T>(2 * seg_size, M::identity());\n\
    \        lazy = std::vector<U>(seg_size, E::identity());\n        for (const usize\
    \ i : rep(0, internal_size)) data[seg_size + i] = vec[i];\n        for (const\
    \ usize i : revrep(1, seg_size)) fetch(i);\n    }\n\n    usize size() const {\
    \ return internal_size; }\n\n    void assign(usize i, const T& value) {\n    \
    \    assert(i < internal_size);\n        i += seg_size;\n        for (const usize\
    \ d : revrep(1, logn + 1)) flush(i >> d);\n        data[i] = value;\n        for\
    \ (const usize d : rep(1, logn + 1)) fetch(i >> d);\n    }\n    void operate(usize\
    \ l, usize r, const U& e) {\n        assert(l <= r and r <= internal_size);\n\
    \        l += seg_size;\n        r += seg_size;\n        push(l);\n        push(r);\n\
    \        for (usize l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {\n         \
    \   if (l0 & 1) apply(l0++, e);\n            if (r0 & 1) apply(--r0, e);\n   \
    \     }\n        pull(l);\n        pull(r);\n    }\n\n    T fold() const { return\
    \ data[1]; }\n    T fold(usize l, usize r) {\n        assert(l <= r and r <= internal_size);\n\
    \        l += seg_size;\n        r += seg_size;\n        push(l);\n        push(r);\n\
    \        T ret_l = M::identity(), ret_r = M::identity();\n        while (l < r)\
    \ {\n            if (l & 1) ret_l = M::operation(ret_l, data[l++]);\n        \
    \    if (r & 1) ret_r = M::operation(data[--r], ret_r);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return M::operation(ret_l, ret_r);\n\
    \    }\n\n    template <class F> usize max_right(usize l, const F& f) {\n    \
    \    assert(l <= internal_size);\n        assert(f(M::identity()));\n        if\
    \ (l == internal_size) return internal_size;\n        l += seg_size;\n       \
    \ for (const usize d : revrep(1, logn + 1)) flush(l >> d);\n        T sum = M::identity();\n\
    \        do {\n            while (!(l & 1)) l >>= 1;\n            if (!f(M::operation(sum,\
    \ data[l]))) {\n                while (l < seg_size) {\n                    flush(l);\n\
    \                    l = 2 * l;\n                    if (f(M::operation(sum, data[l])))\
    \ sum = M::operation(sum, data[l++]);\n                }\n                return\
    \ l - seg_size;\n            }\n            sum = M::operation(sum, data[l++]);\n\
    \        } while ((l & -l) != l);\n        return internal_size;\n    }\n\n  \
    \  template <class F> usize min_left(usize r, const F& f) {\n        assert(r\
    \ <= internal_size);\n        assert(f(M::identity()));\n        if (r == 0) return\
    \ 0;\n        r += seg_size;\n        for (const usize d : revrep(1, logn + 1))\
    \ flush((r - 1) >> d);\n        T sum = M::identity();\n        do {\n       \
    \     r -= 1;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if\
    \ (!f(M::operation(data[r], sum))) {\n                while (r < seg_size) {\n\
    \                    flush(r);\n                    r = 2 * r + 1;\n         \
    \           if (f(M::operation(data[r], sum))) sum = M::operation(data[r--], sum);\n\
    \                }\n                return r + 1 - seg_size;\n            }\n\
    \            sum = M::operation(data[r], sum);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n};\n"
  dependsOn:
  - bit/bit_rzeros.cpp
  - utility/int_alias.cpp
  - bit/ceil_log2.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: false
  path: container/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/container/lazy_segment_tree.cpp
- /library/container/lazy_segment_tree.cpp.html
title: container/lazy_segment_tree.cpp
---
