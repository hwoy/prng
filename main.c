#include "distribution.h"
#include "minstd.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int i;
    uint32_t seed = 2;
    for (i = 0; i < 5; ++i)
        printf("%u\n", lcg_ms(&seed));

    printf("***************************\n");
    srand(2);
    for (i = 0; i < 5; ++i)
        printf("%u\n", rand());
    return 0;
}
