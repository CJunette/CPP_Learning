// 5.2_ScopeAndVisiblity_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//1.函数原型作用域，范围只在函数的形参表的“()”之中。
//之前我们说函数的生命可以只有形参类型没有形参名，就是因为声明时形参的作用域只在形参表内，因此有没有形参名其实不会造成影响。
int test1(int, int);


//3.类的作用域包括类体和类外的成员函数体。
//在类外访问类的成员需要用“.”操作符，且受访问权限限制。访问可以通过类名（静态成员），类的对象名，对象的引用，对象指针等方式。
class TestClass
{
	public:
	void setA(int x) { a = x; }
	void setB(int y);

	private:
	int a, b;
};

void TestClass::setB(int y)
{
	b = y;
}

//4.文件作用域，起始于声明点，结束于文件尾。就是常说的全局变量。
double PI = 3.1415926535898;


static union
{
	int i;
	int f;
};

int main()
{
	i = 42;
	cout << i << endl;
	cout << &i << endl;

	//
	int i = 43;
	cout << i << endl;
	cout << &i << endl;
}


//2.局部作用域，范围是变量所在的最内侧的“{}”所包围的范围。
//这里在函数定义的时候，函数的形参就在局部作用域中起效。
int test1(int a, int b)
{
	//a、b、c的作用域在函数test1()中。
	int c = 0;
	if (a + b > 0)
	{
		//d的作用域在if语句中。
		int d = 0;
		return a + b + c + d;
	}
	else
	{
		return a + b;
	}
    
}