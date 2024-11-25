#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "Valid.h"
#include "PersonInfo.h"


using std::ifstream;
using std::istringstream;


int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(phone);
    std::string fmt = "$2.$5.$7";
    std::smatch m;

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream data("../data.txt");

    while (getline(data, line))
    {
        PersonInfo info;
        record.str(line);
        record.clear();
        record >> info.name;
        while (record >> word)
        {
            for (std::sregex_iterator beginIt(word.begin(), word.end(), r), endIt; beginIt != endIt; ++beginIt)
            {
                if (valid(*beginIt))
                {
                    info.phones.push_back(word);
                }
            }
        }
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        std::ostringstream numbers;
        for (const auto &nums : entry.phones)
        {
            numbers << " " << nums;
        }
        std::cout << entry.name << ":" << std::regex_replace(numbers.str(), r, fmt) << std::endl;
    }

    return 0;
}
