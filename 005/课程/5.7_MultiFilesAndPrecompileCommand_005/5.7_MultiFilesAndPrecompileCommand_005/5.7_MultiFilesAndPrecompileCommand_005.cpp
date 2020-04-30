// 5.7_MultiFilesAndPrecompileCommand_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//这里我又尝试创建了一种书上p170提到的问题的情形。即将定义全部放在头文件，然后在不同的源文件中调用头文件。
//这次的结果同样出现了重复定义的问题。而且这次如书上说，问题出现在了程序的连接的时刻。
//所以接下来要考虑的就是，哪些定义可以被放在头文件中，哪些不可以。
#include <iostream>
#include "head.h"

int calSum(Point pnt);

int main()
{
	Point a(1, 2);
	calSum(a);
}