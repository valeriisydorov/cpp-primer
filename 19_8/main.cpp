#include <iostream>


#include "Query.h"
#include "AndQuery.h"


int main()
{
    Query q1("first");
    Query q2("second");
    QueryBase* aq1 = new AndQuery(q1, q2);
    QueryBase* aq2 = new AndQuery(q1, q2);

    if (typeid(*aq1) == typeid(*aq2))
    {
        std::cout << "pointers are the same type: ";

        if (AndQuery* aq = dynamic_cast<AndQuery*>(aq1))
        {
            std::cout << "AndQuery" << std::endl;
        }
    }

    return 0;
}