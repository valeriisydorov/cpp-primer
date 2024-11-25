#include <iostream>

int findMore(int val1, const int *val2)
{
    return val1 < *val2 ? *val2 : val1;
}

int main() {
    int val1 = 17;
    int val2 = 13;
    std::cout << findMore(val1, &val2) << std::endl;
    return 0;
}
