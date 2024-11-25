#include "Employee.h"

int main() {
    Employee unknown;
    Employee unknown2;
    Employee employee("Peter");
    Employee employee2(employee);
    Employee employee3 = employee2;
    Employee employee4("John");
    unknown = employee4;
    unknown2 = employee;

    return 0;
}
