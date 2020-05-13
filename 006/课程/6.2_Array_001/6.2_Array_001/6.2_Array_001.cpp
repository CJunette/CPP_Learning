// 6.2_Array_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[10], b[10];
	//如果把下面的条件改为i<=10，确实会发生错误。但错误并不是因为对不该访问的内存进行了赋值操作，而是b数组的下边在i=10的时候变成了负值。
	for (int i = 0; i < 10; i++)
	{
		a[i] = 2 * i - 1;
		b[9 - i] = a[i];
	}

	//因为下面的循环条件被我修改了，所以出现了数组越界的情况。正确的写法是把“<=”改为“<”。
	for (int i = 0; i <= 10; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
		cout << "b[" << i << "] = " << b[i] << endl;
	}
}

