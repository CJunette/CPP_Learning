// 3_homework_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//3.7, 3.8, 3.9, 3.10

#include <iostream>
#include <cmath>
using namespace std;

short _3_7(unsigned short a, unsigned short b);
float _3_8(float f);
bool _3_9(int a);
int _3_10_1(int a, int b);
int _3_10_2(int a, int b);

int main()
{
	while (true)
	{
		cout << "Please input the number for excuting certain program. (example, 37 for 3-7; input 0 for exit.)\n";
		int number;
		cin >> number;
		cout << endl;

		switch (number)
		{
			case 0:
				goto exit;
				break;

			case 37:
				//两整数相除
				cout << "3-7\n";
				cout << "Please input two non-negative integer:\n";
				int a_37, b_37, result_37;
				cin >> a_37 >> b_37;
				result_37 = _3_7(a_37, b_37);
				if (result_37 < 0)
				{
					cout << "Sorry, can't divide by 0!\n";
				}
				else
				{
					cout << "a / b = " << result_37 << endl;
				}				
				cout << endl;
				break;

			case 38:
				//华氏转摄氏
				cout << "3-8\n";
				cout << "Please input a Fahrenheit temperature: ";
				float f_38;
				cin >> f_38;
				cout << "The corresponding Celsius temperature is " << _3_8(f_38) << " .\n";
				cout << endl;
				break;

			case 39:
				//判断是否为质数
				cout << "3-9\n";
				cout << "Please input an integer: ";
				int a_39;				
				cin >> a_39;
				if (_3_9(a_39))
				{
					cout << a_39 << " is a prime number.\n";
				}
				else
				{
					cout << a_39 << " is not a prime number.\n";
				}
				cout << endl;
				break;

			case 310:
				//求最大公约数和最小公倍数
				cout << "3-10\n";
				cout << "Please input 2 integers:\n";
				int a_310, b_310;
				cin >> a_310 >> b_310;
				cout << "The greatest common divisor of " << a_310 << " and " << b_310 << " is " << _3_10_1(a_310, b_310) << endl;
				cout << "The lowest common multiple of " << a_310 << " and " << b_310 << " is " << _3_10_2(a_310, b_310) << endl;
				cout << endl;
				break;

			default:
				break;
		}
	}	

exit:
	return 0;
}

short _3_7(unsigned short a, unsigned short b)
{
	if (b == 0)
	{
		return -1;
	}
	else
	{
		return a / b;
	}
}

float _3_8(float f)
{
	return 5.0 / 9.0 * (f - 32);
}

bool _3_9(int a)
{
	int b = sqrt(a);
	//求是否是质数只需要循环到sqrt(a)就够了，不需要循环到a。
	for (int i = 2; i < b; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
		
	}
	return true;
}

int _3_10_1(int a, int b)
{
	//求最大公约数
	/*
	int min;
	if (a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}

	for (int i = min; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
	return 1;
	*/

	//答案使用了欧几里得算法来求最大公约数
	if (a < b)
	{
		int t = a;
		a = b;
		b = t;
	}

	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int _3_10_2(int a, int b)
{
	//求最小公倍数
	//我自己写的做法有点太复杂。
	/*
	int gcd = _3_10_1(a, b);
	int i = 1;
	int lcm = gcd;
		
	while (lcm % a != 0 || lcm % b != 0)
	{
		lcm = gcd * ++i;
	}
	*/

	int gcd = _3_10_1(a, b);
	int lcm = a * b / gcd;
	return lcm;
}