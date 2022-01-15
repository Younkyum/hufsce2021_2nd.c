#include <iostream>
using namespace std;
 
class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int subtract(int a, int b) = 0;
	virtual float average(int a[], int size) = 0;
};

class GoodCalc : public Calculator {
public:
	int add(int a, int b) override {
		int sum;
		sum = a + b;
		return sum;
	}
	int subtract(int a, int b) override {
		int sub;
		sub = a - b;
		return sub;
	}
	float average(int a[], int size) override {
		float sum = 0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
		}
		return sum/size; 
	}
};

int main() {
	int a[] = {1,2,3,4,5};
	Calculator *p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}

