#include <stdio.h>

int main() {
	int n;
	int result = 0;

	scanf("%d", &n);
	while (n != 0) {
		result *= 10;
		result += n % 10;
		n /= 10;
	}

	printf("%d", result);

	return 0;
}