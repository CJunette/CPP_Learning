// 8.2_OperatorOverload_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//运算符重载的相关内容
//运算符重载只能重载已有的运算符。重载不会改变运算符的优先级。
//另外成员访问运算符“.”、成员指针运算符“.*”、作用域分辨符“::”、三目运算符“?:”不能被重载。

//重载可以将运算符重载为类的非静态成员函数，也可以重载为类外的非成员函数。
//首先讨论将双目运算符重载为类的非静态成员函数。

//对于任意双目操作符B，有表达式“oprd1 B oprd2”，其中oprd1为A类对象，则B应该被重载为A类的成员函数（如果A类不是自定义类而是基本类型，则需要将B重载为非成员函数），形参类型应该是oprd2所属的类型。
//经过重载后，上述表达式相当于“oprd1.operator B(oprd2)”。

#include <iostream>
using namespace std;

class Complex
{
    public:
    Complex(double real = 0, double imagine = 0):
        real(real), imag(imagine)
    {

    }
    //重载运算符时，“operator”和运算符中间需要有一个空格。形参表中的参数个数是原有的操作数个数减1（后置单目运算符除外。）
    Complex operator +(const Complex &c) const
    {
        double r = real + c.real;
        double i = imag + c.imag;
        return Complex(r, i);
    }    
    Complex operator -(const Complex &c) const
    {
        double r = real - c.real;
        double i = imag - c.imag;
        return Complex(r, i);
    }
    //关于虚数与实数的运算符重载。
    Complex operator +(double const &r) const
    {
        double re = real + r;
        return Complex(re, imag);
    }
    Complex operator -(double const &r) const
    {
        double re = real - r;
        return Complex(re, imag);
    }
    void display() const
    {
        cout << "(" << real << ", " << imag << ")" << endl;
    }

    private:
    double real;
    double imag;
};

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    c3 = c1 - c2;
    cout << "c3 = c1 - c2 = ";
    c3.display();
    c3 = c1 + c2;
    cout << "c3 = c1 + c2 = ";
    c3.display();
    c3 = c1 + 1;
    cout << "c3 = c1 + 1 = ";
    c3.display();
}

