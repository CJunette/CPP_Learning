// 6.12_String_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//getline()可以进行整行字符串的输入（需要头文件string）。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //1.与cin不同，getline()并不会自动地被空格分割（cin会以空格作为对字符串的分割，输入空格前的字符串；空格后的字符串将被放在键盘缓冲区等待下次输入），而是整行地输入字符串（getline()默认以“\n”作为分隔符。）。
    cout << "getline() can overcome space input." << endl;
    string s;
    //2.getline()的第一个参数是文件流对象，用cin说明从键盘输入；等之后学习文件io后还可以放文本文件等其他输入。
    getline(cin, s);
    cout << s << endl;

    //3.getline()可以用第三个参数来自定义用作分隔符的字符，注意这里只能使字符不能是字符串。（在输入流参数为cin的情况下，如果一直没有读取到分隔符，就会一直要求用户输入。）
    cout << "getline() can customize separator with the third parameter." << endl;
    string s1, s2, s3;
    getline(cin, s1, ',');
    cout << s1 << endl;
    getline(cin, s2);
    cout << s2 << endl;

    //4.不管是cin还是getline()，如果输入的内容因为分隔符而停留在键盘缓冲区的话，下次输入会先读取这些缓冲区中停留的内容。
    //4.因此如果设置了分隔符，但没有妥善处理缓冲区内的内容，很可能会造成诸多麻烦。
}
