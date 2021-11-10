#pragma once
#include <cassert>
#include "int_alias.cpp"

class IndexOffset {
    usize offset, len;

  public:
    explicit constexpr IndexOffset(const usize o, const usize l) noexcept : offset(o), len(l) {}
    constexpr usize size() const { return len; }
    constexpr usize operator[](const usize i) const noexcept {
        assert(i < len);
        return offset + i;
    }
    constexpr usize to_idx(const usize i) const noexcept {
        assert(offset <= i and i < offset + len);
        return i - offset;
    }
};
