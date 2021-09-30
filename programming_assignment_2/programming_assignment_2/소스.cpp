#include <stdio.h>

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	int k, da, db;
	k = gcd(a, b);
	da = a / k;
	db = b / k;
	return k * da * db;
}

int main() {
	int numArr[10000];
	int n, a = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numArr[i]);
	}
	for (int i = 0; i < n; i++) {
		a = lcm(a, numArr[i]);
	}
	printf("%d", a);
}