// 10.8_Algorithm_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int arr1[] = { 26, 17, 15, 22, 23, 33, 32, 40 };
    vector<int> v0(arr1, arr1 + sizeof(arr1) / sizeof(int));

    //查找并输出第一个最大值元素及其位置。
    vector<int>::iterator p = max_element(v0.begin(), v0.end());
    int n = p - v0.begin();
    cout << "max element: " << *p << " found at " << n << endl << endl;

    //局部排序并复制到其他容器（v1）中。
    vector<int> v1(5);
    partial_sort_copy(v0.begin(), v0.end(), v1.begin(), v1.end());
    ostream_iterator<int> out(cout, " ");
    copy(v1.begin(), v1.end(), out);
    cout << endl << endl;

    //排序，默认为递增。
    sort(v0.begin(), v0.end());
    copy(v0.begin(), v0.end(), out);
    cout << endl << endl;

    //返回小于等于24和大于等于24的元素的位置。
    //上面的这个书上的描述有点不合适。应该是返回二分法查找所得的可插入的迭代器位置对应的元素。
    cout << *lower_bound(v0.begin(), v0.end(), 24) << endl;
    cout << *upper_bound(v0.begin(), v0.end(), 24) << endl;
    cout << endl;

    //对于有序区间，可以用二分查找法寻找某个元素。返回布尔值。
    cout << binary_search(v0.begin(), v0.end(), 33) << endl << endl;

    //合并两个序列v0和v1，并把结果放到v2中。
    //合并后会自动进行排序。
    vector<int> v2(13);
    merge(v0.begin(), v0.end(), v1.begin(), v1.end(), v2.begin());
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    //将小于*(v.begin() + 5)的元素放置在该元素之左。其余置于该元素之右。不保证维持原有的相对位置。
    nth_element(v2.begin(), v2.begin() + 5, v2.end());
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    //排序，并保持原来相对位置。
    stable_sort(v2.begin(), v2.end());
    copy(v2.begin(), v2.end(), out);
    cout << endl << endl;

    //合并两个相邻的有序序列，然后将结果保存到原区间内。(我怎么感觉这就是sort了一下。)
    int arr2[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
    vector<int> v3(arr2, arr2 + sizeof(arr2) / sizeof(int));
    inplace_merge(v3.begin(), v3.begin() + 4, v3.end());
    copy(v3.begin(), v3.end(), out);
    cout << endl << endl;

    //以字典顺序比较序列v3和v4。返回第一个不同元素的位置。
    int arr3[] = { 1, 3, 5, 7, 1, 5, 9, 3 };
    vector<int> v4(arr3, arr3 + sizeof(arr3) / sizeof(int));
    cout << lexicographical_compare(v3.begin(), v3.end(), v4.begin(), v4.end()) << endl;
    cout << endl << endl;
}