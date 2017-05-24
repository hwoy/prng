#include <stdint.h>

uint32_t xorshift32(uint32_t* sd)
{
    uint32_t x = *sd;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *sd = x;
    return x;
}
