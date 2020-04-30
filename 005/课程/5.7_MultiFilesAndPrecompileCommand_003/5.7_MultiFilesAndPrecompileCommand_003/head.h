//Headfile
//point.h
//注意，这里要先把这个“#pragma once”去掉。这是一个避免头文件重复定义的预编译指令。因为我要说明错误，所以把它去掉。
/*
#pragma once
*/


#include <iostream>

//2.这里用预编译指令来避免重复定义。
//2.如果符号HEAD_H未被定义过，那么就将定义HEAD_H，然后将代码运行到#endif的位置。
//2.如果HEAD_H已经被定义了，那么久跳过这段代码。
#ifndef HEAD_H
#define HEAD_H


using namespace std;

//4.注意这里因为定义的位置调整了，所以要把这个内联函数移到前面来。
//4.虽然书上说内联函数的定义通常要放在头文件里，但如果遇到重复调用头文件的问题，导致重复定义内联函数的问题的话，编译器还是会报错。
//4.所以书上那句话是建立在内联函数的头文件定义时已经用了预编译指令避免内联函数被重复定义的情况下的。
inline void countChange()
{
	std::cout << "count number changed" << std::endl;
}

class Point
{
	public:
	Point(int xx = 0, int yy = 0);
	Point(Point &pnt);
	~Point();
	int getX() const;
	int getY() const;
	static void showCount();

	private:
	int x, y;
	static int count;
};


Point::Point(int xx, int yy) :
	x(xx), y(yy)
{
	count++;
	countChange();
}

Point::Point(Point &pnt) :
	x(pnt.x), y(pnt.y)
{
	count++;
	countChange();
}

Point::~Point()
{
	count--;
	countChange();
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


#endif // !HEAD_H