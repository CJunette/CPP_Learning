#include "head.h"


Point::Point(int xx, int yy) :
	x(xx), y(yy)
{
	count++;
}

Point::Point(Point &pnt) :
	x(pnt.x), y(pnt.y)
{
	count++;
}

Point::~Point()
{
	count--;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::showCount()
{
	cout << "Count: " << count << endl;
}

int Point::count = 0;


void Method::helloWorld()
{
	std::cout << "Hello World" << std::endl;
}
