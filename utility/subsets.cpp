#pragma once
#include <variant>
#include "int_alias.cpp"

class SubsetScanner {
    struct Iter {
        u64 s, t;
        explicit constexpr Iter(const u64 s, const u64 t) noexcept : s(s), t(t) {}
        constexpr bool operator!=(std::monostate) const noexcept { return ~t != 0; }
        constexpr void operator++() noexcept { t -= 1; }
        constexpr u64 operator*() noexcept { return t &= s; }
    };
    u64 s;

  public:
    explicit constexpr SubsetScanner(u64 s) noexcept : s(s) {}
    constexpr Iter begin() const noexcept { return Iter(s, s); }
    constexpr std::monostate end() const noexcept { return {}; }
};

constexpr SubsetScanner subsets(const u64 set) noexcept { return SubsetScanner(set); }