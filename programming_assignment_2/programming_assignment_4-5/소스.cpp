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

	int garoIndex[1000];
	int seroIndex[1000];
	int max = 0;

	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			if (boxes[i][j] >= max) {
				max = boxes[i][j];
				garoIndex[i] = j;
			}
		}
		max = 0;
	}

	for (int i = 0; i < garo; i++) {
		for (int j = 0; j < sero; j++) {
			if (boxes[j][i] >= max) {
				max = boxes[j][i];
				seroIndex[i] = j;
			}
		}
		max = 0;
	}

	int sum = 0;
	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo; j++) {
			if (j != garoIndex[i] && i != seroIndex[j]) {
				sum += boxes[i][j];
			}
		}
	}
	printf("%d", sum);
}