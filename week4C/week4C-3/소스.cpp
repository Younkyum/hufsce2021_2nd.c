#include <stdio.h>
#include <math.h>

typedef struct Point {
	float x;
	float y;
} Point;

int main() {
	float length;

	struct Point A;
	struct Point B;
	struct Point New_A;
	struct Point New_B;
	struct Point Overlap;

	scanf("%f %f", &A.x, &A.y);
	scanf("%f %f", &B.x, &B.y);

	if (A.x > B.x) {
		New_A.x = B.x;
		New_A.y = B.y;
		New_B.x = A.x;
		New_B.y = A.y;
	}
	else {
		New_A.x = A.x;
		New_A.y = A.y;
		New_B.x = B.x;
		New_B.y = B.y;
	}

	if (New_B.x <= New_A.y) {
		Overlap.x = New_B.x;
		if (New_B.y <= New_A.y) Overlap.y = New_B.y;
		else Overlap.y = New_A.y;
	}
	else {
		printf("-1");
		return 0;
	}
	length = Overlap.y - Overlap.x;
	printf("%.2f", length);
}