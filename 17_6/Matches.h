#pragma once


#include "Sales_data.h"
#include <vector>


using std::vector;


struct Matches
{
    using store = vector<Sales_data>;
    using size_type = store::size_type;
    using const_iterator = store::const_iterator;

    Matches(size_type num, const_iterator it1, const_iterator it2)
        : number(num)
        , iterator1(it1)
        , iterator2(it2)
    {
    }

    size_type number;
    const_iterator iterator1;
    const_iterator iterator2;
};
