#ifndef _LCG_H_
#define _LCG_H_

#include <stdint.h>

uint32_t lcg_lehmer(uint32_t* sd, uint32_t a, uint32_t m);

uint32_t lcg(uint32_t* sd, uint32_t a, uint32_t c, uint32_t m);

uint32_t lcg_glibc(uint32_t* sd);

uint32_t lcg_ms(uint32_t* sd);

#endif
