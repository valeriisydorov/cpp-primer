#include <iostream>


#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"


int main()
{
    Query q1("first");
    Query q2("second");
    QueryBase* aq = new AndQuery(q1, q2);
    QueryBase* oq = new OrQuery(q1, q2);

    if (AndQuery* aqc = dynamic_cast<AndQuery*>(aq))
    {
        if (typeid(*aqc) == typeid(*oq))
        {
            std::cout << "are equal" << std::endl;
        }
        else
        {
            std::cout << "are not equal" << std::endl;
        }
    }
    else
    {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    return 0;
}