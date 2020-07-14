// 11.2_OutputStream_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-4，控制输出精度

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for(int i = 0; i < 4; i++)
	{
		//在未指定fixed或scientific的情况下，系统根据数字大小自动选择输出模式，用setprecision()所设置的精度表示有效数字位数。
		cout << setiosflags(ios_base::left) << setw(6) << names[i] << resetiosflags(ios_base::left) << setw(10) << setprecision(1) << values[i] << endl;
	}
	cout << endl;
	//当设置fixed或scientific的情况下，setprecision()所设置的精度代表的就是小数点后的有效数字位数。
	cout << setiosflags(ios_base::fixed);
	for(int i = 0; i < 4; i++)
	{		
		cout << setiosflags(ios_base::left) << setw(6) << names[i] << resetiosflags(ios_base::left) << setw(10) << setprecision(1) << values[i] << endl;
	}
	cout << endl;
	//注意，这里需要用resetiosflags(ios_base::fixed)取消fixed设置以后，才能再进行scientific的设置。
	cout << resetiosflags(ios_base::fixed) << setiosflags(ios_base::scientific);
	for(int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) << setw(6) << names[i] << resetiosflags(ios_base::left) << setw(10) << setprecision(1) << values[i] << endl;
	}
}