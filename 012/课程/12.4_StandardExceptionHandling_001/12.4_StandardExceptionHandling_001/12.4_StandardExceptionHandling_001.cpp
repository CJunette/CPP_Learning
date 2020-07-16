// 12.4_StandardExceptionHandling_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例12-3，计算三角形面积

#include <iostream>
using namespace std;

double calArea(double a, double b, double c) throw(invalid_argument)
{
	if(a <= 0 || b <= 0 || c <= 0)
	{
		//invalid_argument是标准异常类，括号中的参数要求是字符串，表示要输出的错误信息。
		throw invalid_argument("Side length should be positive!");
	}
	if(a + b <= c || a + c <= b || b + c <= a)
	{
		throw invalid_argument("Side length should fit the triangle inequation!");
	}
	//计算面积使用Heron公式。
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
	double a, b, c;
	cout << "Please input the side lengths of a triangle: ";
	cin >> a >> b >> c;
	try
	{
		double s = calArea(a, b, c);
		cout << "The area is " << s << endl;
	}
	//exception是invalid_argument的父类，因此能够实现异常捕获。
	catch(const std::exception &e)
	{
		//使用invalid_argument的what()函数可以得到构建异常对象时输入的错误信息。
		cout << "Error: " << e.what() << endl;
	}
}