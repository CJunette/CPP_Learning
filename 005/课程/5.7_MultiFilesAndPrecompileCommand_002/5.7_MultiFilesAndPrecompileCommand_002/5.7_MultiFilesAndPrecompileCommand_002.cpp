// 5.7_MultiFilesAndPrecompileCommand_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//4.对外部函数的引用需要在使用之前给出函数的引用声明，即声明函数的原型。
//4.其实这种做法就相当于在同一个文件中声明原型，然后调用。只要保证在某个位置会给出函数定义即可。只不过这里函数的定义是在另一个将来在编译时才会连接起来的文件中。
void other();

int i = 3;

//2.下面的变量j和k都算是定义性声明。
int j = 3;
//5.全局变量会被赋予默认值。
//5.延伸一下：类的静态数据成员和类的常数据成员都必须手动进行初始化。静态成员的初始化必须在类外，常数据成员的初始化必须用初始化函数的形式。
int k;

void next()
{
    i++;
    cout <<"i: " << i << endl;
    //4.在使用时直接用函数名调用即可。
    //4.不要写extern void other()这种语句，会在编译时被直接跳过。
    other();
}

namespace
{
    //7.命名空间（本文件，也可以说是本编译单元）中的变量默认都是外部变量，可以被同一项目下的其他文件随意访问。
    //7.像这样在一个匿名命名空间中定义的变量会局限在这个编译单元中，不会被外部文件访问。
    int m = 4;

    //8.由于这个匿名命名空间的作用域要小于外部变量存在的作用域，因此在这里定义另一个编译单元中存在的外部变量并不会报错。这等同于内层定义了一个与外层变量同名的变量，从而导致外层变量不再可见。
    int l = 3;    
}

int main()
{
    next();
    cout << "k: " << i << endl;
    cout << "i: " << i << endl;        
    cout << "l: " << l << endl;
}
