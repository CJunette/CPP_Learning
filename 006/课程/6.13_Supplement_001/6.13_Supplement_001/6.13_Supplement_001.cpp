// 6.13_Supplement_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
    Point(float xx = 0, float yy = 0):
        x(xx), y(yy)
    {
        count++;
    }
    Point(Point const &pnt) :
        x(pnt.x), y(pnt.y)
    {
        count++;
    }
    ~Point()
    {
        count--;
    }
    float getX() const { return x; }
    float getY() const { return y; }
    static int getCount(){ return count; }
    friend float lineFit(const Point pnts[], int num)
    {
        float avrX = 0, avrY = 0;
        for (int i = 0; i < num; i++)
        {
            avrX += pnts[i].x;
            avrY += pnts[i].y;
        }
        avrX /= num;
        avrY /= num;

        float lxx = 0, lyy = 0, lxy = 0;
        for (int i = 0; i < num; i++)
        {
            lxx += pow((pnts[i].x - avrX), 2);
            lyy += pow((pnts[i].y - avrY), 2);
            lxy += (pnts[i].x - avrX) * (pnts[i].y - avrY);
        }
        float a = lxy / lxx;
        float b = avrY - a * avrX;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        float r = lxy / sqrt(lxx * lyy);
        return r;
    }

    private:
    float x, y;
    static int count;
};
int Point::count = 0;


int main()
{
    Point points[] = { Point(6, 10), Point(14, 20), Point(26, 30), Point(33, 40), Point(46, 50), Point(54, 60), Point(67, 70), Point(75, 80), Point(84, 90), Point(100, 100) };
    float r = lineFit(points, Point::getCount());
    cout << "r: " << r << endl;
}

