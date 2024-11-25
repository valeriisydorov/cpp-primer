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
            ret.push_back(std::make_pair(it - files.cbegin(), std::make_pair(found.first, found.second)));
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
            os << "store " << store.first
               << " sales: " << std::accumulate(store.second.first, store.second.second, Sales_data(s))
               << std::endl;
        }
    }
}
