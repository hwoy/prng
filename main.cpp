#include "mt19937_64.h"
#include <iostream>
#include <random>

int main(void)
{
    struct mt19937_64 mt;
    mt19937_seed64(&mt, 1);

    for (unsigned int i = 0; i < 5; ++i)
        std::cout << mt19937_extract64(&mt) << std::endl;

    std::cout << "************************************\n";
    std::mt19937_64 gen(1);
    for (unsigned int i = 0; i < 5; ++i)
        std::cout << gen() << std::endl;
    return 0;
}
