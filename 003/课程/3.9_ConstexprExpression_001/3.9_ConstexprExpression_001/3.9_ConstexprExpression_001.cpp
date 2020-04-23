// 3.9_ConstexprExpression_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//constexpr可以保证函数输出的值可以被赋给一个同样被constexpr修饰的常量。
//光是这么看好像constexpr并没什么作用，因为普通的变量的表达式也能实现给常量复制的作用。
//唯一的区别可能是，在constexpr的修饰下，这个常量值可以在编译阶段就被得到。这是一个编译期间可计算的函数。
constexpr int getSize(int a)
{
    return a * a;
}


int main()
{    
    constexpr int a = getSize(2);
    cout << a << endl;
    
    //这里可以看到，将鼠标停留在上面的a时，会显示constexpr int a = 4。
    //而将鼠标停留在下面的y时，只能得到const int y，并没有具体的数值。
    //由此可见constexpr可以在编译期间就直接完成计算。
    int x = 10;
    const int y = x * x;
    const int z = 2;

    //比较麻烦的一点是，由于constexpr是编译期间就可以求值的，因此不能用一个需要在程序运行中才能得到值的const（如y）去给constexpr赋值。
    //只能用在定义时就已经确定值的const（如z）去给constexpr赋值。
    constexpr int b = z;
}

