// 3_homework_3-15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int getPower(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else
	{
		return x * getPower(x, y - 1);
	}
}

double getPower(double x, int y)
{
	if (y == 0)
	{
		return 1.0;
	}
	else
	{
		return x * getPower(x, y - 1);
	}
}

int main()
{
	int a, m;
	double b;
	cout << "Please input integer base a: ";
	cin >> a;
	cout << "Please input double base b: ";
	cin >> b;
	cout << "Please input integer exponent m: ";
	cin >> m;

	printf("getPower(%d, %d) = %d\n", a, m, getPower(a, m));

	//用下面的这个格式就可以在输入为整型的情况下输出实型结果。
	/*
	printf("getPower(%d, %d) = %f\n", a, m, getPower(a*1.0, m));
	*/

	printf("getPower(%f, %d) = %f\n", b, m, getPower(b, m));

}

