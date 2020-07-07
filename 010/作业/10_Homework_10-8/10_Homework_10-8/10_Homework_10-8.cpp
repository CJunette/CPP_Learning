// 10_Homework_10-8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

void checkWithMap()
{
	istream_iterator<string> input(cin), eof;
	map<string, int> m;
	while(input != eof)
	{
		m[*input]++;
		if(m[*input] > 1)
		{
			cout << "Repeated word. It has showed up for " << m[*input] << " times." << endl;
		}
		input++;
	}
}
//个人感觉用multimap甚至还不如用multiset，因为multiap中的附加数据完全没有起到作用。
void checkWithMultimap()
{
	istream_iterator<string> input(cin), eof;
	multimap<string, int> m;
	while(input != eof)
	{
		m.insert(make_pair(*input, 0));
		if(m.count(*input) > 1)
		{
			cout << "Repeated word. It has showed up for " << m.count(*input) << " times." << endl;
		}
		input++;
	}
	
}

int main()
{
	checkWithMap();
	/*
	checkWithMultimap();
	*/
}