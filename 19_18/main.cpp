#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


int main()
{
    std::vector<std::string> vec{"Hi", "", "Yo", "Hey", "", "", "", "", "", "Heya", "Hello", ""};

    std::function<bool (const std::string&)> func = &std::string::empty;
    int count = std::count_if(vec.begin(), vec.end(), func);

    std::cout << count << std::endl;

    return 0;
}
