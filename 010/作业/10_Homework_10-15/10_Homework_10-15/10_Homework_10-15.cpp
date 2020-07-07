// 10_Homework_10-15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

template<class T>
class IncrementIterator: public iterator<input_iterator_tag, T, ptrdiff_t, const T *, const T &>
{
	private:
	T value;
	const T *valuePtr;
	mutable set<T> valueSet;

	const T *getValuePtr(int n) const
	{
		pair<set<T>::iterator, bool> iter = valueSet.insert(n);
		return &(*iter.first);
	}
	void updateValuePtr()
	{
		valuePtr = getValuePtr(value);
	}

	public:
	typedef IncrementIterator<T> Self;

	IncrementIterator(const T &value = T()):
		value(value)
	{
		updateValuePtr();
	}

	bool operator == (const Self &rhs) const
	{
		return value == rhs.value;
	}

	bool operator != (const Self &rhs) const
	{
		return value != rhs.value;
	}

	Self &operator ++()
	{
		value++;
		updateValuePtr();
		return *this;
	}
	Self &operator ++(int)
	{
		Self t = this;
		value++;
		updateValuePtr();
		return t;
	}

	Self &operator--()
	{
		value--;
		updateValuePtr();
		return *this;
	}
	Self &operator--(int)
	{
		Self t = *this;
		value--;
		updateValuePtr;
		return t;
	}

	Self &operator +=(ptrdiff_t delta)
	{
		value += delta;
		updateValuePtr;
		return *this;
	}
	Self &operator -=(ptrdiff_t delta)
	{
		value -= delta;
		updateValuePtr;
		return *this;
	}

	Self operator +(ptrdiff_t delta) const
	{
		return Self(value + delta);
	}
	//由于存在IncrementIterator(const T &value = T())这样的构造函数，因此下面的这个友元函数其实没有必要。因为第一个操作数会被默认构造成IncrementIterator<T>类型的对象。
	friend Self operator +(ptrdiff_t delta, const Self &rhs)
	{
		return Self(delta + rhs.value);
	}
	Self operator -(ptrdiff_t delta) const
	{
		return Self(value - delta);
	}
	friend Self operator -(ptrdiff_t delta, const Self &rhs)
	{
		return Self(delta - rhs.value);
	}

	bool operator <(const Self &rhs) const
	{
		return value < rhs.value;
	}

	const T &operator [](ptrdiff_t delta) const
	{
		return *getValuePtr(value + delta);
	}

	const T &operator *() const
	{
		return *valuePtr;
	}
	const T *operator ->() const
	{
		return valuePtr;
	}
};

int main()
{
	ostream_iterator<int> out(cout, "\t");
	copy(IncrementIterator<int>(), IncrementIterator<int>(10), out);
	cout << endl;
	
	int s[] = { 5, 8, 7, 4, 2, 6, 10, 3 };
	transform(s, s + sizeof(s) / sizeof(int), IncrementIterator<int>(), out, plus<int>());
	cout << endl;
}
