#include <iostream>
#include "RandSeq.h"


int main()
{
    std::cout << randomSequence() << std::endl;
    std::cout << randomSequence() << std::endl;

    std::cout << randomSequence(131071) << std::endl;
    std::cout << randomSequence(131071) << std::endl;

    std::cout << randomSequence(10, 99, 131071) << std::endl;
    std::cout << randomSequence(10, 99, 131071) << std::endl;


    return 0;
}
