#include <iostream>
#include <ctime>
#include "Employee.h"

int main() {
    Employee worker1 = Employee("John Smith", "111-11-1111");

    std::time_t date = std::time(nullptr) + 60 * 60 * 48;
    Employee worker2 = Employee("Valerii Sydorov", "999-99-9999", "engineer", date, 1000);

    return 0;
}
