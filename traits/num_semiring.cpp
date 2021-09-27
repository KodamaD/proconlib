#pragma once

template <class T> struct NumSemiRing {
    using Type = T;
    static constexpr T zero() { return T(0); }
    static constexpr T one() { return T(1); }
    static constexpr T sum(const T& x, const T& y) { return x + y; }
    static constexpr T product(const T& x, const T& y) { return x * y; }
};
