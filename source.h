#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
using namespace std;
class Student{
    
private:    
    string name, department;
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
    }

    void setStudent(int matricula, string name, string department, int credits) 
    {
        this->matricula=matricula;
        this->name=name;
        this->department=department;
        this->credits=credits;
    }

    void outStudent(ofstream& file) { file << matricula << " " << name << " " << department << " " << credits;}
};

class Takes
{

};

class Course
{

};

