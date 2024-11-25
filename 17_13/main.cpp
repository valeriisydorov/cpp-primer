#include "Test.h"
#include <iostream>


int main()
{
    Test userAnswers;

    userAnswers.changeResult(0, true);
    userAnswers.changeResult(1, false);
    userAnswers.changeResult(2, true);
    userAnswers.changeResult(3, true);
    userAnswers.changeResult(4, true);
    userAnswers.changeResult(5, false);
    userAnswers.changeResult(6, false);
    userAnswers.changeResult(7, false);
    userAnswers.changeResult(8, false);
    userAnswers.changeResult(9, true);

    unsigned int controlAnswers = 0b1010110101;

    unsigned int result = userAnswers.answers ^ controlAnswers;

    unsigned int matches = 0;
    for (std::size_t i = 0; i != 10; ++i)
    {
        std::cout << "Answer " << i + 1;
        if ((result & (1 << i)) == 0)
        {
            ++matches;
            std::cout << " is correct";
        }
        else
        {
            std::cout << " is incorrect";
        }
        std::cout << std::endl;
    }

    std::cout << "Number of matches: " << matches << std::endl;

    return 0;
}
