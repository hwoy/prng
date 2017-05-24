#include <stdint.h>

void mersenne_twister_engine_seed32(uint32_t* mt, uint16_t* index, uint32_t _N_, uint32_t seed, uint32_t _F_, uint64_t _W_)
{
    uint32_t i;

    mt[0] = seed;

    for (i = 1; i < _N_; i++) {
        mt[i] = (_F_ * (mt[i - 1] ^ (mt[i - 1] >> (_W_ - 2))) + i);
    }

    *index = _N_;
}

static void mersenne_twister_engine_twist32(uint32_t* mt, uint16_t* index, uint32_t _N_, uint32_t _A_, uint32_t _M_, uint32_t _R_)
{
    uint32_t i, x, xA;
    const uint64_t MASK_UPPER = (1ull << _R_);
    const uint64_t MASK_LOWER = (1ull << _R_) - 1;

    for (i = 0; i < _N_; i++) {
        x = (mt[i] & MASK_UPPER) + (mt[(i + 1) % _N_] & MASK_LOWER);

        xA = x >> 1;

        if (x & 0x1)
            xA ^= _A_;

        mt[i] = mt[(i + _M_) % _N_] ^ xA;
    }

    *index = 0;
}

uint32_t mersenne_twister_engine_extract32(uint32_t* mt, uint16_t* index, uint32_t _N_, uint32_t _A_, uint32_t _M_, uint32_t _R_, uint32_t _U_, uint32_t _S_, uint32_t _B_, uint32_t _T_, uint32_t _C_, uint32_t _L_, uint32_t _D_)
{
    uint32_t y;
    int i = *index;

    if (*index >= _N_) {
        mersenne_twister_engine_twist32(mt, index, _N_, _A_, _M_, _R_);
        i = *index;
    }

    y = mt[i];
    *index = i + 1;

    y ^= (mt[i] >> _U_) & _D_;
    y ^= (y << _S_) & _B_;
    y ^= (y << _T_) & _C_;
    y ^= (y >> _L_);

    return y;
}

#define W32 32U
#define N32 624U
#define M32 397U
#define R32 31U
#define A32 0x9908B0DFU

#define F32 1812433253U

#define U32 11U
#define D32 0xFFFFFFFFU

#define S32 7U
#define B32 0x9D2C5680U

#define T32 15U
#define C32 0xEFC60000U

#define L32 18U

struct mt19937 {
    uint32_t mt[N32];
    uint16_t index;
};

void mt19937_seed32(struct mt19937* gen, uint32_t seed)
{
    mersenne_twister_engine_seed32(gen->mt, &gen->index, N32, seed, F32, W32);
}

uint32_t mt19937_extract32(struct mt19937* gen)
{
    return mersenne_twister_engine_extract32(gen->mt, &gen->index, N32, A32, M32, R32, U32, S32, B32, T32, C32, L32, D32);
}
