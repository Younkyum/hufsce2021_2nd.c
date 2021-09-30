#include <stdio.h>
#include <math.h>
#define MAX 1000

typedef struct Point {
	int dx;
	int dy;
}Point;

double perimeter(Point Polygon[], int n) {
	double result = 0.0;
	double dex, dey, qsum;
	for (int i = 0; i < n - 1; i++) {
		dex = Polygon[i].dx - Polygon[i + 1].dx;
		dex = pow(dex, 2);
		dey = Polygon[i].dy - Polygon[i + 1].dy;
		dey = pow(dey, 2);
		qsum = sqrt(dex + dey);
		result = result + qsum;
	}
	dex = Polygon[0].dx - Polygon[n - 1].dx;
	dey = Polygon[0].dy - Polygon[n - 1].dy;
	qsum = sqrt(pow(dex, 2) + pow(dey, 2));
	result += qsum;
	return result;
}

int main() {
	Point Polygon[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(Polygon[i].dx), &(Polygon[i].dy));
	}

	printf("%.2f", perimeter(Polygon, n));
}