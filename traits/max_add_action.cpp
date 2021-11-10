#pragma once
#include "max_monoid.cpp"
#include "plus_monoid.cpp"

template <class T> struct MaxAddAction {
    using Monoid = MaxMonoid<T>;
    using Effector = PlusMonoid<T>;
    static constexpr std::optional<T> operation(const std::optional<T>& l, const T& r) {
        if (!l) return std::nullopt;
        return std::optional<T>(std::in_place, *l + r);
    }
};