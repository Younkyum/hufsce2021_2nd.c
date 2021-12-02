#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

  // test.txt 파일 생성 
	ofstream Filename("test.txt");

  // 파일 쓰기
	Filename << "학과: 컴퓨터전자시스템공학부 "; 
	Filename << "학번 : 201912345 ";
	Filename << "전화번호: 010-1234-5678 ";
	Filename << "이름: 홍길동";
	
  // 파일 닫기 (ofstream)
	Filename.close();

  // 파일 내용 변수 선언
  string fileline;
	
	// 파일 읽기
	ifstream Filename2("test.txt");
  
  // 파일을 라인 단위로 읽기 (getline 이용)
  while (getline(Filename2, fileline)) {
		cout << fileline;
	}

  // 파일 닫기 (ifstream)
	Filename2.close();
}


