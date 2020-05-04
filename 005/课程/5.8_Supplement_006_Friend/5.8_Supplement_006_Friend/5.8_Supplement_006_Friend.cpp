// 5.8_Supplement_006_Friend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//关于友元不能传递的补充。

#include <iostream>
using namespace std;

class C
{
	friend class B;
	int c = 1;
};

class B
{
	friend class A;

	int b = 0;

	public:
	C c;
	void show()
	{
		cout << c.c << endl;
	}
};

class A
{
	public:
	B b;
	void show()
	{
		cout << b.b << endl;

		//友元不能传递
		/*
		cout << b.c.c << endl;
		*/
	}
};

int main()
{

}