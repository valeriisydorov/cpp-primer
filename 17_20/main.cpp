#include <iostream>
#include <string>
#include <regex>
#include "Valid.h"


int main()
{
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    std::regex r(phone);
    std::smatch m;

    std::string s;
    while (std::getline(std::cin, s))
    {
        for (std::sregex_iterator beginIt(s.begin(), s.end(), r), endIt; beginIt != endIt; ++beginIt)
        {
            if (valid(*beginIt))
            {
                std::cout << "valid: " << beginIt->str() << std::endl;
            }
            else
            {
                std::cout << "not valid: " << beginIt->str() << std::endl;
            }
        }
    }

    return 0;
}
