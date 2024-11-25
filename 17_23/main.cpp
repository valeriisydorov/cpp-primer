#include <iostream>
#include <regex>
#include <string>


int main()
{
    std::string prompt = "Enter a ZIP Code: ";
    std::cout << prompt;

    std::regex rgx("^(\\d{5})(-(\\d{4}))?$");

    std::string code;
    while (std::cin >> code)
    {
        if (code == "exit")
        {
            break;
        }

        if (std::regex_match(code, rgx))
        {
            std::cout << "The ZIP Code matches the rule." << std::endl;
        }
        else
        {
            std::cout << "The ZIP Code does not match the rule." << std::endl;
        }

        std::cout << prompt;
    }

    return 0;
}