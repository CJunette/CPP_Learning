// 10.2_STL_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//对于STL的简单应用。

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

template<class T>
T negative(T ori)
{
	return -ori;
}

int main()
{
	const int N = 5;
	//1.vector<int>的对象s就是“容器”。
	vector<int> s(N);
	cout << "origin: ";
	for(int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	//2.transform就是一个算法。
	//3.s.begin()、s.end()、ostream_iterator都是迭代器。
	//4.negate<int>()是函数对象。注意，调用函数对象时，如果调用的是一个重载了“()”的类的对象，是要加“()”的；如果只是调用一个自定义的函数，则不需要加“()”。
	//5.整个思路是，先创建容器s，接着用容器的迭代器实现对容器内成员的访问；接着讲访问到的成员交给确定了函数对象“negate<int>()”的算法“transform”；最后将返回结果依次送到输出流迭代器“ostream_iterator<int>”中。
	transform(s.begin(), s.end(), ostream_iterator<int>(cout << "reverse: "), negate<int>());	
	
	//4.可以看到，当函数对象是一个函数（或函数模板），而非一个重载了“()”的类的对象时，引用是不需要“()”的。
	/*
	transform(s.begin(), s.end(), ostream_iterator<int>(cout << "reverse: "), negative<int>);
	*/
	cout << endl;
}

//6.课上给出的transform算法的一种实现方式。
//6.函数对象op的返回值通过迭代器result顺序输出。
//6.这里可以看到result作为迭代器，也在算法中不停地移向下一个元素。
//6.也就是说，当完成遍历时，result迭代器指向的是输出的最后一个元素的下一个位置。（这里其实让我有点不理解，流输出迭代器到底是怎么进行操作的。既然迭代器指向的都是最后一个元素之后的位置了，为什么还能正确地实现输出？流输出时不需要将迭代器移到首位吗？还是说此时已经完成输出了？）
/*
template<class InputIterator, class OutputIterator, class UnaryFunction>
OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op)
{
	for(; first != last; ++first, ++result)
	{
		*result = op(*first);
	}
	return result;
}
*/