#include <iostream>
#include <bitset>


int main()
{
    int arr[] = {1, 2, 3, 5, 8, 13, 21};
    constexpr std::size_t size = 24;

    std::bitset<size> bs1;
    for (int i : arr) {
        bs1[i] = true;
    }
    std::cout << "bs1: " << bs1 << std::endl;

    std::bitset<size> bs2;
    for (std::size_t i = 0; i != size; ++i) {
        if (bs1.test(i))
        {
            bs2.set(i);
        }
    }
    std::cout << "bs2: " << bs2 << std::endl;

    return 0;
}
