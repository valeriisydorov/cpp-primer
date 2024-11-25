#include <iostream>

int callCounter()
{
    static int cnt;
    return cnt++;
}

int main() {
    for (int i = 0; i != 10; ++i) {
        std::cout << callCounter() << " ";
    }
    std::cout << std::endl;
    return 0;
}
