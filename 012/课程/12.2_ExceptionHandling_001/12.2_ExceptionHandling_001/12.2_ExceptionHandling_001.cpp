// 12.2_ExceptionHandling_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例12-1，处理除零异常。

#include <iostream>
using namespace std;

//4.为了让函数在被调用时，调用者能清楚地知道函数有可能出现哪些异常，会在函数名后面写“throw(A, B, C, D)”这样的异常接口声明。其中的“ABCD”就是可能的异常对象的数据类型。
//4.如果没有异常接口声明，则说明当前函数有可能抛出任何异常。
//4.如果函数不会抛出任何异常，则可用“double divide(int x, int y) throw()”的写法。
double divide(int x, int y) throw(int)
{
	if(y == 0)
	{
		//1.抛出异常的对象可以是自己构造的，包含诸多错误信息的对象。
		//1.也可以是一般的基本类型的对象。
		throw x;
	}
	return x / y;
}

int main()
{
	try
	{
		cout << "5 / 2 = " << divide(5, 2) << endl;
		cout << "8 / 0 = " << divide(8, 0) << endl;
		//3.当“8 / 0”抛出异常后，后面的“7 / 1”就不在继续被执行了。
		cout << "7 / 1 = " << divide(7, 1) << endl;
	}
	//2.由于上面的divide()抛出的对象是x，因此这里catch的数据类型就是int。
	catch(int e)
	{
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is ok" << endl;
}
