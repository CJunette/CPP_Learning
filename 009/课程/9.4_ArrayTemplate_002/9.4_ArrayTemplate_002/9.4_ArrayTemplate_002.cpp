// 9.4_ArrayTemplate_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//9.4_ArrayTemplate_001中的Array的类模板的一个应用。
//要求输入n，输出2-n中所有的质数。

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

//Array的定义和9.4_ArrayTemplate_001中的完全一致，只是这里删掉了注释。
template<class T>
class Array
{
    public:
    Array(int size = 50);
    Array(const Array<T> &arr);
    ~Array();
    Array<T> &operator = (const Array<T> &arr);
    T &operator [](int i);
    const T &operator [](int i) const;
    operator T *();
    operator const T *() const;
    int getSize() const;
    void resize(int size);
    private:
    T *list;
    int _size;

    public:
    template<size_t N>
    Array<T> &operator = (const T(&arr)[N]);

    template<class S>
    Array<T> &operator = (const Array<S> &arr);
};

template<class T>
Array<T>::Array(int size)
{
    assert(size >= 0);
    _size = size;
    list = new T[_size];
}

template<class T>
Array<T>::Array(const Array<T> &arr):
    _size(arr._size)
{
    T list = new T[_size];
    for(int i = 0; i < _size; i++)
    {
        list[i] = arr.list[i];
    }
}

template<class T>
Array<T>::~Array()
{
    delete[]list;
}

template<class T>
T &Array<T>::operator [](int i)
{
    assert(i >= 0 && i < _size);
    return list[i];
}

template<class T>
const T &Array<T>::operator [](int i) const
{
    assert(i >= 0 && i < _size);
    return list[i];
}

template<class T>
Array<T>::operator T *()
{
    return list;
}

template<class T>
Array<T>::operator const T *() const
{
    return list;
}

template<class T>
int Array<T>::getSize() const
{
    return _size;
}

template<class T>
void Array<T>::resize(int size)
{
    if(size == _size)
    {
        return;
    }
    int n = (size > _size) ? _size : size;
    T *temp = new T[size]();
    for(int i = 0; i < n; i++)
    {
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    _size = size;
}

template<class T>
template< size_t N>
Array<T> &Array<T>::operator = (const T(&arr)[N])
{
    int n = sizeof(arr) / sizeof(T);
    _size = (_size > n) ? n : _size;
    delete[]list;
    list = new T[n];
    for(int i = 0; i < _size; i++)
    {
        list[i] = arr[i];
    }
    _size = n;
    return *this;
}

template<class T>
Array<T> &Array<T>::operator = (const Array<T> &arr)
{
    if(&arr == this)
    {
        return this;
    }
    int n;
    if(_size != arr._size)
    {
        n = (arr._size > _size) ? _size : arr._size;
        _size = arr._size;
        delete[]list;
        list = new T[_size];
    }
    for(int i = 0; i < n; i++)
    {
        list[i] = arr.list[i];
    }
    return *this;
}

template<class T>
template<class S>
Array<T> &Array<T>::operator =(const Array<S> &arr)
{
    int n;
    if(_size != arr.getSize())
    {
        n = (arr.getSize() > _size) ? _size : arr.getSize();
        delete[]list;
        _size = arr.getSize();
        list = new T[_size];
    }
    for(int i = 0; i < n; i++)
    {
        list[i] = arr[i];
    }
    return *this;
}


int main()
{
    int n;
    cout << "Please input an integer larger than 2: ";
    cin >> n;
    assert(n >= 2);

    int count = 0;
    Array<int> a(10);

    for(int num = 2; num <= n; num++)
    {
        bool isPrime = true;
        //判断是否一个数为素数，只要保证这个数除以比它小的所有素数都不为0即可。
        //因为合数一定可以转换为素数的乘积，因此不需要遍历从2到被判断数间的每个整数，只需要遍历小于被判断数的所有素数即可。
        for(int i = 0; i < count; i++)
        {
            if(num % a[i] == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime)
        {
            //如果count等于a.getSize()，说明现有的数组已经装满，需要扩充。
            if(count == a.getSize())
            {
                a.resize(a.getSize() * 2);
            }
            a[count++] = num;
        }
    }

    cout << "Prime numbers between 2 and " << n << " conclude: " << endl;

    for(int i = 0; i < count; i++)
    {
        cout << setw(8) << a[i];
    }
    cout << endl;
}
