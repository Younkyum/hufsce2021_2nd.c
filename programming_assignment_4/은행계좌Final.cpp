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
	int number;
	int count;
	Account *bankacc = new Account[MAX];
	int nc;
	Bank() {
		this->number = 111111;
		this->nc = 0;
		Account *bankacc = new Account[1000];
	}
	Bank(int count) {
		number = 111111;
		this->count = count;
		this->nc = 0;
		Account *bankacc = new Account[count];
	}
	~Bank() {
		delete [] bankacc;
	}
	void open(string name, int balance) {
		Account a;
		a.make(number, name, balance);
		this->number++;
		bankacc[nc] = a;
		this->nc++;
	}
	int finder(int fnum) {
		int reminder = -1;
		for (int i = 0; i < nc; i++) {
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
	int findnextlevel(Account a[], int fnum, int na) {
		int reminder = -1;
		int c;
		int min = MAX;
		for (int i = 0; i < na; i++) {
			c = a[i].accnum;
			if (c - fnum <= min && c > fnum) {
				reminder = i;
				min = c - fnum;
			}
		}
		return reminder;
	}
	void deposit(int num, int amount) {
		if (finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc[finder(num)].income(amount);
		}
	}
	void withdraw(int num, int amount) {
		if(finder(num) == -1) {
			cout << "Error2" << endl;
		} else {
			bankacc[finder(num)].outcome(amount);
		}
	}
	void transfer(int num1, int num2, int amount) {
		if (finder(num1) == -1 || finder(num2) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc[finder(num1)].outcome(amount);
			bankacc[finder(num2)].income(amount);
		}
	}
	void printa(int num) {
		bankacc[finder(num)].print();
	}
	void find_and_print(string fname) {
		Account *namer = new Account[MAX];
		int basic = 111111;
		int counter = 0;
		for (int i = 0; i < this->nc; i++) {
			if (bankacc[i].accname == fname) {
				namer[counter] = bankacc[i];
				counter++;
			}
		}
		if (counter == 0) {
			cout << "Error3" << endl;
		} else {
			basic = 111110;
			for (int i = 0; i < counter; i++) {
				namer[findnextlevel(namer, basic, counter)].print();
				basic = namer[findnextlevel(namer, basic, counter)].accnum;
			}
		}
		delete [] namer;
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
	void all_print() {
		int basic = 111110;
		for (int i = 0; i < nc; i++) {
			bankacc[findnextlevel(bankacc, basic, nc)].print();
			basic = bankacc[findnextlevel(bankacc, basic, nc)].accnum;
		}
	}
};

int main() {
	Bank bank(1000);
	string command;
	string name;
	int accNo, amount;
	int accNo1, accNo2;
	
	while (cin >> command) {
		if (command == "신규") {
			cin >> name >> amount;
			bank.open(name, amount);
		} else if (command == "입금") {
			cin >> accNo >> amount;
			bank.deposit(accNo, amount);
		} else if (command == "출금") {
			cin >> accNo >> amount;
			bank.withdraw(accNo, amount);
		} else if (command == "계좌이체") {
			cin >> accNo1 >> accNo2 >> amount;
			bank.transfer(accNo1, accNo2, amount);
		} else if (command == "계좌번호조회") {
			cin >> accNo;
			bank.printa(accNo);
		} else if (command == "예금주이름조회") {
			cin >> name;
			bank.find_and_print(name); 
		} else if (command == "해지") {
			cin >> accNo;
			bank.eraser(accNo);
		} else if (command == "전체계좌조회") {
			bank.all_print();
		} else if (command == "종료") {
			break;
		}
	}
}
