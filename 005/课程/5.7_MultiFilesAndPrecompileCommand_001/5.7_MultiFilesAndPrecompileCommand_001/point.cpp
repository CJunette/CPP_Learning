#include "point.h"
#include <iostream>

using namespace std;

int Point::count = 0;

//ע�⣬�ֿ�д��ͬ���ֵ�ʱ��һ��Ҫ�ڶ����ຯ����ʱ�����ǰ���������
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

//�����ƺ�������дһ��static����̬�����ھ��嶨��ʱ������дһ��static����������ͬһ�ļ����ǲ�ͬ�ļ�����
void Point::showCount()
{
	cout << "Count: " << count << endl;
}
