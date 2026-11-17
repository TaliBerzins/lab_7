#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"
using namespace std;


class SavingsAccount : public Account {

private:
    const double interestRate; // 5% interest rate
public:
    SavingsAccount(const string& accNum, double initialBalance, const Customer& customer) : Account(accNum, initialBalance, customer), interestRate(0.05) {}
     void closeOfBusiness() override;
     void printAccountInfo() const override;

};

#endif
