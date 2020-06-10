// 8_Experiment_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Date
{
    public:
    Date(int year, int month, int day):
        _year(year), _month(month), _day(day)
    {}
    void show() const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    int getYear() { return _year; }
    int getMonth() { return _month; }
    int getDay() { return _day; }

    bool operator ==(Date d)
    {
        return (_year == d.getYear()) && (_month == d.getMonth()) && (_day == d.getDay());
    }

    private:
    int _year, _month, _day;
};

class People
{
    public:
    People(const char name[11], const char number[7], const char sex[3], Date const &birthday, const char id[16]):
        _birthday(birthday)
    {
        for(int i = 0; i < sizeof(_name) / sizeof(char); i++)
        {
            _name[i] = name[i];
        }
        for(int i = 0; i < sizeof(_number) / sizeof(char); i++)
        {
            _number[i] = number[i];
        }
        for(int i = 0; i < sizeof(_sex) / sizeof(char); i++)
        {
            _sex[i] = sex[i];
        }
        for(int i = 0; i < sizeof(_id) / sizeof(char); i++)
        {
            _id[i] = id[i];
        }
    }
    People(People const &p):
        _birthday(p._birthday)
    {
        for(int i = 0; i < sizeof(_name) / sizeof(char); i++)
        {
            _name[i] = p._name[i];
        }
        for(int i = 0; i < sizeof(_number) / sizeof(char); i++)
        {
            _number[i] = p._number[i];
        }
        for(int i = 0; i < sizeof(_sex) / sizeof(char); i++)
        {
            _sex[i] = p._sex[i];
        }
        for(int i = 0; i < sizeof(_id) / sizeof(char); i++)
        {
            _id[i] = p._id[i];
        }
    }

    void operator =(People const &p)
    {
        _birthday = p._birthday;
        for(int i = 0; i < 11; i++)
        {
            _name[i] = p._name[i];
        }
        for(int i = 0; i < 7; i++)
        {
            _number[i] = p._number[i];
        }
        for(int i = 0; i < 7; i++)
        {
            _sex[i] = p._sex[i];
        }
        for(int i = 0; i < 16; i++)
        {
            _id[i] = p._id[i];
        }
    }

    bool operator ==(People const &p)
    {
        bool bforname = true, bfornumber = true, bforsex = true, bforid = true;
        for(int i = 0; i < sizeof(_name) / sizeof(char); i++)
        {
            if(_name[i] != '\0')
            {
                if(_name[i] != p._name[i])
                {
                    bforname = false;
                }
            }
        }
        for(int i = 0; i < sizeof(_number) / sizeof(char); i++)
        {
            if(_number[i] != '\0')
            {
                if(_number[i] != p._number[i])
                {
                    bfornumber = false;
                }
            }
        }
        for(int i = 0; i < sizeof(_sex) / sizeof(char); i++)
        {
            if(_sex[i] != '\0')
            {
                if(_sex[i] != p._sex[i])
                {
                    bforsex = false;
                }
            }
        }
        for(int i = 0; i < sizeof(_id) / sizeof(char); i++)
        {
            if(_id[i] != '\0')
            {
                if(_id[i] != p._id[i])
                {
                    bforid = false;
                }
            }
        }
        bool bforbirthday = (_birthday == p._birthday);
        return bforname && bfornumber && bforsex && bforbirthday && bforid;
    }

    void showName() const
    {
        for(char c: _name)
        {
            if(c != '\0')
            {
                cout << c;
            }
            else
            {
                cout << endl;
                break;
            }
        }        
    }
    void showNumber() const
    {
        for(char c : _number)
        {
            if(c != '\0')
            {
                cout << c;
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }
    void showSex() const
    {
        for(char c : _sex)
        {
            if(c != '\0')
            {
                cout << c;
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }    
    void showBirthday() const
    {
        _birthday.show();
    }
    void showID() const
    {
        for(char c : _id)
        {
            if(c != '\0')
            {
                cout << c;
            }
            else
            {
                cout << endl;
                break;
            }
        }
    }
    private:
    char _name[11];
    char _number[7];
    char _sex[7];
    Date _birthday;
    char _id[16];
};

int main()
{    
    People p1("Peter", "000001", "male", Date(2000, 1, 1), "00010001");
    People p2 = p1;

    p2.showName();
    p2.showNumber();
    p2.showSex();
    p2.showBirthday();
    p2.showID();

    cout << (p1 == p2) << endl;
}
