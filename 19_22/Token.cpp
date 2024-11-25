#include "Token.h"


Token::Token()
: tok(INT)
, ival{0}
{
}

Token::Token(const Token& tkn)
: tok(tkn.tok)
{
    copyUnion(tkn);
}

Token::~Token()
{
    if (tok == STR)
    {
        sval.~string();
    }

    if (tok == SDT)
    {
        sdtval.~Sales_data();
    }
}

Token& Token::operator=(const Token& rhs)
{
    if (tok == STR && rhs.tok != STR)
    {
        sval.~string();
    }

    if (tok == SDT && rhs.tok != SDT)
    {
        sdtval.~Sales_data();
    }

    if (tok == STR && rhs.tok == STR) {
        sval = rhs.sval;
    }
    else if (tok == SDT && rhs.tok == SDT)
    {
        sdtval = rhs.sdtval;
    }
    else
    {
        copyUnion(rhs);
    }

    tok = rhs.tok;

    return *this;
}

Token& Token::operator=(const string& str)
{
    if (tok == SDT)
    {
        sdtval.~Sales_data();
    }

    if (tok == STR)
    {
        sval = str;
    }
    else
    {
        new(&sval) string(str);

        tok = STR;
    }

    return *this;
}

Token& Token::operator=(const Sales_data& sdt)
{
    if (tok == STR)
    {
        sval.~string();
    }

    if (tok == SDT)
    {
        sdtval = sdt;
    }
    else
    {
        new(&sdtval) Sales_data(sdt);

        tok = SDT;
    }

    return *this;
}

Token& Token::operator=(char ch)
{
    if (tok == STR)
    {
        sval.~string();
    }

    if (tok == SDT)
    {
        sdtval.~Sales_data();
    }

    cval = ch;
    tok = CHAR;

    return *this;
}

Token& Token::operator=(int i)
{
    if (tok == STR)
    {
        sval.~string();
    }

    if (tok == SDT)
    {
        sdtval.~Sales_data();
    }

    ival = i;
    tok = INT;

    return *this;
}

Token& Token::operator=(double dbl)
{
    if (tok == STR)
    {
        sval.~string();
    }

    if (tok == SDT)
    {
        sdtval.~Sales_data();
    }

    dval = dbl;
    tok = DBL;

    return *this;
}

void Token::copyUnion(const Token& tkn)
{
    switch (tkn.tok)
    {
        case Token::INT:
            ival = tkn.ival;
            break;
        case Token::CHAR:
            cval = tkn.cval;
            break;
        case Token::DBL:
            dval = tkn.dval;
            break;
        case Token::STR:
            new(&sval) string(tkn.sval);
            break;
        case Token::SDT:
            new(&sdtval) Sales_data(tkn.sdtval);
            break;
    }
}