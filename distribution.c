
#include "distribution.h"

uint32_t uniform_int_distribution32(uint32_t val, uint32_t a, uint32_t b)
{
    return a > b ? 0 : (val % (b - a + 1)) + a;
}
