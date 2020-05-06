// 5_Homework_5-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n;
void fn();

int main()
{
    n = 0;
	for (int i = 0; i < 10; i++)
	{
		//fn()改变的是作用域范围在fn()函数中的那个静态变量n。	
		//此时全局变量n在fn()中不可见，因此每次会输出的都是静态变量n。
		fn();
	}
	//当离开fn()的作用域，回到主函数时，此时的n指的是全局变量n。
	cout << n << endl;
}
