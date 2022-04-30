#include <iostream>
#include <string>
using namespace std;

class Student
{
private:    
    char name[20], department[20];
    int matricula, credits;

public:
    Student(int matricula,const string& name,const string& department,int credits)
    {
        setMatricula(matricula);
        setName(name);
        setDepart(department);
        setCredits(credits);
        
    }

    void setMatricula(int matricula){this->matricula=matricula;}

    int getMatricula() const {return matricula;}

    void setName(const string& namestring)
    {
        size_t length{namestring.size()};
        length = (length<20 ? length : 19);
        namestring.copy(name,length);
        name[length] = '\0';
    }

    char* getName() {return name;}
    
    void setDepart(const string& departmentstring)
    {
        size_t length{departmentstring.size()};
        length = (length<20 ? length : 19);
        departmentstring.copy(name,length);
        department[length] = '\0';

    }

    char* getDepart() {return department;}

    void setCredits(int credits) {this->credits=credits;}

    int getCredits() {return credits;}
    
};

class Takes
{

};

class Course
{

};