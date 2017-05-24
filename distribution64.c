
#include "distribution64.h"

uint64_t uniform_int_distribution64(uint64_t val, uint64_t a, uint64_t b)
{
    return a > b ? 0 : (val % (b - a + 1)) + a;
}
