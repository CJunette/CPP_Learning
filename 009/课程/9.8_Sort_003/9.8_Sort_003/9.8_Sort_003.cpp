// 9.8_Sort_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//起泡排序。
//要求定义一个函数，当输入一个数组时，对数组内的元素进行从小到大的排序。

#include <iostream>
using namespace std;

template<class T>
//这里的函数名不要用swap，似乎C++有个系统函数就是swap。
void swapNum(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T, size_t N>
void bubbleSort1(T(&a)[N])
{
    //这里的思路是，用两个嵌套循环，保证每次外层循环结束后，前N-i个数中最大的元素都被沉底。
    for(int i = 0; i < N - 1; i++)
    {
        int index = 0;
        int count = 0;
        //注意这里的循环终止条件是“j < N - i”。
        for(int j = 0; j < N - i; j++)
        {
            if(a[index] > a[j])
            {
                swapNum(a[index], a[j]);                
                count++;
            }
            //这里需要把“index = j”放到外面，因为如果“a[index] > a[j]”，则说明当前元素比下一个元素大，需要进行交换，交换后index应该变为下一个元素的序号j；
            //如果“a[index] < a[j]”，则说明当前元素比下一个元素小。因此就应该以下一个元素为最大元素继续交换。
            index = j;
        }
        //起泡排序的好处在于，当某次循环没有发生任何交换时，就说明序列已经是符合要求的了，可以直接跳出循环。
        if(count == 0)
        {
            break;
        }
    }
}

//相比之下，课上提供的示范代码要简单得多。
template<class T, size_t N>
void bubbleSort2(T(&a)[N])
{
    //令i的初始值为N - 1。
    int i = N - 1;
    while(i > 0)
    {        
        int index = 0;
        //当j小于i时，执行内层循环。
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swapNum(a[j], a[j + 1]);
                //当发生交换时，用index记下交换的位置。
                index = j;
            }
        }
        //在循环结束后，index的最终值表示最后发生交换的位置。同时也说明index到N - 1之间没有再次发生过交换。换言之，index到N - 1的元素都是按从小到大排列的。
        //因此，此时下一次的交换只需要从0到index即可。
        //这样一来，循环的次数与交换的次数会被减少很多。
        i = index;
    }
}

int main()
{
    int a1[5] = { 4, 2, 5, 3, 1 };
    for(int i = 0; i < 5; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
    bubbleSort1(a1);
    for(int i = 0; i < 5; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
    int a2[5] = { 4, 2, 5, 3, 1 };
    bubbleSort2(a2);
    for(int i = 0; i < 5; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
}
