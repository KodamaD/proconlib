#pragma once
#include <cstdio>
#include <cstring>
#include <type_traits>
#include <utility>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

namespace fast_io {

template <u64 N> constexpr u64 TEN = 10 * TEN<N - 1>;
template <> constexpr u64 TEN<0> = 1;

constexpr usize BUF_SIZE = 1 << 17;

__attribute__((target("avx2"))) inline constexpr usize integer_digits(const u64 n) {
    if (n >= TEN<10>) {
        if (n >= TEN<15>) {
            if (n >= TEN<19>) return 20;
            if (n >= TEN<18>) return 19;
            if (n >= TEN<17>) return 18;
            if (n >= TEN<16>) return 17;
            return 16;
        } else {
            if (n >= TEN<14>) return 15;
            if (n >= TEN<13>) return 14;
            if (n >= TEN<12>) return 13;
            if (n >= TEN<11>) return 12;
            return 11;
        }
    } else {
        if (n >= TEN<5>) {
            if (n >= TEN<9>) return 10;
            if (n >= TEN<8>) return 9;
            if (n >= TEN<7>) return 8;
            if (n >= TEN<6>) return 7;
            return 6;
        } else {
            if (n >= TEN<4>) return 5;
            if (n >= TEN<3>) return 4;
            if (n >= TEN<2>) return 3;
            if (n >= TEN<1>) return 2;
            return 1;
        }
    }
}

struct NumBlock {
    char NUM[40000];
    constexpr NumBlock() : NUM() {
        for (const usize i : rep(0, 10000)) {
            usize n = i;
            for (const usize j : revrep(0, 4)) {
                NUM[i * 4 + j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
} constexpr num_block;

class Scanner {
    char buf[BUF_SIZE];
    usize left, right;

    __attribute__((target("avx2"))) inline void load() {
        const usize len = right - left;
        std::memcpy(buf, buf + left, len);
        right = len + std::fread(buf + len, 1, BUF_SIZE - len, stdin);
        left = 0;
    }

    __attribute__((target("avx2"))) inline void ignore_spaces() {
        while (buf[left] <= ' ') {
            if (__builtin_expect(++left == right, 0)) load();
        }
    }

  public:
    Scanner() : buf(), left(0), right(0) { load(); }

    __attribute__((target("avx2"))) void scan(char& c) {
        ignore_spaces();
        c = buf[left++];
    }

    template <typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
    __attribute__((target("avx2"))) inline void scan(T& x) {
        ignore_spaces();
        if (__builtin_expect(left + 32 > right, 0)) load();
        char c = buf[left++];
        bool minus = false;
        if constexpr (std::is_signed_v<T>) {
            if (c == '-') {
                minus = 1;
                c = buf[left++];
            }
        }
        x = 0;
        while (c >= '0') {
            x = x * 10 + (c & 15);
            c = buf[left++];
        }
        if constexpr (std::is_signed_v<T>) {
            if (minus) x = -x;
        }
    }

    template <class T, class... Args> __attribute__((target("avx2"))) inline void scan(T& x, Args&... args) {
        scan(x);
        scan(args...);
    }
};

class Printer {
    char buf[BUF_SIZE];
    usize pos;

    __attribute__((target("avx2"))) inline void flush() {
        std::fwrite(buf, 1, pos, stdout);
        pos = 0;
    }

  public:
    Printer() : buf(), pos(0) {}
    ~Printer() { flush(); }

    __attribute__((target("avx2"))) void print(const char c) {
        buf[pos] = c;
        if (__builtin_expect(++pos == BUF_SIZE, 0)) flush();
    }

    template <typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
    __attribute__((target("avx2"))) inline void print(T x) {
        if (__builtin_expect(pos + 32 > BUF_SIZE, 0)) flush();
        if (x == 0) {
            buf[pos++] = '0';
            return;
        }
        if constexpr (std::is_signed_v<T>) {
            if (x < 0) {
                buf[pos++] = '-';
                x = -x;
            }
        }
        const auto digit = integer_digits(x);
        usize len = digit;
        while (len >= 4) {
            len -= 4;
            std::memcpy(buf + pos + len, num_block.NUM + (x % 10000) * 4, 4);
            x /= 10000;
        }
        std::memcpy(buf + pos, num_block.NUM + x * 4 + 4 - len, len);
        pos += digit;
    }

    template <class T, class... Args> __attribute__((target("avx2"))) inline void print(T x, Args&&... args) {
        print(x);
        print(' ');
        print(std::forward<Args>(args)...);
    }

    template <class... Args> __attribute__((target("avx2"))) void println(Args&&... args) {
        print(std::forward<Args>(args)...);
        print('\n');
    }
};

};  // namespace fast_io
