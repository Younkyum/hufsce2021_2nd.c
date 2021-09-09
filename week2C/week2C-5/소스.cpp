#include <stdio.h>
#include <math.h>     
int main(){
	int i, j, n;
	int sum =0;
	int square = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		short isPrime = 1;
		square = (int)sqrt(i);
		for (j = 2; j <= square; j++) { 
			if (i % j == 0) {
				isPrime = 0;
			}
		}
		if (isPrime == 1) {
			printf("%d---", i);
			sum = sum + i;
		}
	}
	printf("%d", sum);
}
