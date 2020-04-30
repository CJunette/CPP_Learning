// 5.7_MultiFilesAndPrecompileCommand_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//根据书上p168的写法，来看p170问题里说到的哪些定义可以写到头文件里，哪些不可以。
//结果发现，只能是能以内联函数形式写进类体的定义，就统统可以在头文件里完成。
//但是，同样的定义，如果从类体内拿出，写到类体外，就会报错。
//类的静态数据成员由于初始化一定是在类体外的，因此必须在其他源文件中进行初始化定义。

//不存在嵌套的情况下，在不同源文件中include头文件时，头文件中的类是不会出现重复定义的问题的，但是头文件中的方法则会出现重复定义的问题。所以当定义被放在类体内时，不会有重复定义的报错，但一放到类体外就出现了报错。

#include <iostream>
#include "head.h"
using namespace std;


int calSum(Point pnt);

int main()
{
	Point a(1, 2);
	cout << calSum(a) << endl;
	Line l;
	cout << l.p.getX() << endl;
	
}