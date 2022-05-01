#include "source.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
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
    Student* arraystudents = new Student[nalumn];

    for(int i=0; i<nalumn; i++)
    {
        string name=" ", dept=" ";
        int tuition{0}, credits{0};

        cout << "Ingrese los datos del estudiante [" << i+1 << "] en el orden correspondiente: (Matricula, Nombre, Facultad, Creditos) "<< endl;
        cin >> tuition >> name >> dept >> credits;
        arraystudents[i].registerStudent(tuition,name,dept,credits);
    }

    
    for(int i=0; i<=nalumn; i++) {
        cout<< arraystudents[i].getMatricula() << arraystudents[i].getName() << arraystudents[i].getDepart() << arraystudents[i].getCredits();
    }

    return 0;
}