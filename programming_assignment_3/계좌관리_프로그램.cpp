#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	int anum = 0;
	string name;
	string pnum;
	int remain = 0;
	int maxwd = 100000;
	int icount = 0;
	int income = 0;
	int ocount = 0;
	int outcome = 0;
public:
	void open(int num, string iname, string ipnum, int iremain);
	void setWithdrawMax(int max);
	void deposit(int inc);
	void withdraw(int out);
	void changePhoneNo(string phoneno);
	void inquire();
	void avrDepositAmount();
	void avrWithdrawtAmount();
};

void Account::open(int num, string iname, string ipnum, int iremain) {
	this -> anum = num;
	this -> name = iname;
	this -> pnum = ipnum;
	this -> remain = iremain;
}
void Account::setWithdrawMax(int max) {
	this->maxwd = maxwd;
}
void Account::deposit(int inc) {
	remain = remain + inc;
	income += inc;
	icount++;
}
void Account::withdraw(int out) {
	if (out > remain) {
		cout << "error 1" << endl;
	}
	else if (out > maxwd) {
		cout << "error 2" << endl;
	}
	else {
		remain = remain - out;
		ocount++;
		outcome = outcome + out;
	}
}
void Account::changePhoneNo(string phoneno) {
	this->pnum = phoneno;
}
void Account::inquire() {
	cout << anum << " " << name << " " << pnum << " " << remain << endl;
}
void Account::avrDepositAmount() {
	cout << icount << " " << income / icount << endl;
}
void Account::avrWithdrawtAmount() {
	cout << ocount << " " << outcome / ocount << endl;
}

int main() {
	Account acc;
	string command;
	int accNo, amount;
	string name;
	string phoneNumber;
	
	while (cin >> command) { // 명령어 입력
		if (command == "open") {
			cin >> accNo >> name >> phoneNumber >> amount;
			acc.open(accNo, name, phoneNumber, amount);
		}
		else if (command == "deposit") {
			cin >> amount;    // 입금액
			acc.deposit(amount);
		}
		else if (command == "withdraw") {
			cin >> amount;   // 출금액
			acc.withdraw(amount);
		}
		else if (command == "inquire") {
			acc.inquire();
		}
		else if (command == "setWithdrawMax") {
			cin >> amount;
			acc.setWithdrawMax(amount);
		}
		else if (command == "changePhoneNo") {
			cin >> phoneNumber;
			acc.changePhoneNo(phoneNumber);
		}
		else if (command == "avrDepositAmount") {
			acc.avrDepositAmount();
		}
		else if (command == "avrWithdrawAmount") {
			acc.avrWithdrawtAmount();
		}
		else if (command == "quit") {
			break;
		}
	}
}
