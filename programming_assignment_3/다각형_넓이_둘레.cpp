#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void mp(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

float ccw(Point p, Point q, Point r) {
	float first = (q.getX() - p.getX()) * (r.getX() - p.getX());
	float second = (q.getY() - p.getY()) * (r.getY() - p.getY());
	float result = first - second;
	return result;
}

class Polygon {
private:
	Point *points = new Point[n];
	int n;
	int count = 0;
public:
	Polygon(int n) {
		this->n = n;
	}
	~Polygon() {
		delete[] points;
	}
	void addPoint(int x, int y) {
		points[count].mp(x, y);
		count++;
	}
	long roundc() {
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum = sum + sqrt(pow(points[i % n].getX() - points[(i + 1) % n].getX(), 2) + pow(points[i % n].getY() - points[(i + 1) % n].getY(), 2));
		}
		return sum+0.5;
	}
	long long areac() {
		float ar;
		float sum = 0, ccwr;
		for (int i = 1; i < n-1; i++) {
			ccwr = ccw(points[0], points[i], points[i+1]);
			sum += ccwr;
		}
		if (sum < 0) sum *= -1;
		sum = sum / 2;
		return sum + 0.5;
	}
};

int main(void) 
{
	int n;
	int x, y;
	cin >> n;
	Polygon poly(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		poly.addPoint(x, y);
	}
	cout << poly.roundc() << endl;
	cout << poly.areac() << endl;
	~poly();
	return 0;
}


