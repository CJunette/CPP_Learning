// 10.8_Algorithm_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

class evenByTwo
{
    private:
    int x;
    public:
    evenByTwo(): x(0) {}
    int operator()() { return x += 2; }
};

int main()
{
    int arr1[] = { 0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 7, 8 };
    int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> v3(2);
    ostream_iterator<int> out(cout, " ");

    //迭代遍历v3区间，每个元素填上-1。
    fill(v3.begin(), v3.end(), -1);
    copy(v3.begin(), v3.end(), out);
    cout << endl << endl;

    //迭代遍历v3区间，对每个元素进行evenByTwo()操作。
    generate(v3.begin(), v3.end(), evenByTwo());
    copy(v3.begin(), v3.end(), out);
    cout << endl << endl;

    //将删除元素6后的v2序列至于另一个容器v4中。
    vector<int> v4;
    remove_copy(v2.begin(), v2.end(), back_inserter(v4), 6);
    //从这里可以看出来，remove算法并没有真正地“删除”元素。详见书上p453。
    copy(v2.begin(), v2.end(), out);   
    cout << endl;
    copy(v4.begin(), v4.end(), out);
    cout << endl << endl;

    //删除v2中小于6的元素。
    v2.erase(remove_if(v2.begin(), v2.end(), bind2nd(less<int>(), 6)), v2.end());
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    //将v2中所有元素值6，改为元素值3.
    replace(v2.begin(), v2.end(), 6, 3);
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    //逆向重排v2中的所有元素。
    reverse(v2.begin(), v2.end());
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    copy(v1.begin(), v1.end(), out);
    cout << endl;
    //将[v1.begin(), v1.begin() + 3)和[v1.begin() + 3, v1.end())两个区间的元素互换结果输出。
    rotate_copy(v1.begin(), v1.begin() + 3, v1.end(), out);
    cout << endl;
}