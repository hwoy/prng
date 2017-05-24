#ifndef _MINSTD_H_
#define _MINSTD_H_

#include "lcg.h"

#define Astd0 16807
#define Cstd 0
#define Mstd 2147483647U

#define Astd 48271

uint32_t minstd_rand0(uint32_t* sd);

uint32_t minstd_rand(uint32_t* sd);

#endif
