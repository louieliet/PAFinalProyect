#include "ProyectHeader.h"


int main() {

    ofstream outStudentFile{"studentfile.txt", ios::out};

    if (!outStudentFile) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    };

    int nalumn{0};

    cout << "Numero de alumnos: " << endl;
    cin >> nalumn;
    Student* list = new Student[nalumn];

    for(int i{0}; i<nalumn; i++)
    {
        list[i].registerStudent();
        list[i].outName(outStudentFile);
    }
    delete list;
    
    return 0;
}
