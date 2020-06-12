// 9.2_FunctionTemplateAndClassTemplate_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//类模板，课上的例子。

#include <iostream>
using namespace std;

struct Student
{
    int id;
    float gpa;
};

template<class T>
class Store
{
    private:
    //用类型参数来确定数据成员的数据类型。
    T item;
    bool haveValue;
    public:
    Store();
    //用类型参数来确定成员函数的返回值的数据类型。
    T &getItem();
    //用类型参数来确定成员函数的参数的数据类型。
    void putItem(const T &item);
};
//这里，每一个成员函数实际上都是一个函数模板。
template<class T>
Store<T>::Store():
    haveValue(false)
{}
template<class T>
T &Store<T>::getItem()
{
    if(haveValue == false)
    {
        cout << "No item present!" << endl;
        exit(1);
    }
    return item;
}
template<class T>
void Store<T>::putItem(const T &i)
{
    haveValue = true;
    item = i;
}

int main()
{
    //当明确类型参数为int时，相当于生成了
    /*
    class Store
    {
        private:
        int item;
        bool haveValue;
        public:
        Store();
        int &getItem();
        void putItem(const int &item);
    };
    */
    //这样的一个类（这只是大致的说明，具体的类的构成根据编译器的不同还是会有差异）。
    Store<int> s1, s2;
    s1.putItem(3);
    s2.putItem(-7);
    cout << s1.getItem() << " " << s2.getItem() << endl;

    //注意，这里的类似数组初始化的方式能够用来构造有多个数据成员的类。（即使那个类没有写默认的构造函数。）
    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putItem(g);
    cout << "Student id: " << s3.getItem().id << endl;

    //此处，由于还没有对s4进行putItem()操作，在haveValue还是false的时候就执行getItem()操作，因此出现了意外退出的情况。
    Store<double> s4;
    cout << "Retrieving object s4..." << endl;
    cout << s4.getItem() << endl;
}
