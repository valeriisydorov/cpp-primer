#include <iostream>
#include <ctime>
#include "Employee.h"

int main() {
    std::time_t date = std::time(nullptr) + 60 * 60 * 48;
    Employee worker = Employee("Valerii Sydorov", "999-99-9999", "engineer", date, 1000);

    std::cout << worker << std::endl;

    return 0;
}
