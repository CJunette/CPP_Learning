// HelloWorldCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include与using有什么差别？？这个<iostream>头文件是类似C#中的类库的文件吗？？
//似乎是名称空间“std”包含在头文件“<iostream>”中？
#include <iostream>
using namespace std;

int main()
{
    printf("printf: Hello World\n");

    //“<<”是输出流运算符。
    cout << "Hello World!\n";
    //这行程序实际上用了2次输出流运算符，一次输出“Welcome to C++!”，一次输出“endl”。
    cout << "Welcome to C++!" << endl;
    

    /*
    cin.get();
    */
}
