#pragma once

template <class T> struct PlusMonoid {
    using Type = T;
    static constexpr T identity() { return T(0); }
    static constexpr T operation(const T& l, const T& r) { return l + r; }
};
