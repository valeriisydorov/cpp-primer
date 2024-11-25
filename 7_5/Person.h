#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person {
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

    string name;
    string address;
};


#endif
