#include "RandSeq.h"


unsigned randomSequence(unsigned start)
{
    static std::default_random_engine e(start);
    static std::uniform_int_distribution<unsigned> u;

    return u(e);
}

unsigned randomSequence(unsigned min, unsigned max, unsigned start)
{
    static std::default_random_engine e(start);
    static std::uniform_int_distribution<unsigned> u(min, max);

    return u(e);
}