#include <iostream>
#include <regex>
#include <string>
#include <set>


int main()
{
    // receipt freind albeit theif receive neighbor

    std::cout << "Enter words: ";

    std::string words;
    std::regex rgx("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::set<std::string> exceptions{"albeit", "being", "neighbor"};
    std::smatch result;

    while (std::getline(std::cin, words))
    {
        for (std::sregex_iterator beginIt(words.begin(), words.end(), rgx), endIt; beginIt != endIt; ++beginIt)
        {
            if (!exceptions.contains(beginIt->str()))
            {
                std::ptrdiff_t pos = beginIt->prefix().length();
                pos = pos > 40 ? pos - 40 : 0;

                std::cout << beginIt->prefix().str().substr(pos)
                          << "\n\t\t>>> " << beginIt->str() << " <<<\n"
                          << beginIt->suffix().str().substr(0, 40) << std::endl;
            }
        }
    }

    return 0;
}
