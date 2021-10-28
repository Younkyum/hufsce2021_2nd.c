#include <iostream>
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
		this -> x = x;
		this -> y = y;
	}
	void setX(int x);
	void setY(int y);
	void setXY(int xVal, int yVal);
	int getX();
	int getY();
};
void Point::setX(int xv) {
	x = xv;
}
void Point::setY(int yv) {
	y = yv;
}
void Point::setXY(int xVal, int yVal) {
	x = xVal;
	y = yVal;
}
int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}

class Rectangle {
private:
	Point lowerLeft;
	Point upperRight;
public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2) {
		lowerLeft.setX(x1);
		lowerLeft.setY(y1);
		upperRight.setX(x2);
		upperRight.setY(y2);
	}
	int getArea();
	void setLowerLeftPt(Point p);
	void setUpperRightPt(Point p);
	Point getLowerLeftPt() { return lowerLeft; }
	Point getUpperRightPt() { return upperRight; }
	int overLap(Rectangle r);
	int overLap(int a, int b, int c, int d);
};

int Rectangle::getArea() {
	int a, b;
	a = upperRight.getX() * lowerLeft.getX();
	b = upperRight.getY() * lowerLeft.getY();
	return a * b;
}
void Rectangle::setLowerLeftPt(Point p) {
	lowerLeft.setX(p.getX());
	lowerLeft.setY(p.getY());
}
void Rectangle::setUpperRightPt(Point p) {
	upperRight.setX(p.getX());
	upperRight.setY(p.getY());
}
int Rectangle::overLap(Rectangle r) {
	Point a, b;
	int g, s;
	Point recll = r.getLowerLeftPt();
	Point recur= r.getUpperRightPt();
	g = overLap(lowerLeft.getX(), upperRight.getX(), recll.getX(), recur.getX());
	s = overLap(lowerLeft.getY(), upperRight.getY(), recll.getY(), recur.getY());
	return g * s;
}
int Rectangle::overLap(int a, int b, int c, int d) {
	int new1l, new1r, new2l, new2r;
	int overlapl, overlapr;
	int between;
	if (a > c) {
		new1l = c;
		new1r = d;
		new2l = a;
		new2r = b;
	}
	else {
		new1l = a;
		new1r = b;
		new2l = c;
		new2r = d;
	}
	if (new2l <= new1r) {
		overlapl = new2l;
		if (new2r <= new1r) overlapr = new2r;
		else overlapr = new1r;
		between = overlapr - overlapl;
	}
	else {
		between = 0; 
	}
	return between;
}