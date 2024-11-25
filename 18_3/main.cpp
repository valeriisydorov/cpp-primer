#include "Exercise.h"
#include <iostream>


int main()
{
    int arr[10] = {0 , 1, 2, 3, 4, 5, 6, 7, 8, 9};

    try {
        exercise2(arr, &arr[10]);
    }
    catch (std::exception &error)
    {
        std::cerr << "exercise2: " << error.what() << std::endl;
    }

    return 0;
}
