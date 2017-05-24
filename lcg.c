#include "lcg.h"

uint32_t lcg_lehmer(uint32_t* sd, uint32_t a, uint32_t m)
{
    uint32_t hi;
    uint32_t lo;

    hi = *sd / (m / a);
    lo = *sd % (m / a);

    *sd = a * lo - (m % a) * hi;

    return (int32_t)*sd <= 0 ? *sd += m : *sd;
}

uint32_t lcg(uint32_t* sd, uint32_t a, uint32_t c, uint32_t m)
{
    return *sd = (*sd * a + c) & m;
}

uint32_t lcg_glibc(uint32_t* sd)
{
    return lcg(sd, 1103515245, 12345, (1U << 31) - 1);
}

uint32_t lcg_ms(uint32_t* sd)
{
    return lcg(sd, 214013, 2531011, (1U << 31) - 1) >> 16;
}
