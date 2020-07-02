// 10.6_AssociativeContainer_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//程序希望用户输入一串实数，要求去掉重复的实数，取最大值和最小值的中值，分别输出小于等于此中值和大于此中值的实数。

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

int main()
{
    double input;
	set<double> s;
	//注意，这个程序有一点不安全的地方，即如果用户直接输入0，会导致集合为空。后面使用迭代器的访问会出现错误。
	while(cin >> input, input != 0)
	{
		//通过将insert()的结果赋值给一个pair对象，然后查看pair对象的第二个对象（即插入是否成功的结果），来判断是否因为集合内已经存在相同元素所以插入失败。
		pair<set<double>::iterator, bool> p = s.insert(input);
		//如果插入失败，说明已经存在相同元素，此时给出报错。
		if(!p.second)
		{
			cout << input << " is duplicated!" << endl;
		}
	}
	set<double>::iterator front = s.begin();
	//注意，这里似乎只能通过自减操作来实现获取尾部迭代器前一项的迭代器。并不能用“back = s.end() - 1”这样的语句。
	set<double>::iterator back = --s.end();
	double mid = (*front + *back) / 2;
	//这里的%.1f是用来设置输出位数的方法。
	printf("<  middle(%.1f): ", mid);
	//这里如果要保证两次输出不存在重复的空间的话，必须将两次的前一次copy()的开区间和后一次copy()的闭区间设为一致。
	copy(s.begin(), s.lower_bound(mid), ostream_iterator<double>(cout, " "));
	cout << endl;
	printf(">= middle(%.1f): ", mid);
	copy(s.lower_bound(mid), s.end(), ostream_iterator<double>(cout, " "));
}