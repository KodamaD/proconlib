#pragma once
#include <cassert>

class IndexOffset {
    int offset, len;

  public:
    constexpr IndexOffset() noexcept : offset(), len() {}
    explicit constexpr IndexOffset(const int o, const int l) noexcept : offset(o), len(l) {}
    constexpr int size() const { return len; }
    constexpr int operator[](const int i) const noexcept {
        assert(i < len);
        return offset + i;
    }
    constexpr int to_idx(const int i) const noexcept {
        assert(offset <= i and i < offset + len);
        return i - offset;
    }
};
