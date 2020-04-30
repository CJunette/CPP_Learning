// 5.7_MultiFilesAndPrecompileCommand_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//因嵌套调用导致的错误。

//我本来写着个文档是为了看看书上p168把有些函数定义在类体内，这么做是不是因为那些函数有什么特殊的地方。

//但从现在看来，不论是普通函数、普通变量、带参数的类、不带参数的类，只要在头函数中声明，然后在主函数中因嵌套调用导致重复定义的，最终都会报错。
//说白了问题就只有一个，即重复定义（编译器是报重复定义，但有一些应该是算重复声明）。因为预编译指令#include会将头文件的代码嵌入主函数代码，所以不论是什么对象，嵌套调用导致重复出现两次声明语句都会导致错误。

//书本p168之所以把一些函数的定义写在了类体内，就是因为确定有预编译指令会保证重复定义的情况不会发生。

#include <iostream>
#include "file1.h"
#include "file2.h"

int main()
{
	
}
