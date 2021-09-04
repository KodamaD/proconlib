#pragma once

template <class T> struct NumSemiRing {
    T val;
    constexpr NumSemiRing() = default;
    constexpr NumSemiRing(const T& val) : val(val) {}
    static constexpr NumSemiRing zero() { return T(0); }
    static constexpr NumSemiRing one() { return T(1); }
    constexpr NumSemiRing operator+(const NumSemiRing& other) const { return val + other.val; }
    constexpr NumSemiRing operator*(const NumSemiRing& other) const { return val * other.val; }
};
