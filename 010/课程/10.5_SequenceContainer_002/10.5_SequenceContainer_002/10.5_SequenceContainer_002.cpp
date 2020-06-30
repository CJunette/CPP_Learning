// 10.5_SequenceContainer_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//双端队列的应用。
//要求：输入一组数据，输出从大到小排序的奇数，然后输出从小到大排序的偶数。

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	istream_iterator<int> i1(cin), i2;
	//在输入内容为终止符之前，持续要求用户输入数字并将其存入vector。
	//这里展示了一种代码上更为便捷的输入方式。
	vector<int> s1(i1, i2);
	sort(s1.begin(), s1.end());
	deque<int> s2;
	for(typename vector<int>::iterator i = s1.begin(); i != s1.end(); i++)
	{
		//如果为偶数，则向deque尾部输入。deque的s2.end()是随着尾部向后移动的。
		if(*i % 2 == 0)
		{
			s2.push_back(*i);
		}
		//如果为奇数，则向deque头部输入。deque的s2.begin()是随着头部向前移动的。
		else
		{
			s2.push_front(*i);
		}
	}
	//最终输出时，输出s2.begin()到s2.end()的内容到ostream_iterator<int>对象中。
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
}