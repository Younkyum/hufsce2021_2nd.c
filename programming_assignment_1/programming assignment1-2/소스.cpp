#include <stdio.h>

int main() {
	int count;
	scanf("%d", &count);
	int num_arr[10000]; //�Է¹޴� �迭
	int count_arr[10000]; //���Ҹ� ���� ������ �迭
	int counter_arr[10000]; //�� ������ ������ ��Ÿ���� �迭
	int limit_num = (count+1) / 2; //���ݼ� üũ ����

	for (int i = 0; i < count; i++) { //�迭 �Է¹ޱ�
		scanf("%d", &num_arr[i]);
	}

	int b = 0;
	for (int i = 0; i < count; i++) { //count�迭�� �ִ� �������� �ľ��ϱ�
		int c = num_arr[i];
		int a = 0;
		int checker;
		for (int j = 0; j < count; j++) { //�ִ� ��� a�� �� 1�� ��ȯ
			if (c == count_arr[j]) {
				a = 1;
				checker = j;
			}
		}
		if (a == 1) { //a == 1�ϰ�� counter�迭�� ���� 1 �߰�
			counter_arr[checker]++;
		}
		else { //a == 0�ϰ�� count�迭�� ���� �߰��� couter�迭�� 1 �߰�
			count_arr[b] = c;
			counter_arr[b] = 1;
			b++;
		}
	}

	int checker = 0;
	for (int i = 0; i < b; i++) { //counter�迭���� ���ݼ��� ������� ���� ��ġ�� �ִ� count�迭�� �ִ� ���� ���
		if (counter_arr[i] >= limit_num) {
			printf("%d ", count_arr[i]);
			checker = 1;
		}
	}
	if (checker == 0) { //����� �̷������ �ʾ��� �� -1 ���
		printf("-1");
	}
}