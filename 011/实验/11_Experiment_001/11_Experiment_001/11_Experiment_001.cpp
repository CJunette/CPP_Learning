// 11_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

//这里是宏定义。
//下面的语句的意思是，输出a语句所代表的内容，并执行a语句。
//宏定义语句可以不以“;”结尾。
#define D(a) T << #a << endl; a;
//在执行宏定义语句前，必须定义其中的T。
//程序完成输出后，记得用写字板打开output.out文件查看结果。
ofstream T("output.out");

int main()
{
    //下面这个D(a)，实际上就是执行了上面的宏定义。
    //下面的语句的意思是，输出“int i = 53”，并执行语句“int i = 53”。
    //这里为了方便程序对齐，我还是把所有的宏定义语句都用“;”结尾了。
    D(int i = 53;);
    D(float f = 4700113.141593;);
    const char *s = "Is there any more?";

    D(T.setf(ios::unitbuf););

    D(T.setf(ios::showbase););
    D(T.setf(ios::uppercase););
    D(T.setf(ios::showpos););
    D(T << i << endl;);

    D(T.setf(ios::hex, ios::basefield););
    D(T << i << endl;);

    D(T.unsetf(ios::uppercase););
    D(T.setf(ios::oct, ios::basefield););
    D(T << i << endl;);

    D(T.unsetf(ios::showbase););
    D(T.setf(ios::dec, ios::basefield););
    D(T.setf(ios::left, ios::adjustfield););
    D(T.fill('0'););
    D(T << "fill char: " << T.fill() << endl;);
    D(T.width(8););
    T << i << endl;

    D(T.setf(ios::internal, ios::adjustfield););
    D(T.width(8););
    T << i << endl;
    D(T << i << endl;);
    
    D(T.unsetf(ios::showpos););
    D(T.setf(ios::showpoint););
    D(T << "prec = " << T.precision() << endl;);
    D(T.setf(ios::scientific, ios::floatfield););
    D(T << endl << f << endl;);

    D(T.setf(ios::fixed, ios::floatfield););
    D(T << f << endl;);

    D(T.setf(0, ios::floatfield););
    D(T << f << endl;);

    D(T.precision(16););
    D(T << "prec = " << T.precision() << endl;);
    D(T << endl << f << endl;);

    D(T.setf(ios::scientific, ios::floatfield););
    D(T << endl << f << endl;);

    D(T.setf(ios::fixed, ios::floatfield););
    D(T << f << endl;);

    D(T.setf(0, ios::floatfield););
    D(T << f << endl;);
    
    D(T.width(8););
    T << s << endl;

    D(T.width(36););
    T << s << endl;
    D(T.setf(ios::left, ios::adjustfield));
    D(T.width(36););
    T << s << endl;

    D(T.unsetf(ios::showpoint););
    D(T.unsetf(ios::unitbuf););
}