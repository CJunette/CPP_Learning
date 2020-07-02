// 10.7_FunctionObject_007.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Car
{
    int id;
    Car(int id):
        id(id)
    {}
    void display() const { cout << "car " << id << endl; }
};

int main()
{
    vector<Car *> pcars;
    vector<Car> cars;
    for(int i = 0; i < 5; i++)
    {
        pcars.push_back(new Car(i));
    }
    for(int i = 5; i < 10; i++)
    {
        cars.push_back(Car(i));
    }
    
    //用men_fun将成员函数适配成函数对象。
    //注意，在这里必须用“&类名::函数名”作为men_fun的参数。
    //之所以这里的men_fun的参数与我们前面看到的重载类的“()”作为函数对象向accumulate算法中输入时的参数不同，是因为之前要求向accumulate中输入的是一个函数对象（更进一步的，对于重载了“()”的类，是输入一个类的对象），而这里要求向mem_fun输入的是一个指向成员函数的函数指针。
    //mem_fun()适用于迭代器所指向的元素是指针。
    for_each(pcars.begin(), pcars.end(), mem_fun(&Car::display));
    cout << endl;
    //men_fun_ref()适用于迭代器所指向的元素是对象。
    for_each(cars.begin(), cars.end(), mem_fun_ref(&Car::display));

    //记得最后要删除动态生成的对象。
    //此外，这里出现了“size_t”类型，STL标准容器的size()返回值类型都是size_t。
    for(size_t i = 0; i < pcars.size(); i++)
    {
        delete pcars[i];
    }
}