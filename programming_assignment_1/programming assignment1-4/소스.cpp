
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
    int i, j, n, m, o;
    int check = 0; //�Ҽ��� ������ ǥ���Ҽ� �ִ��� �Ǻ�
    scanf("%d", &num);
    for (i = 2; i <= num / 2 and check != 1; i++) {
        if (cprime(i) != 0) {
            n = cprime(i); //�ϳ��� �Ҽ��϶�
            o = num - n;
            for (j = 2; j <= o; j++) { //�̸� num���� ���� �ٽ� �Ҽ����� �ľ�
                if (cprime(j) != 0) {
                    m = cprime(j);
                    if (cprime(o - m) != 0) { //�´� �Ҽ��� �Ǹ� ����Ʈ
                        printf("%d %d %d", n, m, cprime(o - m));
                        check = 1;
                        break; //����� �극��ũ�� Ż��
                    }
                }
            }
        }
    }
    if (check == 0) {
        printf("0");
    }
}