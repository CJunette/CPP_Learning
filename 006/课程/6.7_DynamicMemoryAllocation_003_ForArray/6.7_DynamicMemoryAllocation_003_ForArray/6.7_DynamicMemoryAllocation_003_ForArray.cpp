// 6.7_DynamicMemoryAllocation_003_ForArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上的一个例子。但这个例子没那么明确的反映出动态内存分配数组的独特性。

#include <iostream>
using namespace std;

class Point
{
    public:    
    Point(int x, int y) :
        x(x), y(y)
    {
        cout << "Calling constructor..." << endl;
    }
    Point() :
        x(0), y(0)
    {
        cout << "Calling default constructor..." << endl;
    }    
    ~Point()
    {
        cout << "Calling destructor..." << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newX, int newY)
    {
        cout << "Moving to (" << newX << ", " << newY << ")" << endl;
        x = newX;
        y = newY;
    }

    private:
    int x, y;
};

int main()
{
    //这里我有个问题，如何才能对动态内存分配的对象进行逐一的初始化？
    Point *ptr = new Point[2];
    ptr[0].move(5, 10);
    ptr[1].move(15, 20);
    cout << "Deleting..." << endl;
    //此处对动态内存分配的数组进行delete的时候必须在delete后面加上“[]”，才能实现对整个数组的释放。
    //否则释放的就是数组的第一个成员的地址，而非整个数组。
    //另外，ptr必须是数组的首元素的地址。如果之前的程序中对ptr进行了加减操作，造成ptr的指向位置发生变动，那在运行时，到delete这里就会出现程序卡死。
    //这里会发生错误的原因我有点不理解，因为之前已经说过数组名和指针是两个东西。但如果这里指针发生偏移会造成错误，就说明指针里至少储存了要释放多少单元，或释放到哪里为止的信息。而指针本身是不应该有这些信息的。
    delete[] ptr;
}

