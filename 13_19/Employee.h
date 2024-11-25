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
    Employee(const Employee& orig): name(orig.name) {
        id = counter++;
    }
    Employee& operator=(const Employee&);
private:
    std::string name;
    int id;
    static int counter;
};

#endif
