#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

  // test.txt ���� ���� 
	ofstream Filename("test.txt");

  // ���� ����
	Filename << "�а�: ��ǻ�����ڽý��۰��к� "; 
	Filename << "�й� : 201912345 ";
	Filename << "��ȭ��ȣ: 010-1234-5678 ";
	Filename << "�̸�: ȫ�浿";
	
  // ���� �ݱ� (ofstream)
	Filename.close();

  // ���� ���� ���� ����
  string fileline;
	
	// ���� �б�
	ifstream Filename2("test.txt");
  
  // ������ ���� ������ �б� (getline �̿�)
  while (getline(Filename2, fileline)) {
		cout << fileline;
	}

  // ���� �ݱ� (ifstream)
	Filename2.close();
}


