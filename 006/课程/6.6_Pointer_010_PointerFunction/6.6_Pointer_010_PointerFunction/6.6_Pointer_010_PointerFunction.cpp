// 6.6_Pointer_010_PointerFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上关于正确使用指针函数的例子。

#include <iostream>
using namespace std;

//就这个程序本身进行一些补充。
//这里之所以传入a[]后返回的地址是合法有效的，是因为传入的数组名a本身是一个指针。
//如果这里传入的不是数组、不是引用、不是指针，而是一个普通的值或对象，那么在返回的时候那个地址仍然是无效的局部范围内的将要失效的地址。
//因为那种不涉及地址的操作实际上都是在传参区域创建了一个原标识符的副本。而这个副本在函数调用完成后就会失效。
int *searchZero(int a[], int n)
{
	//注意，在这个函数里，a就相当于一个地址值，因此用sizeof()计算a的大小就相当于计算一个地址的大小。
	/*
    int size = sizeof(a);
	*/
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			return &a[i];
		}
	}
	return 0;
}

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	//而在数组定义的函数中，用sizeof()计算a的大小就相当于计算整个数组的大小。
	//根据知乎上的回答https://www.zhihu.com/question/54437699，数组类型的参数在传递给函数的时候，数组类型会退化成相应的指针类型。
	//潜台词就是说数组类型的变量并不像我们一直说的就是指向数组首个成员的地址的指针。
	int *returnValue = searchZero(a, sizeof(a)/sizeof(int));
	if (returnValue)
	{
		cout << "There is 0." << endl;
		cout << "a[" << returnValue - a << "] = " << *returnValue << endl;
	}
	else
	{
		cout << "There is no 0." << endl;
	}
}
