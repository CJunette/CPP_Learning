// 8_Homework_8-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const double Pi = 3.1415926535898;

class Shape
{
    public:
    virtual double getArea() const = 0;
    virtual double getPerim() const = 0;
    int getVertexCount_dynamic();
    int getVertexCount_typeid();
    virtual int getVertexCount_virtual() const;
};

/*----------------------------------------------------------------*/

class Rectangle: public Shape
{
    public:
    Rectangle(double x, double y):
        x(x), y(y)
    {}
    virtual double getArea() const override;
    virtual double getPerim() const override;
    virtual int getVertexCount_virtual() const override;
    private:
    double x, y;
};
double Rectangle::getArea()  const
{
    return x * y;
}
double Rectangle::getPerim() const
{
    return 2 * (x + y);
}
int Rectangle::getVertexCount_virtual() const
{
    return 4;
}

/*----------------------------------------------------------------*/

class Square: public Rectangle
{
    public:
    Square(double x):
        Rectangle(x, x)
    {}
    private:;
};

/*----------------------------------------------------------------*/

class Circle: public Shape
{
    public:
    Circle(double r):
        r(r)
    {}
    virtual double getArea() const override;
    virtual double getPerim() const override;
    virtual int getVertexCount_virtual() const;
    private:
    double r;
};
double Circle::getArea() const
{
    return Pi * r * r;
}
double Circle::getPerim() const
{
    return Pi * r * 2;
}
int Circle::getVertexCount_virtual() const
{
    return 0;
}

/*----------------------------------------------------------------*/

//1.这里由于有涉及Rectangle和Circle类的强制类型转换（即使只是转为指针），所以必须将函数的具体定义放到这两个类的定义之后才行。
int Shape::getVertexCount_dynamic()
{
    if(dynamic_cast<Rectangle *>(this))
    {
        return 4;
    }
    else if(dynamic_cast<Circle *>(this))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//2.如果是求未定义类的指针的typeid，则不需要等到对应的类有了具体实现以后。
//3.但如果是求未定义的类的typeid，则还是要等到类具体定义了以后。原因在第4章前向引用声明中都提到了。
//3.如果这里用了涉及对象的表达式，则还是会报错。因为在类未定义前使用其对象是错误的。
//4.我在这边曾经想尝试，看看是否能够通过在前向引用声明中声明继承关系，然后通过继承关系让Rectangle类具有多态性，然后把“typeid(Rectangle)”放到运行中执行。
//4.但首先，前向引用声明中不能声明继承关系；其次，多态性是针对对象的，而不是针对类的。因此这样的想法是不会成功的。
int Shape::getVertexCount_typeid()
{
    //5.这里，因为指针类型是固定的“Shape *”，因此如果在这里比较指针是否相同，则不论指向对象是什么，结果都会return -1。
    //5.出于这个原因，我将这个函数的定义也放到了Rectangle、Square、Circle类的定义之后。
    //5.然后将比较内容从指针变为了对象。
    if(typeid(*this) == typeid(Rectangle))
    {
        return 4;
    }
    //6.另外，由于typeid的比较是不涉及基类和派生类，只涉及当前类的，因此不能像dynamic_cast那样只写Rectangle不写Square。
    else if(typeid(*this) == typeid(Square))
    {
        return 4;
    }
    else if(typeid(*this) == typeid(Circle))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int Shape::getVertexCount_virtual() const
{
    return -1;
}

/*----------------------------------------------------------------*/

void func(Shape *s)
{
    cout << "Area:\t" << s->getArea() << endl;
    cout << "Perimeter:\t" << s->getPerim() << endl;
    cout << "VertexCount_dynamic:\t" << s->getVertexCount_dynamic() << endl;
    cout << "VertexCount_typeid:\t" << s->getVertexCount_typeid() << endl;
    cout << "VertexCount_virtual:\t" << s->getVertexCount_virtual() << endl;
}

//7.比较看来，虚函数和dynamic_cast的做法都还算简单。由于getVertex这样的功能属于类族的统一接口，因此还是用虚函数做会更合适。
//7.相比之下，typeid由于无法很好地利用继承功能，相关的代码就显得很繁琐。
int main()
{
    Rectangle t(1, 2);
    Square s(1);
    Circle c(1);

    func(&t);
    cout << endl;
    func(&s);
    cout << endl;
    func(&c);
    cout << endl;
}