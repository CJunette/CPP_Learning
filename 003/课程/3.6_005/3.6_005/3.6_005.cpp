// 3.6_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void SwapRef(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

//这个函数虽然在内部对指针指向的对象进行了更换，更换只限于函数内。
//相当于函数本身根据提供的实参创建了两个新的指针，然后交换了这两个新的指针的指向。
void SwapPnt(int *c, int *d)
{
    int *t = c;
    c = d;
    d = t;
}

//但这个函数就不同了，因为调整的对象变成了指针指向的对象，因此无论是否创建了新的指针，指向的对象的参数都会发生变化。
void SwapPntValue(int *c, int *d)
{
    int t = *c;
    *c = *d;
    *d = t;
}

//这个函数实现了引用指针，也就是说在函数不再创建指针的副本，而是直接对指针本身进行修改。
//因此，当我们在函数内修改指针的指向对象时，操作会同样影响到函数外的实参。
void SwapRefPnt(int *&i, int *&j)
{
    int *t = i;
    i = j;
    j = t;
}

//这个函数实际用另一层指针指向了我想修改的指针。
//因为对于非引用的参数，函数都会创建一个指向相同对象的复制对象。
//虽然复制对象的值在函数结束后不会被保留，但指向对象的值如果发生修改，就会确确实实地作用在实参上。
//因此，如果有一个指向指针的指针被传入，我通过修改内层指针的指向对象，也就能实现改变指针变量指向值的目的。
void SwapPntPnt(int **k, int **l)
{
    int *t = *k;
    *k = *l;
    *l = t;
}

int main()
{
    cout << "Example 1" << endl;
    int a = 5, b = 10;
    int c = 5, d = 10;
    cout << "The address of a: " << &a << "  The address of b: " << &b << endl;
    cout << "The address of c: " << &c << "  The address of d: " << &d << endl;

    int &ra = a, &rb = b;
    cout << "SwapRef" << endl;
    SwapRef(ra, rb);
    cout << "ra : " << ra << "  rb :" << rb << endl;
    cout << endl;

    cout << "Example 2" << endl;
    //从这里pc与pd的内存位置来看，ra与rb就被排在内存上d与pc的中间位置。
    int *pc = &c, *pd = &d;
    cout << "The address of pc: " << &pc << "  The address of pd: " << &pd << endl;
    cout << "The address stored in pc: " << pc << "  The address stored in pd: " << pd << endl;
    cout << "SwapPnt" << endl;
    SwapPnt(pc, pd);
    //因为改变只是针对函数内部的复制值的变化，外面的值全都不会受影响。
    cout << "pc : " << *pc << "  pd :" << *pd << endl;
    cout << "The address of pc: " << &pc << "  The address of pd: " << &pd << endl;
    cout << "The address stored in pc: " << pc << "  The address stored in pd: " << pd << endl;
    cout << endl;

    cout << "Example 3" << endl;
    int e = 5, f = 10;
    int *pe = &e, *pf = &f;
    cout << "e: " << e << "  f: " << f << endl;
    cout << "SwapPntValue" << endl;
    SwapPntValue(pe, pf);
    //因为直接调整了指针指向的值，所以外部的值也更正发生了改变。
    cout << "e: " << e << "  f: " << f << endl;
    cout << endl;

    cout << "Example 4" << endl;
    int g = 5, h = 10;
    int *pg = &g, *ph = &h;
    //本来我想尝试让引用变量指向指针的。这样一来在函数中改变引用变量的值相当于就是改变了外部的指针的指向。
    //但引用变量不能指向指针，只能指向指针指向的值。
    //换言之，我暂时不知道要怎么用函数改变指针变量指向的值。
    int &rg = *pg, &rh = *ph;
    cout << "The address of g: " << &g << "  The address of h: " << &h << endl;
    cout << "The address of pg: " << &pg << "  The address of ph: " << &ph << endl;
    cout << "The address stored in rg: " << &rg << "  The address stored in rh: " << &rh << endl;
    cout << endl;

    cout << "Example 5" << endl;
    int i = 5, j = 10;
    int *pi = &i, *pj = &j;
    int *&ri = pi, *&rj = pj;
    cout << "The value of pi: " << *pi << "  The Value of pj: " << *pj << endl;
    cout << "The address stored in pi: " << pi << "  The address stored in pj: " << pj << endl;
    SwapRefPnt(pi, pj);
    cout << "SwapRefPnt" << endl;
    //因为函数使用的是引用指针，所以内部对指针的重新指向会影响外部的实参，导致pi与pj所指向地址的变化。
    cout << "The value of pi: " << *pi << "  The Value of pj: " << *pj << endl;
    cout << "The address stored in pi: " << pi << "  The address stored in pj: " << pj << endl;
    cout << endl;
    
    cout << "Example 6" << endl;
    int k = 5, l = 10;
    int *pk = &k, *pl = &l;
    int **ppk = &pk, **ppl = &pl;
    cout << "The value of pk: " << *pk << "  The Value of pl: " << *pl << endl;
    cout << "The address stored in pk: " << pk << "  The address stored in pl: " << pl << endl;
    SwapPntPnt(ppk, ppl);
    //这个做法其实就是上面例5中的变形。用另一个指向pk指针的指针ppk取代了之前的引用参数。
    //通过修改被复制的外层指针所指向的内层指针的值的手段，来实现利用函数修改指针指向的目的。
    cout << "SwapPntPnt" << endl;
    cout << "The value of pk: " << *pk << "  The Value of pl: " << *pl << endl;
    cout << "The address stored in pk: " << pk << "  The address stored in pl: " << pl << endl;

}
