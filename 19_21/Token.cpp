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
}

Token& Token::operator=(const Token& rhs)
{
    if (tok == STR && rhs.tok != STR)
    {
        sval.~string();
    }

    if (tok == STR && rhs.tok == STR) {
        sval = rhs.sval;
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

Token& Token::operator=(char ch)
{
    if (tok == STR)
    {
        sval.~string();
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
    }
}