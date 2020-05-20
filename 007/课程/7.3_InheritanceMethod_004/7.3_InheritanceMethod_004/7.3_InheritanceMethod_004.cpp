// 7.3_InheritanceMethod_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//多继承时的继承方式问题

#include <iostream>
using namespace std;

class A
{
    public:    
    void showA() const { cout << a << endl; }
    void setA(int sa) { a = sa; }
    private:
    int a;
};
class B
{
    public:
    void showB() const { cout << b << endl; }
    void setB(int sb) { b = sb; }
    private:
    int b;
};
//一个类可以从多个类中继承。对于不同的类可以用不同的继承方式。
class C :public A, private B
{
    public:
    void showC() const
    { 
        //这里必须调用之前为public的成员函数，不能直接访问private对象。
        showA();
        showB();
        cout << c << endl; 
    }
    void setC(int sa, int sb, int sc)
    {
        setA(sa);
        setB(sb);
        c = sc;
    }
    private:
    int c;
};

int main()
{
    C obj;
    obj.setA(5);
    obj.showA();
    obj.setC(6, 7, 9);
    obj.showC();
    //由于C对B的继承是private的，因此无法直接调用showB()和setB()函数。
    /*
    obj.setB(6);
    obj.showB();
    */
}
