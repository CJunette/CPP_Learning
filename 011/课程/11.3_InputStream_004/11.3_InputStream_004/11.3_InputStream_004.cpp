// 11.3_InputStream_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-10，用seekg函数设置位置指针。

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int values[] = { 3, 7, 0, 5, 4 };
    ofstream os("integers", ios_base::binary);
    os.write(reinterpret_cast<char *>(values), sizeof(values));
    os.close();
    ifstream is("integers", ios_base::binary);
    if(is)
    {
        //当需要输出第一个元素时，会写seekg(0)。因此，当需要输出第四个元素时，需要写seekg(3)，跳过三个单位长度。
        //这里必须是基本单位sizeof(int)的倍数，不能写“isseekg(3)”。因为存储时每个元素都是按4个字节进行存储的，这样相当于将文件位置指针移动到了第一个数据的中间位置，读取出来的值一定与预期不符。
        is.seekg(3 * sizeof(int));
        int v;
        //我这边试了一下，如果读取时的长度设置与读取对象的大小不符(如，将代码改为“sizeof(double)”)，则程序在运行时会报错。
        is.read(reinterpret_cast<char *>(&v), sizeof(int));
        cout << "The fourth input number is " << v << endl;
        is.close();
    }
    else
    {
        cout << "Error: can't open file" << endl;
    }
}