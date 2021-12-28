#pragma once
#include <cassert>
#include <utility>
#include <variant>

template <class T> class Factorizer {
    struct Iter {
        T s, t;
        explicit constexpr Iter(const T& s, const T& t) noexcept : s(s), t(t) {}
        constexpr bool operator!=(std::monostate) const noexcept { return s != 1; }
        constexpr void operator++() noexcept { t += 1; }
        constexpr std::pair<T, int> operator*() noexcept {
            while (s % t != 0) {
                if (t * t > s) {
                    const T u = s;
                    s = 1;
                    return {u, 1};
                }
                t += 1;
            }
            int e = 0;
            while (s % t == 0) {
                e += 1;
                s /= t;
            }
            return {t, e};
        }
    };
    T x;

  public:
    explicit constexpr Factorizer(const T& x) noexcept : x(x) { assert(x > 0); }
    constexpr Iter begin() const noexcept { return Iter(x, 2); }
    constexpr std::monostate end() noexcept { return {}; }
};

template <class T> constexpr Factorizer<T> factorize_iter(const T& x) noexcept { return Factorizer<T>(x); }