#include <stdio.h>

int isPerfectNumber(int n) { //� ���� n�� ���������� �Ǵ��ϴ� �Լ�
	int sum = 0;
	for (int i = 1; i < n; i++) { //n���� ���� ������ n�� ���� ������ �������� 0�϶� sum�� ����.
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	if (sum == n) {
		return 1; //�������Ͻ� 1 return
	}
	else {
		return 0; //�������� �ƴҽ� 0 return
	}
}


int main() {
	int a, b;
	int count = 0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		if (isPerfectNumber(i) == 1) { //���� ���������� for ������ �ľ�
			count = count + 1;
		}
	}
	printf("%d", count); //�������� ���� ���
}