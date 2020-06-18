// 9.9_Search_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//折半查找。
//折半查找要求针对有序的数组使用。这里的算法是针对从小到大排列的数组写的。

#include <iostream>
using namespace std;

//1.binSearch1()是我自己写的。与课上的代码相比，可能循环的次数会更少一些，但代码看起来更复杂（多了一个上下界相邻时的比较）。
template<class T, size_t N>
int binSearch1(T(&a)[N], T num)
{
    int i = 0, j = N - 1;
    //1.只要没有return，就一直循环。
    while(true)
    {
        //1.这里这个算式其实就是“(i + j) / 2”，简单的说就是取i、j位置的中间位置。
        int k = i + (j - i) / 2;
        if(a[k] == num)
        {
            return k;
        }
        //1.与课上的示范代码不同，我在调整范围时没有用+1或-1的方法把现有的中间点划分到新范围之外。
        //1.因此，i与j永远不会相等或交叉。最靠近的状态就是两者紧邻。
        else if(a[k] > num)
        {
            j = k;
        }
        else if(a[k] < num)
        {
            i = k;
        }
        //1.在i与j紧邻的情况下，如果不用条件语句进行判断，循环就会一直继续。
        if(j == i + 1)
        {
            //1.之所以对a[i]和a[j]都进行了比较，是因为在不同的范围收缩的情况下，i与j的变化可能各有不同。
            //1.因此一起进行比较，防止遗漏。
            if(a[i] == num)
            {
                return i;
            }
            if(a[j] == num)
            {
                return j;
            }
            return -1;
        }
    }
}

//2.binSearch2()是课上给出的示范代码。
template<class T, size_t N>
int binSearch2(T(&a)[N], T num)
{
    int min = 0, max = N - 1;
    //2.这里由于下面的代码中收缩范围时用了+1或-1，所以min和max是可能出现交叉的情况的。（也就是说min可能大于max。）
    //2.而一旦这种情况发生，就说明整个数组的范围都已经被遍历了。且没有找到需要找到目标数值。
    while(min <= max)
    {
        int mid = (min + max) / 2;
        if(a[mid] == num)
        {
            return mid;
        }
        if(a[mid] > num)
        {
            //2.这里的思路是，既然a[mid]与num不相等，那下面只要在min到mid-1的范围内进行寻找即可。            
            max = mid - 1;
        }
        if(a[mid] < num)
        {
            //2.既然a[mid]与num不相等，那下面只要在mid+1到max的范围内进行寻找即可。
            //2.这里其实有个小瑕疵。如果min是8，max是10，那么mid就为9，此时如果a[9]<num，min会+1,变为9；而当min为9，max为10时，mid依然为9，等于重复了之前的步骤。
            //2.这个问题会在min向max靠近且距离只有2时出现。会出现这个问题的原因是int是自动向下取整的。
            min = mid + 1;
        }        
    }
    return -1;
}

int main()
{
    //3.如果数组是无序的，就先写个排序算法将数组按从小到大进行排序。
    int a[11] = { 5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92 };
    for(int i = 0; i < 11; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;

    int n;
    int num = 5;

    n = binSearch1(a, num);
    if(n >= 0)
    {
        printf("Found! array[%d] = %d", n, a[n]);
    }
    else
    {
        cout << "Not found!" << endl;
    }
    cout << endl;

    n = binSearch2(a, num);
    if(n >= 0)
    {
        printf("Found! array[%d] = %d", n, a[n]);
    }
    else
    {
        cout << "Not found!" << endl;
    }
}
