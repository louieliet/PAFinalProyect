#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
using namespace std;
class Student{
    
private:    
    char* name, department;
    int matricula, credits;
public:
    Student(){};
    ~Student(){};

    void registerStudent()
    {
        int m,c;
        string n,f;
        
        system("cls");
        cout << "\t- Student -" << endl;
        cout << "Matricula, Nombre, Facultad, Creditos" << endl;
        cin >> m >> n >> f >> c;
        setStudent(m,n,f,c);
        system("cls");
        cout << "Student registered succesfuly!";
    }

    void setStudent(int matricula, string name, string department, int credits) 
    {
        this->matricula=matricula;
        this->name=stringtochar(name);
        this->department=stringtochar(department);
        this->credits=credits;
    }

    void outStudent(ofstream& file) { file << matricula << " " << name << " " << department << " " << credits;}

    char* stringtochar(string _name)
    {      
        string name=_name;
        char* c = const_cast<char*>(name.c_str());
        return c;
    }
};

class Takes
{

};

class Course
{

};

