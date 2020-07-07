// 10_Homework_10-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//答案给出的做法是用一般数组做容器，且限定了数组大小。我做了调整，把容器改为set，且不限容器大小。

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

template<class T>
void insertSet(set<T> &s, string str)
{
	string::iterator iter = str.begin();
	while(iter != str.end())
	{		
		//若当前iter为空格，则说明之前有数字或这个空格是开头的空格。
		if(*iter == ' ')
		{
			//如果str的开头位置不为空格，则说明iter之前一定有数字，此时用stoi来将str中用空格区分的第一个数字取出，然后插入到set中。
			if(str[0] != ' ')
			{
				int i = stoi(str);
				s.insert(i);
			}
			//插入完成后，或str开头为空格的情况下，需要删除[str.begin(), ++iter)区间中的内容。
			str.erase(str.begin(), ++iter);
			//同时，完成删除后，必须重置iter，否则会因为删除造成迭代器的失效。之前就因为这个错误重写了代码！！！
			iter = str.begin();
		}
		iter++;
	}
	//如果最后一位数字后面没有空格，则那个数字会被遗漏，此时在进行一次判断，在确认str中还有数字时，将其取出。
	if(str[0] != ' ')
	{
		int i = stoi(str);
		s.insert(i);
	}
}

int main()
{
    set<int> s1, s2;
    
	string str1, str2;
	//由于存在两个输入，所以不方便使用istream_iterator，会出现很多问题。
	//所以先将两个数字段以stirng的方法输入，再将其逐一拆解，放到set中。
	getline(cin, str1);
	getline(cin, str2);

	//用于将string中的数字插入set中。
	insertSet(s1, str1);
	insertSet(s2, str2);

	set<int> intersection_result, union_result, difference_result;
	//注意，由于下面这三个算法都会使用“=”操作符，而set又是不能修改键值的（用set的迭代器iter写“*iter = 1”这样的语句会提示不能对常量进行修改的错误）。
	//所以必须用插入迭代器“inserter”来实现将集合的求解结果传递到新的set中的目的。
	//虽然书上p422提到，“inserter”这样的插入迭代器是适用于顺序容器的，但似乎这里对于关联容器也能使用。
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersection_result, intersection_result.begin()));
	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(union_result, union_result.begin()));
	set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(difference_result, difference_result.begin()));
	
	ostream_iterator<int> output(cout, " ");
	cout << "Intersection result: ";
	copy(intersection_result.begin(), intersection_result.end(), output);
	cout << endl;
	cout << "Union result: ";
	copy(union_result.begin(), union_result.end(), output);
	cout << endl;
	cout << "Difference result: ";
	copy(difference_result.begin(), difference_result.end(), output);
	cout << endl;	
}