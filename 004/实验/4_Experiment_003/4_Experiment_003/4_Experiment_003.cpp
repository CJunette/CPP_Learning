// 4_Experiment_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

enum Sex{MALE, FEMALE};

class Birthday
{
    public:
    Birthday(int yr, int mon, int d) :
        year(yr), month(mon), day(d)
    {
        cout << "Creating Birthday" << endl;
    }
    Birthday():
        Birthday(2000, 1, 1)
    {}
    Birthday(Birthday &bir):
        year(bir.year), month(bir.month), day(bir.day)
    {
        cout << "Copying Birthday" << endl;
    }
    ~Birthday() { cout << "Destroy Birthday" << endl; }
    void setYear(int yr) { year = yr; }
    void setMonth(int mon) { month = mon; }
    void setDay(int dy) { day = dy; }
    void showBirthday() { cout << year << ":" << month << ":" << day << endl; }

    private:
    int year, month, day;
};

class People
{
    public:
    People(int num, double i, Sex sx, Birthday bir) :
        number(num), id(i), sex(sx), birthday(bir)
    {
        cout << "Creating People" << endl;
    }
    People(People &peo) :
        number(peo.number), id(peo.id), sex(peo.sex), birthday(peo.birthday)
    {
        cout << "Copying People" << endl;
    }
    ~People() { cout << "Destroying People" << endl; }
    void setNumber(int num) { number = num; }
    void setID(double i) { id = i; }
    void setSex(Sex s) { sex = s; }
    void setBirthday(Birthday bir) { birthday = bir; }
    void showPeople()
    {
        cout << "Number: " << number << endl;
        cout << "ID: " << setprecision(12) << id << endl;
        cout << "Sex: " << (sex ? "Female" : "Male") << endl;
        cout << "Birthday: ";
        birthday.showBirthday();        
    }

    private:
    int number;
    double id;
    Sex sex;
    Birthday birthday;
    
};

int main()
{
    Birthday birthday(2020, 4, 26);
    People somebody(001, 3120100212, MALE, birthday);
    cout << "-----------------Show-----------------" << endl;
    somebody.showPeople();
    cout << "-----------------Show-----------------" << endl;


}
