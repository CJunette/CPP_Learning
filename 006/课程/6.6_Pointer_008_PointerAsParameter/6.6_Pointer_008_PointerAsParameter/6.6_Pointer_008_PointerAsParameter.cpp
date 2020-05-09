// 6.6_Pointer_008_PointerAsParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上的一个例子。

#include <iostream>
using namespace std;

const int N = 6;
//我们以前学到，如果不希望指针所指向的地址中的数据被改变，需要使用常量指针。
//在写程序时，遵循最小授权原则，授权越少越好。
void print(const int *p)
{
	cout << "{ ";
	for (int i = 0; i < N - 1; i++)
	{
		cout << p[i] << ", ";
	}
	cout << p[N - 1];
	cout << " }" << endl;
}

int main()
{
	int array[N];
	for (int i = 0; i < 6; i++)
	{
		cin >> array[i];
	}
	print(array);	
}
