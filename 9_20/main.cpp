#include <iostream>
#include <list>
#include <deque>

int main() {
    std::list<int> sequence;
    std::deque<int> even;
    std::deque<int> odd;
    for (int i = 0; i < 100 ; ++i) {
        sequence.push_back(i);
    }
    for (int n: sequence) {
        if (n % 2) {
            odd.push_back(n);
        } else {
            even.push_back(n);
        }
    }
    std::cout << "Even numbers: ";
    for (int e: even) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout << "Odd numbers: ";
    for (int o: odd) {
        std::cout << o << " ";
    }
    std::cout << std::endl;

    return 0;
}
