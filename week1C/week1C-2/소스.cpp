#include <stdio.h>

int main() {
	int a, b;
	int temp;

	scanf("%d %d", &a, &b);

	temp = a % b;

	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}

	printf("%d", b);
}