#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <ctime>

using std::ostream;
using std::istream;
using std::string;

class Employee {
    friend ostream& operator<<(ostream&, const Employee&);
    friend istream& operator>>(istream&, Employee&);
public:
    Employee() = default;
    Employee(string nm, string sn, string pos = "trainee"): name(nm), ssn(sn), position(pos) { }
    Employee(string nm, string sn, string pos, std::time_t sd, int sl): name(nm), ssn(sn), position(pos), startDate(sd), salary(sl) { }
    Employee(istream& is): Employee() {
        is >> *this;
    }
private:
    string name;
    string ssn;
    string position;
    std::time_t startDate = std::time(nullptr); // unix timestamp
    int salary = 0;
};

#endif
