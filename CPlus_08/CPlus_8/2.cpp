#include <iostream>
#include <string>
#include "selector.h"
using namespace std;

class Shape
{
public:
	Shape(int x, int y) : x(x), y(y)
	{

	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setName(string n)
	{
		name = n;
	}
	void display()
	{
		cout << name << " 의 위치는" << getX() << ", " << getY() << "이고 "
			<< "면적(넓이)은" << getArea() << "입니다." << endl;
	}
	virtual int getArea() = 0;
private:
	int x, y;
	int area;
	string name;
};
class Rectangle : public Shape
{
public:
	Rectangle(int x, int y,int w,int h) : Shape(x,y),width(w),height(h)
	{
		setName("Rectangle");
		display();
	}
	int getArea()
	{
		return width * height;
	}
private:
	int width, height;
};
int current()
{
	Rectangle r(3, 4, 5, 2);
	return 0;
}