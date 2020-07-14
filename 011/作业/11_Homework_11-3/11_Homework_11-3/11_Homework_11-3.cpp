// 11_Homework_11-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//作业11-3、11-4、11-5。

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const char *FILENAME = "text1.txt";
    ofstream out(FILENAME);
    out << "已成功写入文件！" << endl;
    out.close();
    ifstream in(FILENAME);
    string line;
    getline(in, line);
    cout << line << endl << endl;
    in.close();

    out.open(FILENAME, ios::app);
    out << "已成功添加字符！" << endl;
    out.close();
    in.open(FILENAME, ios::app);
    while(in.tellg() != EOF)
    {
        getline(in, line);
        cout << line << endl;
    }
    in.close();
}
