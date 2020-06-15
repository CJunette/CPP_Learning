// 9.4_ArrayTemplate_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//按课程视频的内容，“9.3 线性群体”并没有需要写代码的地方，所以直接跳到“9.4 数组类模板”。
//1.-7.是写代码时候的备注。8.-11.的是后面重新看代码之后添加的备注。

#include <iostream>
#include <cassert>
using namespace std;

//1.这里之所以多加了一个N(template<class T, int N = 50>)，一是可以z用这个参数直接控制size的默认值；二是在重载用于用任意类型的数组初始化Array中参数list的操作符“=”时，需要size_t类型的参数来确定数组大小。
//1.[修改] 之前这里的写法有误，将“size_t N”放到这里会使得N在类的实例化时就被初始化，这不是我希望的。
template<class T>
class Array
{
    public:
    Array(int size = 50);
    Array(const Array<T> &arr);
    ~Array();
    //5.这里在定义的时候我把三个等号操作符的重载都写到了一起。
    Array<T> &operator = (const Array<T> &arr);
    T &operator [](int i);
    //2.[]的常函数重载。
    const T &operator [](int i) const;
    //3.这个运算符重载是将类名转换为数组指向对象的指针，以实现与“数组名能表示指向数组首地址的指针”一样的功能（一般情况下对象名是不能被直接使用的）。
    //3.值得注意的是，这个运算符重载没有返回值。
    operator T *();
    //3.其次，当这个指针转换操作符需要返回const值时，“const”是写在“operator”和“T*()”之间的。如果写到开头，在具体定义时会提示“转换函数可能会没有返回值”。
    operator const T *() const;
    int getSize() const;
    void resize(int size);
    private:
    T *list;
    int _size;

    public:
    //1.补充一个“=”的重载，使得可以用数组引用对Array进行赋值。
    //1.之前我把下面的这个N写到了整体类模板的模板参数中去，结果使得那个模板参数在类生成的时候就被初始化了，没有达到我希望的目的。
    //1.我希望这里是调用函数的时候才确定具体的数组引用的大小N。
    //1.另外，如果需要在类模板中再套用函数模板，只需要把“template<新的参数>”加到对应函数前即可。
    template<size_t N>
    Array<T> &operator = (const T (&arr)[N]);

    //7.通过再次声明模板函数的方式将一个成员函数变为模板函数，用于进行不同类型的Array对象之间的转换。
    template<class S>
    Array<T> &operator = (const Array<S> &arr);
};

template<class T>
Array<T>::Array(int size)    
{
    //4.“assert”是在内部值为false时报错。
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
    //2.这里，本来我想用
    /*
    return (*this)[i];
    */
    //2.实现代码复用的结果发现这样写的话，在运行时这个函数就在不停地调用自身。所以还是重写一遍代码。
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
    //8.这里首先要确定需要复制的成员的个数。必须是_size和size中较小的那一个。因为如果较大的那一个是size的话，数组_size - 1之后的成员都是空的，不应该被复制。
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

//1.这里必须有一个模板参数用来确定数组引用的大小，否则是无法对数组引用求sizeof()的。
//1.其具体值会由操作数（用于赋值的那个数组引用）提供。
//1.由于上面对类模板的成员函数又进行了一次新的模板的声明，因此这里需要写两个template，且顺序必须正确。
template<class T>
template< size_t N>
Array<T> & Array<T>::operator = (const T(&arr)[N])
{    
    int n = sizeof(arr) / sizeof(T);
    //9.这里_size处理的思路和上满的resize()一样。
    _size = (_size > n) ? n : _size;
    delete[]list;
    list = new T[n];
    for(int i = 0; i < _size; i++)
    {
        list[i] = arr[i];
    }
    //9.只是最后还是需要把_size变为被复制的对象的大小。
    _size = n;
    return *this;
}

template<class T>
Array<T> &Array<T>::operator = (const Array<T> &arr)
{
    //5.如果“=”的第二个操作数是自身，就返回自身。
    //5.这里是对arr进行求址，然后与自身地址进行比较。
    if(&arr == this)
    {
        return this;
    }
    int n;
    //5.如果大小不同，则删掉旧list，以被复制对象的大小创建新的list。
    if(_size != arr._size)
    {
        //10.复制时处理的思路和8.与9.一致。
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

//6.等号操作符重载不能作为非成员函数。
/*
template<class T1, class T2>
Array<T1> operator = (Array<T1>, Array<T2>)
{}
*/

//7.通过创建新的模板函数将操作符“=”的第二个操作数改为与当前类型不同的操作数，以此实现不同类型的Array对象之间的复制。
//7.其实有了这个模板函数，就不需要上面的那个两个操作数都是Array<T>类型的“=”重载了。
template<class T>
template<class S>
Array<T> &Array<T>::operator =(const Array<S> &arr)
{
    int n;
    //11.注意，这里因为Array<S>和Array<T>是两个不同的类，因此不能在Array<T>中直接用arr._size来访问Array<S>的私有成员arr._size。
    if(_size != arr.getSize())
    {
        //10.复制时处理的思路和8.与9.一致。
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
    Array<int> arr1;
    arr1 = { 1, 2, 3, 4, 5 };
    for(int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << endl;

    //3.这里就是指针转换操作符的具体应用。
    cout << arr1 << endl;
    cout << endl;

    arr1.resize(10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << endl;

    Array<double> arr2;
    //6.这里，因为在重载“=”操作符时，是作为成员函数定义的，而操作符对象又是本类对象，因此这个重载就默认了“=”两边的操作数类型是一致的。
    //6.我试图将这个“=”重载为非成员函数，但编译器提示“=”只允许重载为成员函数。
    //6.我也不知道这种类型转换要如何实现。
    /*
    arr2 = arr1;
    */
    
    //7.成功实现不同类型的Array之间的复制。
    arr2 = arr1;
    for(int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}
