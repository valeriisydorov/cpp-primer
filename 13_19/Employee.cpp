#include "Employee.h"

Employee& Employee::operator=(const Employee& orig) {
//    to change or not to change id?
//    id = counter++;
    name = orig.name;
    return *this;
}

int Employee::counter = 0;
