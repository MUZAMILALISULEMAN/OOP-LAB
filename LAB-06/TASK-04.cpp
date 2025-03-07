#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
public:
    Account(): accountNumber(0), balance(0.0) {}
    Account(int accountNumber, float balance): accountNumber(accountNumber), balance(balance) {}
    
    void displayDetails() {
        cout << "ACCOUNT NUMBER: " << accountNumber << endl;
        cout << "BALANCE: " << balance << endl;
    }
};

class SavingsAccount : protected Account {
protected:
    float interestRate;
public:
    SavingsAccount(): Account(), interestRate(0.0) {}
    SavingsAccount(int accountNumber, float balance, float interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}
    
    void displayDetails() {
        Account::displayDetails();
        cout << "INTEREST RATE: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : protected SavingsAccount {
protected:
    float overdraftLimit;
public:
    CheckingAccount(): SavingsAccount(), overdraftLimit(0.0) {}
    CheckingAccount(int accountNumber, float balance, float interestRate, float overdraftLimit)
        : SavingsAccount(accountNumber, balance, interestRate), overdraftLimit(overdraftLimit) {}

    void displayDetails() {
        SavingsAccount::displayDetails();
        cout << "OVERDRAFT LIMIT: " << overdraftLimit << endl;
    }
};

int main() {
    CheckingAccount c1(121, 5200, 3.5, 2000);

    c1.displayDetails();

    return 0;
}
