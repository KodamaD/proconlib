#pragma once
#include <vector>
#include "../utility/int_alias.cpp"

template <class Cont> std::vector<usize> z_algorithm(const Cont& c) {
    const usize size = c.size();
    std::vector<usize> ret(size);
    ret[0] = size;
    usize i = 1, j = 0;
    while (i < size) {
        while (i + j < size && c[i + j] == c[j]) j += 1;
        ret[i] = j;
        if (j == 0) {
            i += 1;
            continue;
        }
        usize k = 1;
        while (i + k < size && k + ret[k] < j) {
            ret[i + k] = ret[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    return ret;
}
