---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fast_io.test.cpp
    title: test/fast_io.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/fast_io.cpp\"\n#include <cstdio>\n#include <cstring>\n\
    #include <type_traits>\n#include <utility>\n#line 2 \"utility/int_alias.cpp\"\n\
    #include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\
    \n\nclass revrep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { --itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr revrep(const usize first, const usize last) noexcept\n        : first(last\
    \ - 1), last(std::min(first, last) - 1) {}\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 9 \"utility/fast_io.cpp\"\n\nnamespace fast_io {\n\ntemplate <u64 N>\
    \ constexpr u64 TEN = 10 * TEN<N - 1>;\ntemplate <> constexpr u64 TEN<0> = 1;\n\
    \nconstexpr usize BUF_SIZE = 1 << 17;\n\n__attribute__((target(\"avx2\"))) inline\
    \ constexpr usize integer_digits(const u64 n) {\n    if (n >= TEN<10>) {\n   \
    \     if (n >= TEN<15>) {\n            if (n >= TEN<19>) return 20;\n        \
    \    if (n >= TEN<18>) return 19;\n            if (n >= TEN<17>) return 18;\n\
    \            if (n >= TEN<16>) return 17;\n            return 16;\n        } else\
    \ {\n            if (n >= TEN<14>) return 15;\n            if (n >= TEN<13>) return\
    \ 14;\n            if (n >= TEN<12>) return 13;\n            if (n >= TEN<11>)\
    \ return 12;\n            return 11;\n        }\n    } else {\n        if (n >=\
    \ TEN<5>) {\n            if (n >= TEN<9>) return 10;\n            if (n >= TEN<8>)\
    \ return 9;\n            if (n >= TEN<7>) return 8;\n            if (n >= TEN<6>)\
    \ return 7;\n            return 6;\n        } else {\n            if (n >= TEN<4>)\
    \ return 5;\n            if (n >= TEN<3>) return 4;\n            if (n >= TEN<2>)\
    \ return 3;\n            if (n >= TEN<1>) return 2;\n            return 1;\n \
    \       }\n    }\n}\n\nstruct NumBlock {\n    char NUM[40000];\n    constexpr\
    \ NumBlock() : NUM() {\n        for (const usize i : rep(0, 10000)) {\n      \
    \      usize n = i;\n            for (const usize j : revrep(0, 4)) {\n      \
    \          NUM[i * 4 + j] = n % 10 + '0';\n                n /= 10;\n        \
    \    }\n        }\n    }\n} constexpr num_block;\n\nclass Scanner {\n    char\
    \ buf[BUF_SIZE];\n    usize left, right;\n\n    __attribute__((target(\"avx2\"\
    ))) inline void load() {\n        const usize len = right - left;\n        std::memcpy(buf,\
    \ buf + left, len);\n        right = len + std::fread(buf + len, 1, BUF_SIZE -\
    \ len, stdin);\n        left = 0;\n    }\n\n    __attribute__((target(\"avx2\"\
    ))) inline void ignore_spaces() {\n        while (buf[left] <= ' ') {\n      \
    \      if (__builtin_expect(++left == right, 0)) load();\n        }\n    }\n\n\
    \  public:\n    Scanner() : buf(), left(0), right(0) { load(); }\n\n    __attribute__((target(\"\
    avx2\"))) void scan(char& c) {\n        ignore_spaces();\n        c = buf[left++];\n\
    \    }\n\n    template <typename T, std::enable_if_t<std::is_integral_v<T>>* =\
    \ nullptr>\n    __attribute__((target(\"avx2\"))) inline void scan(T& x) {\n \
    \       ignore_spaces();\n        if (__builtin_expect(left + 32 > right, 0))\
    \ load();\n        char c = buf[left++];\n        bool minus = false;\n      \
    \  if constexpr (std::is_signed_v<T>) {\n            if (c == '-') {\n       \
    \         minus = 1;\n                c = buf[left++];\n            }\n      \
    \  }\n        x = 0;\n        while (c >= '0') {\n            x = x * 10 + (c\
    \ & 15);\n            c = buf[left++];\n        }\n        if constexpr (std::is_signed_v<T>)\
    \ {\n            if (minus) x = -x;\n        }\n    }\n\n    template <class T,\
    \ class... Args> __attribute__((target(\"avx2\"))) inline void scan(T& x, Args&...\
    \ args) {\n        scan(x);\n        scan(args...);\n    }\n};\n\nclass Printer\
    \ {\n    char buf[BUF_SIZE];\n    usize pos;\n\n    __attribute__((target(\"avx2\"\
    ))) inline void flush() {\n        std::fwrite(buf, 1, pos, stdout);\n       \
    \ pos = 0;\n    }\n\n  public:\n    Printer() : buf(), pos(0) {}\n    ~Printer()\
    \ { flush(); }\n\n    __attribute__((target(\"avx2\"))) void print(const char\
    \ c) {\n        buf[pos] = c;\n        if (__builtin_expect(++pos == BUF_SIZE,\
    \ 0)) flush();\n    }\n\n    template <typename T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    __attribute__((target(\"avx2\"))) inline void print(T x) {\n\
    \        if (__builtin_expect(pos + 32 > BUF_SIZE, 0)) flush();\n        if (x\
    \ == 0) {\n            buf[pos++] = '0';\n            return;\n        }\n   \
    \     if constexpr (std::is_signed_v<T>) {\n            if (x < 0) {\n       \
    \         buf[pos++] = '-';\n                x = -x;\n            }\n        }\n\
    \        const auto digit = integer_digits(x);\n        usize len = digit;\n \
    \       while (len >= 4) {\n            len -= 4;\n            std::memcpy(buf\
    \ + pos + len, num_block.NUM + (x % 10000) * 4, 4);\n            x /= 10000;\n\
    \        }\n        std::memcpy(buf + pos, num_block.NUM + x * 4 + 4 - len, len);\n\
    \        pos += digit;\n    }\n\n    template <class T, class... Args> __attribute__((target(\"\
    avx2\"))) inline void print(T x, Args&&... args) {\n        print(x);\n      \
    \  print(' ');\n        print(std::forward<Args>(args)...);\n    }\n\n    template\
    \ <class... Args> __attribute__((target(\"avx2\"))) void println(Args&&... args)\
    \ {\n        print(std::forward<Args>(args)...);\n        print('\\n');\n    }\n\
    };\n\n};  // namespace fast_io\n"
  code: "#pragma once\n#include <cstdio>\n#include <cstring>\n#include <type_traits>\n\
    #include <utility>\n#include \"int_alias.cpp\"\n#include \"rep.cpp\"\n#include\
    \ \"revrep.cpp\"\n\nnamespace fast_io {\n\ntemplate <u64 N> constexpr u64 TEN\
    \ = 10 * TEN<N - 1>;\ntemplate <> constexpr u64 TEN<0> = 1;\n\nconstexpr usize\
    \ BUF_SIZE = 1 << 17;\n\n__attribute__((target(\"avx2\"))) inline constexpr usize\
    \ integer_digits(const u64 n) {\n    if (n >= TEN<10>) {\n        if (n >= TEN<15>)\
    \ {\n            if (n >= TEN<19>) return 20;\n            if (n >= TEN<18>) return\
    \ 19;\n            if (n >= TEN<17>) return 18;\n            if (n >= TEN<16>)\
    \ return 17;\n            return 16;\n        } else {\n            if (n >= TEN<14>)\
    \ return 15;\n            if (n >= TEN<13>) return 14;\n            if (n >= TEN<12>)\
    \ return 13;\n            if (n >= TEN<11>) return 12;\n            return 11;\n\
    \        }\n    } else {\n        if (n >= TEN<5>) {\n            if (n >= TEN<9>)\
    \ return 10;\n            if (n >= TEN<8>) return 9;\n            if (n >= TEN<7>)\
    \ return 8;\n            if (n >= TEN<6>) return 7;\n            return 6;\n \
    \       } else {\n            if (n >= TEN<4>) return 5;\n            if (n >=\
    \ TEN<3>) return 4;\n            if (n >= TEN<2>) return 3;\n            if (n\
    \ >= TEN<1>) return 2;\n            return 1;\n        }\n    }\n}\n\nstruct NumBlock\
    \ {\n    char NUM[40000];\n    constexpr NumBlock() : NUM() {\n        for (const\
    \ usize i : rep(0, 10000)) {\n            usize n = i;\n            for (const\
    \ usize j : revrep(0, 4)) {\n                NUM[i * 4 + j] = n % 10 + '0';\n\
    \                n /= 10;\n            }\n        }\n    }\n} constexpr num_block;\n\
    \nclass Scanner {\n    char buf[BUF_SIZE];\n    usize left, right;\n\n    __attribute__((target(\"\
    avx2\"))) inline void load() {\n        const usize len = right - left;\n    \
    \    std::memcpy(buf, buf + left, len);\n        right = len + std::fread(buf\
    \ + len, 1, BUF_SIZE - len, stdin);\n        left = 0;\n    }\n\n    __attribute__((target(\"\
    avx2\"))) inline void ignore_spaces() {\n        while (buf[left] <= ' ') {\n\
    \            if (__builtin_expect(++left == right, 0)) load();\n        }\n  \
    \  }\n\n  public:\n    Scanner() : buf(), left(0), right(0) { load(); }\n\n  \
    \  __attribute__((target(\"avx2\"))) void scan(char& c) {\n        ignore_spaces();\n\
    \        c = buf[left++];\n    }\n\n    template <typename T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    __attribute__((target(\"avx2\"))) inline void scan(T& x) {\n\
    \        ignore_spaces();\n        if (__builtin_expect(left + 32 > right, 0))\
    \ load();\n        char c = buf[left++];\n        bool minus = false;\n      \
    \  if constexpr (std::is_signed_v<T>) {\n            if (c == '-') {\n       \
    \         minus = 1;\n                c = buf[left++];\n            }\n      \
    \  }\n        x = 0;\n        while (c >= '0') {\n            x = x * 10 + (c\
    \ & 15);\n            c = buf[left++];\n        }\n        if constexpr (std::is_signed_v<T>)\
    \ {\n            if (minus) x = -x;\n        }\n    }\n\n    template <class T,\
    \ class... Args> __attribute__((target(\"avx2\"))) inline void scan(T& x, Args&...\
    \ args) {\n        scan(x);\n        scan(args...);\n    }\n};\n\nclass Printer\
    \ {\n    char buf[BUF_SIZE];\n    usize pos;\n\n    __attribute__((target(\"avx2\"\
    ))) inline void flush() {\n        std::fwrite(buf, 1, pos, stdout);\n       \
    \ pos = 0;\n    }\n\n  public:\n    Printer() : buf(), pos(0) {}\n    ~Printer()\
    \ { flush(); }\n\n    __attribute__((target(\"avx2\"))) void print(const char\
    \ c) {\n        buf[pos] = c;\n        if (__builtin_expect(++pos == BUF_SIZE,\
    \ 0)) flush();\n    }\n\n    template <typename T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    __attribute__((target(\"avx2\"))) inline void print(T x) {\n\
    \        if (__builtin_expect(pos + 32 > BUF_SIZE, 0)) flush();\n        if (x\
    \ == 0) {\n            buf[pos++] = '0';\n            return;\n        }\n   \
    \     if constexpr (std::is_signed_v<T>) {\n            if (x < 0) {\n       \
    \         buf[pos++] = '-';\n                x = -x;\n            }\n        }\n\
    \        const auto digit = integer_digits(x);\n        usize len = digit;\n \
    \       while (len >= 4) {\n            len -= 4;\n            std::memcpy(buf\
    \ + pos + len, num_block.NUM + (x % 10000) * 4, 4);\n            x /= 10000;\n\
    \        }\n        std::memcpy(buf + pos, num_block.NUM + x * 4 + 4 - len, len);\n\
    \        pos += digit;\n    }\n\n    template <class T, class... Args> __attribute__((target(\"\
    avx2\"))) inline void print(T x, Args&&... args) {\n        print(x);\n      \
    \  print(' ');\n        print(std::forward<Args>(args)...);\n    }\n\n    template\
    \ <class... Args> __attribute__((target(\"avx2\"))) void println(Args&&... args)\
    \ {\n        print(std::forward<Args>(args)...);\n        print('\\n');\n    }\n\
    };\n\n};  // namespace fast_io\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: false
  path: utility/fast_io.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fast_io.test.cpp
documentation_of: utility/fast_io.cpp
layout: document
redirect_from:
- /library/utility/fast_io.cpp
- /library/utility/fast_io.cpp.html
title: utility/fast_io.cpp
---
