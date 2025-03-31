
#include <stdexcept>

class BankAccount {
public:
    BankAccount(double balance = 0);
    double deposit(double amount);
    double withdraw(double amount);
    double view_balance() const;
    void transfer(BankAccount& otherAccount, double amount);

private:
    double balance;
};

BankAccount::BankAccount(double balance) : balance(balance) {}

double BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Invalid amount");
    }
    balance += amount;
    return balance;
}

double BankAccount::withdraw(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Invalid amount");
    }
    if (amount > balance) {
        throw std::invalid_argument("Insufficient balance.");
    }
    balance -= amount;
    return balance;
}

double BankAccount::view_balance() const {
    return balance;
}

void BankAccount::transfer(BankAccount& otherAccount, double amount) {
    withdraw(amount);
    otherAccount.deposit(amount);
}
