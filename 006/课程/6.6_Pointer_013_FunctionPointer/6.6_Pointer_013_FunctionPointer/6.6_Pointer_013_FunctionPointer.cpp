// 6.6_Pointer_013_FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//注意，函数指针（function pointer）是指指向的地址是函数的首地址的指针。
//而之前提到的指针类型的函数（point function）是指返回值是指针的函数。
//这里先给出书上的一个例子。我觉得这个例子比较好的反映了函数指针的定义、赋值相关的的内容。

//另外，课上老师提到过，定义函数指针时需要“存储类型 数据类型 (*函数指针名)()”，这里的存储类型就是“static”这些。

#include <iostream>
using namespace std;

void printStuff(float)
{
    cout << "Printing stuff..." << endl;
}

void printMessage(float data)
{
    cout << "Printing message: " << data << endl;
}

void printFloat(float data)
{
    cout << "Printing float: " << data << endl;
}

const float PI = 3.141592635898;

int main()
{
    //在定义函数指针时，需要用“数据类型 (*函数指针名)(形参列表)”。其中函数指针名外的括号是十分重要的，因为去掉括号就变成了定义返回值为指针的函数。
    //同样注意，不要把形参表写到那个括号里去。
    //之所以有这些复杂的规则，说白了还是因为“指针指向对象的类型必须和指针自身的类型相符”这一原则。函数指针必须在定义时就确定好自己指向的目标的类型是怎样的。
    void (*funcPtr)(float);

    //注意这里有两个问题。
    //1.这里的“&”可以加，也可以不加。因为单独的函数名也能代表函数所在的内存位置。
    //2.这里有个C#里就遇到过的老问题。在设置函数指针的时候，只要具体函数即可，不需要加括号！
    funcPtr = &printStuff;
    //调用时，将实参传入函数指针的参数列表。
    funcPtr(PI);

    funcPtr = &printMessage;
    funcPtr(PI);
    funcPtr = &printFloat;
    funcPtr(PI);

    //当需要定义多个定义函数指针时，还可以用typedef实现更加简洁的定义。如下面就为返回值为void，参数为float的函数指针定义了一个别名voidFunctionFloat。
    typedef void (*voidFunctionFloat)(float);
    //当在需要定义这种类型的指针时，可以用这个别名实现快速的定义。
    voidFunctionFloat funPtr_1;
    voidFunctionFloat funPtr_2;
    voidFunctionFloat funPtr_3;
}
