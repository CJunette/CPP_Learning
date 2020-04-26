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
    //1.����Point�౻Line�൱����Աʹ�ã�������Point��û��Ĭ�Ϲ���������Line���ڳ��Դ���Ĭ�ϵ�Point����ʱ�ͻᱨ��   
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
    //6.��������������Ĺ��캯����д��������ʽ������ٵ�������Point�ĸ��ƹ��캯����
    //�������������Ҫ�������еĺ�������˲������const���η���Ҳ�͵������޷���ֻ����ʽ�������ã�����������˫�򴫵ݵķ��ա�������Ҳ��ȷ������д���׶Բ��ԡ�
    /*
    Line(Point &a, Point &b) :
    */
    Line(Point a, Point b) :
        //2.�������δ�Գ�Ա����p1��p2���г�ʼ����������������ᰴ��Point��Ĭ�ϵĹ��캯�����г�ʼ����
        //��ʱ���Point��û��Ĭ�Ϲ��캯�����ͻ�ֱ�ӱ���
        p1(a), p2(b)
    {
        double x = (double)(a.getX() - b.getX());
        double y = (double)(a.getY() - b.getY());
        length = sqrt(x * x + y * y);
        cout << "Calling line constructor.\n";
    }
    
    //2.������Ҳ��һ�������LineĬ�ϵĳ�ʼ�����캯�����ǡ�Line(){}������Point��û��Ĭ�Ϲ��캯���Ļ����������ͻ���Ϊp1��p2�޷��ҵ����ڳ�ʼ����Ĭ�Ϲ��캯��������
    //����ע�⣬������Ҫдһ���յ�Ĭ�Ϲ��캯����ҲҪдLine(){}����ҪֻдLine()���ᱨ����������Point()���Ĭ�Ϲ��캯��Ҳ��������
    Line()
    {
        //2.����ΪPoint������Ĭ�ϵĹ��캯����������汻ע�͵Ĵ��뼴ʹ��ʡ�ԣ�p1��p2Ҳ�����Ĭ�Ϲ��캯�����г�ʼ����
        /*
        Point a, b;
        p1 = a;
        p2 = b;
        */
        length = 0;
        cout << "Calling line constructor.\n";
    }
    
    Line(const Line &line) :
        p1(line.p1), p2(line.p2), length(line.length)
    {
        cout << "Calling line copy constructor.\n";
    }

    double getLength()
    {
        return length;
    }

    private:
    //3.��������ĳ�ʼ��˳���ǰ��ն���Ķ���˳���������ġ����������p1��p2��length�����Ĵ���
    Point p1, p2;
    double length;
};

int main()
{
    Point myp1(1, 1), myp2(4, 5);        
    //4.�ڴ˿��Կ�������������ʽ��ϣ���ֵ�Ǵ��βε��Ҳ࿪ʼ�ġ�����Ӧ��ϵ�Ľ����Ǵ������ҵģ�
    Line l1(myp1, myp2);
    Line l2(l1);
    cout << "The length of l1 is " << l1.getLength() << ".\n";
    cout << "The length of l2 is " << l2.getLength() << ".\n"; 

    //5.ע�⣬��������������Ǵ���ġ����������ᱨ����ֱ������������䡣
    Line l3(Point a, Point b);
    Line l4();
}

