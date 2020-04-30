//Definition of class Point.
//point.cpp

#include "point.h"
#include <iostream>

using namespace std;

//ע�⣬�ֿ�д��ͬ���ֵ�ʱ��һ��Ҫ�ڶ����ຯ����ʱ�����ǰ���������
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

//�����ƺ�������дһ��static����̬�����ھ��嶨��ʱ������дһ��static����������ͬһ�ļ����ǲ�ͬ�ļ�����
void Point::showCount()
{
	cout << "Count: " << count << endl;
}

int Point::count = 0;