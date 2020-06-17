// 9.8_Sort_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//插入排序。
//要求定义一个函数，当输入一个数组时，对数组内的元素进行从小到大的排序。

#include <iostream>
using namespace std;

//1.这个函数是通过交换来实现课上展示的那种“插入”的过程的。
//1.顺带说一句，插入排序的因为应该是insertion sort。
template<class T, size_t N>
void insertSort1(T (&a)[N])
{
    int n = N;
	//1.默认视首元素为已经排序好的元素（因为只有一个元素）。所以这里的循环从1开始。
	for(int i = 1; i < n; i++)
	{
		//1.因为排序会涉及对数组内元素的改变，因此这时必须拷贝数组内的对象，不能只拷贝元素在数组中的位置。
		T temp = a[i];
		int j = i;
		//1.如果此时的a[i]前的元素a[i-1]要比a[i]的元素小的话，则将a[i-1]放到a[i]的位置。
		//1.这里之所以用了j是因为这个过程要一直进行重复，知道到达数组的最前端，或找到一个元素，其左侧的元素比当前的a[i]中的元素小。
		//1.由于对大小的比较判断必须把当前元素前的所有元素都遍历以便，所以这里的条件是j > 0。
		while(j > 0 && a[j - 1] > temp)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}

#include "LinkedList.h"
//2.这里想要更好地展示“插入”的过程，用链表会比较合适。这里就使用9.5_LinkedList_002中定义的链表。
//2.这里与课上的思路有一点不同的地方。因为课上使用的是数组，数组必须一个一个地移动数组元素，无法直接实现插入；因此课上的算法是从当前值开始，向前逐个判断，当遇到比当前值大的数时，就将其后面所有的元素都移后一位。
template<class T, size_t N>
void insertSort2(T(&a)[N])
{
	LinkedList<T> list;
	//2.首先，以数组元素创建一个链表。
	for(int i = 0; i < N; i++)
	{
		list.insertRear(a[i]);
	}
	
	//2.因为第一个元素被认为是已经排好序的，因此从第二个元素开始。
	int pos = 1;
	//2.接着，准备对整个链表的元素进行排序。
	while(pos < N)
	{
		//2.第一步，将链表归零。
		list.reset();		
		//2.第二步，将链表移到pos位置。
		for(int i = 0; i < pos; i++)
		{
			list.next();
		}
		//2.第三步，取出链表pos位置的数据元素的值，并再次将链表归零。
		T currData = list.data();
		list.reset();

		//2.第四步，循环链表之前的结点，看是否存在比之前取出的元素要大的值。
		//2.如果存在，就将exist变为true，并跳出循环。否则继续看下一个结点。
		bool exist = false;
		for(int i = 0; i < pos; i++)
		{
			if(list.data() > currData)
			{
				exist = true;
				break;
			}
			//2.由于之前存在更大元素的情况已经跳出循环了，所以这里不用进行额外处理。
			list.next();						
		}
		//2.第五步，如果exist为true，则说明pos之前存在比pos位的元素要大的元素。此时需要在该元素前插入一个新结点，结点的元素就是之前的pos位的元素。
		//2.此时由于之前退出循环时是用了break的，因此这种情况下list的currPtr还是指向那个更大的元素的。
		if(exist)
		{
			list.insertBefore(currData);
			list.reset();
			//2.添加完结点后，再移动到之前pos的位置。
			//2.因为这里在左侧添加了一个新的结点，所以之前结点的位置相当于都后移了一位，因此这里是pos + 1。			
			for(int i = 0; i < pos + 1; i++)
			{
				list.next();
			}
			//2.移动完成后，删除pos（现在是pos + 1）位的结点。
			list.deleteCurrent();			
		}
		//2.第六步，完成一次循环后，将pos加一。
		pos++;
	}

	//2.最后将链表归零，然后将链表中的数据放回数组中。
	list.reset();

	for(int i = 0; i < N; i++)
	{
		a[i] = list.data();
		list.next();
	}
}

int main()
{
	int a1[5] = { 4, 2, 5, 3, 1 };
	int a2[5] = { 4, 2, 5, 3, 1 };

	for(int i = 0; i < 5; i++)
	{
		cout << a1[i] << "\t";
	}
	cout << endl;
	insertSort1(a1);
	for(int i = 0; i < 5; i++)
	{
		cout << a1[i] << "\t";
	}
	cout << endl;

	insertSort2(a2);
	for(int i = 0; i < 5; i++)
	{
		cout << a2[i] << "\t";
	}
}