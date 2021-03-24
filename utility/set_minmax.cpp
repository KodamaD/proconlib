#pragma once

template <class T>
bool setmin(T& lhs, const T& rhs) {
    if (lhs > rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}

template <class T>
bool setmax(T& lhs, const T& rhs) {
    if (lhs < rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}
