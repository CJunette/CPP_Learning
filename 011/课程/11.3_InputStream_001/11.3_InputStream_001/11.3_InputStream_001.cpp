// 11.3_InputStream_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-7，get函数的应用。

#include <iostream>
using namespace std;

int main()
{
    char ch;
	//get()函数的返回值，就是输入到输入流对象中的字符。
	//当cin.get()接受到的字符不为EOF时，继续循环。
	//这里的EOF就是之前提到的文件结束标记。Windows可以用ctrl+z表示键盘输入的文件结束标记。
	while((ch = cin.get()) != EOF)
	{
		cout.put(ch);
	}
}