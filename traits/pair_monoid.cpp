#pragma once
#include <utility>

template <class M, class N> struct PairMonoid {
    using Type = std::pair<typename M::Type, typename N::Type>;
    static constexpr Type identity() { return {M::identity(), N::identity()}; }
    static constexpr Type operation(const Type& l, const Type& r) {
        return {M::operation(l.first, r.first), N::operation(l.second, r.second)};
    }
};
