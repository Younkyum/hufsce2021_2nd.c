#include <stdio.h>
#include <math.h>

int isPrimesum(int n) {
	int i, j;
	int sum = 0;
	int square = 0;
	for (i = 2; i <= n; i++) {
		short isPrime = 1;
		square = (int)sqrt(i);

		for (j = 2; j <= square; j++) {
			if (i % j == 0)
				isPrime = 0;
		}
		if (isPrime == 1)
			sum += i;
	}
	return sum;
}

int main() {
	int n;
	int sum;
	scanf("%d", &n);
	sum = isPrimesum(n);
	printf("%d", sum);
}

