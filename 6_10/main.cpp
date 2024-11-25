#include <iostream>

void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 8;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    swapValues(&x, &y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}
