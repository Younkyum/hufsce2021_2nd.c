#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c); //���� �Է¹ޱ�
	int num_arr[10000];
	int max_count = 0;
	int count = 1;
	for (int i = 0; i < c; i++) { //���� �迭 �Է¹ޱ�
		scanf("%d", &num_arr[i]);
	}
	int pre = num_arr[0];
	for (int i = 1; i < c+1; i++) {
		if (num_arr[i-1] == num_arr[i]) { //���� ���ڿ� �������
			count++; //ī��Ʈ �߰�
			if (count >= max_count) {
				max_count = count; //ī��Ʈ�� �ƽ�ī��Ʈ���� Ŭ��� ī��Ʈ�� ����
			}
		}
		else {
			count = 1; //���� ���ڿ� ���� ���� ��� ī��Ʈ 1�� ����
		}
	}
	printf("%d", max_count);
}