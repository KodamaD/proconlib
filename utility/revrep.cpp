#pragma once
#include <algorithm>

class ReversedRange {
    struct Iter {
        int itr;
        constexpr Iter(const int pos) noexcept : itr(pos) {}
        constexpr void operator++() noexcept { --itr; }
        constexpr bool operator!=(const Iter& other) const noexcept { return itr != other.itr; }
        constexpr int operator*() const noexcept { return itr; }
    };
    const Iter first, last;

  public:
    explicit constexpr ReversedRange(const int first, const int last) noexcept
        : first(last - 1), last(std::min(first, last) - 1) {}
    constexpr Iter begin() const noexcept { return first; }
    constexpr Iter end() const noexcept { return last; }
};

constexpr ReversedRange revrep(const int l, const int r) noexcept { return ReversedRange(l, r); }
constexpr ReversedRange revrep(const int n) noexcept { return ReversedRange(0, n); }