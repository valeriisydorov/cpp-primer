#include "FindAndReport.h"


#include <algorithm>
#include <numeric>


vector<matches> findBook(const stores& files, const string& book)
{
    vector<matches> ret;

    for (stores::const_iterator it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);

        if (found.first != found.second)
        {
            ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
        }
    }

    return ret;
}

void reportResult(std::istream& in, std::ostream& os, const stores& files)
{
    string s;
    while (in >> s)
    {
        vector<matches> trans = findBook(files, s);
        if (trans.empty())
        {
            std::cout << s << " not found in any stores" << std::endl;
        }

        for (const auto& store : trans)
        {
            os << "store " << std::get<0>(store)
               << " sales: " << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s))
               << std::endl;
        }
    }
}
