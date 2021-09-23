#include<stdio.h>
#define MAX 10000

int intersection(int a[], int b[], int nA, int nB) {
	int i, j;
	int count = 0; //교집합 원소의 개수
	for (i = 0; i < nA; i++) {
		for (j = 0; j < nB; j++) {
			if (a[i] == b[j]) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int A[MAX], B[MAX], nA, nB, i;
	int nc = 0;
	scanf("%d", &nA);
	for (i = 0; i < nA; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &nB);
	for (i = 0; i < nB; i++) {
		scanf("%d", &B[i]);
	}
	nc = intersection(A, B, nA, nB);
	printf("%d ", nc);
	return 0;
}