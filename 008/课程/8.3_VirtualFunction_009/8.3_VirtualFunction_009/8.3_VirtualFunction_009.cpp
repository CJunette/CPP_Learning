// 8.3_VirtualFunction_009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//多继承与虚函数

#include <iostream>
using namespace std;

class Base1
{
	public:
	virtual void func() { cout << "Base1" << endl; }
};
class Base2
{
	public:
	virtual void func() { cout << "Base2" << endl; }
};
class Derived1: public Base1, public Base2
{
	public:	
	//1.这里出现了一个问题，当两个类中都有同名虚函数，且同时成为一个派生类的基类。此时如果在派生类中重写虚函数，会被视为是重写哪一个？
	virtual void func() { cout << "Derived1" << endl; }
	//5.如果说两个类中虚函数是纯虚函数，则可以用下面这种形式实现分开的重写。
	/*
	virtual void Base1::func() { cout << "Derived1 from Base1" << endl; }
	virtual void Base2::func() { cout << "Derived1 from Base2" << endl; }
	*/
};
class Derived2: public Base1, public Base2
{
};

int main()
{
	Derived1 d1;
	Base1 *pb1 = &d1;
	Base2 *pb2 = &d1;
	//2.从输出的角度来看，两个基类的虚函数都被覆盖了。
	pb1->func();
	pb2->func();
	//3.如果通过命令行查看类在内存中的分布会发现，只有基类声明时排序在第一个的基类的虚表中存放了指向重写后的虚函数的指针。
	//3.而其余的基类的虚表会有一个跳转到第一个基类虚表中虚函数指针的指针。

	Derived2 d2;
	Derived2 *pd2 = &d2;	
	//4.如果在多继承的派生类中没有对两个基类中同名的虚函数重载，则这两个虚函数就相当于普通的成员函数。
	//4.无法直接用派生类调用这两个虚函数，因为两者同名，编译器无法区分。
	/*
	pd2->func();
	*/
	//4.而由于两个基类都会给派生类虚表指针，因此用基类的指针去调用时会分别根据两个虚表指针去调用对应的虚函数，而不会发生混淆。
	Base1 *pb12 = &d2;
	pb12->func();
	Base2 *pb22 = &d2;
	pb22->func();
}
