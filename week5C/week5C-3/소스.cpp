#include <stdio.h>
#include <math.h>

struct Fraction {
	int numerator; //����
	int denominator; //�и�
};

int gcd(int a, int b) {
	int r;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

void print(struct Fraction r) {
	if (r.denominator < 0) {
		r.numerator *= -1;
		r.denominator *= -1;
	}
	printf("%d/%d\n", r.numerator, r.denominator);
}

struct Fraction reduce(struct Fraction r) {
	int gcdNumDen;
	if (r.numerator == 0 || r.denominator == 0) {
		return r;
	}
	gcdNumDen = gcd(r.numerator, r.denominator);
	r.numerator = r.numerator / gcdNumDen;
	r.denominator = r.denominator / gcdNumDen;
	return r;
}

struct Fraction add(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
	r = reduce(r);
	return r;
}

int main() {
	struct Fraction r1, r2, result;
	scanf("%d %d %d %d", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	result = add(r1, r2);
	print(result);
	return 0;
}