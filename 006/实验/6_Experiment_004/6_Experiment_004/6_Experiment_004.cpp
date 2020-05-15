// 6_Experiment_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

char *link(char *a, char *b)
{
	int m = 0, n = 0;
	while (a[m] != '\0')
	{
		m++;
	}
	while (b[n] != '\0')
	{
		n++;
	}
	//之前写错代码的时候吧这里写成了char(m + n + 1)，造成最后delete的时候报错。
	char *c = new char[m + n + 1];
	for (int i = 0; i < m; i++)
	{
		c[i] = a[i];
	}
	for (int i = m; i < m + n; i++)
	{
		c[i] = b[i - m];
	}
	c[m + n] = '\0';

	return c;
}

int main()
{
	char a[] = "abc";
	char b[] = "def";
	char *charStar = link(a, b);
	cout << charStar << endl;
	delete charStar;

	string c = "ghi";
	string d = "jkl";
	string e;
	e = c + d;
	cout << e << endl;
}
