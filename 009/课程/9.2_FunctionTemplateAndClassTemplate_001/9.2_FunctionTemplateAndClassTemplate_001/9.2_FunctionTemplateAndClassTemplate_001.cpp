// 9.2_FunctionTemplateAndClassTemplate_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//函数模板

#include <iostream>
using namespace std;

class A
{};
ostream &operator << (ostream &out, A)
{
    out << "class A" << endl;
    return out;
}

class B
{
    public:
    double b = 0;    
    double operator -()
    {
        return -b;
    }
    bool operator <(double x)
    {
        if(b < x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream &operator << (ostream &out, B b)
{
    out << "class B: " << b.b << endl;
    return out;
}

class C
{
    public:
    C(double c = 0):
        c(c)
    {}
    double c = 0;
    double operator -()
    {
        return -c;
    }
    bool operator <(double x)
    {
        if(c < x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream &operator << (ostream &out, C c)
{
    out << "class C: " << c.c << endl;
    return out;
}

//1.这里的typename T就是类型参数。在需要调用函数时，编译器会从实参的类型推导出函数模板的类型参数。
template <typename T>
T abs(T x)
{
    return x < 0 ? -x : x;
}

//2.函数模板支持模板参数表中有多个参数。
template <class T1, class T2>
T1 add(T1 t1, T2 t2)
{
    return t1 + t2;
}

int main()
{
    {
        //1.课上的例子。
        double a = -5.5;
        int b = 5;
        //1.在类型参数确定之后，编译器将以函数模板为样板，生成一个函数。这一过程称为函数模板的实例化。
        //1.如，针对下面的abs(a)，编译器实际上会生成
        /*
        int abs(int x)
        {
            return x < 0 ? -x : x;
        }
        */
        //1.这样一段函数。
        cout << abs(a) << endl;

        cout << abs(b) << endl;
        cout << endl;
    }

    {
        //2.函数参数表中有多个参数的具体运算。
        double a = 1;
        int b = 2;
        cout << add(a, b) << endl;
        cout << endl;
    }

    {
        A a;
        //3.由于A类型没有重载函数模板abs中需要的运算符“<”和“-”，因此将A类的对象作为参数报错。
        /*
        cout << abs(a) << endl;
        */
        B b;
        //3.即使B类对运算符进行了重载，但由于运算符计算“x < 0 ? -x : x”的结果返回值是double类型的；而模板abs()所需要的返回值是B类型的，B类中又没有明确的以double类型为参数的构造函数。
        //3.因此此时依然会报错。
        /*
        cout << abs(b) << endl;
        */
        //3.此时，由于C类有以double为参数的构造函数了，因此abs()的运算中会将得到的x作为参数，构造出一个C类的临时对象作为返回。
        //3.然后再执行流插入运算符<<的操作。
        C c;
        cout << abs(c) << endl;
        cout << endl;
    }
}
