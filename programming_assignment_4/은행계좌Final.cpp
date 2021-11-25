#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	int accnum;
	string accname;
	int balance;
	void make(int accnum, string accname, int balance) {
		this->accnum = accnum;
		this->accname = accname;
		this->balance = balance;
	}
	void income(int amount) {
		this->balance += amount;
	}
	void outcome(int amount) {
		if (amount > this->balance){
			cout << "Error2" << endl;
		} else {
			this->balance -= amount;
		}
	}
	void print() {
		cout << accnum << " " << accname << " " << balance << endl;
	}
};


class Bank {
public:
	int number = 1111;
	int count;
	Account *bankacc;
	int nc;
	Bank() {
		this->number = 111111;
		this->nc = 0;
	}
	Bank(int count) {
		number = 111111;
		this->count = count;
		this->nc = 0;
	}
	int finder(int fnum) {
		int reminder = -1;
		for (int i = 0; i < count; i++) {
			if (bankacc[i] == fnum) {
				reminder = i;
			}
		}
		if (reminder == -1) {
			return -1;
		} else {
			return reminder;
		}
	}
	void open(stirng name, int balance) {
		Account a;
		a.make(accnum, name, balance);
		accnum++;
		bankacc[nc] = a;
		nc++;
	}
	void deposit(int num, int amount) {
		
	}
};














