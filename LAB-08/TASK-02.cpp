#include <iostream>
#include <string>

using namespace std;

class Account;

class Manager {
public:
    void displayAccountDetails(const Account& account) const;
    void deposit(Account& account, double amount);
    void withdraw(Account& account, double amount);
};

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

void Manager::displayAccountDetails(const Account& account) const {
    cout << "ACCOUNT NUMBER: " << account.accountNumber << endl;
    cout << "BALANCE: RS " << account.balance << endl;
}

void Manager::deposit(Account& account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        cout << "DEPOSITED RS " << amount << " INTO ACCOUNT " << account.accountNumber << endl;
    } else {
        cout << "INVALID DEPOSIT AMOUNT!" << endl;
    }
}

void Manager::withdraw(Account& account, double amount) {
    if (amount > 0 && account.balance >= amount) {
        account.balance -= amount;
        cout << "WITHDREW RS " << amount << " FROM ACCOUNT " << account.accountNumber << endl;
    } else {
        cout << "INSUFFICIENT BALANCE OR INVALID WITHDRAWAL AMOUNT!" << endl;
    }
}

void transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "TRANSFERRED RS " << amount << " FROM ACCOUNT " << from.accountNumber
             << " TO ACCOUNT " << to.accountNumber << endl;
    } else {
        cout << "TRANSFER FAILED: INSUFFICIENT BALANCE OR INVALID AMOUNT!" << endl;
    }
}

int main() {
    Account acc1("123456", 1000.0);
    Account acc2("654321", 500.0);

    Manager manager;

    cout << "INITIAL ACCOUNT DETAILS:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    manager.deposit(acc1, 200.0);
    manager.withdraw(acc2, 100.0);

    cout << "\nAFTER DEPOSIT AND WITHDRAWAL:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    transferFunds(acc1, acc2, 300.0);

    cout << "\nAFTER TRANSFER:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    return 0;
}