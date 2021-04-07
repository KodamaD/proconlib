#pragma once
#include "../utility/int_alias.cpp"
#include "../bit/ceil_log2.cpp"
#include <utility>
#include <vector>

template <class F>
class AutoRealloc {
    using R = typename decltype(std::declval<F>()((usize) 0))::value_type;
    F func;
    std::vector<R> data;
public:
    template <class G>
    explicit AutoRealloc(G&& g, const usize capacity = 0): func(std::forward<G>(g)), data() { reserve(capacity); }
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

template <class G>
AutoRealloc(G&&, usize = 0) -> AutoRealloc<std::decay_t<G>>;
