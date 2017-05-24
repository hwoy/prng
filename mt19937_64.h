#include <stdint.h>

void mersenne_twister_engine_seed64(uint64_t* mt, uint16_t* index, uint64_t _N_, uint64_t seed, uint64_t _F_, uint64_t _W_)
{
    uint32_t i;

    mt[0] = seed;

    for (i = 1; i < _N_; i++) {
        mt[i] = (_F_ * (mt[i - 1] ^ (mt[i - 1] >> (_W_ - 2))) + i);
    }

    *index = _N_;
}

static void mersenne_twister_engine_twist64(uint64_t* mt, uint16_t* index, uint64_t _N_, uint64_t _A_, uint64_t _M_, uint64_t _R_)
{
    uint64_t x, xA;
    uint32_t i;
    const uint64_t MASK_LOWER = 0x7FFFFFFF;
    const uint64_t MASK_UPPER = ~MASK_LOWER;

    for (i = 0; i < _N_; i++) {
        x = (mt[i] & MASK_UPPER) + (mt[(i + 1) % _N_] & MASK_LOWER);

        xA = x >> 1;

        if (x & 0x1)
            xA ^= _A_;

        mt[i] = mt[(i + _M_) % _N_] ^ xA;
    }

    *index = 0;
}

uint64_t mersenne_twister_engine_extract64(uint64_t* mt, uint16_t* index, uint64_t _N_, uint64_t _A_, uint64_t _M_, uint64_t _R_, uint64_t _U_, uint64_t _S_, uint64_t _B_, uint64_t _T_, uint64_t _C_, uint64_t _L_, uint64_t _D_)
{
    uint64_t y;
    int i = *index;

    if (*index >= _N_) {
        mersenne_twister_engine_twist64(mt, index, _N_, _A_, _M_, _R_);
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

#define W64 64U
#define N64 312U
#define M64 156U
#define R64 31U
#define A64 0xb5026f5aa96619e9ULL

#define F64 6364136223846793005ULL

#define U64 29U
#define D64 0x5555555555555555ULL

#define S64 17U
#define B64 0x71d67fffeda60000U

#define T64 37U
#define C64 0xfff7eee000000000U

#define L64 43U

struct mt19937_64 {
    uint64_t mt[N64];
    uint16_t index;
};

void mt19937_seed64(struct mt19937_64* gen, uint64_t seed)
{
    mersenne_twister_engine_seed64(gen->mt, &gen->index, N64, seed, F64, W64);
}

uint64_t mt19937_extract64(struct mt19937_64* gen)
{
    return mersenne_twister_engine_extract64(gen->mt, &gen->index, N64, A64, M64, R64, U64, S64, B64, T64, C64, L64, D64);
}
