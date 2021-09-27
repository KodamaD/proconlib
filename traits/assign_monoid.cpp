#pragma once
#include <optional>

template <class T> struct AssignMonoid {
    using Type = std::optional<T>;
    static constexpr Type identity() { return std::nullopt; }
    static constexpr Type operation(const Type& l, const Type& r) { return r ? r : l; }
};
