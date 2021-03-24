#pragma once
#include "int_alias.cpp"
#include <algorithm>

class revrep {
    struct Iter {
        usize itr;
        constexpr Iter(const usize pos) noexcept: itr(pos) { }
        constexpr void operator ++ () noexcept { --itr; }
        constexpr bool operator != (const Iter &other) const noexcept { return itr != other.itr; }
        constexpr usize operator * () const noexcept { return itr; }
    };
    const Iter first, last;
public:
    explicit constexpr revrep(const usize first, const usize last) noexcept: first(last - 1), last(std::min(first, last) - 1) { }
    constexpr Iter begin() const noexcept { return first; }
    constexpr Iter end() const noexcept { return last; }
};