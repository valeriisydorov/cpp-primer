#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::vector<double> math{3.1415926536, 2.7182818284, 1.6180339887};
    std::cout << std::setprecision(11) << math.at(0) << std::endl;
    std::cout << std::setprecision(11) << math.front() << std::endl;
    std::cout << std::setprecision(11) << *math.begin() << std::endl;
    std::cout << std::setprecision(11) << math[0] << std::endl;
    return 0;
}

