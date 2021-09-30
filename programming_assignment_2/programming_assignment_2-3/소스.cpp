#include <stdio.h>

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Rectangle{
	Point lowerLeftPt;
	Point upperRightPt;
} Rectangle;

int find_overlap(int a, int b, int c, int d) {
	int length;

	struct Point A;
	struct Point B;
	struct Point New_A;
	struct Point New_B;
	struct Point Overlap;

	A.x = a;
	A.y = b;
	B.x = c;
	B.y = d;

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
	return length;
}

int main() {
	struct Rectangle A;
	struct Rectangle B;
	struct Rectangle Overlap;
	int a, b;
	

	scanf("%d %d %d %d", &A.lowerLeftPt.x, &A.lowerLeftPt.y, &A.upperRightPt.x, &A.upperRightPt.y);
	scanf("%d %d %d %d", &B.lowerLeftPt.x, &B.lowerLeftPt.y, &B.upperRightPt.x, &B.upperRightPt.y);

	a = find_overlap(A.lowerLeftPt.y, A.upperRightPt.y, B.lowerLeftPt.y, B.upperRightPt.y);
	b = find_overlap(A.lowerLeftPt.x, A.upperRightPt.x, B.lowerLeftPt.x, B.upperRightPt.x);
	printf("%d", a * b);
}