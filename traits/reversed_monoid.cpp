#pragma once

template <class M> struct ReversedMonoid {
    using Type = typename M::Type;
    static constexpr Type identity() { return M::identity(); }
    static constexpr Type operation(const Type& l, const Type& r) { return M::operation(r, l); }
};
