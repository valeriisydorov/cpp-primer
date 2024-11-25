#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<ctime>

using std::string;

class Employee {
public:
    Employee() = default;
    Employee(string nm, string sn, string pos = "trainee"): name(nm), ssn(sn), position(pos) { }
    Employee(string nm, string sn, string pos, std::time_t sd, int sl): name(nm), ssn(sn), position(pos), startDate(sd), salary(sl) { }
private:
    string name;
    string ssn;
    string position;
    std::time_t startDate = std::time(nullptr); // unix timestamp
    int salary = 0;
};

#endif
