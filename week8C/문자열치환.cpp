#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[80];
	char find[10];
	char change[10];
	char *pstr;
	char *temp = new char[80];
	cin.getline(str, 80);
	cin.getline(find,10);
	cin.getline(change, 10);
	
	pstr = strstr(str, find);
	string strs = str;
	string finds = find;
	string changes = change;
	strs.replace(strs.find(finds), finds.length(), changes);
	
	delete[] temp;
	cout << strs << endl;
	return 0;
}


