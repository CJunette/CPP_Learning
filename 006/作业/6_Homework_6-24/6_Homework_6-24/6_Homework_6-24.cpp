// 6_Homework_6-24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
    public:
    MyString(const char *s)
    {
        strsize = 0;
        const char *ptr = s;
        while (ptr[strsize] != '\0')
        {
            strsize++;
        }        
        str = new char[strsize + 1];
        for (int i = 0; i < strsize; i++)
        {
            str[i] = s[i];
        }
        str[strsize] = '\0';
    }
    MyString() :
        MyString("")
    {}
    MyString(MyString const &mstr)
    {
        strsize = mstr.strsize;
        str = new char[strsize + 1];
        for (int i = 0; i < strsize; i++)
        {
            str[i] = mstr.str[i];
        }
        str[strsize] = '\0';
    }
    ~MyString()
    {
        delete[] str;
    }
    
    int size() { return strsize; }
    void out()
    {
        for (int i = 0; i < strsize; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }

    char& operator [] (unsigned int i) const 
    {
        if (i > strsize)
        {
            return *(str + strsize - 1);
        }
        else
        {
            return *(str + i);
        }
    }
    MyString operator + (MyString const &addstr)
    {
        char *add = new char[strsize + addstr.strsize + 1];
        for (int i = 0; i < strsize; i++)
        {
            add[i] = str[i];
        }
        for (int i = 0; i < addstr.strsize; i++)
        {
            add[i + strsize] = addstr[i];
        }
        add[strsize + addstr.strsize] = '\0';
        return MyString(add);
    }
    void operator = (MyString const &equalstr)
    {
        assign(equalstr.str);
    }
    void operator += (MyString const &addequalstr)
    {
        assign((*this + addequalstr).str);
    }

    //改变调用对象本身的str。
    MyString &insert(unsigned int pos, const char *s)
    {
        if (pos > strsize || pos < 0)
        {
            cout << "Wrong position!" << endl;
            exit(1);
        }

        MyString ms(s);
        char *newstr = new char[ms.strsize + strsize + 1];
        for (int i = 0; i < pos; i++)
        {
            newstr[i] = str[i];            
        }
        int j = 0;
        for (int i = pos; i < pos + ms.strsize; i++)
        {
            newstr[i] = ms[j];
            j++;
        }
        j = pos;
        for (int i = pos + ms.strsize; i < strsize + ms.strsize; i++)
        {
            newstr[i] = str[j];
            j++;
        }
        newstr[ms.strsize + strsize] = '\0';
        delete str;
        str = newstr;
        strsize = ms.strsize + strsize;
        //这里既然对象本身被改变了，返回时直接用*this返回对象本身即可。
        return *this;
    }

    //不改变调用对象本身的str。
    MyString substr(unsigned int pos, unsigned int n) const
    {
        if (pos > strsize - 1 || n > strsize - pos)
        {
            cout << "Wrong position or wrong length!" << endl;
            exit(1);
        }
        
        char *sub = new char[n + 1];
        int j = 0;
        for (int i = pos; i < pos + n; i++)
        {
            sub[j] = str[i];
            j++;
        }
        sub[n] = '\0';        
        MyString retsub(sub);
        delete[] sub;
        return retsub;
    }

    //改变调用对象本身的str。
    MyString &append(const char *s)
    {
        return insert(strsize, s);
    }

    //改变调用对象本身的str。
    MyString &assign(const char *s)
    {
        delete str;
        MyString newstr(s);
        str = new char[newstr.strsize + 1];
        for (int i = 0; i < newstr.strsize; i++)
        {
            str[i] = newstr[i];
        }
        str[newstr.strsize] = '\0';
        strsize = newstr.strsize;
        return *this;
    }

    //不改变调用对象本身的str。
    int find(const char *fndstr) const
    {
        MyString fmstr(fndstr);
        for (int i = 0; i < strsize; i++)
        {
            if (str[i] == fndstr[0])
            {
                if (strsize - i < fmstr.strsize)
                {
                    break;
                }
                else
                {
                    MyString check = this->substr(i, fmstr.strsize);
                    if (check.compare(fmstr) == 0)
                    {
                        return i;
                    }
                }
                
            }
        }
        return -1;
    }
    //不改变调用对象本身的str。
    int compare(const MyString &compstr) const
    {
        int i = 0;
        while (str[i] != '\0' && compstr[i] != '\0')
        {
            if (str[i] > compstr[i])
            {
                return 1;
            }
            if (str[i] < compstr[i])
            {
                return -1;
            }
            i++;
        }
        if (str[i] != 0 && compstr[i] == 0)
        {
            return 1;
        }
        else if (str[i] == 0 && compstr[i] != 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    //改变调用对象本身的str。
    void swap(MyString &swpstr)
    {
        char *tempstr = str;
        int tempsize = strsize;
        str = swpstr.str;
        strsize = swpstr.strsize;
        swpstr.str = tempstr;
        swpstr.strsize = tempsize;
    }

    private:
    char *str;
    int strsize;
};

int main()
{
    MyString mstr("abcd");
    mstr.out();

    mstr.substr(0, 2).out();
    mstr.out();

    mstr.insert(1, "zzzz").out();
    mstr.out();

    mstr.append("qqq").out();
    mstr.out();

    mstr.assign("sssq").out();
    mstr.out();

    cout << mstr.compare("ssqs") << endl;

    cout << mstr.find("sq") << endl;

    MyString swap("Hello");
    mstr.swap(swap);
    mstr.out();
    swap.out();

    (mstr + "abcde").out();
    mstr.out();

    mstr = "World";
    mstr.out();

    mstr += " Hello";
    mstr.out();
}
