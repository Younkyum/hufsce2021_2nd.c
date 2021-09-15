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
    int num_arr[100][3];
    int i, j, k, n, m, o;
    int cnt = 0;
    int check = 0; //소수의 합으로 표현할수 있는지 판별
    scanf("%d", &num);
    for (i = 2; i <= num; i++) {
        if (cprime(i) != 0) {
            n = cprime(i); //하나가 소수일때
            o = num - n;
            for (j = 2; j <= o; j++) { //이를 num에서 뺀뒤 다시 소수인지 파악
                if (cprime(j) != 0) {
                    m = cprime(j);
                    if (cprime(o - m) != 0) { //셋다 소수가 되면 프린트
                        num_arr[cnt][0] = n;
                        num_arr[cnt][1] = m;
                        num_arr[cnt][2] = cprime(o - m); //각각 배열에 추가
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
        int first_max = 0; //감소하지 않는 순서에서, 처음 소수가 가장 큰 것을 출력하면 된다.
        int first, second, third;
        for (i = 0; i < cnt; i++) {
            if (num_arr[i][0] <= num_arr[i][1] && num_arr[i][1] <= num_arr[i][2]) {
                first = num_arr[i][0];
                second = num_arr[i][1];
                if (first_max <= first) { //처음 소수가 가장 커야함
                    first_max = first;
                    third = num_arr[i][2];
                }
            }
        }
        printf("%d %d %d", first_max, second, third);
    }
}