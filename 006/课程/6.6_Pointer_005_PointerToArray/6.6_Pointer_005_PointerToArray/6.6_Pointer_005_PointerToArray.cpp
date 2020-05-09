// 6.6_Pointer_005_PointerToArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int *pa = a;
    //经过上面的初始化后，以下四种写法都是等效的。    
    //a[i], *(pa + i), *(a + i), pa[i]
    //甚至可以用指针名当数组名用。
    //但这里需要注意，指针名是可以写pa++这样的自增的表达式的；但数组名因为是一个常量，所以不能这么写。

    int b[5] = { 1, 2, 3, 4, 5 };
    //如果指针指向的不是数组的首位而是中间，上述表达仍然能够使用，只不过会产生一些偏移。
    int *pb = &b[2];
    cout << b[2] << endl;
    cout << pb[2] << endl;

    //这里再次用指针证明了连续声明的两个局部变量在内存上并不是紧邻着排布的。
    int c = 0;
    int d = 1;
    int *pc = &c;
    cout << &c << endl;
    cout << &d << endl;
    cout << *(pc - 3) << endl;
    cout << endl;

    //有一个10元素的数组，要求用不同方法输出它的各个元素。

    int e[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *pe = e;

    //用最简单的“数组[序号]”方式。
    for (int i = 0; i < 10; i++)
    {
        cout << e[i] << '\t';
    }
    cout << endl;
    //用“*(指针 + 序号)”方式。
    for (int i = 0; i < 10; i++)
    {
        cout << *(pe + i) << '\t';
    }
    cout << endl;
    //用“*(数组名 + 序号)”方式。
    for (int i = 0; i < 10; i++)
    {
        cout << *(e + i) << '\t';
    }
    cout << endl;
    //用“指针[序号]”方式。
    for (int i = 0; i < 10; i++)
    {
        cout << pe[i] << '\t';
    }
    cout << endl;
}