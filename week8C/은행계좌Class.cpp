#include <iostream>
using namespace std;

class Account{
private:
	int accountNumber;
	char *owner;
	int balance;
public:
	void setOwner(char *owner);
	char *getOwner();
	void setAccountNumber(int anum);
	int getAccountNumber();
	void setBalance(int balance);
	int getBalance();
	void deposit(int income);
	void withdraw(int outcome);
};

void Account::setOwner(char *owner){
	this->owner = owner;
}
char* Account::getOwner(){
	return owner;
}
void Account::setAccountNumber(int anum) {
	this->accountNumber = anum;
}
int Account::getAccountNumber(){
	return accountNumber;
}
void Account::setBalance(int balance) {
	this->balance = balance;
}
int Account::getBalance() {
	return balance;
}
void Account::deposit(int income){
	balance += income;
}
void Account::withdraw(int outcome) {
	balance -= outcome;
}
