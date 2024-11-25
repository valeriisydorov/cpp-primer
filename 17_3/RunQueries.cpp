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

        TextQuery::TupleResult result = tq.query(s);
        print(std::cout, result) << std::endl;
    }
}

std::ostream& print(std::ostream& os, TextQuery::TupleResult& qr)
{
    const std::string& sought = std::get<0>(qr);
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines = std::get<1>(qr);
    StrBlobPtr temp(std::get<2>(qr));

    os << sought << " occurs " << lines->size() << " time(s)" << std::endl;

    for (std::vector<std::string>::size_type num : *lines)
    {
        for (int i = 0; i != num; ++i)
        {
            temp.incr();
        }

        os << "\t(line " << num + 1 << ") " << temp.deref() << std::endl;
    }

    return os;
}

