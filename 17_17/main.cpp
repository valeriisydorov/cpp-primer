#include <iostream>
#include <regex>
#include <string>


int main()
{
    // receipt freind theif receive
    
    std::cout << "Enter words: ";

    std::string words;
    std::regex rgx("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::smatch result;
    
    while (std::getline(std::cin, words))
    {
        for (std::sregex_iterator beginIt(words.begin(), words.end(), rgx), endIt; beginIt != endIt; ++beginIt) 
        {
            std::ptrdiff_t pos = beginIt->prefix().length();
            pos = pos > 40 ? pos - 40 : 0;
            
            std::cout << beginIt->prefix().str().substr(pos)
                      << "\n\t\t>>> " << beginIt->str() << " <<<\n"
                      << beginIt->suffix().str().substr(0, 40) << std::endl;
        }
    }

    return 0;
}
