#include <stdexcept>
#include <iostream>
#include <typeinfo>


#include "Query.h"
#include "AndQuery.h"


int main()
{
    Query q1("first");
    Query q2("second");
    QueryBase* aq = new AndQuery(q1, q2);

    try
    {
        AndQuery& aqc = dynamic_cast<AndQuery&>(*aq);

        std::cout << "dynamic_cast success" << std::endl;
    }
    catch (std::bad_cast)
    {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    return 0;
}