// 11.4_Supplement_002_WideStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    locale loc(".936");
    wcout.imbue(loc);
    wifstream in("article.txt");
    in.imbue(loc);

    wstring str;
    //count用来统计行数。
    int count = 1;
    //getline在实现输入的同时也会移动文件位置指针。
    while(getline(in, str))
    {
        if(str.find_first_of(L"人") != wstring::npos)
        {
            wcout << count << L":" << str << endl << endl;
        }
        count++;
    }
}