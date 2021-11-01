#pragma once
#include <algorithm>
#include "../traits/optional_monoid.cpp"

template <class T> struct MinSemiGroup {
    using Type = T;
    static constexpr T operation(const T& l, const T& r) { return std::min(l, r); }
};

template <class T> using MinMonoid = OptionalMonoid<MinSemiGroup<T>>;