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
    Student(int matricula, string name, string department, int credits) {
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

