#include <iostream>
#include <initializer_list>

int binSum(std::initializer_list<int> bin)
{
    int sum;
    for (auto beg = bin.begin(); beg != bin.end(); ++beg) {
        sum += *beg;
    }
    return sum;
}

int main()
{
    std::initializer_list<int> bin{1, 4, 6, 4, 1};
    std::cout << binSum(bin);

    return 0;
}