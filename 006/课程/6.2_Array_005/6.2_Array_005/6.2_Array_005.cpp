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

    //4.这里之所以不用for循环去执行一个5次的循环，就是因为单次输入的答案数量可能是不确定的，如果用for循环就会把超出5的所有答案再进行一次得分统计。
    //4.而从程序设计的角度，我希望单次输入超出5的那部分答案会直接被丢弃。
    while (cin.get(c))
    {
        //1.如果用cin.get()，则输入语句中的“\n”也会作为字符串被输入。
        //1.这里之所以输入“ctrl+z”能跳出循环（其他什么ctrl+x，ctrl+y都没有用），好像是因为在命令行中“ctrl+z”相当于文件结束符EOF。
        //1.cin.get()这个函数的形参必须是char类型。如果输入的是正常的字符，就返回这个字符；如果输入的是EOF，就返回null（大概是这样）。
        //1.如果输入“任意字符+ctrl+z”，结果是ctrl+z还是会被当做char处理；只有单独输入ctrl+z，系统才会认为这是EOF。
        //2.如果在这里输入的答案超过了5个，程序会继续访问key[]数组后面的内存，但因为那些内存里都是垃圾值，所以还是会认为答案是错误的。（不过也存在垃圾值恰好就是答案的可能，但可能性不大。）
        //2.而且如果没有特别的语句处理这部分内容，就会导致接下来的每一个额外的答案都会进行一次成绩的输出。
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
        //3.所以在这里我对实例程序进行了一些修改。
        else if(c == '\n')
        {            
            cout << "Score: " << correct / QUEST_NUM * 100 << endl;
            count = 0;
            correct = 0;
            cout << endl;
        }
        //3.当输入的答案超过5个时，直接跳过第五个以后的答案。不用去考虑清空输入缓冲区什么的问题，直接跳到'\n'的位置。
        else
        { }
    }
}
