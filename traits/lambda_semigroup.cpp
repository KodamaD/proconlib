#pragma once
#include <memory>
#include <utility>

template <class F> class LambdaSemiGroup {
    template <class> struct GetArg;
    template <class C, class T> struct GetArg<T (C::*)(T, T) const> { using Type = T; };

    static inline std::unique_ptr<F> OP;

  public:
    using Type = typename GetArg<decltype(&F::operator())>::Type;
    static constexpr Type operation(const Type& l, const Type& r) {
        assert(OP);
        return OP->operator()(l, r);
    }
    explicit constexpr LambdaSemiGroup(F&& f) { OP = std::make_unique<F>(std::move(f)); }
};

template <class F> decltype(auto) lambda_semigroup(F&& f) { return LambdaSemiGroup<F>(std::move(f)); }
