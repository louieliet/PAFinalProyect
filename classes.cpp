#include <iostream>
using namespace std;

class Student
{
private:    
    char name[20], department[20];
    int matricula, credits;
public:
    Student(int matricula,char name[20],char department[20] ,int credits)
    {
        this->matricula=matricula;
        *this->name=*name;
        *this->department=*department;
        this->credits=credits;
    };

};

class Takes
{

};

class Course
{

};