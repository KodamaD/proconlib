#pragma once
#include <optional>
#include <utility>

template <class S> struct OptionalMonoid {
    using Type = std::optional<typename S::Type>;
    static constexpr Type identity() { return std::nullopt; }
    static constexpr Type operation(const Type& l, const Type& r) {
        if (!l) return r;
        if (!r) return l;
        return Type(std::in_place, S::operation(*l, *r));
    }
};