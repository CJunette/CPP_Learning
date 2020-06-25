#pragma once
#include <cassert>

template<class T>
class Array
{
	private:
	int size;
	T *list;

	public:
	Array(int sz = 50);
	Array(const Array<T> &arr);
	~Array();
	Array<T> &operator =(const Array<T> &arr);
	T &operator [](int i);
	const T &operator [](int i) const;
	operator T *();
	operator const T *() const;
	int getSize() const;
	void resize(int newsize);
};

//写这个的时候我又把具体定义都放到其他源文件中了。
//注意！！！！！
//正常情况下，模板的声明和定义都是在头文件中的！！
template<class T>
Array<T>::Array(int sz)
{
	assert(sz >= 0);
	size = sz;
	list = new T[size];
}

template<class T>
Array<T>::Array(const Array &arr)
{
	size = arr.size;
	list = new T[size];
	for(int i = 0; i < size; i++)
	{
		list[i] = arr.list[i];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] list;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &arr)
{
	if(this == &this)
	{
		if(size != arr.size)
		{
			delete[] list;
			list = new T[arr.size];
		}
		for(int i = 0; i < arr.size; i++)
		{
			list[i] = arr.list[i];
		}
	}
	return *this;
}

template<class T>
T &Array<T>::operator[](int i)
{
	return const_cast<T &>((*static_cast<const Array<T> *>(this))[i]);
}

template<class T>
const T &Array<T>::operator[](int i) const
{
	assert(i >= 0 && i < size);
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
	return size;
}

template<class T>
void Array<T>::resize(int sz)
{
	assert(sz >= 0);
	if(sz == size)
	{
		return;
	}
	int n = (size < sz) ? size : sz;
	T *temp = new T[sz];
	for(int i = 0; i < n; i++)
	{
		temp[i] = list[i];
	}
	delete[]list;
	list = temp;
	size = sz;
}