// 11.3_InputStream_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-12，用istringstream将字符串转换为数值。

#include <iostream>
#include <sstream>
using namespace std;

template<class T>
inline T fromString(const string &str)
{
    istringstream is(str);    
    T v;
    //如果字符串中存在空格的话，执行“>>”会自动将空格作为分隔符，然后依次提取被空格分隔的元素（如果只有一个元素，没有空格，就重复提取）。下面被注释掉的代码就是用于演示这一过程的。
    //执行“>>”并不会使字符串本身发生改变（也即是说，虽然当存在空格时，每次“>>”所取出的元素都是“下一个”元素，但字符串本身并没有被逐个拆解），与别的输入流一样，这样的操作是依赖一个指针完成的。
    is >> v;
    /*
    cout << v << endl;
    is >> v;
    cout << v << endl;
    cout << is.str() << endl;
    */
    return v;
}

int main()
{
    cout << fromString<int>("5") << endl;
    /*
    cout << fromString<int>("5 3 4") << endl;
    */
    cout << fromString<double>("1.2") << endl;
}