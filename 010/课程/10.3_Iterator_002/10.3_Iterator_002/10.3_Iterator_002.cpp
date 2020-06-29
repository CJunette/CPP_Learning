// 10.3_Iterator_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template<class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<T> s;
	for(; first != last; ++first)
	{
		s.push_back(*first);		
	}
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);
}

int main()
{
	double a[5] = { 1.1, 2.4, 0.8, 3.3, 3.2 };
	//这里看似是从double *类型到模板类型参数InputIterator类型的转换，但实际上InputIterator是根据实际参数的类型决定的，InputIterator本身就是double *类型。
	mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));	
	cout << endl;
	//这里的算法并没有像10.3_Iterator_001中那样每次进行输入完后按回车，都会执行一次输出。可能的原因就是在算法的循环中没有“result = ...;”类似的语句。
	//如果在其中加上“result = first”，则这个算法也同样会每次按回车都进行一次输出。
	mySort<double>(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, " "));
	cout << endl;
}
