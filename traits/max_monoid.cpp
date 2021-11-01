#pragma once
#include <algorithm>
#include "../traits/optional_monoid.cpp"

template <class T> struct MaxSemiGroup {
    using Type = T;
    static constexpr T operation(const T& l, const T& r) { return std::max(l, r); }
};

template <class T> using MaxMonoid = OptionalMonoid<MaxSemiGroup<T>>;