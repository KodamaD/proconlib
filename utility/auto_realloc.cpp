#pragma once
#include <utility>
#include <vector>
#include "ceil_log2.cpp"
#include "int_alias.cpp"

template <class F> class AutoReallocation {
    using R = typename decltype(std::declval<F>()(0))::value_type;

    F func;
    mutable std::vector<R> data;

  public:
    explicit AutoReallocation(F&& f) : func(std::forward<F>(f)), data() {}

    void reserve(const int size) const {
        if ((int)data.size() < size) data = func(((int)1 << ceil_log2(size)));
    }
    R operator[](const int i) const {
        assert(i >= 0);
        reserve(i + 1);
        return data[i];
    }
};

template <class F> decltype(auto) auto_realloc(F&& f) { return AutoReallocation<F>(std::forward<F>(f)); }
