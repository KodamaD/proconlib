#pragma once
#include "affine_composite_monoid.cpp"
#include "pair_monoid.cpp"
#include "plus_monoid.cpp"

template <class T> struct SumAffineAction {
    using Monoid = PairMonoid<PlusMonoid<T>, PlusMonoid<T>>;
    using Effector = AffineCompositeMonoid<T>;
    static constexpr std::pair<T, T> operation(const std::pair<T, T>& m, const Affine<T>& e) {
        return {e.a * m.first + e.b * m.second, m.second};
    }
};