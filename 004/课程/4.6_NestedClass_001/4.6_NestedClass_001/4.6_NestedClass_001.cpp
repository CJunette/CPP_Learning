// 4.6_NestedClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int a, int b) :
        x(a), y(b)
    {
        cout << "Calling Point constructor.\n";
    }
    //����Point�౻Line�൱����Աʹ�ã�������Point��û��Ĭ�Ϲ���������Line���ڳ��Դ���Ĭ�ϵ�Point����ʱ�ͻᱨ��    
    Point() :
        Point(0, 0)
    {}
    

    Point(const Point &pnt)
    {
        x = pnt.x;
        y = pnt.y;
        cout << "Calling point copy constructor.\n";
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    private:
    int x, y;
};

class Line
{
    public:
    Line(Point a, Point b) :
        p1(a), p2(b)
    {
        double x = (double)(a.getX() - b.getX());
        double y = (double)(a.getY() - b.getY());
        length = sqrt(x * x + y * y);
        cout << "Calling line constructor.\n";
    }
    
    Line()
    {
        Point a, b;
        p1 = a;
        p2 = b;
        length = 0;
        cout << "Calling line constructor.\n";
    }
    
    Line(Line &line) :
        p1(line.p1), p2(line.p2), length(line.length)
    {
        cout << "Calling line copy constructor.\n";
    }

    double getLength()
    {
        return length;
    }

    private:
    Point p1, p2;
    double length;
};

class Face
{
    private:
    Line l1, l2, l3;
};

int main()
{
    Point myp1(1, 1), myp2(4, 5);        
    //�ڴ˿��Կ�������������ʽ��ϣ���ֵ�Ǵ��βε��Ҳ࿪ʼ�ġ�����Ӧ��ϵ�Ľ����Ǵ������ҵģ�
    Line l1(myp1, myp2);
    Line l2(l1);
    cout << "The length of l1 is " << l1.getLength() << ".\n";
    cout << "The length of l2 is " << l2.getLength() << ".\n"; 

    //ע�⣬����������Ǵ���ġ����������ᱨ����ֱ������������䡣
    Line l3(Point a, Point b);
}

