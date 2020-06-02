// 8.3_VirtualFunction_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里主要讨论派生类中的虚函数对基类中虚函数的覆盖及虚函数的重载。

#include <iostream>
using namespace std;

class Base1
{
	public:
	void virtual display() const { cout << "display1 in Base1" << endl; }
	//1.当下面这个有参数的display()函数不添加virtual关键字时，它不会被视为虚函数。在下面函数func1()中，输入Base2的指针仍然会调用Base1的函数。
	//1.也就是说虚函数的重载不是默认的会变成虚函数。
	void display(int a) const { cout << "display2 in Base1" << endl; }
};

class Base2: public Base1
{
	public:
	//2.而这里虽然写了“virtual”关键字，实际上也只是覆盖了之前的display()函数，重新建立了一个新的虚函数。
	void virtual display(int a) const { cout << "display2 in Base2" << endl; };
};

class Derived: public Base2
{
	public:
	void display(int a) const { cout << "display2 in Derived" << endl; };
};

void func1(Base1 *ptr)
{
	ptr->display(1);
}

void func2(Base2 *ptr)
{
	ptr->display(1);
}

void func3(Base1 *ptr)
{
	ptr->display();
}

int main()
{
	//1.从这里的输出结果可以看出，此时Base1中的带参数的display()并不是虚函数。
	Base1 b1;
	Base2 b2;
	Derived d;
	func1(&b1);
	func1(&b2);
	func1(&d);
	cout << endl;
	
	//2.这里可以看到，在基类中同名函数（且参数表和返回值相同）不是虚函数的情况下，在派生类中创建同名函数并用“virtual”修饰可以实现覆盖。
	func2(&b2);
	func2(&d);
	cout << endl;
	
	//3.虽然说在派生类继承基类的虚函数时，会隐藏基类与虚函数同名的所有其他函数，但当通过基类指针去调用时，仍然可以访问那些重载函数。
	func3(&b2);
	//3.当直接用派生类对象访问时，则会报错。
	/*
	b2.display();
	*/
}
