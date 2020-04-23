// 3.9_ConstexprExpression_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//总结
//关于constexpr，需要知道的就是，这是一个可以让被修饰的变量在编译期间就能得到值的修饰符。
//constexpr对被修饰对象的唯一要求就是，它的值必须是编译期间就确定的。因此它可以被一个有编译期间确定值的常量const赋值，
//也可以被一个有constexpr修饰符的变量赋值，也可以被一个有constexpr的函数赋值。
//未被constexpr修饰的变量，其值在编译期间都是不确定的，因此不能用来给被constexpr修饰的变量赋值。

//一般的常量修饰符const也会有一些类似constexpr的特征。如，const修饰的常量如果被赋予了确定的值，那么在编译过程中将鼠标到这个常量上也会显示出值。（如下面的常量z）
//但const没有constexpr那么严格。const允许用在编译时不确定值的变量给自己进行初始化赋值。constexpr则不允许。

//constexpr可以保证函数输出的值可以被赋给一个同样被constexpr修饰的常量。
//光是这么看好像constexpr并没什么作用，因为普通的变量的表达式也能实现给常量复制的作用。
//唯一的区别可能是，在constexpr的修饰下，这个常量值可以在编译阶段就被得到。这是一个编译期间可计算的函数。
constexpr int getSize(int a)
{
    return a * a;
}


int main()
{    
    //带有constexpr的函数可以给带有constexpr的变量赋值。
    //被constexpr修饰的函数会要求其中的参数也是一个被constexpr的变量，或一个可在编译期间计算出结果的表达式。
    //也就是说，像int j = 2;这样的变量j，不能作为getSize(j)的参数。因为其值在编译过程中不确定，必须到运行过程中才能得到。
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


    //但如果求值过程中的所有待求值变量都是用constexpr修饰的话，则所有变量都可以在编译过程中就得到值，因此也可以用来给一个新的constexpr变量赋值。
    constexpr int i = a * z;
    constexpr int c = i;
}

