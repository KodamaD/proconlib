#pragma once
#include <functional>
#include <limits>

template <class T> struct MaxMonoid {
    using Type = T;
    static constexpr T identity() { return std::numeric_limits<T>::min(); }
    static constexpr T operation(const T& l, const T& r) { return std::max(l, r); }
};
