#include "Date.h"

int main() {
    Date dateString1("Jan 03, 1975");
    Date dateString2("12/10/2002");
    Date dateString3("October 4, 2012");

    dateString1.printDate();
    dateString2.printDate();
    dateString3.printDate();

    return 0;
}
