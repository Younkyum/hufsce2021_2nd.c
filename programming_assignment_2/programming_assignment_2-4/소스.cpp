#include <stdio.h>

typedef struct Point {
	int x;
	int y;
};

typedef struct Rectangle {
	Point lowerLeftPt;
	Point upperRightPt;
} Rectangle;

Point find_overlap_loc(int a, int b, int c, int d) {
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
		Overlap.x = 0;
		Overlap.y = 0;
	}
	return Overlap;
}

Rectangle overlap_rectangle(Rectangle A, Rectangle B) {
	struct Rectangle Overlap;
	Point a, b;
	a = find_overlap_loc(A.lowerLeftPt.x, A.upperRightPt.x, B.lowerLeftPt.x, B.upperRightPt.x);
	b = find_overlap_loc(A.lowerLeftPt.y, A.upperRightPt.y, B.lowerLeftPt.y, B.upperRightPt.y);
	Overlap.lowerLeftPt.x = a.x;
	Overlap.lowerLeftPt.y = b.x;
	Overlap.upperRightPt.x = a.y;
	Overlap.upperRightPt.y = b.y;
	return Overlap;
}

int main() {
	Rectangle recArr[1000];
	Rectangle final;
	int n;
	int g, s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &recArr[i].lowerLeftPt.x, &recArr[i].lowerLeftPt.y, &recArr[i].upperRightPt.x, &recArr[i].upperRightPt.y);
	}
	final = recArr[0];
	for (int i = 0; i < n; i++) {
		final = overlap_rectangle(final, recArr[i]);
	}
	g = final.upperRightPt.x - final.lowerLeftPt.x;
	s = final.upperRightPt.y - final.lowerLeftPt.y;
	printf("%d", g * s);
	return 0;
}