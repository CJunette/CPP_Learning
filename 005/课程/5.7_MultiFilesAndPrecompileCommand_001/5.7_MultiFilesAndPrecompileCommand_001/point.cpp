#include "point.h"
#include <iostream>

using namespace std;

int Point::count = 0;

//注意，分开写不同部分的时候，一定要在定义类函数的时候加上前面的类名！
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

//这里似乎不用再写一次static。静态函数在具体定义时不用再写一次static（不论是在同一文件还是不同文件）。
void Point::showCount()
{
	cout << "Count: " << count << endl;
}
