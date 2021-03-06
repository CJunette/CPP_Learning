﻿// 6.6_Pointer_012_PointerAndArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里是书上没有的内容，我简单对指针和数组进行一点小补充。

#include <iostream>
using namespace std;

void size(int a[])
{
    cout << "sizeof(a) in size(int a[]): " << sizeof(a) << endl;
}

int main()
{
    int a_1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    //1.在这里我们可以看到，在数组定义的地方调用sizeof()所得到的大小和将数组名作为参数传入函数后在函数中调用sizeof()所得到大小是不同的。
    //1.根据知乎上的回答https://www.zhihu.com/question/54437699，数组在作为实参被传入函数时，数组类型会退化成相应的指针类型。
    cout << "sizeof(a) in main(): " << sizeof(a_1) << endl;
    size(a_1);
    //1.作为一种“退化”，将指针指向数组的时候，这个标识符的大小是不会对应的变成那个数组的大小的。
    int *d = a_1;
    cout << sizeof(d) << endl;    

    int a_2[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    //2.接着我们继续看。下面的这个(*b)[10]，实际上等同于b[1][10]，也就是一个指向某个有10个元素的数组的指针。
    //2.但在对b进行初始化时，必须用&对a_1进行取地址的操作。我们清楚，实际上&a_1和a_1的值是一样的，都是a_1这个数组的首元素的地址。
    //2.但对于编译器而言，由于两者的数据类型不同，前者是“int * [10]”，后者是“int *”。所以即使我们知道初始化的时候只是对地址进行一个赋值，这种对编译器而言的类型不同的两个标识符也不能相互赋值。
    //2.另外，由于我们之前提到的数组的正确访问机制，如果这里试图用有12个元素的a_2去替换a_1的话，会报错。
    int(*b)[10] = &a_1;    
    //2.和上面这行代码类似的是下面这行代码。虽然d和&d在内存中都是地址，但仍然不能直接用d去对指向指针的指针f进行初始化。指针所指向的对象的类型必须和指针自身的类型相同。
    int **f = &d;

    //5.但其实上面这行代码又出现了另一个问题，如果我们想让f指向的是a_1的地址而非d的地址（如之前说的，a_1也是一个指针）。
    //5.下面这行代码是会报错的，因为编译器会认为这是把一个数组成员(int变量)的地址给了一个指针的指针，这是错误的。
    /*
    f = &(*d);
    */
    //5.而如果用下面这种更直接的写法，同样也会报错（不能用int * [10]来给int **初始化）。
    //5.这里其实说明了三点；一、指针类型必须与其所指向的对象类型相同，二、数组名确实不能完全地被视为指针，三、想要让一个指向指针的指针指向一个数组名本身就是一个错误的想法。
    //5.具体来说。f是一个指向指针的指针，也就是说它的值应该是某个指针所在的地址；而对a_1求址得到的地址并不能为f初始化，那就只能说明a_1并不是一个指针。
    //5.从内存角度来看，f作为指针的指针，其指向的地址中存储的内容应该是另一个地址；对于a_1而言，这个标识符的地址中实际存放的是a_1的第一个成员的值。
    //5.所以说我们说a_1是一个指针，这样的说法更多的是从标识符的角度，说a_1是一个能反应自身地址的标识符。而如果从内存的角度来看，a_1实际上存储的并不是一个地址值，因此并不能称其为一个严格的指针。
    /*
    f = &a_1;
    */
    //5.而下面的这种写法之所以不会报错，是因为此时的f已经指向了一个指针d。这么做只不过是让d指向了a_1。
    *f = a_1;
        
    //3.接下来这个问题就更能说明指针和数组的差别了。根据我们之前学过的，数组名就相当于指针。在第2条中也提到了(*b)[10]实际就是等同于b[1][10]。
    //3.但当我们真的对这样一个二维数组进行初始化的时候，之前使用的方法就不在适用了。与之前提到过的一样，新的数组是不能用已有的数组来进行初始化的；同样，也不能简单地用一个地址来尝试初始化。（一维数组也是这样。）
    //3.数组的初始化就只有用“{}”这一种方式。且数组名作为常量，必须在声明时就用这种方式进行初始化。
    //3.根据知乎https://www.zhihu.com/question/377249567，数组在初始化时不能被当成指针直接用地址赋值似乎是一个以前就存在的语言遗留原因。
    //3.（不过也存在各种形式的特例，如char a[] = "abcd"就是用一个已有数组来初始化新的数组）。
    /*
    int c[1][10] = &a_1;
    */            

    //4.如果利用C++中的自动确定类型的方法定义变量，然后将初始值设为a_1的话，此时e的数据类型会变成给一个指针，而非数组。
    //4.还是上面那篇知乎的回答，里面的解释是auto在进行类型推导的时候采用的是函数参数的规则。
    auto e = a_1;
    cout << sizeof(e) << endl;
}
