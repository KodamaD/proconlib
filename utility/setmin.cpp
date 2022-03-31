#pragma once

template <class T> constexpr bool setmin(T& lhs, const T& rhs) {
    if (lhs > rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}
