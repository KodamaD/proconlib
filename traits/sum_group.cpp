#pragma once

template <class T> struct SumGroup {
    using Type = T;
    static constexpr T identity() { return T(0); }
    static constexpr T operation(const T& l, const T& r) { return l + r; }
    static constexpr T inverse(const T& x) { return -x; }
};
