// 8.2_OperatorOverload_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//将运算符重载为类外的非成员函数。

#include <iostream>
using namespace std;

class Complex
{
    public:
    Complex(double r = 0, double i = 0):
        real(r), imag(i)
    {
    }
    //将运算符重载函数声明为类的友元，以便访问类的私有对象。声明友元函数是需要带上参数列表。
    //这里其实引发了一些问题，当声明友元函数时需要附带函数列表的话，操作符的参数列表不同的重载就都需要在类内进行友元声明。
    friend Complex operator +(Complex const &c1, Complex const &c2);
    friend Complex operator -(Complex const &c1, Complex const &c2);
    friend ostream& operator <<(ostream &o, Complex const&c);

    private:
    double real, imag;
};

Complex operator +(Complex const &c1, Complex const &c2)
{
    double r = c1.real + c2.real;
    double i = c1.imag + c2.imag;
    return Complex(r, i);
}

Complex operator -(Complex const &c1, Complex const &c2)
{
    double r = c1.real - c2.real;
    double i = c1.imag - c2.imag;
    return Complex(r, i);
}

//此处第一个形参是输出流类的对象，不能用const，因为运算符需要修改其值。
//“<<”操作符的原理是，将需要输出的数据全都用“<<”输入一个ostream类型的对象中，当需要在屏幕上输出是，就选择cout为对象。
ostream& operator <<(ostream &out, Complex const &c)
{
    //将“<<”右侧的数据传入输出流对象中。
    out << "(" << c.real << ", " << c.imag << ")";
    return out;
}

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    //由于在类外重载了“<<”操作符，因此可以直接在“<<”后接Complex的对象。
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    c3 = c1 - c2;
    cout << "c3 = c1 - c2 = " << c3 << endl;
    c3 = c1 + c2;
    cout << "c3 = c1 + c2 = " << c3 << endl;
}
