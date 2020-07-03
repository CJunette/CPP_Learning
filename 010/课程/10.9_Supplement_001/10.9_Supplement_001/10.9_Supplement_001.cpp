// 10.9_Supplement_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p471-472的自定义迭代器的内容。

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template<class T>
//迭代器的关联类型——“iterator”，用来作为基类。
class IncrementIterator: public iterator<input_iterator_tag, T, ptrdiff_t, const T *, const T &>
{
    private:
    //这个迭代器并不指向任何元素。
    T value;
    public:
    typedef IncrementIterator<T> Self;
    IncrementIterator(const T& value = T()): value(value){}
    bool operator ==(const Self &rhs) const { return value == rhs.value; };
    bool operator !=(const Self &rhs) const { return value != rhs.value; };
    //这个迭代器的++并不是获得容器的下一个元素的迭代器，而是对自身成员value的自增。
    Self &operator++() { value++; return *this; }
    Self &operator++(int) 
    {
        Self temp = *this;
        value++;
        return temp;
    }
    const T &operator *()const { return value; }
    const T *operator ->()const { return &value; }

};

int main()
{
    //输出[0, 10)范围内的整数。这里实际是IncrementIterator<int>输出一次，对其中的value自增一次。
    copy(IncrementIterator<int>(), IncrementIterator<int>(10), ostream_iterator<int>(cout, " "));
    cout << endl;
    int s[] = { 5, 8, 7, 4, 2, 6, 10, 3 };
    //将s中的元素与IncrementIterator<int>迭代器所指元素进行plus<int>()，然后输出。
    //其中，每轮调用都会使IncrementIterator<int>迭代器中的value元素自增1。
    transform(s, s + sizeof(s) / sizeof(int), IncrementIterator<int>(), ostream_iterator<int>(cout, " "), plus<int>());
    cout << endl;
}
