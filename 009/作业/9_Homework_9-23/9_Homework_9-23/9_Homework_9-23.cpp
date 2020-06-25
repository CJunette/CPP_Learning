// 9_Homework_9-23.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;

/*
//P(m, n)（其中n较大，m较小），意思就是从n个数中抽取m个数的组合个数。
//计算公式为n! / (n - m)!。
template<unsigned M, unsigned N>
struct Permutation
{
    enum { NUMERATOR = (N * Permutation<M, N - 1>::NUMERATOR), DENOMINATOR = (N - M) * Permutation<M, N - 1>::DENOMINATOR, VALUE = NUMERATOR / DENOMINATOR };
};

template<unsigned M>
struct Permutation<M, 1>
{
    enum { NUMERATOR = 1, DENOMINATOR = 1};
};

//这里想要实现(n - m)!，只能通过让n不停地缩小，直到n = m时结束。
//但由于n!的计算过程中也一定会经过这里，因此需要将NUMERATOR再写成能够继续递归的形式。

template<unsigned M>
struct Permutation<M, M>
{
    enum { NUMERATOR = M * Permutation<M, M - 1>::NUMERATOR, DENOMINATOR = 1};
};

//如果两个参数都为1的话，结果肯定也是1。
template<>
struct Permutation<1, 1>
{
    enum { NUMERATOR = 1 , DENOMINATOR = 1, VALUE = 1};
};
*/

//答案给出的做法更为简单。
template<unsigned M, unsigned N>
struct Permutation
{
    enum {VALUE = Permutation<M - 1, N>::VALUE * (N - M + 1) };
};

template<unsigned N>
struct Permutation<1, N>
{
    enum {VALUE = 1};
};

/*----------------------------------*/

template<unsigned M, unsigned N>
struct Gcd
{
    enum { VALUE = (N % M == 0) ? M : Gcd<N % M, M>::VALUE };
};
//这里，虽然上面的三目表达式已经涵盖了所有情况，当N%M == 0时，会返回M。
//但由于在同行中还是会出现"Gcd<0, M>::VALUE"的情况，因此还是必须准备一个Gcd<0, N>的偏特化（这里写的参数名称不重要，因为辗转相除时会颠倒除数与被除数）。
template<unsigned N>
struct Gcd<0, N>
{
    enum { VALUE = N };
};

int main()
{
    cout << Permutation<2, 6>::VALUE << endl;
    cout << Gcd<6, 33>::VALUE << endl;
}