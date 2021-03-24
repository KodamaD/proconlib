#pragma once
#include <utility>

template <class Func>
struct RecLambda: private Func {
    explicit constexpr RecLambda(Func &&func): Func(std::forward<Func>(func)) { }
    template <class... Args>
    constexpr decltype(auto) operator () (Args&&... args) const {
        return Func::operator()(*this, std::forward<Args>(args)...);
    }
};
