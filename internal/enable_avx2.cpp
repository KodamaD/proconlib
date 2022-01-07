#pragma once

#ifdef ENABLE_AVX2
#define TARGET_AVX2 __attribute__((target("avx2")))
#else
#define TARGET_AVX2
#endif