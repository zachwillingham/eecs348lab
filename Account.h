#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance);

    void displayDetails() const;

    void deposit(double amount);

    virtual void withdraw(double amount);

    virtual void displayAdditionalDetails() const;

    virtual std::string getAccountType() const;

    friend Account operator+(const Account& lhs, const Account& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

#endif // ACCOUNT_H