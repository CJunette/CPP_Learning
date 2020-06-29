// 10.3_Iterator_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//关于输出流迭代器和输入流迭代器的问题。

#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    //激活其中一个代码段时，请注释掉其他代码段。
    /*
    {
        istream_iterator<double> it(cin);
        istream_iterator<double> eof;         
        cout << *it << endl << endl;

        while(it != eof)
        {
            //1.这里可以看到，在对输入迭代器进行++操作的前后，迭代器的地址并没有发生变化。
            //1.也就是说，输入迭代器的++操作只是单纯地从输入队列中获取下一个对象。
            //1.但这就带来另一个问题，书上p406说p1++的返回类型是不确定的，但如果每次输入流迭代器都是在同一个位置接受新的输入的话，为什么返回值类型会变化呢？不是应该一直都是迭代器的类型吗？
            cout << &it << endl;
            //1.在此，由于是后置++，因此每次输出的都是上一次的输入值。
            //1.如果将这里改成前置++，则在最后输入结束符时，就会对一个空地址解引用，进而报错。            
            cout << *it++ << endl;
            cout << &it << endl;
            cout << typeid(it).name() << endl;
            cout << endl;
        }
    }
    */
    
    {
        //2.同样的，对输出迭代器进行++操作，迭代器的地址也不发生改变，++地址只是单纯地向输出流输出下一个对象。
        ostream_iterator<double> it(cout);
        for(int i = 0; i < 5; i++)
        {
            cout << &it<< endl;
            //2.输出流迭代器的对象只能在使用“=”进行赋值时实现输出，且对输出流迭代器进行多次的解引用，其结果的数据类型依然是输出流迭代器。
            //2.那这里就带来一个问题，为什么书上p406要说“=”和“++”必须交替进行？在实际操作中，不交替进行同样不会出现错误。
            //2.另外，这里似乎前置和后置的“++”对输出结果并不会有影响。这是为什么？输出迭代器的前置和后置“++”操作有什么区别？
            *++it = i;            
            cout << endl << &it << endl << endl;
        }
    }
    
    /*
    {
        //3.在这里，根据书上p406说的，it1 == it2并不能保证++it1 == ++it2。通过F12查看定义可以发现，两个迭代器是否相同实际比较的是其中的指针是否相同，而指针是否相同实际就是其中储存的地址是否相同。
        //3.但由于自增操作是不会改变地址的，因此按理说it1 == it2就必然意味着++it1 == ++it2。这与书上的结论就矛盾了，为什么？
        istream_iterator<double> it1(cin);
        istream_iterator<double> it2 = it1;
        bool a = it1 == it2;
        istream_iterator<double> eof;

        while(it1 != eof)
        {
            cout << &it1 << endl;
            cout << *++it1 << endl;
            cout << &it2 << endl;
            cout << *++it2 << endl;
            cout << endl;
        }
    }
    */
}