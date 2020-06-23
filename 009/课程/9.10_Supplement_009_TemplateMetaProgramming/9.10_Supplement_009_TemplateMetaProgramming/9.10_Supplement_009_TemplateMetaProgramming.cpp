// 9.10_Supplement_009_TemplateMetaProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p392-395的模板元编程。模板元编程的技巧和方法十分丰富，这里只是个简介。
//模板元编程的意思就是指在模板实例化的同时利用编译器完成一些计算任务。

#include <iostream>
using namespace std;

//1.当希望使用正常的阶乘函数来计算结果，并将结果作为一般数组的大小时，会出现错误。
unsigned getFactorial_1(unsigned i)
{
    return (i == 1) ? 1 : i * getFactorial_1(i - 1);
}

/*----------------------------------------------------------------------------*/

//2.但是，通过模板元编程，就可以实现将计算在编译过程实现的目的。
//2.通过在模板类中定义匿名枚举，并让枚举值等于一个递归表达式，递归表达式的终点是某个特化的模板，即可达到目的。
//2.这样做之所以可行，是因为递归的值是要在编译过程中就求出的。这里的枚举值其实就是类中的一个静态常量。
template<unsigned N>
struct Factorial
{
    enum { VALUE = Factorial<N - 1>::VALUE };
    static unsigned i;
    static const unsigned j = Factorial<N - 1>::j;
};
template<unsigned N>
unsigned Factorial<N>::i = Factorial<N - 1>::i;
//2.阶乘的终点是乘数为1的情况，因此对模板参数N = 1的情况进行特化。将其中的枚举值VALUE定义为1。
template<>
struct Factorial<1>
{
    enum { VALUE = 1 };
    static unsigned i;
    static const unsigned j = 1;
};
unsigned Factorial<1>::i = 1;

template<unsigned N>
unsigned getFactorial_2()
{
    return (N == 1) ? 1 : N * getFactorial_2(N - 1);
}

/*----------------------------------------------------------------------------*/

//3.一般情况下，计算乘方会采用<cmath>中的pow()或像下面这样定义一个专门的内联函数进行计算（以增加效率）。
//3.但是次数当较小时，用pow()会比较浪费效率；当底数较复杂时，下面这种power()在处理参数时会比较繁琐。
inline double getPower0(double x, unsigned n)
{
    double product = 1;
    for(int i = 0; i < n; i++)
    {
        product *= x;
    }
    return product;
}

/*----------------------------------------------------------------------------*/

//4.对应的，可以用模板来实现乘方的算法。
//4.这样，既可以保证参数处理的方便，又可以保证在函数内联的情况下，运行效率有所提升。
template<unsigned N>
inline double getPower1(double a)
{
    return a * getPower1<N - 1>(a);
}
template<>
inline double getPower1<1>(double a)
{
    return a;
}

/*----------------------------------------------------------------------------*/

//5.但由于上面的函数模板无法实现偏特化，因此想要将数据类型从double扩展到任意类型的话，就需要定义类模板。
//5.下面这个Power1类是我写的。
template<class T>
struct Power1
{
    template<unsigned N>
    //5.这里将函数设置为静态函数，方便直接通过类来调用。
    inline static double getPower(T a)
    {
        return a * getPower<N - 1>(a);
    }
    template<>
    inline static double getPower<1>(T a)
    {
        return a;
    }
};
//5.下面这个Power2类是书上的示例。
template<unsigned N>
struct Power2
{
    template<class T>
    inline static double getPower(T a)
    {
        return a * Power2<N - 1>::getPower(a);
    }
};
template<>
struct Power2<1>
{
    template<class T>
    inline static double getPower(T a)
    {
        return a;
    }
};
//5.在此基础上，可以再写一个模板函数用于更方便地调用类的静态函数。
template<unsigned N, class T>
inline T getPower2(T t)
{
    return Power1<T>::getPower<N>(t);
}


int main()
{
    {
        //1.因为函数的返回值要到运行时才能确定，而数组的大小必须在编译时就确定。                
        //1.因此下面这种希望以函数返回值作为数组大小的做法是不成立的。        
        /*
        int a[getFactorial_1(5)];
        */
    }
    
    {
        //2.在这里可以看到，匿名枚举的值可以充当数组的大小。
        int a[Factorial<5>::VALUE];
        //2.但相应的，如果在模板内定义静态成员，是无法达到相同目的的。因为静态成员的定义要在类外靠单独的定义语句进行，所以无法实现编译器静态。
        /*
        int b[Factorial<5>::i];
        */
        //2.但如果定义的是静态成员常量，则可以实现相同目的。因为静态成员常量的定义时可以在类体内进行的（书上p166）。
        int c[Factorial<5>::j];
        //2.由于此处模板元编程的实现是基于编译器静态的，因此函数模板并不能实现我需要的目的。
        /*
        int d[getFactorial_2<5>()];
        */
    }

    {
        //3.用一般的做法实现乘方运算。
        cout << getPower0(2, 3) << endl;
        cout << endl;
    }

    {
        //4.用函数模板实现类型确定的乘方运算函数。
        cout << getPower1<3>(2) << endl;
        cout << endl;
    }

    {        
        //5.用类模板实现类型不定的乘方运算函数模板。
        cout << Power1<int>::getPower<3>(2) << endl;
        cout << Power2<3>::getPower<double>(2) << endl;
        //5.利用类模板加函数模板的方式，进一步简化调用操作。
        cout << getPower2<3>(2) << endl;
    }
}
