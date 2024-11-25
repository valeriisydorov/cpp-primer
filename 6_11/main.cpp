#include <iostream>

void reset(int &val)
{
    val = 0;
}

int main() {
    int val = 1;
    std::cout << "val = " << val << std::endl;

    reset(val);
    std::cout << "val = " << val << std::endl;

    return 0;
}
