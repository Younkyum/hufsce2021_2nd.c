#include <iostream>
using namespace std;

class Circle
{
private:
	double radius;
public:
	void setRadius(double radius);
	double getArea();
};

void Circle::setRadius(double radius) {
	this -> radius = radius;
}
double Circle::getArea() {
	double area;
	area = radius * radius * 3.14;
	return area;
}

int main() {
	int n = 0;
	int count = 0;
	double rad;
	cin >> n;
	Circle* arr = (Circle*)malloc(sizeof(Circle) * n);
	for (int i = 0; i < n; i++) {
		cin >> rad;
		arr[i].setRadius(rad);
		if (arr[i].getArea() > 100) {
			count++;
		}
	}
	cout << count << endl;
}