
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	int anum = 0;
	string name;
	string pnum;
	int remain = 0;
	int maxwd = 100000; // ��� �ѵ� (default)
	int icount = 0;
	int income = 0;
	int ocount = 0;
	int outcome = 0;
public:
	void open(int num, string iname, string ipnum, int iremain); // ���� ����
	void setWithdrawMax(int max); // ��� �ѵ� ����
	void deposit(int inc); // �Ա�
	void withdraw(int out); // ���
	void changePhoneNo(string phoneno); // �޴���ȭ ��ȣ ����
	void inquire(); // ���� ���
	void avrDepositAmount(); // ��� �Ա� �ݾ�
	void avrWithdrawtAmount(); // ��� ��� �ݾ�
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
	Account acc; // ���� ����
	string command;
	int accNo, amount;
	string name;
	string phoneNumber;
	
	while (cin >> command) { // ��ɾ� �Է�
		if (command == "open") { 
			cin >> accNo >> name >> phoneNumber >> amount;
			acc.open(accNo, name, phoneNumber, amount);
		}
		else if (command == "deposit") {
			cin >> amount; // �Աݾ�
			acc.deposit(amount);
		}
		else if (command == "withdraw") {
			cin >> amount; // ��ݾ�
			acc.withdraw(amount);
		}
		else if (command == "inquire") {
			acc.inquire(); // ���
		}
		else if (command == "setWithdrawMax") {
			cin >> amount; // �� �Է¹���
			acc.setWithdrawMax(amount); // ��� ���� �ݾ� ����
		}
		else if (command == "changePhoneNo") {
			cin >> phoneNumber; // ��ȭ��ȣ �Է¹���
			acc.changePhoneNo(phoneNumber); // ��ȭ��ȣ ����
		}
		else if (command == "avrDepositAmount") {
			acc.avrDepositAmount(); // ��� �Ա� �ݾ�  
		}
		else if (command == "avrWithdrawAmount") {
			acc.avrWithdrawtAmount(); // ��� ��� �ݾ�
		}
		else if (command == "quit") {
			break;
		}
	}
}
