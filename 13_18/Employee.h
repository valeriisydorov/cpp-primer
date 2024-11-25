#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee() {
        id = counter++;
    }
    Employee(const std::string& n): name(n) {
        id = counter++;
    }
private:
    std::string name;
    int id;
    static int counter;
};

#endif
