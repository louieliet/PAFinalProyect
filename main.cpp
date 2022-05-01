#include "source.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    ofstream outStudentFile{"studentfile.txt", ios::out};

    if (!outStudentFile) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    };

    int nalumn{0};
    bool out = true;

    cout << "Numero de estudiantes: " << endl;
    cin >> nalumn;
    Student* studentList = new Student[nalumn];

    for(int i{0};i<nalumn;i++)
    {
        studentList[i].registerStudent();
    }
    


    



    return 0;
}