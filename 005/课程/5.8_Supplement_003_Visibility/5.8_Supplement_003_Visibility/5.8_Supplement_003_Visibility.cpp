// 5.8_Supplement_003_Visibility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//关于可见性的补充。

#include <iostream>
using namespace std;

int i;
enum a { A, B, C };

class TestClass
{
    public:
    int k = 0;
};

void sayHello()
{
    cout << "Hello" << endl;
}

namespace Ns
{    
    int j;

    class TestClass
    {
        public:
        int k = 1;
        //类中也可声明与外部全局函数同名的函数。不过这个好像没什么实际意义，因为类中的函数成员都必须依托对象或类才能调用。可能唯一的作用就是在类的定义时顶替了外部的同名函数。
        void sayHello()
        {
            cout << "Hello, World." << endl;
        }
        //类中重名的枚举与函数同理。
        enum a {A, B, C};
    };

}

int main()
{
    i = 5;
    Ns::j = 6;
    {
        using namespace Ns;
        int i = 1;
        cout << "i: " << i << endl;

        int j = 2;
        cout << "j: " << j << endl;

        //如果用“Ns::”来确定范围，那么就不会受可见性的影响。
        cout << "Ns_j: " << Ns::j << endl;
    }

    cout << "i: " << i << endl;    
    cout << "Ns_j: " << Ns::j << endl;

    cout << endl;


    TestClass tc;
    cout << "tc.k: " << tc.k << endl;

    //using语句只影响其语句下面的代码，不影响上面的代码。
    using namespace Ns;
    //如果此时再定义一个TestClass的对象，就会出现歧义。
    /*
    TestClass tc;
    */

    {
        //同名对象导致外层对象不可见。
        Ns::TestClass tc;
        cout << "tc.k: " << tc.k << endl;
    }
    cout << "tc.k: " << tc.k << endl;


}
