#pragma once
#include "sum_group.cpp"
#include "product_monoid.cpp"

template <class T> struct NumRing {
    using Type = T;
    using Sum = SumGroup<T>;
    using Product = ProductMonoid<T>;
};