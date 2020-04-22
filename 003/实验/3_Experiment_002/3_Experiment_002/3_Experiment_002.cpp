// 3_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <initializer_list>
#include <cmath>
#include <string>
using namespace std;

int Max1(int a, int b);
double Max1(double a, double b);
int Max1(int a, int b, int c);
double Max1(double a, double b, double c);

//initializer_list<int>与initializer_list<float>被认为是相同的数据类型，因此不能以此写函数重载。
int Max1(initializer_list<int> ls);

//用于判断是否输入为浮点数。
bool CheckFloat(double a, double b);
bool CheckFloat(double a, double b, double c);


int main()
{
	cout << "Please input some numbers:\n";
	double a[3];
	string s[3];
	
		
	for (int i = 0; i < 3; i++)
	{
		cin >> s[i];
	}

	//用于判断是否第1与第2个数的输入不是数字。
	try
	{
		for (int i = 0; i < 2; i++)
		{
			a[i] = stof(s[i]);
		}
	}
	catch (const std::exception &)
	{		
		cout << "Input Error!!\n";
		return 1;
	}

	//用于判断第3个输入是不是数字。如果不是数字，则进行2个数字的比较，否则进行3个数字的比较。
	bool inputerror = false;
	try
	{
		a[2] = stof(s[2]);
	}
	catch (const std::exception e)
	{
		inputerror = true;
	}	

	if (!inputerror)
	{
		if (CheckFloat(a[0], a[1], a[2]))
		{
			cout << "Max number is " << Max1(a[0], a[1], a[2]) << ".\n";
		}
		else
		{
			cout << "Max number is " << Max1((int)a[0], (int)a[1], (int)a[2]) << ".\n";
		}
	}
	else
	{
		if (CheckFloat(a[0], a[1]))
		{
			cout << "Max number is " << Max1(a[0], a[1]) << ".\n";
		}
		else
		{
			cout << "Max number is " << Max1((int)a[0], (int)a[1]) << ".\n";
		}
	}

}


int Max1(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

double Max1(double a, double b)
{
	//这一步没有必要，但是展现了比较两个浮点数是否相同的方法。
	//只要两个浮点数的差的绝对值十分小，就说明这两数相等。
	if (abs(a-b) < 1e-10)
	{
		return a;
	}
	else if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Max1(int a, int b, int c)
{
	//在这里利用先前定义的函数来处理这个函数的算法。
	return Max1(Max1(a, b), c);
}

double Max1(double a, double b, double c)
{
	return Max1(Max1(a, b), c);
}

//这个函数实际没用到。因为要实现输入未知数量的参数并将其储存，我暂时不知道在c++中有什么快捷的做法。
int Max1(initializer_list<int> ls)
{
	int x = *(ls.begin());
	for (auto i = ls.begin(); i < ls.end(); i++)
	{
		if (x < *i)
		{
			x = *i;
		}
	}
	return x;
}

bool CheckFloat(double a, double b)
{
	int x = (int)a;
	int y = (int)b;
	if (x != a || y != b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckFloat(double a, double b, double c)
{
	int x = (int)c;
	if (CheckFloat(a, b) || x != c)
	{
		return true;
	}
	else
	{
		return false;
	}
}