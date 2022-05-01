#include <iostream>
#include <string>
using namespace std;

class Student
{
private:    
    string name, department;
    int matricula, credits;
public:
    void registerStudent() 
    {
        string nombre, facultad;
        int matricula, creditos;
        system("cls");
        cout << " -Register Student- " << endl;
        cout << "- Matricula - " << endl;
        cin >> matricula;
        cout << "- Nombre - " << endl;
        cin >> nombre;
        cout << "- Facultad - " << endl;
        cin >> facultad;
        cout << "- Creditos - " << endl;
        cin >> creditos;

        setStudent(matricula,nombre,facultad,creditos);
        system("cls");

    }
    void setStudent(int matricula, string name, string department, int credits)
    {
        this->matricula=matricula;
        this->name=name;
        this->department=department;
        this->credits=credits;

    }
    void setCredits(int credits) {this->credits=credits;}
    void setMatricula(int matricula){this->matricula=matricula;}
    void setName(const string& namestring)
    {
    }
    void setDepart(const string& departmentstring)
    {
    }
    char getName() {return name;}
    char getDepart() {return department;}
    int getCredits() {return credits;}
    int getMatricula() const {return matricula;}
};

class Takes
{

};

class Course
{

};

