#include<stdio.h>

int cprime(int num)
{
    int i;
    for (i = 2; i <= num; i++) {
        if (num % i == 0) {
            if (num == i) return num; //����Լ� �̿�
            if (num != i) return 0;
        }
    }
    return 0;
}
int main() {
    int num; //�Է¹���
    int num_arr[100][3];
    int i, j, k, n, m, o;
    int cnt = 0;
    int check = 0; //�Ҽ��� ������ ǥ���Ҽ� �ִ��� �Ǻ�
    scanf("%d", &num);
    for (i = 2; i <= num; i++) {
        if (cprime(i) != 0) {
            n = cprime(i); //�ϳ��� �Ҽ��϶�
            o = num - n;
            for (j = 2; j <= o; j++) { //�̸� num���� ���� �ٽ� �Ҽ����� �ľ�
                if (cprime(j) != 0) {
                    m = cprime(j);
                    if (cprime(o - m) != 0) { //�´� �Ҽ��� �Ǹ� ����Ʈ
                        num_arr[cnt][0] = n;
                        num_arr[cnt][1] = m;
                        num_arr[cnt][2] = cprime(o - m); //���� �迭�� �߰�
                        cnt++;
                        check = 1;
                    }
                }
            }
        }
    }
    if (check == 0) {
        printf("0");
    }
    else {
        int first_max = 0; //�������� �ʴ� ��������, ó�� �Ҽ��� ���� ū ���� ����ϸ� �ȴ�.
        int first, second, third;
        for (i = 0; i < cnt; i++) {
            if (num_arr[i][0] <= num_arr[i][1] && num_arr[i][1] <= num_arr[i][2]) {
                first = num_arr[i][0];
                second = num_arr[i][1];
                if (first_max <= first) { //ó�� �Ҽ��� ���� Ŀ����
                    first_max = first;
                    third = num_arr[i][2];
                }
            }
        }
        printf("%d %d %d", first_max, second, third);
    }
}