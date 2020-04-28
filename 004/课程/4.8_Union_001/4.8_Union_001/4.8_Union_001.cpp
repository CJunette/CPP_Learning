// 4.8_Union_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//union成员共用一个内存单元，内存大小由最大的成员决定。
//联合体不能有自定义的构造函数、自定义的析构函数、重载的复制赋值运算符，不仅联合体的成员不能有这些函数，成员的对象成员也不能有。
//联合体不能继承，因此不支持多态。
union Mark
{
    char grade;
    bool pass;    
    int percent;
};

//union还可以声明无名联合体。在程序中可以直接输入变量名进行访问。
//添加了static修饰是因为如果没有这个修饰就会导致编译报错。错误是namespace或全局条件下的union必须是static的。
//无名联合体只能对一个成员进行初始化。如果我初始化了i，再对j进行初始化就会导致报错。
static union 
{
    int i;
    float f;
};

int main()
{
    Mark mark;
    mark.grade = 'A';
    cout << "grade is " << mark.grade << endl << endl;
    mark.pass = true;
    cout << "grade is " << mark.grade << endl;
    cout << "pass is " << mark.pass << endl << endl;
    mark.percent = 90;
    cout << "percent is " << mark.percent << endl;
    cout << "grade is " << mark.grade << endl;
    cout << "pass is " << mark.pass << endl << endl;

    //访问无名联合体成员时可以直接用变量名访问。
    i = 303;
    f = (float)3.21;

    //由于无名联合体共用一段内存，因此如果出现了值类型不同的重写（float替换int），原类型的数据就会出现巨大变化（下面输出的i的值实际上是f以float形式存储的值用int方式读取的结果）。
    cout << f << endl;
    cout << i << endl;
    cout << &i << endl;
    //注意，这里如果在无名联合体外又一次声明了新变量i，就会无法再通过变量名访问无名联合体中的i。
    //将来会提到，这是可见性的问题。
    int i;
    i = 100;
    cout << i << endl;
    cout << &i << endl;
    //但对于另外一个未被影响的无名联合体变量，则仍然可以正常访问。
    cout << f << endl;
    cout << &f << endl;
}

