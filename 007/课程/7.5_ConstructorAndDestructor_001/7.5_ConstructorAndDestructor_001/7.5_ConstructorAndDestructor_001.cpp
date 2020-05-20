// 7.5_ConstructorForDerivedClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//派生类的构造函数

#include <iostream>
using namespace std;

//派生类的构造函数有3个主要任务：
//用构造函数初始化派生类新增的成员。
//调用基类的构造函数初始化继承来的基类的成员。
//派生类的构造函数必须将基类构造函数需要的参数传递给它。

class Base1
{
	public:
	int b1;
	Base1(int b = 1)
	{
		b1 = b;
		cout << "Calling Base1 constructor..." << endl;
	}
};

class Base2: public Base1
{
	public:
	//1.C++11允许用using语句继承基类的构造函数。但这种构造函数只能初始化从基类继承的成员。此时不需要括号。
	using Base1::Base1;
	//1.对于b2这个派生类中新出现的成员，基类的构造函数时无法对其初始化的，因此其值会被初始化为垃圾值。
	//1.因此这种构造函数通常只会用在派生类没有添加新成员的情况下。（但如果派生类没有添加新成员，那就等于和基类一样了，所以等于说这种构造函数没有实际用处。）
	int b2;
	//1.此时，如果重新写了一个类的构造函数，那么那行“using”就不再起作用了，构造函数会调用基类的默认构造函数，如果基类不存在默认构造函数则会报错。
	/*
	Base2()
	{
		b2 = 2;
	}
	*/
	//1.此时如果创建一个基类对象的同名成员，基类的构造函数还是会被照常执行，但之后派生类的成员会覆盖基类对象的成员。
	/*
	int b1;
	*/
};

//2.单继承的情况如下。
class Base3: public Base1
{
	public:
	Base3(int b1, int b3);
	int b3;
};
//2.构造函数写在类体内外都可以。
Base3::Base3(int b1, int b3):
	Base1(b1), b3(b3)
{
	cout << "Calling Base3 constructor..." << endl;
}

//3.Base4的定义与Base1类似，不是任何类的派生类。
class Base4
{
	public:
	int b4;
	Base4(int b = 4)
	{
		b4 = b;
		cout << "Calling Base4 constructor..." << endl;
	}
	Base4(const Base4 &base4):
		b4(base4.b4)
	{
		cout << "Calling Base4 copy constructor..." << endl;
	}
};

//3.多继承的情况下，需要为所有基类的构造函数提供参数并初始化。
class Base5: public Base1, public Base4
{
	public:
	int b5;
	Base5(int b1 = 1, int b4 = 4, int b5 = 5):
		Base1(b1), Base4(b4), b5(b5)
	{
		cout << "Calling Base5 constructor..." << endl;
	}
};

//4.Base6的定义与Base1类似，不是任何类的派生类。
class Base6
{
	public:
	int b6;
	Base6(int b = 6)
	{
		b6 = b;
		cout << "Calling Base6 constructor..." << endl;
	}
};

//4.当派生类中既存在继承又存在对象成员时，派生类的构造函数需要将这些对象全都初始化。
//4.这些构造函数的调用次序为：首先调用基类构造函数（按基类声明时从左向右），再对初始化列表中的成员进行初始化（按在类中定义的顺序，对象成员在其中），最后执行派生类的构造函数体中的内容。
class Base7: public Base1, public Base6
{
	public:
	int b7;
	Base4 base4;
	Base7(Base4 &base4, int b1 = 1, int b6 = 6, int b7 = 7):
		//4.可以看到，初始化列表中的排序并不影响最终的初始化顺序。
		b7(b7), base4(base4), Base1(b1), Base6(6)
	{
		cout << "Calling Base7 constructor..." << endl;
	}
};

int main()
{
	Base1 b1;
	cout << endl;
	Base2 b2;
	cout << endl;
	Base3 b3(1, 3);
	cout << endl;
	Base4 b4(4);
	cout << endl;
	Base5 b5(1, 4, 5);
	cout << endl;
	Base6 b6(6);
	cout << endl;
	Base7 b7(b4, 1, 6, 7);
	cout << endl;

}
