#pragma once
#include "../utility/int_alias.cpp"

class BarretReduction {
    u32 mod;
    u64 near_inv;

  public:
    explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1) / mod + 1) {}
    constexpr u32 product(const u32 a, const u32 b) const noexcept {
        const u64 z = (u64)a * b;
        const u64 x = ((u128)z * near_inv) >> 64;
        const u32 v = z - x * mod;
        return v < mod ? v : v + mod;
    }
    constexpr u32 get_mod() const noexcept { return mod; }
};