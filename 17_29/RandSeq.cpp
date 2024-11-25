#include "RandSeq.h"
#include <random>


unsigned randomSequence()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> u;

    return u(e);
}

unsigned randomSequence(unsigned start)
{
    static std::default_random_engine e(start);
    static std::uniform_int_distribution<unsigned> u;

    return u(e);
}