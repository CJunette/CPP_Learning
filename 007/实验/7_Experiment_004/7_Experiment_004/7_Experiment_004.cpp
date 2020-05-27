// 7_Experiment_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        if(m < 1 || m > 12)
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
        if(isLeap && m == 2)
        {
            if(d < 0 || d > 29)
            {
                cout << "Wrong input of day!" << endl;
                exit(1);
            }
        }
        if(d > maxDays[m - 1] || d < 0)
        {
            cout << "Wrong input of day!" << endl;
            exit(1);
        }
    }
};

class People
{
    public:
    People(string const &name, string const &number, string const &sex, Date const &birthday, string const &id):
        name(name), number(number), sex(sex), birthday(birthday), id(id)
    {}
    People(const People &p):
        name(p.name), number(p.number), sex(p.sex), birthday(p.birthday), id(p.id)
    {}
    ~People()
    {}
    void showName() const { cout << name << endl; }
    void showNumber() const { cout << number << endl; }
    void showSex() const { cout << sex << endl; }
    void showID() const { cout << id << endl; }
    void showBirthday() const { birthday.show(); }
    void setName(string const &n) { name = n; }
    void setNumber(string const &nb) { number = nb; }
    void setSex(string const &s) { sex = s; }
    void setID(string const &i) { id = i; }
    void setBirthday(Date const &b) { birthday = b; }

    private:
    string name, number, sex, id;
    Date birthday;
};

class Student: virtual public People
{
    public:
    Student(People const &peo, char const (&classno)[7]):
        People(peo)
    {
        for(int i = 0; i < 7; i++)
        {
            classNo[i] = classno[i];
        }
    }
    void showClassNo() const 
    {
        for(int i = 0; i < 7; i++)
        {
            cout << classNo[i];
        }
        cout << endl;
    }
    void setClassNo(char const (&cn)[7])
    {
        for(int i = 0; i < 7; i++)
        {
            classNo[i] = cn[i];
        }
    }

    private:
    char classNo[7];
};

class Teacher: virtual public People
{
    public:
    Teacher(string const &name, string const &number, string const &sex, Date const &birthday, string const &id, char const (&principal)[11], char const (&departm)[21]):
        People(name, number, sex, birthday, id)
    {
        for(int i = 0; i < 11; i++)
        {
            principalship[i] = principal[i];
        }
        for(int i = 0; i < 21; i++)
        {
            department[i] = departm[i];
        }
    }
    void showPrincipalship() const
    {
        for(int i = 0; i < 11; i++)
        {
            cout << principalship[i];
        }
        cout << endl;
    }
    void setPrincipalship(char (&principal)[11])
    {
        for(int i = 0; i < 11; i++)
        {
            principalship[i] = principal[i];
        }
    }
    void showDepartment() const
    {
        for(int i = 0; i < 21; i++)
        {
            cout << department[i];
        }
        cout << endl;
    }
    void setDepartment(char(&departm)[21])
    {
        for(int i = 0; i < 11; i++)
        {
            department[i] = departm[i];
        }
    }
    private:
    char principalship[11];
    char department[21];
};

class Graduate: public Student
{
    public:
    Graduate(string const &name, string const &number, string const &sex, Date const &birthday, string const &id, char const (&classno)[7], char const (&subj)[21], Teacher *teach):
        People(name, number, sex, birthday, id), Student(name, number, sex, birthday, id, classno)
    {
        advisor = teach;
        for(int i = 0; i < 21; i++)
        {
            subject[i] = subj[i];
        }
    }
    void showSubject() const
    {
        for(int i = 0; i < 21; i++)
        {
            cout << subject[i];
        }
        cout << endl;
    }
    void setSubject(char const (&subj)[21])
    {
        for(int i = 0; i < 21; i++)
        {
            subject[i] = subj[i];
        }
    }
    void showTeacher() const
    {
        advisor->showName();
    }
    void setTeacher(Teacher *teach)
    {
        advisor = teach;
    }

    private:
    char subject[21];
    Teacher *advisor;
};

class TA: public Graduate, public Teacher
{
    public:
    TA(string const &name, string const &number, string const &sex, Date const &birthday, string const &id, char const (&classno)[7], char const (&subj)[21], Teacher *teach, char const (&principal)[11], char const (&departm)[21]):
        People(name, number, sex, birthday, id), Graduate(name, number, sex, birthday, id, classno, subj, teach), Teacher(name, number, sex, birthday, id, principal, departm)
    {
    }

    private:
};

int main()
{
    Date d1(1971, 10, 29);
    Date d2(1964, 9, 10);
    People pp[] = {
    People("Pony Ma", "000000001", "Male", d1, "11011011011011"),
    People("Jack Ma", "000000001", "Male", d2, "11011011011011")
    };

    Date d3(1965, 1, 1);
    char prin[11] = "Law";
    char depm[21] = "Law";
    Teacher LX("Luoxiang", "000001", "male", d3, "lx", prin, depm);

    char clasno[7] = "01";
    TA ta[] = {
        TA("ZhangSan", "000002", "male", d1, "zs", clasno, depm, &LX, prin, depm), 
        TA("LiSi", "000003", "male", d1, "ls", clasno, depm, &LX, prin, depm)
    };
}
