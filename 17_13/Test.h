#pragma once


#include <cstddef>


struct Test
{
    unsigned int answers = 0;

    void changeResult(const std::size_t num, const bool res)
    {
        if (res)
        {
            answers |= (1 << num);
        } else {
            answers &= ~(1 << num);
        }
    }
};