#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit);

    void withdraw(double amount) override;

    void displayAdditionalDetails() const override;

    std::string getAccountType() const override;
};

#endif // CURRENTACCOUNT_H