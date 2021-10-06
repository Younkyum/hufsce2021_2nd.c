#include <stdio.h>

int main() {
	int boxes[1000][1000];
	int garo, sero;
	scanf("%d %d", &sero, &garo);
	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			scanf("%d", &boxes[i][j]);
		}
	}

	int garom[1000];
	int serom[1000];
	long long sum = 0;
	int c = 0;

	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			sum = sum + boxes[i][j];
		}
	}

	for (int i = 0; i < sero; i++) {
		garom[i] = boxes[i][0];
		for (int j = 1; j < garo; j++) {
			if (garom[i] < boxes[i][j]) {
				garom[i] = boxes[i][j];
			}
		}
		sum = sum - garom[i];
	}

	for (int i = 0; i < garo; i++) {
		serom[i] = boxes[0][i];
		for (int j = 0; j < sero; j++) {
			if (serom[i] < boxes[j][i]) {
				serom[i] = boxes[j][i];
			}
		}
		for (int j = 0; j < sero; j++) {
			if (garom[j] == serom[i]) {
				c = 1;
			}
		}
		if (c == 0) {
			sum = sum - serom[i];
		}
		c = 0;
	}

	printf("%lld", sum);
}