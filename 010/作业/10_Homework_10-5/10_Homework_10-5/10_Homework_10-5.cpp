// 10_Homework_10-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
using namespace std;

template<class T>
void joseph(int m, int n)
{
	//start和finish用于计算程序运行时间。
	clock_t start = clock(), finish;
	T container;
	for(int i = 0; i < m; i++)
	{
		container.push_back(i);
	}
	
	int count = 0;
	typename T::iterator iter;

	while(container.size() != 1)
	{
		iter = container.begin();

		//当count大于size时，将其归零。
		if(count >= container.size() - 1)
		{
			count = 0;
		}
		//之所以每次都要从头一定，是因为我考虑到可能.erase()会造成迭代器的失效。
		for(int i = 0; i < count; i++)
		{
			iter++;
		}
				
		typename T::iterator iterDelete = iter;

		//distance代表到末尾为止，还能移动的距离。为1则说明下一位就是container.end()。
		//由于是从自身开始报1，所以实际会发生的移动步数是n - 1。
		
		int distance = 0;
		for(iterDelete; iterDelete != container.end(); iterDelete++)
		{
			distance++;
		}
		iterDelete = iter;
		
		int step;
		if(distance < n)
		{
			//如果剩余距离不足，则计算循环后重新从begin()开始的步数。
			step = (n - distance) % container.size() - 1;
			//如果余数为0，则说明应该移动到end()前的位置。此时减1后，step会变为-1。
			if(step < 0)
			{
				step = container.size() - 1;
			}
			//同时将iterDelete移回begin()位置。
			iterDelete = container.begin();
		}
		else
		{
			step = n - 1;
		}
		for(int i = 0; i < step; i++)
		{
			iterDelete++;
		}
		/*
		cout << "Knight [" << *iter << "]\t anounces: ";
		cout << "Knight [" << *iterDelete << "]\t deleted." << endl;
		*/
		container.erase(iterDelete);
		count++;
	}
	/*
	cout << endl;
	*/
	//输出最后剩下的那个。
	iter = container.begin();
	cout << "Knight[" << *iter << "] is the last kinght left." << endl;
	finish = clock();
	cout << "Container: " << typeid(container).name() << " costs " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " seconds" << endl << endl;
}

int main()
{
	joseph<vector<int>>(1000, 5);	
	joseph<deque<int>>(1000, 5);
	joseph<list<int>>(1000, 5);
	
}