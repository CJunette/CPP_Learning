// 8.5_Supplement_005_VirtualFunctionInDiamondInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//菱形继承中的虚函数。

#include <iostream>
using namespace std;

class Base0
{
	public:
	virtual void func() { cout << "Base0" << endl; }
	int a = 0;
};

class Base1: virtual public Base0
{
	public:
	virtual void func() { cout << "Base1" << endl; }
	int a = 1;
};
class Base2: virtual public Base0
{
	public:
	virtual void func() { cout << "Base2" << endl; }
	int a = 2;
};
class Derived1: public Base1, public Base2
{
	public:
	virtual void func() { cout << "Derived1" << endl; }
	int a = 3;
};

int main()
{
	//在用虚继承处理菱形继承问题时，虚表指针会被认为是来自于共同基类的成员，因此被放入“共同区域”中。
	//因此，在派生类Derived1中，会有两个来自直接基类Base1和Base2的指向共同区域的指针，在共同区域中，会有一个虚表指针。
	//换言之，菱形继承的情况下，通过虚表调用，就只能调用到一个虚函数。且派生类必须对直接基类的虚函数进行重写，不然会重写函数重名的错误。
	Derived1 d1;
	Base1 *pb1 = &d1;
	Base2 *pb2 = &d1;
	pb1->func();
	pb2->func();	
}