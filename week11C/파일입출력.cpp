#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
	string array[3];
	array[0]=" 20100001 ȫ�浿 100";
	array[1]="20100002 ������ 90";
	array[2]="20100003 ������ 80";
		
	//test.txt�� �ۼ�
	ofstream out("test.txt");
	for(int i=0;i<3;i++){
		out << array[i] << endl;
	}
	//test.txt �� �� �ٿ� ��ȣ�� �ٿ� output.txt�� �ۼ�
	ifstream in("test.txt");
	ofstream fout("output.txt");
	char c;
	int line_number=1; //�տ� ��ȣ
	/*
	get�� ���� c�� �ϳ��� �޾� �ⷰ
	*/
	for (int i = 0; i < 3; i++) {
		fout << line_number << ":";
		line_number++;
		while (in.get(c)) {
			fout << c;
			if (c == '\n') {
				break;
			}
		}
	}
	in.close();
	fout.close();
	
	//output.txt ������ ȭ�鿡 ���
	ifstream fin("output.txt");
	char s;
	for (int i = 0; i < 3; i++) {
		while (fin.get(s)) {
			cout << s;
		}
		cout << endl;
	}
	/*
	get�� ���� s�� �ϳ��� �޾� ���
	*/
	fin.close(); // ���� �ݱ�

	return 0;
}
	
