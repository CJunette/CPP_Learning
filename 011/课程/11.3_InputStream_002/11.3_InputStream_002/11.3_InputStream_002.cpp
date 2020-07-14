// 11.3_InputStream_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-8，为输入流指定终止字符。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cout << "Type a line terminated by 't'." << endl;
    //getline()的第一个参数是文本文件的输入流对象；第二个参数是string类型的用于字符串存储的对象；第三个参数是可选参数，用于指定作为分隔符的对象。
    //如果指定了分隔符，则原来的分隔符空格就不在作为分隔符使用了。
    getline(cin, line, 't');
    cout << line << endl;
}