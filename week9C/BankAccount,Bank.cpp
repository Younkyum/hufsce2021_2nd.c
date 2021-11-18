#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
#define SIZE 10

class Account {
private:
	int accountNumber;
	string owner;
	int balance;
public:
	Account(int a, string b, int c);
	Account();
	void setAccountNumber(int number);
	void setOwner(string name);
	void setBalance(int amount);
	int getAccountNumber();
	string getOwner();
	int getBalance();
	void deposit(int amount);
	void withdraw(int amount);
	void printAccount();
};

Account::Account()
{
	
	this->accountNumber = 0;
	this->owner="null";
	this->balance = 0;
	
}


Account::Account(int a, string b, int c) {
	this->accountNumber = a;
	this->owner = b;
	this->balance = c;
}

void Account::setAccountNumber(int number) {
	this->accountNumber = number;
}
void Account::setOwner(string name) {
	this->owner = name;
}

void Account::setBalance(int amount) {
	this->balance = amount;
}

int Account::getAccountNumber() {
	return accountNumber;
}

string Account::getOwner() {
	return owner;
}

int Account::getBalance() {
	return balance;
}

void Account::deposit(int amount) {
	balance += amount;
	cout << "now balance: " << balance << endl;
}

void Account::withdraw(int amount) {
	if(amount>balance){
		cout<<"No withdraw"<<endl;
	}
	else{
		balance -= amount;
		cout << "now balance: " << balance << endl;
	}
	
}

void Account::printAccount() {
	cout << "Account Number : " << accountNumber << endl;
	cout << "Name : " << owner << endl;
	cout << "Balance : " << balance << endl;
}


class Bank{
private:
	vector<Account> account;
public:
	void accountOpen(int accNum,string owner,int balance);
	void accountClose(int accountNumber);
	void printAllAccounts();
	void inquire(int accountNumber);
	void deposit(int accountNumber,int amount);
	void withdraw(int accountNumber,int amount);
	int findAccountIndex(int accountNumber);
};
void Bank::accountClose(int accountNumber) {
	account[0] = account[2];
	account.erase(account.end());
	
}
void Bank::accountOpen(int accNum, string owner, int balance) {
	Account maker;
	maker.setAccountNumber(accNum);
	maker.setBalance(balance);
	maker.setOwner(owner);
	account.push_back(maker);
}
int Bank::findAccountIndex(int accountNumber) {
	int i = 0, checker = 0;
	for (i = 0; i < account.size(); i++) {
		if (account[i].getAccountNumber() == accountNumber){
			checker = 1;
			break;
		}
	}
	if (checker == 1) return i;
	else return -1;
} 

void Bank::printAllAccounts() {
	for (int i = 0; i < account.size(); i++) {
		cout << account[i].getAccountNumber() << " " << account[i].getOwner() << " " << account[i].getBalance() << endl;
	}
}
void Bank::inquire(int accountNumber) {
	int checker = 0;
	checker = findAccountIndex(accountNumber);
	if (checker == -1) {
		cout << "Wrong account number" << endl;
	} else {
		account[checker].printAccount();
	}
}
void Bank::deposit(int accountNumber, int amount) {
	int checker = 0;
	checker = findAccountIndex(accountNumber);
	if (checker == -1) {
		cout << "Wrong account number" << endl;
	} else {
		account[checker].deposit(amount);
	}
}
void Bank::withdraw(int accountNumber, int amount) {
	int checker = 0;
	checker = findAccountIndex(accountNumber);
	if (checker == -1) {
		cout << "Wrong account number" << endl;
	} else {
		account[checker].withdraw(amount);
	}
}

int main() {
	Bank b;

	int menu;
	int accountNumber,amount;
	Account account[SIZE];
	b.accountOpen(1,"a",20000);
	b.accountOpen(2,"b",20000);
	b.accountOpen(3,"c",20000);
	do {

		cin >> menu;

		switch(menu) {
			case 1:{
				int accNum;
				string owner="";
				int balance;
				cin >>accNum>>owner>> balance;
				b.accountOpen(accNum,owner,balance);
				
				break;
			}
				
			case 2:
				cin >> accountNumber;
				b.accountClose(accountNumber);
				break;
			case 3:
				b.printAllAccounts();
				break;
			case 4:
				cin >> accountNumber;
				b.inquire(accountNumber);
				break;
			case 5:
				cin >>accountNumber>> amount;
				b.deposit(accountNumber,amount);
				break;
			case 6:
				cin >>accountNumber>> amount;
				b.withdraw(accountNumber,amount);
				break;
			case -1:
				break;
			default:
				;
		}


	} while(menu >= 1 && menu <= 6);

	return 0;
}

