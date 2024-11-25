#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4 ,6, 8};

decltype(odd) &func(int i)
{
    return (i % 2) ? odd : even;
}

int main() {
    int (&arr)[5] = func(7);
    for (int i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
