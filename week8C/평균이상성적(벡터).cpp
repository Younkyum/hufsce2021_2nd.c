#include <iostream>
#include <vector>
using namespace std; 

int main() {
	vector<int> v1;
	int sum = 0, count = 0;
	int avr;
	int inser;
	while (cin >> inser) {
		if (inser == -1) {
			break;
		}
		v1.push_back(inser);
		count++;
		sum = sum + inser;
	}
	avr = sum / count;
	for (int i = 0; i < count; i++) {
		if (v1[i] >= avr) {
			cout << v1[i] << endl;
		}
	}
}
