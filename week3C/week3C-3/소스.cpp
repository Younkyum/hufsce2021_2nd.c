#include <stdio.h>

int power(int a, int n, int m) {
	int mult, i, r;
	mult = 1;
	for (i = 0; i < n; i++) {
		mult = mult * a;
	}
	r = mult % m;
	return r;
}

int main() {
	int a, n, m;
	scanf("%d %d %d", &a, &n, &m);
	printf("%d\n", power(a, n, m));
	return 0;
}