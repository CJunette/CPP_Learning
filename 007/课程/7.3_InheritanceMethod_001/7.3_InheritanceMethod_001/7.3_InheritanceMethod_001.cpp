// 7.3_InheritanceMethod_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//公有继承

#include <iostream>
using namespace std;

class Point
{
    public:
    void initPoint(float ix, float iy)
    {
        x = ix;
        y = iy;
    }
    void move(float offx, float offy)
    {
        x += offx;
        y += offy;
    }
    float getX() const { return x; }
    float getY() const { return y; }

    private:
    float x, y;
};

class Rectangle : public Point
{
    public:
    void initRectangle(float ix, float iy, float iw, float ih)
    {
        //由于x和y是Point类的private属性，不能直接被Rectangle类访问。所以要用initPoint()来实现对x和y的修改。
        //而能够使用initPoint()的原因是这个基类中的函数被继承了，且是public成员。
        initPoint(ix, iy);
        w = iw;
        h = ih;
    }
    float getW() const { return w; }
    float getH() const { return h; }

    private:
    float w, h;
};

int main()
{
    Rectangle rect;
    rect.initRectangle(2, 3, 20, 10);
    //move()是Point类中的public成员，被Rectangle类继承。
    rect.move(3, 2);
    cout << "The data of rectangle:" << endl;
    //同理，由于不能访问x和y，所以要通过getX()和getY()这些接口来间接地访问。
    //getX()和getY()都是public成员，且被继承。
    //此处还有一个小问题，当cout中有多个函数被调用时，会从右向左逐个执行，而非从左向右。
    cout << rect.getX() << ", " << rect.getY() << ", " << rect.getW() << ", " << rect.getH() << endl;
}
