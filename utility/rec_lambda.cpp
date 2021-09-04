#pragma once
#include <type_traits>
#include <utility>

template <class F> struct RecursiveLambda : private F {
    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}
    template <class... Args> constexpr decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};

template <class F> constexpr decltype(auto) rec_lambda(F&& f) {
    using G = std::decay_t<F>;
    return RecursiveLambda<G>(std::forward<G>(f));
}
