// 3.7_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <initializer_list>
using namespace std;

//参考“https://www.cnblogs.com/ljqblogs/p/12185230.html”。
//这个initializer_list有点类似C#里的迭代器IEnumerable？
void error_msg(int ErrorCode, initializer_list<string> il)
{
    cout << "Error Code " << ErrorCode << ": ";
	for (auto beg = il.begin(); beg < il.end(); beg++)
	{
		cout << *beg << " ";
	}
	cout << endl;
}

int main()
{
	//这里印证了含有initializer_list类型参数的函数还可以有其他类型（int）的参数。
	error_msg(2, { "ENOENT.", "No such file or directory!", "Please enter again!" });
}
