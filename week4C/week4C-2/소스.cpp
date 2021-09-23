#include <stdio.h>
#define MAX 10000

int largestIndex(int a[], int nA) {
	int index = 0;
	for (int i = 0; i < nA; i++) {
		if (a[index] <= a[i]) {
			index = i;
		}
	}
	return index;
}

int sortIndex(int a[], int nA) {
	int i, j, temp;
	int c, maxloc;
	for (i = 0; i < nA - 1; i++) {
		c = nA - i - 1;
		temp = a[largestIndex(a, nA - i)];
		a[largestIndex(a, nA - i)] = a[c];
		a[c] = temp;
	}
}

int main() {
	int index = 0;
	int nA, i;
	int A[MAX];

	scanf("%d", &nA);
	for (i = 0; i < nA; i++) {
		scanf("%d", &A[i]);
	}
	sortIndex(A, nA);
	for (i = 0; i < nA; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}