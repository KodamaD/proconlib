#pragma once

template <class T> struct Affine {
    T a, b;
    constexpr Affine(const T& a = 1, const T& b = 0) : a(a), b(b) {}
    constexpr T eval(const T& x) const { return a * x + b; }
    constexpr Affine operator+(const Affine& other) const { return affine(a + other.a, b + other.b); }
    constexpr Affine composite(const Affine& other) const { return Affine(a * other.a, b * other.a + other.b); }
};

template <class T> struct AffineCompositeMonoid {
    using Type = Affine<T>;
    static constexpr Type identity() { return Type(); }
    static constexpr Type operation(const Type& l, const Type& r) noexcept { return l.composite(r); }
};
