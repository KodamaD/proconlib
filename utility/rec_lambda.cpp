#pragma once
#include <utility>

template <class F>
struct RecLambda: private F {
    explicit constexpr RecLambda(F&& f): F(std::forward<F>(f)) { }
    template <class... Args>
    constexpr decltype(auto) operator () (Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
