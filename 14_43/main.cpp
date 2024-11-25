#include <iostream>
#include <functional>
#include <vector>

int main() {
    std::vector<int> intVector{};
    for (int i = 0; i != 50 ; ++i) {
        intVector.push_back(i);
    }
    std::modulus<int> intModulus;
    int m = 3;

    for (int& i: intVector) {
        std::cout << "the number " << i << " is" << (intModulus(i, m) ? " not" : "") << " divisible by " << m << std::endl;
    }
    
    return 0;
}
