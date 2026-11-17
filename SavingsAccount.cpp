using namespace std;
#include <iostream>
#include "SavingsAccount.h"
#include <numeric> // for accumulate


void SavingsAccount::closeOfBusiness() {
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestRate);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();

}

void SavingsAccount::printAccountInfo() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    owner.printCustomerInfo();
}