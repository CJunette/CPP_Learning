// 10.6_AssociativeContainer_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//统计一句话中各个字母出现的次序。

#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main()
{
	map<char, int> s;
	char c;
	while(cin >> c, c != '.')
	{
		//isalpha()用于确定输入的对象是否为字母。
		if(isalpha(c))
		{
			//用tolower()将所有的字母都转变为小写字母，避免大小写重复计数。
			c = tolower(c);
			//s[c]的意义是，如果映射中不存在键为c的元素，则添加一个这样的元素，并返回其引用；如果存在，则返回这个元素的附加数据的引用。
			s[c]++;
		}
	}
	map<char, int>::iterator iter1 = s.begin();
	while(iter1 != s.end())
	{
		cout << iter1->first << ": " << iter1->second << endl;
		iter1++;
	}
}
