﻿// 9.2_FunctionTemplateAndClassTemplate_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//函数模板与类模板的模板参数表中的默认参数。

#include <iostream>
using namespace std;

//0.下面的代码前，先建立一个概念：模板参数也是一种形参，在实例化时也必须为其提供具体的实参；它的实参可以通过函数的形参推测得到，也可以在“<>”中进行直接输入。
//0.而实例化的要求就是，每一个不存在默认值的模板参数都能够找到对应的实参，实现初始化。

//1.函数模板允许默认参数。
template<typename T = int>
void func1(T t)
{}

//2.函数模板允许模板参数表中有多个参数，且常量参数也可以设置默认参数。
template<typename T = int, int i = 0>
void func2(T t)
{
    //2.这边展示一下常量参数的作用。不过对于函数模板而言，其实可以通过在函数参数表中添加参数来实现同样的操作。
    t = i;
}

//3.函数模板的模板参数表并没有一般函数参数表的“默认参数必须放在最右侧”的规定。
//3.默认参数可以在任意位置。
template<typename T1 = double, typename T2>
//3.在函数模板的模板参数表中设置了默认参数以后，还可以在函数的参数表中在进行默认参数的设置。
//3.另外，虽然模板参数可以不要求默认参数在最右侧，但这里函数的参数表还是必须遵守默认参数在最右侧的规定。
void func3(T1 t1 = 0, T2 t2 = 0)
{}

//4.在函数模板的模板参数表中定义了多个参数的情况下（不存在默认参数），如果函数中只使用了一个参数，在实例化这个函数时，必须用“<>”显式地为模板参数表中的形参提供实参。
template<typename T1, typename T2>
void func4(T1 t1)
{
    cout << typeid(t1).name() << endl;
}

//5.func5和func6的区别在于模板参数表中默认参数所在的位置的差异。
//5.到主程序中会发现，其实像func5这样把默认参数写在左侧的做法不仅没有意义，不能减少实参个数，还增加了麻烦（所以我也不知道到底为什么要为模板函数设置这么一个特性[下面7.中会说到]）。
template<typename T1 = int, typename T2>
//5.这里虽然为函数的形参都准备了初始值，但这些初始值只有在类型确定的情况下才有意义。
void func5(T1 t1 = 0, T2 t2 = 0)
{
    cout << typeid(t1).name() << endl;
    cout << typeid(t2).name() << endl;
}
//6.func6中模板参数的默认参数的位置被放到了最右侧。
template<typename T1, typename T2 = int>
void func6(T1 t1 = 0, T2 t2 = 0)
{
    cout << typeid(t1).name() << endl;
    cout << typeid(t2).name() << endl;
}

//7.在4.中提到，函数模板的模板参数表中定义了多个参数的情况下，如果函数只有一个形参，则必须显示地声明另一个形参。
//7.在5.中提到，函数模板的模板参数中如果存在不再最右侧的默认参数，不能减少实参个数。
//7.这里结合这两条，给出一个反例。
template<typename T1 = int, typename T2>
void func7(T2 t2)
{
    cout << typeid(t2).name() << endl;
}
//8.也就是说，类似的，如果对5.中的函数func5()进行修改，让未被赋值的模板参数T2被放到优先结合的左侧的位置，就能实现只用一个参数实例化func8()的目的。
//8.但这样写并不利于代码的阅读和理解。
template<typename T1 = int, typename T2>
void func8(T2 t2 = 0, T1 t1 = 0)
{
    cout << typeid(t1).name() << endl;
    cout << typeid(t2).name() << endl;
}

//9.类模板同样允许默认参数。
template<typename T = int>
struct defClass
{    
    T i;
};

//9.类模板中还是要求默认参数必须在模板参数表的最右侧。可能是因为类模板在实例化的时候必须显式地声明类型参数。
/*
template<typename T1 = int, typename T2>
struct defClass2
{};
*/

int main()
{
    {
        //4.这里必须显示的为模板参数表提供参数（反例见7.）。
        func4<double, double>(1);
        //4.如果只是简单地按照函数的格式进行调用，会报错。因为模板参数表中的参数没有默认值，且程序没有给它提供实参。
        /*
        func4(1);
        */
        cout << "------------------------------------" << endl;
    }

    {
        int a = 1;
        double b = 2;        
        //5.下面的这两种写法都是错误的。
        //5.func5看似好像给一个模板参数添加了默认值，但实际上由于参数的形实结合是从左向右进行的（书上p83），因此func5()的参数表中如果只有一个参数b，它会选择和func5(T1 t1, T2 t2)的第一个形参t1结合。
        //5.func5的模板参数表也是一样，当只有一个参数double时，它会和template<typename T1, typenamte T2>中的第一个形参T1结合。
        //5.这也就是下面这两种写法的错误的原因。
        //5.换句话说，由于参数的形实结合必须从左向右，因此在函数模板中把默认参数放到非默认参数的左侧这种做法实际上没有任何意义（意义其实也有，见7.和8.）。
        /*
        func5(b);        
        func5<double>(b);
        */
        //5.如果函数模板的默认参数不再最右侧，那么在实例化时，必须在模板参数表中将所有的模板参数都列出；或者在函数的参数表中为所有形参都提供实参，是模板自己能从函数的参数表中推测出需要的模板参数。
        func5<int, double>(b);
        func5(a, b);     
        cout << "------------------------------------" << endl;
    }

    {
        int a = 1;
        double b = 2;
        //5.这里可以看到，只有当默认参数在最右侧时，向参数表中提供单一参数，参数才能正确地和模板中非默认的参数结合。
        //6.此处模板参数的第一个参数是通过函数的形参推测得到的。
        func6(b);

        //6.由于函数的形参都已经存在默认值了，因此只需要为模板参数提供参数，就能实现函数模板的实例化。
        func6<int, double>();

        //6.更简洁地，由于函数的所有参数都有默认值，且模板参数已经有一个参数存在默认值了，因此只需要提供一个类型参数，就能实现函数模板的实例化。
        func6<int>();

        //6.但如果什么都不提供的话，由于缺少一个模板参数，所以无法实现实例化。
        /*
        func6();
        */
    }    

    

    {
        long a = 1;
        //7.可以看到，虽然函数模板的参数T1没有在函数形参中出现（违反了4.），且它还是个不在最右侧的默认参数（违反了5.）。
        //7.但由于在实例化时，T1本身有默认值，T2的值可以从函数参数中进行推断，因此实例化还是成功地完成了。
        //7.由此可以看出，模板参数其实与一般的函数形参一样，其重点并不是是否为默认参数或是否出现在函数参数表中，而是在实例化的过程中，是否有实参与不存在默认值的形参进行结合。
        func7(a);
        //8.可以看到，这里函数的构造与5.唯一的差别就在于调换了函数参数的顺序。
        //8.这样一来，由于在func5()中无法确定的模板参数T2现在会在函数的参数表中被优先结合，因此T2的类型可以被确定，实例化可以实现。
        func8(a);
    }
}
