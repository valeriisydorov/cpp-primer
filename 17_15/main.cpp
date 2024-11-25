#include <iostream>
#include <regex>
#include <string>


int main()
{
    std::cout << "Enter a word: ";

    std::string word;
    while (std::cin >> word)
    {
        std::regex rgx("[[:alpha:]]*[^c]ei[[:alpha:]]*");

        if (!std::regex_match(word, rgx))
        {
            std::cout << "The word matches the rule." << std::endl;
        }
        else
        {
            std::cout << "The word does not match the rule." << std::endl;
        }
    }

    return 0;
}
