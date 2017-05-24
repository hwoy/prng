#include "minstd.h"

uint32_t minstd_rand0(uint32_t* sd)
{
    return lcg_lehmer(sd, Astd0, Mstd);
}

uint32_t minstd_rand(uint32_t* sd)
{
    return lcg_lehmer(sd, Astd, Mstd);
}
