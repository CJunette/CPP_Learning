//Headfile
//point.h
//ע�⣬����Ҫ�Ȱ������#pragma once��ȥ��������һ������ͷ�ļ��ظ������Ԥ����ָ���Ϊ��Ҫ˵���������԰���ȥ����
/*
#pragma once
*/


#include <iostream>

//2.������Ԥ����ָ���������ظ����塣
//2.�������HEAD_Hδ�����������ô�ͽ�����HEAD_H��Ȼ�󽫴������е�#endif��λ�á�
//2.���HEAD_H�Ѿ��������ˣ���ô��������δ��롣
#ifndef HEAD_H
#define HEAD_H


using namespace std;

//4.ע��������Ϊ�����λ�õ����ˣ�����Ҫ��������������Ƶ�ǰ������
//4.��Ȼ����˵���������Ķ���ͨ��Ҫ����ͷ�ļ������������ظ�����ͷ�ļ������⣬�����ظ�������������������Ļ������������ǻᱨ��
//4.���������Ǿ仰�ǽ���������������ͷ�ļ�����ʱ�Ѿ�����Ԥ����ָ����������������ظ����������µġ�
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