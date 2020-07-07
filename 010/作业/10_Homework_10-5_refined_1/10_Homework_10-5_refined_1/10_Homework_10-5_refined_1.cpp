// 10_Homework_10-5_refined_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//参考答案的代码。
//参考答案最重要的思路是，不去考虑当前位置与规定移动步数的大小，直接向前移动；当移动到容器尾部时，直接将迭代器拖到容器头部。
//我重新看了一下题目，发现题目本身有点表述上的问题。
//题目如下：n个骑士编号，1，2，3，...，n，围坐在圆桌旁。编号为1的骑士从1开始报数，报到m的骑士出列，然后下一个位置再从1开始报数，找出最后留在圆桌旁的骑士编号。
//这里的歧义在于，“下一个位置”到底是指什么？是指“1”后的下一个位置，还是“m”后的下一个位置？
//从答案来看，似乎是指“m”后的下一个位置，也就是n个人，每隔m位删除一人。

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
using namespace std;

template<class T>
//这里按照题意，纠正了一下m和n的前后顺序。
void joseph(T collection, int n, int m)
{
 	for(int i = 1; i <= n; i++)
	{
		collection.push_back(i);
	}
	typename T::iterator iter = collection.begin(), del;
	int count = 1;
	clock_t start = clock(), finish;

	while(collection.size() != 1)
	{
		//这边源代码是用while配合逻辑语句的，我觉得没必要所以就改成if语句了。
		if(count % m == 0)
		{
			count = 1;
			if(typeid(T) != typeid(list<T::value_type>))
			{				
				iter = collection.erase(iter);				
			}
			else
			{
				//因为list的.erase()不会返回迭代器，所以要自己将迭代器指向下一项。
				del = iter;
				iter++;
				collection.erase(del);
			}
			//如果删除后迭代器在.end()位置，则使其移动到.begin()位置。
			if(iter == collection.end())
			{
				iter = collection.begin();
			}
			//如果n = 1，也就是删除的就是当前迭代器本身，则直接进入下一个循环。
			if(m == 1)
			{
				continue;
			}
		}
		count++;
		iter++;
		if(iter == collection.end())
		{
			iter = collection.begin();
		}
	}
	finish = clock();
	cout << "Last Kinght left is Kinght[" << *iter << "]" << endl;
	cout << typeid(T).name() << " costs " << 1.0 * (finish - start) / CLOCKS_PER_SEC << endl;
}

int main()
{
	vector<int> v;
	deque<int> d;
	list<int> l;
	joseph(v, 10000, 5);	
	joseph(d, 10000, 5);
	joseph(l, 10000, 5);
}
