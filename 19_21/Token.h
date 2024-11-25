#pragma once


#include <string>


using std::string;


class Token
{
public:
    Token();
    Token(const Token& tkn);

    Token& operator=(const Token& rhs);

    ~Token();

    Token& operator=(const string& str);
    Token& operator=(char ch);
    Token& operator=(int i);
    Token& operator=(double dbl);

private:
    enum
    {
        INT,
        CHAR,
        DBL,
        STR
    } tok;
    union
    {
        char cval;
        int ival;
        double dval;
        string sval;
    };

    void copyUnion(const Token& tkn);

};
