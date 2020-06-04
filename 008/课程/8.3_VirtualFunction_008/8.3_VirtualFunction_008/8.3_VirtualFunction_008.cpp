// 8.3_VirtualFunction_008.cpp : This file contains the 'main' function. Program execution begins and ends there.
//虚表与动态绑定。书上p340-343。

#include <iostream>

class Base
{
	public:
	//虚表中包括f()与g()的地址。
	virtual void f();
	virtual void g();
	private:
	int i;
};
class Derived: public Base
{
	public:
	//虚表中包括f()、g()与h()的地址。其中f()和h()指向派生类新定义的函数代码位置，g()指向基类中的函数代码位置。
	virtual void f();
	virtual void h();
	private:
	int j;
};

int main()
{
    
}
