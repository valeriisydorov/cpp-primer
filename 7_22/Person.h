#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person {
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);

public:
    Person() = default;
    Person(const std::string &n, const std::string &a): name(n), address(a) { }
    Person(std::istream &);

    /**
     *
     * @return
     */
    string getName() const {
        return name;
    }

    /**
     *
     * @return
     */
    string getAddress() const {
        return address;
    }

private:
    string name;
    string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);


#endif
