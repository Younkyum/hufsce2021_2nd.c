#include <stdio.h>
#include <math.h>

struct Point {
	int dx;
	int dy;
};

void move(struct Point *P, int deltaX, int deltaY) {
	P->dx = P->dx + deltaX;
	P->dy = P->dy + deltaY;
}

int main() {
	struct Point P1, P2;
	int dx, dy;
	scanf("%d %d %d %d", &P1.dx, &P1.dy, &P2.dx, &P2.dy);
	scanf("%d %d", &dx, &dy);
	move(&P1, dx, dy);
	move(&P2, dx, dy);
	printf("%d %d %d %d", P1.dx, P1.dy, P2.dx, P2.dy);
}