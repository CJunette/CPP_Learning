// 5.7_MultiFilesAndPrecompileCommand_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//对于预编译指令及之前说到的不要在头文件中做类的定义的说明。

//1.由于头文件可以嵌套包含，所以当file1.h和file2.h同时包含了head.h的时候，没有保护性的预编译指令存在的情况下，在head.h中定义的point类就会被定义两次。因此造成错误。
#include <iostream>
#include "file1.h"
#include "file2.h"

//3.虽然有预编译指令可以解决重复定义的问题，但是现实情况下仍然不推荐把定义写在头文件里。

int main()
{
    Point a(1, 2);
    a.showCount();    
}
