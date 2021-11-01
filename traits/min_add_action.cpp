#pragma once
#include "../traits/min_monoid.cpp"
#include "../traits/plus_monoid.cpp"

template <class T> struct MinAddAction {
    using Monoid = MinMonoid<T>;
    using Effector = PlusMonoid<T>;
    static constexpr std::optional<T> operation(const std::optional<T>& l, const T& r) {
        if (!l) return std::nullopt;
        return std::optional<T>(std::in_place, *l + r);
    }
};