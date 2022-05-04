#include "Header.h"

Student::Student(){}
Student::~Student(){}
void Student::registerStudent(){

    string fn,ln;

    cout << "\t- Student  -" << endl;
    cout << "Nombre, Apellido" << endl;
    cin >> fn >> ln;
    setFirstName(fn);
    setLastName(ln);
    system("cls");
    cout << "Student registered succesfuly!";
}
void Student::setFirstName(const string& FirstName)
{
    size_t length{FirstName.size()};
    length = (length < 15 ? length : 14);
    FirstName.copy(fname, length);
    fname[length] = '\0';
}
void Student::setLastName(const string& LastName)
    {
        size_t length{LastName.size()};
        length = (length < 10 ? length : 9);
        LastName.copy(lname, length);
        lname[length] = '\0';
    }
   