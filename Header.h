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
    int matricula, credits, indice;
public:
    Student(){};
    ~Student(){};
    void registerStudent(){}
    void setFirstName(const string& FirstName){}
    void setLastName(const string& LastName){}
    void outStudent(ofstream& file) { file << matricula << " " << fname << lname << " " << department << " " << credits;}    
};


