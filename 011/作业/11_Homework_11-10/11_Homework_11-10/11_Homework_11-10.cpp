// 11_Homework_11-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    wifstream in;
	locale loc(".936");
	in.imbue(loc);
	in.open("text.txt", ios_base::binary);
	if(!in)
	{
		cout << "Error: Can not open file!" << endl;
		return 1;
	}

    wstring line;
	map<wchar_t, int> text;
	while(in.tellg() != EOF)
	{
		getline(in, line);
		wstring::iterator begin, end;
		begin = line.begin();
		end = line.end();
		while(begin != end)
		{
			text[*begin++]++;
		}
	}
	in.close();

	wofstream out;
	out.imbue(loc);
	out.open("info.txt");

	wcout.imbue(loc);
	map<wchar_t, int>::iterator iter = text.begin();
	while(iter != text.end())
	{
		wcout << iter->first << ": " << iter->second << endl;
		out << iter->first << ": " << iter->second << endl;
		iter++;
	}
	out.close();
}