#pragma once
#include "max_monoid.cpp"
#include "sum_group.cpp"

template <class T> struct MaxAddAction {
    using Monoid = MaxMonoid<T>;
    using Effector = SumGroup<T>;
    static constexpr std::optional<T> operation(const std::optional<T>& l, const T& r) {
        if (!l) return std::nullopt;
        return std::optional<T>(std::in_place, *l + r);
    }
};