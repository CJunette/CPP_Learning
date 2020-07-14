// 11.2_OutputStream_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-1，使用width控制输出宽度。
//例11-2，使用setw操纵符指定宽度。
//例11-3，设置对齐方式。

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	for(int i = 0; i < 4; i++)
	{
		//1.默认的对齐方式是右对齐。
		//1.当输出的字符不足时，会用前导字符去填充空位，默认的前导字符是空格。
		cout.width(16);
		//1.使用成员函数fill()可以手动设置插用于填充空位的前导字符。
		/*
		cout.fill('*');
		*/
		cout << values[i] << endl;
	}
	cout << endl;

	string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for(int i = 0; i < 4; i++)
	{
		//2.使用setw()同样可以实现控制输出宽度的目的。
		//2.需要注意的是，width和setw都只会影响其后紧跟的那个输出项（其他流格式操纵符会一直保持有效，甚至影响到下一次的流输出操作，直到被重新设置）。
		cout << setw(6) << names[i] << setw(10) << values[i] << endl;
	}
	cout << endl;

	for(int i = 0; i < 4; i++)
	{
		//3.setiosflags不同于width和setw，它的影响是持久的，直到被重新设置或用resetiosflags恢复默认值为止。
		//3.setiosflags(ios_base::left)用于将输出的对齐方式设置为左对齐；而resetiosflags(ios_base::left)则用于取消ios_base::left设置，如果之前没有进行过ios_base::left的设置，则这条语句无效。
		//3.由于默认的对齐方式是右对齐，因此取消setiosflags(ios_base::left)后，后面的输出项就默认都变为右对齐了。
		//3.由于ios_base::left是ios_base的静态常量，因此引用时必须包括“ios_base::”前缀。
		//4.另外，如果这里后面的那一个操纵符是setiosflags(ios_base::right)的话，names[]的输出只有第一次会进行左对齐，之后都会保持右对齐。
		//4.原因不明？
		cout << setiosflags(ios_base::left)<< setw(6) << names[i] << resetiosflags(ios_base::left) << setw(10) << values[i] << endl;
		//5.setiosflags的参数是该流的格式标准值，可用按位或“|”运算符进行组合。
	}
	cout << endl;
}