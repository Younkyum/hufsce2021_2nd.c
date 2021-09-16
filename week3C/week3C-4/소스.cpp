#include<stdio.h>

#define MAX 10000

int arraySum(int a[], int n);
float mean(int a[], int n);

int arraySum(int a[], int n) {
	int sum, i;
	sum = 0;
	for (i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	return sum;
}

float mean(int a[], int n) {
	float ave;
	float all;
	all = arraySum(a, n);
	ave = (float)all / (float)n;
	return ave;
}


int main() {
	int a[MAX], n, i;
	float average;
	int cnt = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	average = mean(a, n);
	printf("%.2f ", average);
	for (i = 0; i < n; i++) {
		if (a[i] >= average) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}