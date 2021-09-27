#pragma once
#include <functional>
#include <limits>

template <class T> struct MinMonoid {
    using Type = T;
    static constexpr T identity() { return std::numeric_limits<T>::max(); }
    static constexpr T operation(const T& l, const T& r) { return std::min(l, r); }
};
