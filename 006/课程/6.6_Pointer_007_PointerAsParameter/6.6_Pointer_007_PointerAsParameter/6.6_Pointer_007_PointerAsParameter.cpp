// 6.6_Pointer_007_PointerAsParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上的一个例子。
//其实用指针做实参和用数组做实参十分相似。

#include <iostream>
using namespace std;

void splitFloat(float x, int *intPart, float *floatPart)
{
    *intPart = (int)x;
    *floatPart = x - *intPart;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		float x;
		cout << "Please input a float." << endl;
		cin >> x;
		//在这里不能写两个未初始化的指针，会直接报错（使用未初始化的内存）；也不能写两个空指针，因为在splitFloat()中是要让指针指向的地址存储值的，而空指针所指向的地址并不能存值。
		int intPart[1];
		float floatPart[1];
		//老师课上的举例是创建了一个float类型的变量、一个int类型的变量，然后在函数这里将两个变量的地址作为指针传入。
		splitFloat(x, intPart, floatPart);
		cout << "Int Part: " << *intPart << endl;
		cout << "Float Part: " << *floatPart << endl;
		cout << endl;
	}
}
