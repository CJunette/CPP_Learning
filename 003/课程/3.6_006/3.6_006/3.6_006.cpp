// 3.6_006.cpp: This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Add(int a)
{
	++a;
}
void AddRef(int &a)
{
	++a;
}
void AddPnt(int *a)
{
	++ *a;
}

int main()
{
	int a = 0;
	int ra = a;
	int *pa = &a;

	//函数形参为值参数，传入实参为值变量，结果不对值变量产生影响。
	Add(a);
	cout << a << endl;
	//函数形参为值参数，传入实参为引用，结果不对引用指向的对象产生影响。说明形参复制的是引用指向的值，而非复制引用所指向的地址。
	a = 0;
	Add(ra);
	cout << a << endl;
	//函数形参为引用参数，传入实参为值变量，结果对实参产生影响。说明只要参数类型为引用参数，形参就会影响实参。
	a = 0;
	AddRef(a);
	cout << a << endl;
	//函数形参为值参数，传入实参为指针，结果对指针所指向的对象产生影响。说明形参复制的是指针中存储的地址，而非指针所指向的值。
	a = 0;
	AddPnt(pa);
	cout << a << endl;
	//函数形参为值参数，传入实参为指针指向的值变量，结果不对实参产生影响。与第一种情况相同。
	a = 0;
	Add(*pa);
	cout << a << endl;
}
