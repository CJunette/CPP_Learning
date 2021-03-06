﻿// 6.12_String_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//C风格的字符串，即用字符数组来储存字符串。

#include <iostream>
using namespace std;

int main()
{
    //双引号内的内容是一个字符串常量，它相当于一个字符数组，其中每个字符占一个字节，依次排列，以“\0”结尾。
    //在程序中，"CString"所代表的就是这个字符数组的首地址。
    //因为它是一个字符串常量，因此只能用一个char类型的常量指针指向它。
    //这里其实有点奇怪，因为“CStirng”其实是一个右值，而指针指向右值的情况还是很少见。在以前的C++（包括现在的C中），还允许char *s = "string";这样的写法。
    //网上的解释是，双引号起到的作用是在常量区申请了空间，然后返回地址。（所以字符串常量全都不是右值？？？）    
    //之后我又看到，字符串常量就是左值。
    const char *s1 = "CString";
    cout << (s1[7] == '\0') << endl;

    //如果直接用字符数组储存字符串，就不用受const的限制。因为这本质上相当于创建了一个新的char数组，然后将字符串中的字符逐一填入。    
    char s2[8] = "CString";
    //我之所以会认为字符数组的储存方式是将字符串常量的每个元素都拷贝过来的原因是下面的代码是会报错的。也就是说，用“字符数组=字符串常量”的做法并不是简单地将数组首地址指向字符串常量首地址。
    //其实上面这个解释太复杂了。最简单的解释就是，数组名是个常量，它是不能用另一个地址进行重新赋值的。
    /*
    char s2[];
    s2 = "CString";
    */

    //但要注意，如果用“{}”进行初始化，末尾一定要加上“\0”。
    //如果末尾没有添加“\0”，程序处理时就会出错。
    char s3[] = { 'C', 'S', 't', 'r', 'i', 'n', 'g', '\0' };
    cout << s3 << endl;
    //C风格的字符串有许多缺点，如，由于是数组因此会存在下标越界问题（字符串长度大于为其分配的空间）；连接、拷贝等操作需要调用库函数，十分麻烦；字符串长度不确定时需要用new来动态创建数组，再用delete释放。
    //因此在C++中出现了string，来替代C风格的字符串。
}
