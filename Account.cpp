#include "Account.h"
#include <iomanip>

Account::Account(const std::string& number, const std::string& holder, double initialBalance)
    : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

void Account::displayDetails() const {
    std::cout << "Account Details for " << getAccountType() << " (ID: " << accountNumber << "):" << std::endl;
    std::cout << "   Holder: " << accountHolder << std::endl;
    std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    displayAdditionalDetails();
    std::cout << std::endl;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds for withdrawal." << std::endl;
    }
}

void Account::displayAdditionalDetails() const {
    // This method is meant to be overridden by derived classes.
}

std::string Account::getAccountType() const {
    return "Generic Account";
}

Account operator+(const Account& lhs, const Account& rhs) {
    Account result("Transfer", "", 0);
    result.balance = lhs.balance + rhs.balance;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Details after transfer:" << std::endl;
    os << account;
    return os;
}