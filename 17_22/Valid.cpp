#include "Valid.h"


bool valid(const std::smatch& m)
{
    if (m[1].matched)
    {
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    }
    else
    {
        return m[3].matched && m[4].str() == m[6].str();
    }
}
