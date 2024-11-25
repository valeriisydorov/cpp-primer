#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "FindTemplate.h"


int main() {
    std::vector<std::string> vecStr = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::list<std::string> lstStr = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::string strForVec = {"Four"};
    std::string strForLst = {"One"};

    std::vector<std::string>::iterator resultVec = findTpl(vecStr.begin(), vecStr.end(), strForVec);
    std::cout << *resultVec << " is found." << std::endl;

    std::list<std::string>::iterator resultLst = findTpl(lstStr.begin(), lstStr.end(), strForLst);
    std::cout << *resultLst << " is found." << std::endl;

    return 0;
}
