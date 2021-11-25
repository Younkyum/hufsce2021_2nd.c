#include <iostream> 
using namespace std;

class shape {
private:
	double width;
	double height;
public:
	virtual double getArea() {
		return width * height;
	}
	virtual void move(int x, int y) = 0;
	virtual void createShape() = 0;
};


