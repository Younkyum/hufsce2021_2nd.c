#include <stdio.h>

int isPerfectNumber(int n) { //어떤 정수 n이 완전수인지 판단하는 함수
	int sum = 0;
	for (int i = 1; i < n; i++) { //n보다 작은 수들을 n에 대해 나누어 나머지가 0일때 sum에 더함.
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	if (sum == n) {
		return 1; //완전수일시 1 return
	}
	else {
		return 0; //완전수가 아닐시 0 return
	}
}


int main() {
	int a, b;
	int count = 0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		if (isPerfectNumber(i) == 1) { //각각 완전수인지 for 문으로 파악
			count = count + 1;
		}
	}
	printf("%d", count); //완전수의 개수 출력
}