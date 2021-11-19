#include <iostream>
#include <string>
using namespace std;
const float pi=3.14;

class Shape {
public:
	int x;
	int y;
};

class Square : Shape {
private:
	int width;
	int height;
public:
	Square();
	Square(int xpoint, int ypoint, int width, int height) {
		x = xpoint;
		y = ypoint;
		this->width = width;
		this->height = height;
	}
	float getArea() {
		float ar;
		ar = height * width;
		return ar;
	}
	void print() {
		cout << "shape at (" << x << ", " << y << ") : width=" << width << " height=" << height;
		cout << fixed;
		cout.precision(2);
		cout << " area=" << getArea() << endl;
	}
};
class Circle : Shape {
private:
	flaot radius;
public:
	Circle();
	Circle(int xpoint, int ypoint, flaot radius) {
		x = xpoint;
		y = ypoint;
		this->radius = radius;
	}
	float getArea() {
		float ar;
		ar = radius*radius*pi;
		return ar;
	}
	void print() {
		cout << "shape at (" << x << ", " << y << ") : radius=" << radius;
		cout << fixed;
		cout.precision(2);
		cout << " area=" << getArea() << endl;
	}
};
class Triangle : Shape {
private:
	int width;
	int height;
public:
	Triangle();
	Triangle(int xpoint, int ypoint, int width, int height) {
		x = xpoint;
		y = ypoint;
		this->width = width;
		this->height = height;
	}
	float getArea() {
		float ar;
		ar = width * height * 0.5;
		return ar;
	}
	void print() {
		cout << "shape at (" << x << ", " << y << ") : width=" << width << " height=" << height;
		cout << fixed;
		cout.precision(2);
		cout << " area=" << getArea() << endl;
	}
};



int main(){
   int check=0;
   int xpoint, ypoint;
   double width, height;
   double radius;

   cin>>check;
   if(check==0){
      cin>> xpoint >> ypoint>> width >> height;
      //Square 객체 만들고 print함수 실행
      Square S(xpoint,ypoint,width,height);
      S.print();
   }
   else if(check==1){
      cin>>xpoint>>ypoint >> radius;
      //Circle 객체 만들고 print함수 실행
      Circle C(xpoint,ypoint,radius);
      C.print();
   }
   else{
      cin>>xpoint >> ypoint >> width >> height;
      //Triangle 객체 만들고 print함수 실행
      Triangle T(xpoint, ypoint,width,height);
      T.print();
   }

   return 0;
}
