#include <stdio.h>

int main() {
	int score;
	int n = 0, sum = 0;
	int max = 0, min = 0;
	float avr;

	scanf("%d", &score);
	max = score;
	min = score;

	while (score > 0) {
		if (max < score) {
			max = score;
		}
		if (min > score) {
			min = score;
		}
		n++;
		sum = sum + score;
		scanf("%d", &score);
	}

	avr = (float)sum / (float)n;
	printf("%d %d %.2f", min, max, avr);
	return 0;
}