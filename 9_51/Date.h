#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <array>

using std::string;
using std::array;

class Date
{
private:
    const array<string, 12> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    const string numbers{"0123456789"};

public:
    Date(const std::string& dateString) {
        string::size_type firstNumberPosition = dateString.find_first_of(numbers);
        string::size_type dayNumberStart = 0;
        if (firstNumberPosition) {
            for (string::size_type i = 0; i != 12; ++i) {
                if (dateString.substr(0, 3) == months[i]) {
                    month = i + 1;
                    break;
                }
            }
            dayNumberStart = firstNumberPosition;
        } else {
            month = stoi(dateString.substr(0, dateString.find_first_not_of(numbers)));
            dayNumberStart = dateString.find_first_of(numbers, dateString.find_first_not_of(numbers));
        }

        string dateStringWithoutMonth = dateString.substr(dayNumberStart);
        day = stoi(dateStringWithoutMonth.substr(0, dateStringWithoutMonth.find_first_not_of(numbers)));
        year = stoi(dateStringWithoutMonth.substr(dateStringWithoutMonth.size() - 4));
    };

    unsigned int month;
    unsigned int day;
    unsigned int year;

    void printDate() const
    {
        std::cout << "Date: " << month << "." << day << "." << year << std::endl;
    }
};

#endif
