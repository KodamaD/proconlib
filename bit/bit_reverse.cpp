#pragma once
#include "../utility/int_alias.cpp"

constexpr u64 bit_reverse(u64 x) {
    x = ((x >> 1) & 0x5555555555555555) | ((x & 0x5555555555555555) << 1);
    x = ((x >> 2) & 0x3333333333333333) | ((x & 0x3333333333333333) << 2);
    x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);
    x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x & 0x00FF00FF00FF00FF) << 8);
    x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x & 0x0000FFFF0000FFFF) << 16);
    x = (x >> 32) | (x << 32);
    return x;
}