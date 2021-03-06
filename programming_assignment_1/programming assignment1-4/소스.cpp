#include<stdio.h>

int cprime(int num)
{
    int i;
    for (i = 2; i <= num; i++) {
        if (num % i == 0) {
            if (num == i) return num; //재귀함수 이용
            if (num != i) return 0;
        }
    }
    return 0;
}

int main() {
    int num; //입력받음
    int i, j, k, n, m, o;
    int first, second, third;
    int check = 0; //소수의 합으로 표현할수 있는지 판별
    scanf("%d", &num);
    for (i = 2; i <= num / 2; i++) {
        if (cprime(i) != 0) {
            n = cprime(i); //하나가 소수일때
            o = num - n;
            for (j = 2; j <= o; j++) { //이를 num에서 뺀뒤 다시 소수인지 파악
                if (cprime(j) != 0) {
                    m = cprime(j);
                    if (cprime(o - m) != 0) { //셋다 소수가 되면 프린트
                                            //printf("%d %d %d\n", n, m, o-m);
                        if (n <= m && n <= o - m && m <= o - m) {
                            first = n;
                            second = m;
                            third = o - m; //각각 배열에 추가
                        }
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
        printf("%d %d %d", first, second, third);
    }
}