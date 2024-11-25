#pragma once


#include <string>
#include "Sales_data.h"


using std::string;


class Token
{
public:
    Token();
    Token(const Token& tkn);

    Token& operator=(const Token& rhs);

    ~Token();

    Token& operator=(const string& str);
    Token& operator=(const Sales_data& sdt);
    Token& operator=(char ch);
    Token& operator=(int i);
    Token& operator=(double dbl);

private:
    enum
    {
        INT,
        CHAR,
        DBL,
        STR,
        SDT
    } tok;
    union
    {
        char cval;
        int ival;
        double dval;
        string sval;
        Sales_data sdtval;
    };

    void copyUnion(const Token& tkn);

};
