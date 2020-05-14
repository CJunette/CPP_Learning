// 6.9_Vector_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//我们之前曾经尝试过将某个类的动态数组封装到另一个类中，以实现更复杂的功能和更简单的操作。
//但如果每遇到一个类就需要进行一次这样的封装，那就会出现类型膨胀的问题。
//vector这个类模板能很好地解决上述的问题。vector可以用来容纳任何类型的动态数组，能够实现自动创建和删除，能够对下标越界进行检查（简单地说就是像以前我们自己做的那样在vector类里定义了另一个类的数组并使用了泛型）。

#include <iostream>
#include <vector>
using namespace std;

//说实话我觉得在这个程序示例中，这里用引用的形式没什么必要。
//[纠正]像vector这种类模板的对象，本身可能就占据了大量的内存空间。此时如果不用引用而用一般的值作为参数，在传入函数时需要执行复制，会耗费大量的计算资源。
//而用指针、数组、引用作为形参的一大目的其实就是实现直接访问，避免大量复制造成的浪费。因此这里使用引用很有必要。
double getAverage(const vector<double> &a)
{
    double sum = 0;
    //vector的另一个便利之处在于它内置了.size()函数用于求内部的成员个数。
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    return sum / a.size();
}

int main()
{
    int n;
    cout << "Please input a number" << endl;
    cin >> n;
    
    //注意，定义vector时，动态数组的长度是在圆括号中的，不像一般的数组那样在方括号中。如果没有给出长度，则默认长度为0。
    //同时，定义vector时，需要给出数组类型。
    //通过F12查看代码我们知道，vector本身实际就是一个类（class）。
    vector<double> ary(n);
    cout << "Please input " << n << " real numbers." << endl;
    for (int i = 0; i < n; i++)
    {
        //而在使用vector时，是可以将vector名当做数组名来使用的。
        //要注意的是，vector名并不像数组名那样能代表数组首地址。我尝试输出vector名时，编译器会报错。这里就比较奇怪了，因为vector声明的标识符应该是一个对象，而输出对象应该会输出对象所在的内存的首地址。
        //但这里输出vector名的时候却会报错，原因不明？[纠正]，直接输出对象名也会导致报错，不奇怪。
        //这里可以用方括号+下标的方式来访问vector中的成员的原因是在vector中对下标运算符进行了重载（第8、第9章中会深入讲）。
        cin >> ary[i];
    }

    //vector也可以在初始化定义时，用第二个参数给所有的元素指定相同初值。如，下面声明的这个vector就有5个元素，初值都为1。
    vector<int> defaultArr(5, 1);

    cout << "The average is " << getAverage(ary) << endl;

    cout << endl;

    cout << "Output with ranged for loop:" << endl;

    //下面是利用auto和基于范围的for循环来实现数组元素的遍历。

    //这里.begin()返回的是“起始指针”，之所以有引号是因为这实际上是一个迭代器（第10章中会深入讲），但是目前来说可以暂时把它理解为指针。
    for (auto i = ary.begin(); i < ary.end(); i++)
    {        
        //因此这里想要输出指针指向的对象需要用寻址操作。
        cout << *i << endl;
    }
    for (auto e: ary)
    {
        //此时的e是当前地址中的对象。
        cout << e << endl;
    }

    //当出现越界访问时，会像之前那样通过assert报错。
    /*
    cout << ary[19] << endl;
    */
}
