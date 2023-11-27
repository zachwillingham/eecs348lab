#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate);

    void withdraw(double amount) override;

    void displayAdditionalDetails() const override;

    std::string getAccountType() const override;
};

#endif // SAVINGSACCOUNT_H