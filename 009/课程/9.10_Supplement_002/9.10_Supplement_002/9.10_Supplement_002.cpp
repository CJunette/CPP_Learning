// 9.10_Supplement_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里利用函数模板和dynamic_cast()，实现了之前虚函数中无法实现的数据成员的“动态绑定”。
//其基本思路就是利用函数模板来手动输入派生类类型，然后用dynamic_cast()来进行类型转换。利用转换后得到的派生类指针去调用派生类中的成员。

#include <iostream>
using namespace std;

struct Base
{
    int a = 1;
    virtual void g() { cout << "Base" << endl; }
};

struct Derived: public Base
{
    int a = 2;
    virtual void g() { cout << "Derived" << endl; }
};

//不知道这里有没有什么方法，可以让S自动初始化为t所指向对象的类型？
//不过我想了想，应该是不存在这样的方法的。因为模板的实例化时在编译期间的，但动态绑定是在运行期间的。
//也就是说，即使能有自动给S赋值的方法，其得到的值也是T类型。
//换言之，如果真的想实现那个功能，至少要先搞清楚“如何才能实现非成员函数的动态绑定”。
template<class S, class T>
void f(T *t)
{    
    if(typeid(S) != typeid(T))
    {
        S *s;
        //要注意，dynamic_cast是针指针的，而不是针对对象的。
        s = dynamic_cast<S* >(t);
        cout << s->a << endl;        
    } 
    else
    {
        cout << t->a << endl;        
    }   
    t->g();
}

int main()
{
    Base b;
    Derived d;

    Base *pb = &b;
    f<Base>(pb);

    pb = &d;
    f<Derived>(pb);    
}
