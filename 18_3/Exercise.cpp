#include "Exercise.h"


#include <vector>
#include <fstream>
#include <stdexcept>
#include <memory>


void exercise1(int* b, int* e)
{
    std::vector<int> v(b, e);
    int* p = new int[v.size()];

    try
    {
        std::fstream in("../ints");
        if (!in)
        {
            throw std::runtime_error("runtime_error: Could not open the file.");
        }
    }
    catch (std::exception &r)
    {
        delete[] p;
    }
}

void exercise2(int* b, int* e)
{
    std::vector<int> v(b, e);
    std::unique_ptr<int[]> p(new int[v.size()]);

    std::fstream in("../ints");
    if (!in)
    {
        throw std::runtime_error("runtime_error: Could not open the file.");
    }
}