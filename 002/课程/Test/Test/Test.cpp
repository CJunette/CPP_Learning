// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	int a = 1;
	cout << a++ << endl;
	cout << a << endl;

	cout << endl;

	int b = 1;
	cout << ++b << endl;
	cout << b << endl;

	cout << endl;

	int c = 2;
	//赋值结果的类型由左侧被赋值的变量决定。
	c = (double)c + 1;
	double d = c + 1;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	cout << endl;

	int e = -8;
	e >>= 2;
	cout << e << endl;
	
	cout << endl;
	char f = 0x21;
	cout << f << endl;
	cout << (0 || sizeof(int)) << endl;
	char g = true;	
	//不这么写就没法输出g。
	cout << g << endl;

	cout << endl;

	double h = double(1), h = (double)2, h = static_cast<double>(3);
	cout << h << endl;
}
