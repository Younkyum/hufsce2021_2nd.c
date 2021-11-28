#include <iostream>
#include <string>
#define MAX 10000
using namespace std;


class Account { // 계좌 클래스 
public:
	int accnum; 
	string accname;
	int balance;
	void make(int accnum, string accname, int balance) { // 계좌 개설 함수 
		this->accnum = accnum;
		this->accname = accname;
		this->balance = balance;
	}
	void income(int amount) { // 계좌 입금 함수 
		this->balance += amount;
	}
	void outcome(int amount) { // 계좌 출금 함수 - 잔고보다 출금을 많이 할 경우 Error2출력 
		if (amount > this->balance){
			cout << "Error2" << endl;
		} else {
			this->balance -= amount;
		}
	}
	void print() { // 계좌 출력 
		cout << accnum << " " << accname << " " << balance << endl; 
	}
};


class Bank {
public:
	int number; // 계좌번호 
	int count; // 계좌 배열 개수 
	Account *bankacc = new Account[MAX]; // 계좌 배열 
	int nc; // 실제 계좌 개 수  
	Bank() {
		this->number = 111111;
		this->nc = 0;
		Account *bankacc = new Account[1000];
	}
	Bank(int count) { // 생성 자  
		number = 111111;
		this->count = count;
		this->nc = 0;
		Account *bankacc = new Account[count];
	}
	~Bank() { // 소멸자  
		delete [] bankacc;
	}
	void open(string name, int balance) { // 계좌 개설  
		Account a;
		a.make(number, name, balance);
		this->number++;
		bankacc[nc] = a;
		this->nc++;
	}
	int finder(int fnum) { // 계좌번호를 입력받으면 계좌의 index를 리턴하는 함수  
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
	int findnextlevel(Account a[], int fnum, int na) { // 계좌와 가장 가까운 계좌번호 탐색 - 오름차순 출력 위해  
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
	void deposit(int num, int amount) { // 입금 함수 
		if (finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc[finder(num)].income(amount);
		}
	}
	void withdraw(int num, int amount) { // 출금 함수 
		if(finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc[finder(num)].outcome(amount);
		}
	}
	void transfer(int num1, int num2, int amount) { // 계좌 이체 함수  
		if (finder(num1) == -1 || finder(num2) == -1) {
			cout << "Error1" << endl;
		} else {
			if (bankacc[finder(num1)].balance >= amount) {
				bankacc[finder(num2)].income(amount);
			}
			bankacc[finder(num1)].outcome(amount);
		}
	}
	void printa(int num) { // 단일 계좌 출력  
		if (finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			bankacc[finder(num)].print();
		}
	}
	void find_and_print(string fname) { // 계좌 예금주 이름 같은 계좌 출력  
		Account *namer = new Account[MAX]; // 새로운 배열 - 예금주가 같은 계좌 
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
	void eraser(int num) { // 해지 함수  
		int index;
		if (finder(num) == -1) {
			cout << "Error1" << endl;
		} else {
			index = finder(num);
			bankacc[index] = bankacc[nc-1];
			nc--; // 개수 감소  
		}
	}
	void all_print() { // 전체 계좌 출력 - 오름차순  
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
