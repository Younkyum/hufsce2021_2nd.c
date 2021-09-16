#include <stdio.h>

int GCD(int a, int b);

int main() {
	int a, b, c;
	int temp;
	scanf("%d %d", &a, &b); //a, b는 양의 정수      
	c = GCD(a, b);
	printf("%d", c);
}

int GCD(int a, int b) {
	int temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}