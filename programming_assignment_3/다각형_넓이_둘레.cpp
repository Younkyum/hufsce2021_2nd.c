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
	float roundc() {
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum = sum + sqrt(pow(points[i % n].getX() - points[(i + 1) % n].getX(), 2) + pow(points[i % n].getY() - points[(i + 1) % n].getY(), 2));
		}
		return sum;
	}
	float areac() {
		float ar;
		float x3, y3;
		float x1, y1, x2, y2;
		float sumx = 0, sumy = 0;
		for (int i = 0; i < n; i++) {
			sumx += points[i].getX();
			sumy += points[i].getY();
		}
		x3 = sumx / n;
		y3 = sumy / n;
		x1 = points[0].getX(); 
		y1 = points[0].getY();
		x2 = points[1].getX(); 
		y2 = points[1].getY();
		ar = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
		if (ar >= 0) { 
		ar = ar/2 * n; 
		}
		else { 
		ar = (-1) * ar/2 * n; 
		}
		return ar;
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
	return 0;
}
