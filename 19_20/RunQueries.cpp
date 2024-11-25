#include "RunQueries.h"


void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);

    while (true)
    {
        std::cout << "enter word to lock for, or q to quit: ";

        std::string s;
        if (!(std::cin >> s) || s == "q")
        {
            break;
        }

        print(std::cout, tq.query(s)) << std::endl;
    }
}