#pragma once
#include <variant>
#include "../utility/int_alias.cpp"

class subsets {
    struct Iter {
        u64 s, t;
        explicit constexpr Iter(const u64 s, const u64 t) noexcept : s(s), t(t) {}
        constexpr bool operator!=(std::monostate) const noexcept { return ~t != 0; }
        constexpr void operator++() noexcept { t -= 1; }
        constexpr u64 operator*() noexcept { return t &= s; }
    };
    u64 s;

  public:
    explicit constexpr subsets(u64 s) noexcept : s(s) {}
    constexpr Iter begin() const noexcept { return Iter(s, s); }
    constexpr std::monostate end() noexcept { return {}; }
};