#ifndef INC_7_57_ACCOUNT_H
#define INC_7_57_ACCOUNT_H

#include <string>


class Account {
public:
    Account() = default;
    Account(const std::string &s, double am): owner(s), amount(am) {};
    void calculate()
    {
        amount += amount * interestRate;
    }
    static double rate() {
        return interestRate;
    }
    static void rate(double );
    double getAmount() {
        return amount;
    }
private:
    std::string owner;
    double amount = 0.0;
    static double interestRate;
    static double initRate()
    {
        return 0.05;
    }
    static constexpr int period = 30;
    double daily_tbl[period];
};


#endif
