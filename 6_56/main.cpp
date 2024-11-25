#include <iostream>
#include <vector>

int addition(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

int main() {
    std::vector<int (*)(int, int)> v;

    v.push_back(&addition);
    v.push_back(&subtraction);
    v.push_back(&multiplication);
    v.push_back(&division);

    for (int (*fn)(int, int): v) {
        std::cout << fn(15, 3) << std::endl;
    }

    return 0;
}