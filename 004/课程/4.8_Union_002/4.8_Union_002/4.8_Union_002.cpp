// 4.8_Union_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Example
//union通常被植入class中使用。

#include <iostream>
#include <string>
using namespace std;

class ExamInfo
{
    public:
    ExamInfo(string cours, char grd) :
        course(cours), mode(GRADE), grade(grd)
    {}
    ExamInfo(string cours, bool pas) :
        course(cours), mode(PASS), pass(pas)
    {}
    ExamInfo(string cours, int pecnt) :
        course(cours), mode(PERCENT), percent(pecnt)
    {}

    void showInfo()
    {
        cout << course << ": ";
        switch (mode)
        {
            case ExamInfo::GRADE:
                cout << grade << endl;
                break;
            case ExamInfo::PASS:
                //注意这里这个三目运算要用括号。
                cout << (pass ? "Pass" : "Fail") << endl;
                break;
            case ExamInfo::PERCENT:
                cout << percent << endl;
                break;
            default:
                break;
        }
    }

    private:
    string course;

    //这里如果我把enum的这行代码写成“enum mode {GRADE, PASS, PERCENT}”，会出现了报错（mode is not a nonstatic data member or base class of class）。
    //将鼠标移到代码错误时候的上面的mode上，会显示mode是一个enum类型的类。而实际上，在这里我们需要的是一个mode类的对象。
    //修改后的这种“{}”在前，名称在后的写法。其实就相当于先写了“mode {GRADE, PASS, PERCENT}”，然后写“mode mode”创建了一个对象。（注意现实中不要让类名和变量名相同）
    //而在修改之后我们再将鼠标移到mode上会发现,mode有了“field”的字样，说明它现在是一个对象成员。
    enum { GRADE, PASS, PERCENT } mode;

    union
    {
        char grade;
        bool pass;
        int percent;
    };
};

int main()
{
    ExamInfo course1("English", 'A');
    ExamInfo course2("Calculus", true);
    ExamInfo course3("C++ Programming", 95);

    course1.showInfo();
    course2.showInfo();
    course3.showInfo();

}

