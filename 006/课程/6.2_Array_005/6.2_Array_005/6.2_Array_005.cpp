// 6.2_Array_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const char key[5] = { 'a', 'b', 'c', 'd', 'a' };
    const int QUEST_NUM = 5;
    cout << "Please input " << QUEST_NUM << " answers." << endl;
    char c;
    int count = 0;
    double correct = 0;

    while (cin.get(c))
    {
        //如果用cin.get()，则输入语句中的“\n”也会作为字符串被输入。
        //这里之所以输入“ctrl+z”能跳出循环（其他什么ctrl+x，ctrl+y都没有用），好像是因为在命令行中“ctrl+z”相当于文件结束符EOF。
        //如果在这里输入的答案超过了5个，程序会继续访问key[]数组后面的内存，但因为那些内存里都是垃圾值，所以还是会认为答案是错误的。（不过也存在垃圾值恰好就是答案的可能，但可能性不大。）
        if (c != '\n' && count < 5)
        {
            if (c == key[count])
            {
                cout << " ";
                correct++;
            }
            else
            {
                cout << '*';
            }
            count++;
        }
        else if(c == '\n')
        {            
            cout << "Score: " << correct / QUEST_NUM * 100 << endl;
            count = 0;
            correct = 0;
        }
        //当输入的答案超过5个时，直接跳过第五个以后的答案。不用去考虑清空输入缓冲区什么的问题，直接跳到'\n'的位置。
        else
        { }
    }
}
