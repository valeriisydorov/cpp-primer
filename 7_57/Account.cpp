#include "Account.h"

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}