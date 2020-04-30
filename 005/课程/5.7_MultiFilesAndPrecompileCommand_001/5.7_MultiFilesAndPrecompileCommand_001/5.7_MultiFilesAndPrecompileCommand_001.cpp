// 5.7_MultiFilesAndPrecompileCommand_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//对于自定义的头文件通常用“#include "文件名"”的形式include。
//这样的写法会让程序在include头文件时首先在当前目录下寻找需要的头文件，找不到了再到标准目录下去找；而“#include <文件名>”的写法会到编译环境的include子目录（就是之前说的的标准目录）下寻找预设的头文件。
#include "point.h"
using namespace std;

int main()
{
    Point a(4, 5);
    cout << "Point A: " << a.getX() << "," << a.getY() << endl;
    Point::showCount();

    Point b(a);
    cout << "Point B: " << b.getX() << "," << b.getY() << endl;
    Point::showCount();
    
    countChange();
}
