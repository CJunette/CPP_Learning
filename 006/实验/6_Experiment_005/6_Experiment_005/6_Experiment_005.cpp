// 6_Experiment_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

const int maxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
    public:
    Date(int y, int m, int d)
    {
        isLeap = isLeapYear(y);        
        if (m < 1 || m > 12)
        {
            cout << "Wrong input of month!" << endl;
            exit(1);
        }
        checkDays(m, d);
        year = y;
        month = m;
        day = d;
    }
    void show() const
    {
        cout << year << "-" << month << "-" << day << endl;
    }

    private:
    int year, month, day;
    bool isLeap;
    bool isLeapYear(int y)
    {
        return y % 4 == 0 && y % 100 != 0 || y && 400 == 0;
    }
    void checkDays(int m, int d)
    {
        if (isLeap && m == 2)
        {
            if (d < 0 || d > 29)
            {
                cout << "Wrong input of day!" << endl;
                exit(1);
            }            
        }
        if (d > maxDays[m-1] || d < 0)
        {
            cout << "Wrong input of day!" << endl;
            exit(1);
        }
    }
};

class People
{
    public:
    People(string const &n, string const &nb, string const &s, Date const &b, string const &i) :
        name(n), number(nb), sex(s), birthday(b), id(i)
    {}
    People(const People& p):
        name(p.name), number(p.number), sex(p.sex), birthday(p.birthday), id(p.id)
    {}
    ~People()
    {}
    void showName() const{ cout << name << endl; }
    void showNumber() const { cout << number << endl; }
    void showSex() const { cout << sex << endl; }
    void showID() const { cout << id << endl; }
    void showBirthday() const{ birthday.show(); }
    void setName(string const &n) { name = n; }
    void setNumber(string const &nb) { number = nb; }
    void setSex(string const &s) { sex = s; }
    void setID(string const &i) { id = i; }
    void setBirthday(Date const &b) { birthday = b; }

    private:
    string name, number, sex, id;
    Date birthday;
};

int main()
{
    Date d1(1971, 10, 29);
    Date d2(1964, 9, 10);    
    People pp[] = {
    People("Pony Ma", "000000001", "Male", d1, "11011011011011"),
    People("Jack Ma", "000000001", "Male", d2, "11011011011011")
    };

}
