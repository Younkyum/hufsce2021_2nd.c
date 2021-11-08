
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	int anum = 0;
	string name;
	string pnum;
	int remain = 0;
	int maxwd = 100000; // 출금 한도 (default)
	int icount = 0;
	int income = 0;
	int ocount = 0;
	int outcome = 0;
public:
	void open(int num, string iname, string ipnum, int iremain); // 계좌 오픈
	void setWithdrawMax(int max); // 출금 한도 제한
	void deposit(int inc); // 입금
	void withdraw(int out); // 출금
	void changePhoneNo(string phoneno); // 휴대전화 번호 번경
	void inquire(); // 정보 출력
	void avrDepositAmount(); // 평균 입금 금액
	void avrWithdrawtAmount(); // 평균 출금 금액
};

void Account::open(int num, string iname, string ipnum, int iremain) {
	this -> anum = num;
	this -> name = iname;
	this -> pnum = ipnum;
	this -> remain = iremain;
}
void Account::setWithdrawMax(int max) {
	this->maxwd = max;
}
void Account::deposit(int inc) {
	remain = remain + inc;
	income += inc;
	icount++;
}
void Account::withdraw(int out) {
	if (out > remain) {
		cout << "error1" << endl;
	}
	else if (out > maxwd) {
		cout << "error2" << endl;
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
	Account acc; // 계좌 선언
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
			cin >> amount; // 입금액
			acc.deposit(amount);
		}
		else if (command == "withdraw") {
			cin >> amount; // 출금액
			acc.withdraw(amount);
		}
		else if (command == "inquire") {
			acc.inquire(); // 출력
		}
		else if (command == "setWithdrawMax") {
			cin >> amount; // 값 입력받음
			acc.setWithdrawMax(amount); // 출금 제한 금액 설정
		}
		else if (command == "changePhoneNo") {
			cin >> phoneNumber; // 전화번호 입력받음
			acc.changePhoneNo(phoneNumber); // 전화번호 변경
		}
		else if (command == "avrDepositAmount") {
			acc.avrDepositAmount(); // 평균 입금 금액  
		}
		else if (command == "avrWithdrawAmount") {
			acc.avrWithdrawtAmount(); // 평균 출금 금액
		}
		else if (command == "quit") {
			break;
		}
	}
}
