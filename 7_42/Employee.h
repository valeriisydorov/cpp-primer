#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<ctime>
#include<iostream>

using std::string;

class Employee {
public:
    Employee(string nm, string sn, string pos, std::time_t sd, int sl): name(nm), ssn(sn), position(pos), startDate(sd), salary(sl) { }
    Employee(string nm, string sn, string pos = "trainee"): name(nm), ssn(sn), position(pos) {
        std::cout << "Constructor1" << std::endl;
    }
    Employee(): Employee("John Doe", "XXX-YY-ZZZZ") {
        std::cout << "Constructor2" << std::endl;
    };
private:
    string name;
    string ssn;
    string position;
    std::time_t startDate = std::time(nullptr); // unix timestamp
    int salary = 0;
};

#endif
