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

	void insertSort();
	void selectSort();
	void bubbleSort();
	template<size_t N>
	Array(const T (&a)[N]);
};


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

template<class T>
void swap(T &t1, T &t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template<class T>
void Array<T>::insertSort()
{
	for(int i = 1; i < size; i++)
	{
		T num = list[i];
		int j = i;
		for(j; j > 0; j--)
		{
			T a1 = list[j - 1];
			T a2 = list[j];
			if(list[j - 1] > num)
			{
				list[j] = list[j - 1];
			}
			else
			{
				break;
			}
		}
		list[j] = num;
	}
}

template<class T>
void Array<T>::selectSort()
{
	int min;
	for(int i = 0; i < size; i++)
	{
		min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(list[j] < list[min])
			{
				min = j;
			}
		}
		swap(list[i], list[min]);
	}
}

template<class T>
void Array<T>::bubbleSort()
{
	int i = size - 1;
	while(i > 0)
	{
		int j = 0;
		for(int k = 0; k < i; k++)
		{
			T a1 = list[k];
			T a2 = list[k + 1];
			if(list[k] > list[k + 1])
			{
				swap(list[k], list[k + 1]);
				j++;
			}
		}
		i = j;
	}
}

template<class T>
template<size_t N>
Array<T>::Array(const T(&a)[N])
{
	size = N;
	list = new T[size];
	for(int i = 0; i < size; i++)
	{
		list[i] = a[i];
	}
}