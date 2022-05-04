#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
class Student{
private:    
    char fname[15], lname[10], department[7];
    int matricula, credits;
public:
    Student(){};
    ~Student(){};

    void registerStudent(){
        int m,c;
        string fn,ln,f;
        
        cout << "\t- Student  -" << endl;
        cout << "Matricula, Nombre, Apellido, Facultad, Creditos" << endl;
        cin >> m >> fn >> ln >> f >> c;
        setInts(m,c);
        setFirstName(fn);
        setLastName(ln);
        setDepartment(f);
        system("cls");
        cout << "Student registered succesfuly!";
    }

    void setFirstName(const string& FirstName)
    {
        size_t length{FirstName.size()};
        length = (length < 15 ? length : 14);
        FirstName.copy(fname, length);
        fname[length] = '\0';
    }
    void setLastName(const string& LastName)
    {
        size_t length{LastName.size()};
        length = (length < 10 ? length : 9);
        LastName.copy(lname, length);
        lname[length] = '\0';
    }
    void setDepartment(const string& Department)
    {
        size_t length{Department.size()};
        length = (length < 7 ? length : 6);
        Department.copy(lname, length);
        department[length] = '\0';
    }
    void setInts(int tuition, int credits)
    {
        this->matricula=tuition;
        this->credits=credits;
    }

    void outStudent(ofstream& file) { file << matricula << " " << fname << lname << " " << department << " " << credits;}    
};


