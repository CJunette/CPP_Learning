// 6.6_Pointer_006_ArrayOfPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//指针数组就是指数组元素是指针的数组。

#include <iostream>
using namespace std;

int main()
{
    int line1[] = { 1, 0, 0 };
    int line2[] = { 0, 1, 0 };
    int line3[] = { 0, 0, 1 };

    //从结果上来看，这种指针数组和二维数组起到的作用是一样的。但实际上两者还是有些不同。
    //1.从功能上来看，二维数组要求所有数组的第二维度都大小相同；但指针数组并不要求数组内指针指向的数组的大小相同。
    //2.从内存存储上来看，二维数组的所有元素都是紧邻存储的；但指针数组之后数组中的指针是紧邻存储的，指针所指向的数组并不一定是紧邻存储的。
    int *pLine_1[3] = { line1, line2, line3 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //其实这里更直观的写法应该是“*(pLine_1[i] + j)”。但是之前我们说过了，指针名也可以直接拿来当数组名用，所以写成下面这种形式也是正确的。
            cout << pLine_1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    int line4[] = { 1 };
    int line5[] = { 2, 3 };
    int line6[] = { 4, 5, 6 };
    int *pLine_2[3] = { line4, line5, line6 };
    
    //如上面说到的，因为指针数组只有指针的存放是紧邻的，而指针指向的存放则不一定是紧邻的。所以如果此时我们希望像以前在二维数组中那样做越界访问的话，很有可能访问到的的就是垃圾值了。
    cout << pLine_2[0][0] << endl;
    cout << &pLine_2[0][0] << endl;
    cout << pLine_2[0][1] << endl;
    cout << &pLine_2[0][1] << endl;
    cout << pLine_2[1][0] << endl;
    cout << &pLine_2[1][0] << endl;
}
