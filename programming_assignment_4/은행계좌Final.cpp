#include <iostream>
#include <string>
#define MAX 1000
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
		Account *bankacc = new Account[this->count];
	}
	int finder(int fnum) {
		int reminder = -1;
		for (int i = 0; i < count; i++) {
			if (bankacc[i].accnum == fnum) {
				reminder = i;
			}
		}
		if (reminder == -1) {
			return -1;
		} else {
			return reminder;
		}
	}
	int findnextlevel(Account a[], int fnum) {
		int reminder = -1;
		int c;
		int min = 0;
		for (int i = 0; i < count; i++) {
			c = a[i].accnum;
			if (c - fnum > min) {
				reminder = i;
				min = c - fnum;
			}
		}
		if (min == 0 || reminder == -1) {
			return -1;
		} else {
			return reminder;
		}
	}
	void open(stirng name, int balance) {
		Account a;
		a.make(number, name, balance);
		number++;
		bankacc[nc] = a;
		nc++;
	}
	void deposit(int num, int amount) {
		if (finer(num) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc(finder(num)).income(amount);
		}
	}
	void withdraw(int num, int amount) {
		if(finder(num) == -1) {
			cout << "Error2" << endl;
		} else {
			bankacc(finder(num)).outcome(amount);
		}
	}
	void transfer(int num1, int num2, int amount) {
		if (finder(num1) == -1 || finder(num2) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc(finder(num1)).outcome(amount);
			bankacc(finder(num2)).income(amount);
		}
	}
	void printa(int num) {
		bankacc(finder(num)).print();
	}
	void find_and_print(string fname) {
		Account namer[MAX];
		int basic = 111111;
		int counter = 1;
		for (int i = 0; i < this->count; i++) {
			if (bankacc[i].accname == fname) {
				namer[counter - 1] = bankacc[i];
				counter++
			}
		}
		if (counter == 1) {
			cout << "Error1" << endl;
		} else {
			for (int i = 0; i < counter; i++) {
				namer[findnextlevel(namer, basic)].print();
				basic = namer[findnextlevel(namer, basic)].accnum;
			}
		}
	}
	void eraser(int num) {
		int index;
		if (finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			index = finder(num);
			bankacc[index] = bankacc[nc-1];
			nc--;
		}
	}
};














