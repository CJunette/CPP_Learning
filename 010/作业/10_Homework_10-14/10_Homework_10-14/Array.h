#pragma once
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

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
    void swap(Array<T> &arr);
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

template<class T>
void Array<T>::swap(Array<T> &arr)
{
    T *temp_ptr = list;
    int temp_size = _size;
    list = arr.list;
    _size = arr._size;
    arr.list = temp_ptr;
    arr._size = temp_size;
}
