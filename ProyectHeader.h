#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class Student
{
private:    
    char fname[15], lname[10], department[7];
    int matricula, credits, indice;
public:
    Student(){};
    ~Student(){};
    void registerStudent(){
    string fn,ln;

    cout << "\t- Student  -" << endl;
    cout << "Nombre, Apellido" << endl;
    cin >> fn >> ln;
    setFirstName(fn);
    setLastName(ln);
    system("cls");
    cout << "Student registered succesfuly!";
    }
    void setFirstName(const string & FirstName) {
    size_t length {FirstName.size()};
    length = (
        length < 15
            ? length
            : 14
    );
    FirstName.copy(fname, length);
    fname[length] = '\0';
    }
    void setLastName(const string & LastName) {
    size_t length {LastName.size()};
    length = (
        length < 10
            ? length
            : 9
    );
    LastName.copy(lname, length);
    lname[length] = '\0';
    }
    void outStudent(ofstream& file) { file << matricula << " " << fname << lname << " " << department << " " << credits;}    
};
