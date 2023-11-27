#include "CurrentAccount.h"
#include <iostream>
#include <iomanip>

CurrentAccount::CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
    : Account(number, holder, initialBalance), overdraftLimit(limit) {}

void CurrentAccount::withdraw(double amount) {
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
    } else {
        std::cout << "Withdrawal not allowed. Overdraft limit exceeded." << std::endl;
    }
}

void CurrentAccount::displayAdditionalDetails() const {
    std::cout << "   Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << std::endl;
}

std::string CurrentAccount::getAccountType() const {
    return "Current Account";
}