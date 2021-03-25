#pragma once
#include "../utility/int_alias.cpp"
#include "../bit/ceil_log2.cpp"
#include <utility>
#include <vector>

template <class F>
class AutoRealloc {
    using R = typename decltype(std::declval<F>().operator()(std::declval<usize>()))::value_type;
    F func;
    std::vector<R> data;
public:
    explicit AutoRealloc(F&& func): func(std::forward<F>(func)), data() { }
    explicit AutoRealloc(F&& func, const usize capacity): func(std::forward<F>(func)) { reserve(capacity); }
    void reserve(const usize size) {
        if (data.size() < size) {
            const usize pow2 = ((usize) 1 << ceil_log2(size));
            data = func(pow2);
        }
    }
    R operator [] (const usize i) {
        reserve(i + 1);
        return data[i];
    }
};
