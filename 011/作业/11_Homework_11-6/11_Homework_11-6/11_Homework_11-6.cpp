// 11_Homework_11-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

class Dog
{
    public:
    Dog(double weight = 1, int age = 0):
        weight(weight), age(age)
    {}
    double getWeight() const { return weight; }
    int getAge() const { return age; }    
    void setWeight(double w) { weight = w; }
    void setAge(double a) { age = a; }

    private:
    double weight;
    int age;
};

ostream &operator << (ostream &out, const Dog &d)
{
    out << d.getWeight() << " " << d.getAge();
    return out;
}

istream &operator >> (istream &in, Dog &d)
{
    double weight;
    int age;
    in >> weight >> age;
    d.setWeight(weight);
    d.setAge(age);
    return in;
}

int main()
{
    {
        Dog d1(5, 10);
        //是否使用二进制作为提取或插入的区别在于，不使用二进制会导致10被存入时出现书上p490讲到的问题。
        //即，10会被当成换行符，而windows要求换行符要搭配回车符，因此10会被储存为10 13（书上说是10 13，练习册是13 10）。
        ofstream out("data.txt", ios::binary);
        if(!out)
        {
            cout << "Error: Can't open file!";
            return 1;
        }
        out << d1;
        out.close();

        Dog d2;
        ifstream in("data.txt", ios::binary);
        if(!in)
        {
            cout << "Error: Can't open file!";
            return 1;
        }
        in >> d2;
        cout << "Weight: " << d2.getWeight() << "\tAge: " << d2.getAge() << endl << endl;
        in.close();
    }
    
    {
        //下面是练习册上给出的利用write()和read()函数的做法。
        Dog d1(5, 10);
        ofstream out("data1.txt", ios::binary);
        if(!out)
        {
            cout << "Error: Can't open file!";
            return 1;
        }
        out.write((char*)(&d1), sizeof(d1));
        out.close();

        Dog d2;
        ifstream in("data1.txt", ios::binary);
        if(!in)
        {
            cout << "Error: Can't open file!";
            return 1;
        }
        in.read((char *)(&d2), sizeof(d2));
        cout << "Weight: " << d2.getWeight() << "\tAge: " << d2.getAge() << endl << endl;
        in.close();
    }
}