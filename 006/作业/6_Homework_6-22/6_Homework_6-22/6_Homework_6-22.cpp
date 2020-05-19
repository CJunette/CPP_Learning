// 6_Homework_6-22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void reverse(const string &s)
{
    char last = s[0];
	string substr = s.substr(1, s.size() - 1);
	if (s.size() > 1)
	{
		reverse(substr);
	}
	cout << last;
}

string reversestr(const string &s)
{
	if (s.size() > 1)
	{		
		//substr是去掉首尾字母的子串。
		string substr = s.substr(1, s.size() - 2);		
		//在这里，返回“尾字母+下一层递归+首字母”。
		return s.substr(s.size() - 1, 1) + reversestr(substr) + s.substr(0, 1);
	}
	else
	{
		return s;
	}
}

int main()
{
	string s;
	cout << "Please input the sentence to be reversed:" << endl;
	getline(cin, s);
	cout << "Here is the reversed sentence:" << endl;
	cout << reversestr(s) << endl;
}
