// 5.8_Supplement_005_StaticMember.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p157提到，静态成员函数访问非静态数据成员时，必须通过对象名。


#include <iostream>
using namespace std;

class A
{
    public:
    static void f(A a)
    {
        cout << a.i << endl;

        //下面这个写法是错误的。
        /*
        cout << i << endl;
        */
    }

    int getI() { return i; }

    private:
    int i;
};


int main()
{
    //这里其实有个问题，就是为什么i的值被初始化为0了。按道理在没有写构造函数的情况下，这里的i值应该是一个垃圾值才对。
    //难道用A()这种类型构造的临时对象是会被给予默认值的吗？
    A::f(A());

    cout << A().getI() << endl;

    A a;
    cout << a.getI() << endl;
    A::f(a);
}
