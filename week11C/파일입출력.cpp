#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
	string array[3];
	array[0]=" 20100001 홍길동 100";
	array[1]="20100002 김유신 90";
	array[2]="20100003 강감찬 80";
		
	//test.txt에 작성
	ofstream out("test.txt");
	for(int i=0;i<3;i++){
		out << array[i] << endl;
	}
	//test.txt 의 각 줄에 번호를 붙여 output.txt에 작성
	ifstream in("test.txt");
	ofstream fout("output.txt");
	char c;
	int line_number=1; //앞에 번호
	/*
	get을 통해 c를 하나씩 받아 출럭
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
	
	//output.txt 내용을 화면에 출력
	ifstream fin("output.txt");
	char s;
	for (int i = 0; i < 3; i++) {
		while (fin.get(s)) {
			cout << s;
		}
		cout << endl;
	}
	/*
	get을 통해 s를 하나씩 받아 출력
	*/
	fin.close(); // 파일 닫기

	return 0;
}
	
