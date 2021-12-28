#pragma once

template <class T> struct ProductMonoid {
    using Type = T;
    static constexpr T identity() { return T(1); }
    static constexpr T operation(const T& l, const T& r) { return l * r; }
};
