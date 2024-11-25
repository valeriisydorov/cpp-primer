#include "Employee.h"

ostream& operator<<(ostream& os, const Employee& em) {
    std::tm *localTime = std::localtime(&em.startDate);
    os << em.name << " " << em.ssn << " " << em.position << " " << (localTime->tm_year + 1900) << '-' << (localTime->tm_mon + 1) << '-' << localTime->tm_mday << " " << em.salary;
}