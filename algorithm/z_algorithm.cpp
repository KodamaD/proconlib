#pragma once
#include <vector>

template <class Cont> std::vector<int> z_algorithm(const Cont& c) {
    const int size = c.size();
    std::vector<int> ret(size);
    ret[0] = size;
    int i = 1, j = 0;
    while (i < size) {
        while (i + j < size && c[i + j] == c[j]) j += 1;
        ret[i] = j;
        if (j == 0) {
            i += 1;
            continue;
        }
        int k = 1;
        while (i + k < size && k + ret[k] < j) {
            ret[i + k] = ret[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    return ret;
}
