#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c); //���� �Է¹ޱ�
	int num_arr[10000];
	int max_count = 1;
	int count = 1;
	short check = 0;
	for (int i = 0; i < c; i++) { //���� �迭 �Է¹ޱ�
		scanf("%d", &num_arr[i]);
		if (num_arr[i] == 1) check = 1;
	}
	for (int i = 0; i < c; i++) {
		if (num_arr[i + 1] == 1 && num_arr[i] == 1) { //���� ���ڿ� �������
			count++; //ī��Ʈ �߰�
			check = 1;
			if (count > max_count) {
				max_count = count; //ī��Ʈ�� �ƽ�ī��Ʈ���� Ŭ��� ī��Ʈ�� ����
			}
		}
		else {
			count = 1; //���� ���ڿ� ���� ���� ��� ī��Ʈ 1�� ����
		}
	}
	if (check == 0) max_count = 0;

	printf("%d", max_count);
}