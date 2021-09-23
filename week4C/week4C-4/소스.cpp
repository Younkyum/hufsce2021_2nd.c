#include <stdio.h>

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct Rectangle {
	struct Point lowerLeft;
	struct Point upperRight;
	struct Point lowerRight;
	struct Point upperLeft;
} Rectangle;

int main() {

	struct Rectangle R;


	scanf("%d %d %d %d", &R.upperLeft.x, &R.upperLeft.y, &R.lowerRight.x, &R.lowerRight.y);
	R.upperRight.x = R.lowerRight.x;
	R.upperRight.y = R.upperLeft.y;
	R.lowerLeft.x = R.upperLeft.x;
	R.lowerLeft.y = R.lowerRight.y;

	int area;

	area = abs(R.lowerLeft.x - R.upperRight.x) * abs(R.lowerLeft.y - R.upperRight.y);
	printf("%d", area);
}