#include <iostream>
#include <string>
#define PI 3.14
using namespace std;

class Shape
{
protected:
	int x,y;
public:
	void setOrigin(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	virtual void draw()
	{
		cout<<"Shape Draw"<<endl;
	}
	virtual void move(int x, int y) = 0;
	virtual double getArea() = 0;
	virtual Shape* createShape() = 0;
};

class Rectangle : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Rectangle Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y) override
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() 
	{
		return width * height;
	}
	virtual Shape* createShape()
	{
		return new Rectangle;
	}
};

class Ellipse : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Ellipse Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y) override
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() override
	{
		return height * width * PI;
	}
	virtual Shape* createShape()
	{
		return new Ellipse;
	}
};
class Triangle : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Triangle Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() override
	{
		return width * height * 0.5;
	}
	virtual Shape* createShape()
	{
		return new Triangle;
		}
};
int main()
{
	Rectangle r;
	Ellipse e;
	Triangle t;
	//createShape로 도형생성
	Shape *pr = r.createShape(); //rectangle
	Shape *pe = e.createShape(); //Ellipse
	Shape *pt = t.createShape(); //Triangle	 
	pr->setOrigin(3, 5);
	((Rectangle *) pr)->setWidth(4);
	((Rectangle *) pr)->setHeight(2);
	//pr:기준점(3,5) width 4, height 2 설정
	
	pe->setOrigin(3, 3);
	((Ellipse *) pe)->setWidth(4);
	((Ellipse *) pe)->setHeight(2);
	//pe:기준점(3,3) width 4, height 2 설정
	
	pt->setOrigin(2, 2);
	((Triangle *) pt)->setWidth(4);
	((Triangle *) pt)->setHeight(2);
	//pt:기준점(2,2) width 4, height 2 설정

	pr->draw();
	cout<<"면  적 : "<<pr->getArea()<<endl;
	pr->move(2,1);
	pe->draw();
	cout<<"면  적 : "<<pe->getArea()<<endl;
	pe->move(2,0);
	pt->draw();
	cout<<"면  적 : "<<pt->getArea()<<endl;
	pt->move(0,1);
	return 0;
}

