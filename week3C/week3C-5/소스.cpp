#include<stdio.h>
#define MAX 10000
int largestIndex(int arr[], int nA){
	int index = 0;
	for (int i = 0; i < nA; i++) {
		if (arr[i] >= arr[index]) {
			index = i;
		}
	}
	return index;
}

int main() {
	int index = 0;
	int nA, i;
	int A[MAX];
	scanf("%d", &nA);
	for (i = 0; i < nA; i++) {
		scanf("%d", &A[i]);
	}
	index = largestIndex(A, nA);
	printf("%d", A[index]);
	return 0;
}
