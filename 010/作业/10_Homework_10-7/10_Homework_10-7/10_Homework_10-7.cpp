// 10_Homework_10-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    cout << "Stack:" << endl;
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(6);
    cout << "pop1: " << s.top() << "\t";
    s.pop();
    cout << "pop1: " << s.top() << "\t";
    s.pop();
    s.push(2);
    s.push(3);
    cout << "pop1: " << s.top() << "\t";
    s.pop();
    cout << "pop1: " << s.top() << "\t";
    s.pop();
    cout << endl << endl;


    cout << "Queue:" << endl;
    q.push(5);
    q.push(1);
    q.push(4);
    q.push(6);
    cout << "pop1: " << q.front() << "\t";
    q.pop();
    cout << "pop1: " << q.front() << "\t";
    q.pop();
    q.push(2);
    q.push(3);
    cout << "pop1: " << q.front() << "\t";
    q.pop();
    cout << "pop1: " << q.front() << "\t";
    q.pop();
    cout << endl << endl;

    cout << "Priority Queue:" << endl;
    pq.push(5);
    pq.push(1);
    pq.push(4);
    pq.push(6);
    cout << "pop1: " << pq.top()<< "\t";
    pq.pop();
    cout << "pop1: " << pq.top() << "\t";
    pq.pop();
    pq.push(2);
    pq.push(3);
    cout << "pop1: " << pq.top() << "\t";
    pq.pop();
    cout << "pop1: " << pq.top() << "\t";
    pq.pop();
    cout << endl << endl;
}