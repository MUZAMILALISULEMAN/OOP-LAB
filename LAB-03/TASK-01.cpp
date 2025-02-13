#include<iostream>
using namespace std;

class Wallet {
		string ownerName;
		double totalAmount;
		string transactionHistory[100];
		int count;
		float balance;

	public:
		Wallet() {
			totalAmount  = 0;
			balance= 0;
		}
		Wallet(string name, double amount,float Balance) {
			ownerName = name;
			totalAmount = amount;
			count = 0;
			if(Balance > 0) {
				balance = Balance;
			} else {
				balance = 0;
			}
		}

		void addMoney(double amount) {
			if (amount > 0) {
				totalAmount += amount;
				cout << "AMOUNT HAS BEEN ADDED SUCCESSFULLY!" << endl;
				if (count < 100) {
					transactionHistory[count] = "DEPOSITED: " + to_string(amount);
					count++;
				}
			} else {
				cout << "PLEASE ENTER A VALID AMOUNT!" << endl;
			}
			notify();
		}

		void spendMoney(double amount) {
			if (totalAmount >= amount) {
				totalAmount -= amount;
				cout << "AMOUNT HAS BEEN WITHDRAWN SUCCESSFULLY!" << endl;
				if (count < 100) {
					transactionHistory[count] = "WITHDRAWN: " + to_string(amount);
					count++;
				}
			} else {
				cout << "NOT ENOUGH MONEY!" << endl;
			}
			notify();
		}

		void display() {
			cout << "TRANSACTION HISTORY: " << endl << endl;
			for (int i = 0; i < count; i++) {
				cout << transactionHistory[i] << endl;
			}
		}

		void notify() {
			if (totalAmount < balance) {
				cout << "ALERT! AMOUNT IS LESS THAN " <<balance<< endl;
			}
		}
};

int main() {
	
	Wallet myWallet("Muzamil Ali Suleman", 3000,500);
	myWallet.addMoney(1000);
	myWallet.spendMoney(4000);
	myWallet.display();

	return 0;
}