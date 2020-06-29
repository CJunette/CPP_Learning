// 10.5_OrderContainer_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <list>
#include <deque>
using namespace std;

template<class T>
//1.虽然这个函数目前没有起作用，但是还是有必要提一点。这里的deque<T>::iterator其实是一个嵌套在类中的类，因此在其前面必须用typename进行修饰，避免编译器将其当做是deque<T>的一般数据成员。
ostream &operator <<(ostream &out, const typename deque<T>::iterator &d)
{
    out << *d;
    return out;
}

template<class T>
void printContainer(const char *msg, const T &s)
{
    cout << msg << ": ";
    //1.示范代码中这里“ostream_iterator”的模板参数是int，为什么我试图将“ostream_iterator”的模板参数改成T时会报错？？    
    //1.1.[回答] 这里的原因有点复杂。首先，ostream_iterator中对“=”的重载是与构造对象时的类型模板参数一致的（在这里就是deque<int>），copy()中有“=”运算，但运算所执行的操作实际上是求迭代器的值，也就是说copy中“=”右侧的数据类型是int，而非需要的deque<int>，这就造成了第一个错误。
    //1.1.接下来，即使通过构造函数，重新将那个int类型的数据变为deque<int>（在这里无法实现，但在自己执行“=”操作时可以），还是会有问题。因为ostream_iterator的对“=”的重载中，是通过“<<”运算符来实现输出的，而“<<”本身并没有以deque<int>对象为参数的重载。
    //1.1.此时会希望在主函数中重载“<<”运算符以解决问题。但到此会有一个无法解决的问题，如果在成员函数中调用运算符，则此时主函数中的运算符重载将无法影响那个函数中的运算符。由于“<<”是在运算符“=”的重载成员函数中的，因此无论在主函数中如何进行重载，都无法对其产生影响。    
    //1.2.[回答] 最为正确且快捷的做法是，将下面的模板参数写为<T::value_type>，也就是说，去获得deque<T>中的那个模板参数T所对应的类型，来作为ostream_iterator<T>的模板参数。
    copy(s.begin(), s.end(), ostream_iterator<T::value_type>(cout, " "));    
    cout << endl;
}

int main()
{
    deque<int> s;
    for(int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        //2.因为这里是用了push_front()，所以使得输入到s中的元素是以FILO的方式进行储存的。
        s.push_front(x);
    }    
    printContainer("deque at first", s);
    //2.用deque的逆序对list进行初始化，就可以实现正向输出之前从键盘输入的元素。
    list<int> l(s.rbegin(), s.rend());
    printContainer("list at first", l);
    
    //3.接下来是实现对list内的元素的两两互换。
    list<int>::iterator iter = l.begin();
    while(iter != l.end())
    {
        int v = *iter;
        //3.l.erase()返回的是被删除元素的下一个元素的迭代器。
        iter = l.erase(iter);
        //3.l.insert()执行的是在++iter（也就是iter的后一个元素的迭代器）之前，插入元素v。这个函数的返回值是插入后的元素的迭代器。但由于这里并没有对象去接收这个返回值，因此不用太在意。
        //3.注意，这里如果容器元素数是奇数，程序会在运行到最后一次insert()时由于++iter而报错。
        l.insert(++iter, v);
    }
    printContainer("list after swap", l);
    
    //4.s.assign()会在赋值之前，将容器内之前的元素都清除。
    s.assign(l.begin(), l.end());
    printContainer("deque at last", s);
}